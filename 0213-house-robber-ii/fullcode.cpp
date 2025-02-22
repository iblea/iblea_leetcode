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



/* https://leetcode.com/problems/house-robber-ii/
 * @lc app=leetcode id=213 lang=cpp
 * [213] House Robber II

You are a professional robber planning to rob houses along a street. Each house has a certain amount of money stashed. All houses at this place are arranged in a circle. That means the first house is the neighbor of the last one. Meanwhile, adjacent houses have a security system connected, and it will automatically contact the police if two adjacent houses were broken into on the same night.
Given an integer array nums representing the amount of money of each house, return the maximum amount of money you can rob tonight without alerting the police.

당신은 거리에 있는 집들을 털려고 계획하는 전문 도둑입니다. 각 집에는 일정 금액의 돈이 보관되어 있습니다. 이 장소의 모든 집들은 원형으로 배치되어 있어서 첫 번째 집이 마지막 집과 이웃해 있습니다. 한편, 인접한 집들은 보안 시스템이 연결되어 있어서 같은 날 밤에 인접한 두 집이 침입을 당하면 자동으로 경찰에 연락이 갑니다.
각 집의 돈의 양을 나타내는 정수 배열 nums가 주어질 때, 경찰에 연락가지 않고 오늘 밤 훔칠 수 있는 최대 금액을 반환하세요.

Constraints:
1 <= nums.length <= 100
0 <= nums[i] <= 1000
 */


// @lc code=start
class Solution {
private:
    int dp(vector<int>& nums, int start, int end) {
        int n = end - start;

        vector<int> tmp(n, 0);
        tmp[0] = nums[start];
        tmp[1] = max(nums[start], nums[start + 1]);

        for (int i = 2; i < n; i++) {
            tmp[i] = max(tmp[i-1], tmp[i-2] + nums[i + start]);
        }
        return tmp[n-1];
    }
public:
    int rob(vector<int>& nums) {
        if (nums.size() == 1) return nums[0];
        if (nums.size() == 2) return max(nums[0], nums[1]);

        int n = nums.size();

        // 첫 번째 집을 털 경우, 마지막 집을 털 수 없고, 마지막 집을 털 경우, 첫 번째 집을 털 수 없는 점을 이용하여 두 가지 경우로 나누어 계산
        // 첫 번째 집부터 마지막 - 1 번째 집까지
        int result1 = dp(nums, 0, n - 1);
        // 두 번째 집부터 마지막 집까지
        int result2 = dp(nums, 1, n);

        return max(result1, result2);
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
    // Input: nums = [2,3,2]
    // Output: 3
    // Explanation: You cannot rob house 1 (money = 2) and then rob house 3 (money = 2), because they are adjacent houses.

    vector<int> nums = {2,3,2};
	EXPECT_EQ(this->s.rob(nums), 3);
}

TEST_F(CLASS_NAME, __LINE__)
{
    // Example 2:
    // Input: nums = [1,2,3,1]
    // Output: 4
    // Explanation: Rob house 1 (money = 1) and then rob house 3 (money = 3).
    // Total amount you can rob = 1 + 3 = 4.

    vector<int> nums = {1,2,3,1};
	EXPECT_EQ(this->s.rob(nums), 4);
}

TEST_F(CLASS_NAME, __LINE__)
{
    // Example 3:
    // Input: nums = [1,2,3]
    // Output: 3

    vector<int> nums = {1,2,3};
	EXPECT_EQ(this->s.rob(nums), 3);
}



int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
