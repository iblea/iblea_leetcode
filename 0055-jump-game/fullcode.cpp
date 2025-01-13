#include <gtest/gtest.h>
#include <iostream>
#include <iomanip>
#include <algorithm>
#include <vector>
#include <string>
#include <map>

using namespace std;



/*
https://leetcode.com/problems/jump-game/description/
 * @lc app=leetcode id=55 lang=cpp
 * [55] Jump Game

You are given an integer array nums. You are initially positioned at the array's first index, and each element in the array represents your maximum jump length at that position.
Return true if you can reach the last index, or false otherwise.

정수 배열 nums가 주어집니다. 처음에는 배열의 첫 번째 인덱스에 위치하며, 배열의 각 요소는 해당 위치에서 최대 점프 길이를 나타냅니다.
마지막 인덱스에 도달할 수 있으면 true를 반환하고, 그렇지 않으면 false를 반환합니다.

Example 1:
Input: nums = [2,3,1,1,4]
Output: true
Explanation: Jump 1 step from index 0 to 1, then 3 steps to the last index.

Example 2:
Input: nums = [3,2,1,0,4]
Output: false
Explanation: You will always arrive at index 3 no matter what. Its maximum jump length is 0, which makes it impossible to reach the last index.

Constraints:
- 1 <= nums.length <= 10**4
- 0 <= nums[i] <= 10**5
 */

// @lc code=start
class Solution {
public:
    bool canJump(vector<int>& nums) {
        if (nums.size() == 1) return true;
        if (nums[0] == 0) return false;
        if (nums.size() == 2) return true;
        int jump_max = nums.size() - 1;
        vector<bool> dp(jump_max, false);

        for (int i = jump_max - 1; i >= 0; i--) {
            for (int j = 1; j <= nums[i]; j++) {
                if (i + j >= jump_max) {
                    dp[i] = true;
                    break;
                }
                if (dp[i + j]) {
                    dp[i] = true;
                    break;
                }
            }
        }
        return dp[0];
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
    vector<int> nums = {2,3,1,1,4};
	EXPECT_EQ(this->s.canJump(nums), true);
}

TEST_F(CLASS_NAME, __LINE__)
{
    vector<int> nums = {3,2,1,0,4};
	EXPECT_EQ(this->s.canJump(nums), false);
}

TEST_F(CLASS_NAME, __LINE__)
{
    vector<int> nums = {0};
	EXPECT_EQ(this->s.canJump(nums), true);
}

TEST_F(CLASS_NAME, __LINE__)
{
    vector<int> nums = {0, 1};
	EXPECT_EQ(this->s.canJump(nums), false);
}

TEST_F(CLASS_NAME, __LINE__)
{
    vector<int> nums = {1, 0};
	EXPECT_EQ(this->s.canJump(nums), true);
}


int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}