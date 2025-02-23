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


/* https://leetcode.com/problems/largest-divisible-subset/
 * @lc app=leetcode id=368 lang=cpp
 * [368] Largest Divisible Subset

Given a set of distinct positive integers nums, return the largest subset answer such that every pair (answer[i], answer[j]) of elements in this subset satisfies:
answer[i] % answer[j] == 0, or
answer[j] % answer[i] == 0
If there are multiple solutions, return any of them.

서로 다른 양의 정수들의 집합 nums가 주어졌을 때, 다음 조건을 만족하는 가장 큰 부분집합 answer를 반환하세요:
부분집합의 모든 쌍 (answer[i], answer[j])에 대해
answer[i] % answer[j] == 0 이거나
answer[j] % answer[i] == 0 입니다.
여러 해답이 있다면 그 중 아무거나 반환하세요.

Constraints:
1 <= nums.length <= 1000
1 <= nums[i] <= 2 * 10**9
All the integers in nums are unique.
 */

// @lc code=start
class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, 1);
        vector<int> prev(n, -1);
        vector<int> result;

        int max_len = 0;
        int max_index = 0;
        sort(nums.begin(), nums.end());

        for (int i = 1; i < n; i++) {
            for (int j = 0; j < i; j++) {
                if (nums[i] % nums[j] == 0 && dp[i] < dp[j] + 1) {
                    dp[i] = dp[j] + 1;
                    prev[i] = j;
                }
            }
            if (max_len < dp[i]) {
                max_len = dp[i];
                max_index = i;
            }
        }

        while (max_index != -1) {
            result.push_back(nums[max_index]);
            max_index = prev[max_index];
        }
        reverse(result.begin(), result.end());
        return result;
    };
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
    // Input: nums = [1,2,3]
    // Output: [1,2]
    // Explanation: [1,3] is also accepted.

    vector<int> nums = {1,2,3};
    vector<vector<int>> answer = {{1,2}, {1,3}};
    vector<int> result = this->s.largestDivisibleSubset(nums);
    for (auto &a : result) {
        cout << a << " ";
    }
    cout << endl;
    bool is_answer = false;
    for (auto a : answer) {
        if (a == result) {
            is_answer = true;
            break;
        }
    }
    EXPECT_TRUE(is_answer);
}

TEST_F(CLASS_NAME, __LINE__)
{
    // Example 2:
    // Input: nums = [1,2,4,8]
    // Output: [1,2,4,8]

    vector<int> nums = {1,2,4,8};
    vector<int> answer = {1,2,4,8};
    EXPECT_EQ(this->s.largestDivisibleSubset(nums), answer);
}

TEST_F(CLASS_NAME, __LINE__)
{
    vector<int> nums = {1,2,3,6};
    vector<vector<int>> answer = {{1,2,6}, {1,3,6}};
    vector<int> result = this->s.largestDivisibleSubset(nums);
    for (auto a : result) {
        cout << a << " ";
    }
    cout << endl;
    bool is_answer = false;
    for (auto a : answer) {
        if (a == result) {
            is_answer = true;
            break;
        }
    }
    EXPECT_TRUE(is_answer);
}


int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
