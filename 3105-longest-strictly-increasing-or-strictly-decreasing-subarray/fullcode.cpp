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



/* https://leetcode.com/problems/longest-strictly-increasing-or-strictly-decreasing-subarray/?envType=daily-question&envId=2025-02-03
 * @lc app=leetcode id=3105 lang=cpp
 * [3105] Longest Strictly Increasing or Strictly Decreasing Subarray

You are given an array of integers nums. Return the length of the longest subarray of nums which is either strictly increasing or strictly decreasing.

정수 배열 nums가 주어집니다. 순증가하거나 순감소하는 nums의 가장 긴 부분 배열의 길이를 반환하세요.
이때, 순증가 또는 순감소수열은, 단조증가 또는 감소하면서 같은 값에 두 번 이상 머무르지 않는 수열이다

Constraints:
1 <= nums.length <= 50
1 <= nums[i] <= 50
 */

// @lc code=start
#define SAME 0
#define INCREASE 1
#define DECREASE 2
typedef unsigned char uchar;

class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int nlen = nums.size() - 1;
        if (nlen == 0) {
            return 1;
        }
        int result = 1;
        int cnt = 0;
        uchar stat = SAME;

        for (int i = 0; i < nlen; i++) {
            if (nums[i] < nums[i+1]) {
                if (stat == INCREASE) {
                    cnt++;
                    continue;
                }
                result = max(result, cnt);
                cnt = 2;
                stat = INCREASE;
            } else if (nums[i] > nums[i+1]) {
                if (stat == DECREASE) {
                    cnt++;
                    continue;
                }
                result = max(result, cnt);
                cnt = 2;
                stat = DECREASE;
            } else {
                result = max(result, cnt);
                stat = SAME;
                cnt = 1;
            }
        }
        result = max(result, cnt);
        return result;
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
    // Input: nums = [1,4,3,3,2]
    // Output: 2
    // Explanation:
    // The strictly increasing subarrays of nums are [1], [2], [3], [3], [4], and [1,4].
    // The strictly decreasing subarrays of nums are [1], [2], [3], [3], [4], [3,2], and [4,3].
    // Hence, we return 2.
    vector<int> nums1 = {1,4,3,3,2};
	EXPECT_EQ(this->s.longestMonotonicSubarray(nums1), 2);
}

TEST_F(CLASS_NAME, __LINE__)
{
    // Example 2:
    // Input: nums = [3,3,3,3]
    // Output: 1
    // Explanation:
    // The strictly increasing subarrays of nums are [3], [3], [3], and [3].
    // The strictly decreasing subarrays of nums are [3], [3], [3], and [3].
    // Hence, we return 1.
    vector<int> nums2 = {3,3,3,3};
	EXPECT_EQ(this->s.longestMonotonicSubarray(nums2), 1);
}

TEST_F(CLASS_NAME, __LINE__)
{
    // Example 3:
    // Input: nums = [3,2,1]
    // Output: 3
    // Explanation:
    // The strictly increasing subarrays of nums are [3], [2], and [1].
    // The strictly decreasing subarrays of nums are [3], [2], [1], [3,2], [2,1], and [3,2,1].
    // Hence, we return 3.
    vector<int> nums3 = {3,2,1};
	EXPECT_EQ(this->s.longestMonotonicSubarray(nums3), 3);
}

TEST_F(CLASS_NAME, __LINE__)
{
    vector<int> nums = {3,3,4,5,3,3,3};
	EXPECT_EQ(this->s.longestMonotonicSubarray(nums), 3);
}

TEST_F(CLASS_NAME, __LINE__)
{
    vector<int> nums = {3,3,3,4,5};
	EXPECT_EQ(this->s.longestMonotonicSubarray(nums), 3);
}

TEST_F(CLASS_NAME, __LINE__)
{
    vector<int> nums = {1,10,10};
	EXPECT_EQ(this->s.longestMonotonicSubarray(nums), 2);
}


TEST_F(CLASS_NAME, __LINE__)
{
    vector<int> nums = {3,4,5,5,5};
	EXPECT_EQ(this->s.longestMonotonicSubarray(nums), 3);
}




int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}