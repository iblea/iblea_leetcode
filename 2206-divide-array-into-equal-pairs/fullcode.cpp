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



/* https://leetcode.com/problems/divide-array-into-equal-pairs/?envType=daily-question&envId=2025-03-17
 * @lc app=leetcode id=2206 lang=cpp
 * [2206] Divide Array Into Equal Pairs

You are given an integer array nums consisting of 2 * n integers.
You need to divide nums into n pairs such that:
- Each element belongs to exactly one pair.
- The elements present in a pair are equal.
Return true if nums can be divided into n pairs, otherwise return false.

2 * n개의 정수로 구성된 정수 배열 nums가 주어집니다.
다음 조건을 만족하도록 nums를 n개의 쌍으로 나누어야 합니다:
- 각 요소는 정확히 하나의 쌍에 속합니다.
- 쌍에 있는 요소들은 서로 같아야 합니다.
nums를 n개의 쌍으로 나눌 수 있으면 true를, 그렇지 않으면 false를 반환합니다.

Constraints:
nums.length == 2 * n
1 <= n <= 500
1 <= nums[i] <= 500
 */

// @lc code=start
#define MAX_NUM 501
class Solution {
public:
    bool divideArray(vector<int>& nums) {
        int arr[MAX_NUM] = {0};
        int count = 0;
        int n = nums.size();

        for (int i = 0; i < n; i++) {
            if (arr[nums[i]] == 0) {
                arr[nums[i]]++;
                count++;
            } else {
                arr[nums[i]]--;
                count--;
            }

        }
        return count == 0;
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
    // Input: nums = [3,2,3,2,2,2]
    // Output: true
    // Explanation:
    // There are 6 elements in nums, so they should be divided into 6 / 2 = 3 pairs.
    // If nums is divided into the pairs (2, 2), (3, 3), and (2, 2), it will satisfy all the conditions.

    vector<int> nums = {3,2,3,2,2,2};
    EXPECT_EQ(this->s.divideArray(nums), true);
}

TEST_F(CLASS_NAME, __LINE__)
{
    // Example 2:
    // Input: nums = [1,2,3,4]
    // Output: false
    // Explanation:
    // There is no way to divide nums into 4 / 2 = 2 pairs such that the pairs satisfy every condition.

    vector<int> nums = {1,2,3,4};
    EXPECT_EQ(this->s.divideArray(nums), false);
}



int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
