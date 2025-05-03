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
#include <any>

using namespace std;



/* https://leetcode.com/problems/maximum-value-of-an-ordered-triplet-i/?envType=daily-question&envId=2025-04-02
 * @lc app=leetcode id=2873 lang=cpp
 * [2873] Maximum Value of an Ordered Triplet I

You are given a 0-indexed integer array nums.
Return the maximum value over all triplets of indices (i, j, k) such that i < j < k. If all such triplets have a negative value, return 0.
The value of a triplet of indices (i, j, k) is equal to (nums[i] - nums[j]) * nums[k].

0-인덱스 정수 배열 nums가 주어집니다.
i < j < k를 만족하는 모든 인덱스 세 쌍 (i, j, k)에 대해 최대값을 반환하세요. 만약 모든 세 쌍의 값이 음수라면 0을 반환하세요.
인덱스 세 쌍 (i, j, k)의 값은 (nums[i] - nums[j]) * nums[k]로 계산됩니다.


Constraints:
3 <= nums.length <= 100
1 <= nums[i] <= 10**6
 */

// @lc code=start
class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        // 음수 * 음수
        // 양수 * 양수

        int n = nums.size();
        int first = n - 2;
        int second = n - 1;
        long long max_value = 0;
        long long minus;
        long long value;

        for (int i = 0; i < first; i++) {
            for (int j = i + 1; j < second; j++) {
                minus = nums[i] - nums[j];
                for (int k = j + 1; k < n; k++) {
                    value = minus * nums[k];
                    max_value = max(max_value, value);
                }
            }
        }

        return max_value;
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
    // Input: nums = [12,6,1,2,7]
    // Output: 77
    // Explanation: The value of the triplet (0, 2, 4) is (nums[0] - nums[2]) * nums[4] = 77.
    // It can be shown that there are no ordered triplets of indices with a value greater than 77.

    vector<int> nums = {12,6,1,2,7};
    EXPECT_EQ(this->s.maximumTripletValue(nums), 77);
}

TEST_F(CLASS_NAME, __LINE__)
{
    // Example 2:
    // Input: nums = [1,10,3,4,19]
    // Output: 133
    // Explanation: The value of the triplet (1, 2, 4) is (nums[1] - nums[2]) * nums[4] = 133.
    // It can be shown that there are no ordered triplets of indices with a value greater than 133.

    vector<int> nums = {1,10,3,4,19};
    EXPECT_EQ(this->s.maximumTripletValue(nums), 133);
}

TEST_F(CLASS_NAME, __LINE__)
{
    // Example 3:
    // Input: nums = [1,2,3]
    // Output: 0
    // Explanation: The only ordered triplet of indices (0, 1, 2) has a negative value of (nums[0] - nums[1]) * nums[2] = -3. Hence, the answer would be 0.

    vector<int> nums = {1,2,3};
    EXPECT_EQ(this->s.maximumTripletValue(nums), 0);
}



int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
