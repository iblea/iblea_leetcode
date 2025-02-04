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



/* https://leetcode.com/problems/maximum-ascending-subarray-sum/?envType=daily-question&envId=2025-02-04
 * @lc app=leetcode id=1800 lang=cpp
 * [1800] Maximum Ascending Subarray Sum

Given an array of positive integers nums, return the maximum possible sum of an ascending subarray in nums.
A subarray is defined as a contiguous sequence of numbers in an array.
A subarray [numsl, numsl+1, ..., numsr-1, numsr] is ascending if for all i where l <= i < r, numsi  < numsi+1. Note that a subarray of size 1 is ascending.

양의 정수 배열 nums가 주어졌을 때, nums에서 오름차순 부분 배열의 최대 가능한 합을 반환하세요.
부분 배열은 배열에서 연속된 숫자들의 시퀀스로 정의됩니다.
부분 배열 [numsl, numsl+1, ..., numsr-1, numsr]은 l <= i < r인 모든 i에 대해 numsi < numsi+1일 때 오름차순입니다. 크기가 1인 부분 배열도 오름차순으로 간주됩니다.

Constraints:
1 <= nums.length <= 100
1 <= nums[i] <= 100
 */

// @lc code=start
class Solution {
public:
    int maxAscendingSum(vector<int>& nums) {
        int max_sum = 0;
        int sum = nums[0];

        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] > nums[i - 1]) {
                sum += nums[i];
            } else {
                max_sum = max(max_sum, sum);
                sum = nums[i];
            }
        }
        max_sum = max(max_sum, sum);
        return max_sum;
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
    // Input: nums = [10,20,30,5,10,50]
    // Output: 65
    // Explanation: [5,10,50] is the ascending subarray with the maximum sum of 65.

    vector<int> nums = {10,20,30,5,10,50};
	EXPECT_EQ(this->s.maxAscendingSum(nums), 65);
}
TEST_F(CLASS_NAME, __LINE__)
{
    // Example 2:
    // Input: nums = [10,20,30,40,50]
    // Output: 150
    // Explanation: [10,20,30,40,50] is the ascending subarray with the maximum sum of 150.

    vector<int> nums = {10,20,30,40,50};
    EXPECT_EQ(this->s.maxAscendingSum(nums), 150);
}

TEST_F(CLASS_NAME, __LINE__)
{
    // Example 3:
    // Input: nums = [12,17,15,13,10,11,12]
    // Output: 33
    // Explanation: [10,11,12] is the ascending subarray with the maximum sum of 33.

    vector<int> nums = {12,17,15,13,10,11,12};
    EXPECT_EQ(this->s.maxAscendingSum(nums), 33);
}

TEST_F(CLASS_NAME, __LINE__)
{
    vector<int> nums = {3,6,10,1,8,9,9,8,9};
    EXPECT_EQ(this->s.maxAscendingSum(nums), 19);
}



int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}