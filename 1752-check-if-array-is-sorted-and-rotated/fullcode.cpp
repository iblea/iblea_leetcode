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



/* https://leetcode.com/problems/check-if-array-is-sorted-and-rotated/description/?envType=daily-question&envId=2025-02-02
 * @lc app=leetcode id=1752 lang=cpp
 * [1752] Check if Array Is Sorted and Rotated

Given an array nums, return true if the array was originally sorted in non-decreasing order, then rotated some number of positions (including zero). Otherwise, return false.
There may be duplicates in the original array.
Note: An array A rotated by x positions results in an array B of the same length such that A[i] == B[(i+x) % A.length], where % is the modulo operation.

배열 nums가 주어졌을 때, 이 배열이 원래 비감소 순서로 정렬되어 있었고 이후 특정 위치만큼(0 포함) 회전된 것이라면 true를 반환하고, 그렇지 않다면 false를 반환합니다.
원래 배열에는 중복된 값이 있을 수 있습니다.
참고: 배열 A를 x 위치만큼 회전하면 동일한 길이의 배열 B가 생성되며, A[i] == B[(i+x) % A.length]를 만족합니다. 여기서 %는 모듈로 연산입니다.

Constraints:
1 <= nums.length <= 100
1 <= nums[i] <= 100
 */

// @lc code=start
class Solution {
public:
    bool check(vector<int>& nums) {

        int max_num = 0;
        int n = nums.size();
        for (int i = 1; i < n; i++) {
            if (max_num > 0 && nums[i] > max_num) {
                return false;
            }
            if (nums[i] >= nums[i-1]) {
                continue;
            }

            if (max_num <= 0) {
                max_num = nums[i-1];
                continue;
            }
            return false;
        }
        if (max_num <= 0) {
            if (nums[n-1] < nums[0]) {
                return false;
            }
        } else {
            if (nums[n-1] > nums[0]) {
                return false;
            }
        }
        return true;
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
    vector<int> nums = {3,4,5,1,2};
    EXPECT_EQ(this->s.check(nums), true);
}
TEST_F(CLASS_NAME, __LINE__)
{
    vector<int> nums = {2,1,3,4};
    EXPECT_EQ(this->s.check(nums), false);
}
TEST_F(CLASS_NAME, __LINE__)
{
    vector<int> nums = {1,2,3};
    EXPECT_EQ(this->s.check(nums), true);
}
TEST_F(CLASS_NAME, __LINE__)
{
    vector<int> nums = {2,4,1,3};
    EXPECT_EQ(this->s.check(nums), false);
}
TEST_F(CLASS_NAME, __LINE__)
{
    vector<int> nums = {10,1,4,5,10};
    EXPECT_EQ(this->s.check(nums), true);
}





int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}