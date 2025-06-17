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



/* https://leetcode.com/problems/maximum-difference-between-increasing-elements
 * @lc app=leetcode id=2016 lang=cpp
 * [2016] Maximum Difference Between Increasing Elements

Given a 0-indexed integer array nums of size n, find the maximum difference between nums[i] and nums[j] (i.e., nums[j] - nums[i]), such that 0 <= i < j < n and nums[i] < nums[j].
Return the maximum difference. If no such i and j exists, return -1.

크기가 n인 0-인덱스 정수 배열 nums가 주어졌을 때, nums[i]와 nums[j] 사이의 최대 차이(즉, nums[j] - nums[i])를 찾아라. 단, 0 <= i < j < n이고 nums[i] < nums[j]를 만족해야 한다.
최대 차이를 반환하라. 그러한 i와 j가 존재하지 않으면 -1을 반환하라.

Constraints:
n == nums.length
2 <= n <= 1000
1 <= nums[i] <= 10**9
 */

// @lc code=start
class Solution {
public:
    int maximumDifference(vector<int>& nums) {
        int n = nums.size();
        int result = 0;
        int min_val = INT_MAX, max_val = 0;
        int min_idx = -1, max_idx = -1;

        for (int i = 0; i < n; i++) {
            if (nums[i] < min_val) {
                min_val = nums[i];
                min_idx = i;
                if (max_idx < min_idx) {
                    max_val = 0;
                    max_idx = -1;
                }
            }

            if (nums[i] > max_val) {
                max_val = nums[i];
                max_idx = i;
            }
            result = max(result, max_val - min_val);
        }
        return result == 0 ? -1 : result;
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
    // Input: nums = [7,1,5,4]
    // Output: 4
    // Explanation:
    // The maximum difference occurs with i = 1 and j = 2, nums[j] - nums[i] = 5 - 1 = 4.
    // Note that with i = 1 and j = 0, the difference nums[j] - nums[i] = 7 - 1 = 6, but i > j, so it is not valid.

    vector<int> nums = {7,1,5,4};
    EXPECT_EQ(this->s.maximumDifference(nums), 4);
}

TEST_F(CLASS_NAME, __LINE__)
{
    // Example 2:
    // Input: nums = [9,4,3,2]
    // Output: -1
    // Explanation:
    // There is no i and j such that i < j and nums[i] < nums[j].

    vector<int> nums = {9,4,3,2};
    EXPECT_EQ(this->s.maximumDifference(nums), -1);
}

TEST_F(CLASS_NAME, __LINE__)
{
    // Example 3:
    // Input: nums = [1,5,2,10]
    // Output: 9
    // Explanation:
    // The maximum difference occurs with i = 0 and j = 3, nums[j] - nums[i] = 10 - 1 = 9.

    vector<int> nums = {1,5,2,10};
    EXPECT_EQ(this->s.maximumDifference(nums), 9);
}

TEST_F(CLASS_NAME, __LINE__)
{
    vector<int> nums = {3,7,1,6};
    EXPECT_EQ(this->s.maximumDifference(nums), 5);
}

TEST_F(CLASS_NAME, __LINE__)
{
    vector<int> nums = {3,7,1,9};
    EXPECT_EQ(this->s.maximumDifference(nums), 8);
}



int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
