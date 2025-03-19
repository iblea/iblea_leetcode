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



/* https://leetcode.com/problems/longest-nice-subarray/?envType=daily-question&envId=2025-03-18
 * @lc app=leetcode id=2401 lang=cpp
 * [2401] Longest Nice Subarray

You are given an array nums consisting of positive integers.
We call a subarray of nums nice if the bitwise AND of every pair of elements that are in different positions in the subarray is equal to 0.
Return the length of the longest nice subarray.
A subarray is a contiguous part of an array.
Note that subarrays of length 1 are always considered nice.

양의 정수로 구성된 배열 nums가 주어집니다.
서로 다른 위치에 있는 모든 요소 쌍의 비트 AND 연산 결과가 0인 경우, nums의 부분 배열을 "nice"하다고 부릅니다.
가장 긴 nice 부분 배열의 길이를 반환하세요.
부분 배열은 배열의 연속적인 부분입니다.
길이가 1인 부분 배열은 항상 nice하다고 간주됩니다.

Constraints:
1 <= nums.length <= 10**5
1 <= nums[i] <= 10**9
 */

// @lc code=start
class Solution {
public:
    int longestNiceSubarray(vector<int>& nums) {

        int n = nums.size();
        int max_length = 1;

        int left = 0;
        int right = 0;
        int used = 0;

        for (right = 0; right < n; right++) {

            while ((used & nums[right]) != 0) {
                used ^= nums[left];
                left++;
            }

            used |= nums[right];
            max_length = max(max_length, right - left + 1);
        }

        return max_length;
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
    // Input: nums = [1,3,8,48,10]
    // Output: 3
    // Explanation: The longest nice subarray is [3,8,48]. This subarray satisfies the conditions:
    // - 3 AND 8 = 0.
    // - 3 AND 48 = 0.
    // - 8 AND 48 = 0.
    // It can be proven that no longer nice subarray can be obtained, so we return 3.


    vector<int> nums1 = {1,3,8,48,10};
	EXPECT_EQ(this->s.longestNiceSubarray(nums1), 3);
}

TEST_F(CLASS_NAME, __LINE__)
{
    // Example 2:
    // Input: nums = [3,1,5,11,13]
    // Output: 1
    // Explanation: The length of the longest nice subarray is 1. Any subarray of length 1 can be chosen.

    vector<int> nums2 = {3,1,5,11,13};
	EXPECT_EQ(this->s.longestNiceSubarray(nums2), 1);
}


int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
