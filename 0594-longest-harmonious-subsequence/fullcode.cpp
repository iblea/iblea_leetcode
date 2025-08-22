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



/* https://leetcode.com/problems/longest-harmonious-subsequence
 * @lc app=leetcode id=594 lang=cpp
 * [594] Longest Harmonious Subsequence

We define a harmonious array as an array where the difference between its maximum value and its minimum value is exactly 1.
Given an integer array nums, return the length of its longest harmonious subsequence among all its possible subsequences.

조화로운 배열(harmonious array)을 최댓값과 최솟값의 차이가 정확히 1인 배열로 정의합니다.
정수 배열 nums가 주어졌을 때, 가능한 모든 부분 수열 중에서 가장 긴 조화로운 부분 수열의 길이를 반환하세요.

Constraints:
1 <= nums.length <= 2 * (10**4)
((-10)**9) <= nums[i] <= (10**9)
 */

// @lc code=start
class Solution {
public:
    int findLHS(vector<int>& nums) {
        int max_length = 0;
        map<int, int> num_map;

        for (int num : nums) {
            num_map[num]++;
        }

        int cur_num;
        for (auto it = num_map.begin(); it != num_map.end(); it++) {
            cur_num = it->first;
            if (num_map.find(cur_num + 1) != num_map.end()) {
                max_length = max(max_length, it->second + num_map[cur_num + 1]);
            }
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
    // Input: nums = [1,3,2,2,5,2,3,7]
    // Output: 5
    // Explanation:
    // The longest harmonious subsequence is [3,2,2,2,3].
    vector<int> nums = {1,3,2,2,5,2,3,7};
    EXPECT_EQ(this->s.findLHS(nums), 5);
}

TEST_F(CLASS_NAME, __LINE__)
{
    // Example 2:
    // Input: nums = [1,2,3,4]
    // Output: 2
    // Explanation:
    // The longest harmonious subsequences are [1,2], [2,3], and [3,4], all of which have a length of 2.

    vector<int> nums = {1,2,3,4};
    EXPECT_EQ(this->s.findLHS(nums), 2);
}

TEST_F(CLASS_NAME, __LINE__)
{
    // Example 3:
    // Input: nums = [1,1,1,1]
    // Output: 0
    // Explanation:
    // No harmonic subsequence exists.

    vector<int> nums = {1,1,1,1};
    EXPECT_EQ(this->s.findLHS(nums), 0);
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
