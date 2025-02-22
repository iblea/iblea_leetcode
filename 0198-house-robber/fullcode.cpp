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



/* https://leetcode.com/problems/house-robber/
 * @lc app=leetcode id=198 lang=cpp
 * [198] House Robber

You are a professional robber planning to rob houses along a street. Each house has a certain amount of money stashed, the only constraint stopping you from robbing each of them is that adjacent houses have security systems connected and it will automatically contact the police if two adjacent houses were broken into on the same night.
Given an integer array nums representing the amount of money of each house, return the maximum amount of money you can rob tonight without alerting the police.

당신은 거리에 있는 집들을 털려고 계획하는 전문 도둑입니다. 각 집에는 일정 금액의 돈이 숨겨져 있습니다. 인접한 집들은 보안 시스템이 연결되어 있어서 같은 날 밤에 인접한 두 집을 털면 자동으로 경찰에 연락이 가게 되는 것이 유일한 제약 조건입니다.
각 집의 돈의 양을 나타내는 정수 배열 nums가 주어질 때, 경찰에 연락가지 않고 오늘 밤 털 수 있는 최대 금액을 반환하세요.

Constraints:
1 <= nums.length <= 100
0 <= nums[i] <= 400

 */

// @lc code=start
class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) return nums[0];
        if (n == 2) return max(nums[0], nums[1]);

        vector<int> dp(n, 0);
        dp[0] = nums[0];
        dp[1] = max(nums[0], nums[1]);

        for (int i = 2; i < n; i++) {
            dp[i] = max(dp[i-2] + nums[i], dp[i-1]);
        }
        return dp[n-1];
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
    // Input: nums = [1,2,3,1]
    // Output: 4
    // Explanation: Rob house 1 (money = 1) and then rob house 3 (money = 3).
    // Total amount you can rob = 1 + 3 = 4.

    vector<int> nums = {1,2,3,1};
	EXPECT_EQ(this->s.rob(nums), 4);
}

TEST_F(CLASS_NAME, __LINE__)
{
    // Example 2:
    // Input: nums = [2,7,9,3,1]
    // Output: 12
    // Explanation: Rob house 1 (money = 2), rob house 3 (money = 9) and rob house 5 (money = 1).
    // Total amount you can rob = 2 + 9 + 1 = 12.

    vector<int> nums = {2,7,9,3,1};
	EXPECT_EQ(this->s.rob(nums), 12);
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
