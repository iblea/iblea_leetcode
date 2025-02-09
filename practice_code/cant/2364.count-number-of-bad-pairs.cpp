#include <gtest/gtest.h>
#include <iostream>
#include <iomanip>
#include <algorithm>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <queue>
#include <array>

using namespace std;



/* https://leetcode.com/problems/count-number-of-bad-pairs/?envType=daily-question&envId=2025-02-09
 * @lc app=leetcode id=2364 lang=cpp
 * [2364] Count Number of Bad Pairs

You are given a 0-indexed integer array nums. A pair of indices (i, j) is a bad pair if i < j and j - i != nums[j] - nums[i].
Return the total number of bad pairs in nums.

0-인덱스 정수 배열 nums가 주어집니다. 인덱스 쌍 (i, j)에 대해 i < j이고 j - i != nums[j] - nums[i]인 경우 해당 쌍을 나쁜 쌍이라고 합니다.
nums에서 나쁜 쌍의 총 개수를 반환하세요.

Constraints:
1 <= nums.length <= 10**5
1 <= nums[i] <= 10**9
 */

// @lc code=start
class Solution {
public:
    long long countBadPairs(vector<int>& nums) {
        // 2->1
        // 3->3
        // 4->6  4*3/2
        // 5->10 5*4/2
        // 6->15 6*5/2
        int nlen = nums.size();
        long long total_nums = (long long)nlen * (nlen - 1) / 2;
        unordered_map<long long, int> diff_map;
        long long good_pairs = 0;
        // j - i == nums[j] - nums[i]
        // nums[j] - j == nums[i] - i
        // -> nums[i] - i 가 같은 값이면 좋은 쌍임.
        // 따라서 전체 쌍에서 좋은 쌍을 빼서 나쁜 쌍을 구하면 된다.
        for (int i = 0; i < nlen; i++) {
            long long diff = nums[i] - i;
            if (diff_map.find(diff) != diff_map.end()) {
                good_pairs += diff_map[diff];
                diff_map[diff]++;
            } else {
                diff_map[diff] = 1;
            }
        }

        return total_nums - good_pairs;
    }
};
// @lc code=end





#define CLASS_NAME gtest_template

class CLASS_NAME: public ::testing::Test {
private:
	clock_t t0;
	clock_t t1;
public:
	Solution s;
protected:
	CLASS_NAME() { this->s = Solution(); }
	~CLASS_NAME() override { }

	void SetUp() override { set_start_time(); }
	void TearDown() override { set_end_time(); get_duration_time(); }

	void set_start_time() {
		this->t0 = clock(); // or gettimeofday or whatever
	}
	void set_end_time() {
		this->t1 = clock(); // or gettimeofday or whatever
	}

	// 시간 관련 체크
	void get_duration_time() {
		double elapsedSec = (double)(this->t1 - this->t0) / (double)1000000;
		double elapsedMS = (double)(this->t1 - this->t0) / (double)1000;

		cout << setprecision(3) << fixed << endl << "Duration of Times : ";
		cout << elapsedMS << "ms, " << elapsedSec << "sec" << endl << endl;
	}

};

TEST_F(CLASS_NAME, __LINE__)
{
    // Example 1:
    // Input: nums = [4,1,3,3]
    // Output: 5
    // Explanation: The pair (0, 1) is a bad pair since 1 - 0 != 1 - 4.
    // The pair (0, 2) is a bad pair since 2 - 0 != 3 - 4, 2 != -1.
    // The pair (0, 3) is a bad pair since 3 - 0 != 3 - 4, 3 != -1.
    // The pair (1, 2) is a bad pair since 2 - 1 != 3 - 1, 1 != 2.
    // The pair (2, 3) is a bad pair since 3 - 2 != 3 - 3, 1 != 0.
    // There are a total of 5 bad pairs, so we return 5.

    vector<int> nums = {4,1,3,3};
	EXPECT_EQ(this->s.countBadPairs(nums), 5);
}

TEST_F(CLASS_NAME, __LINE__)
{
    // Example 2:
    // Input: nums = [1,2,3,4,5]
    // Output: 0
    // Explanation: There are no bad pairs.
    vector<int> nums = {1,2,3,4,5};
	EXPECT_EQ(this->s.countBadPairs(nums), 0);
}



int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}