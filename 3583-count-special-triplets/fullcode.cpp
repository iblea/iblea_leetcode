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



/* https://leetcode.com/problems/count-special-triplets
 * @lc app=leetcode id=3583 lang=cpp
 * [3583] Count Special Triplets

You are given an integer array nums.

A special triplet is defined as a triplet of indices (i, j, k) such that:

0 <= i < j < k < n, where n = nums.length
nums[i] == nums[j] * 2
nums[k] == nums[j] * 2
Return the total number of special triplets in the array.

Since the answer may be large, return it modulo (10**9) + 7.

정수 배열 nums가 주어집니다.

특별한 삼중항은 다음 조건을 만족하는 인덱스 (i, j, k)의 삼중항으로 정의됩니다:

0 <= i < j < k < n, 여기서 n = nums.length
nums[i] == nums[j] * 2
nums[k] == nums[j] * 2
배열에서 특별한 삼중항의 총 개수를 반환하세요.

답이 클 수 있으므로 (10**9) + 7로 나눈 나머지를 반환하세요.

Constraints:
3 <= n == nums.length <= (10**5)
0 <= nums[i] <= (10**5)

 */
// @lc code=start
class Solution {
public:
    int specialTriplets_o_square_2(vector<int>& nums) {

        int for_check = nums.size() - 1;
        int result = 0;

        for (int i = 1; i < for_check; i++) {
            int find_val = nums[i] * 2;
            int left_count = 0;
            int right_count = 0;
            for (int left = 0; left < i; left++) {
                if (nums[left] == find_val) {
                    left_count++;
                }
            }
            for (int right = i + 1; right <= for_check; right++) {
                if (nums[right] == find_val) {
                    right_count++;
                }
            }
            long long count = (long long)left_count * (long long)right_count;
            result = (result + (int)(count % 1000000007)) % 1000000007;
        }
        return result;
    }

    int specialTriplets(vector<int>& nums) {
        const int MOD = 1e9 + 7;

        unordered_map<int, int> left_count, right_count;
        for (int num : nums) {
            right_count[num]++;
        }

        long long result = 0;
        for (int i = 0; i < nums.size(); i++) {
            int val = nums[i];
            int target = val * 2;
            right_count[val]--;
            long long count = (long long)left_count[target] * (long long)right_count[target];
            result = (result + count) % MOD;
            left_count[val]++;
        }

        return (int)(result);
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
    // Input: nums = [6,3,6]
    // Output: 1
    // Explanation:
    // The only special triplet is (i, j, k) = (0, 1, 2), where:
    // nums[0] = 6, nums[1] = 3, nums[2] = 6
    // nums[0] = nums[1] * 2 = 3 * 2 = 6
    // nums[2] = nums[1] * 2 = 3 * 2 = 6

    vector<int> nums = {6,3,6};
    EXPECT_EQ(this->s.specialTriplets(nums), 1);
}

TEST_F(CLASS_NAME, __LINE__)
{
    // Example 2:
    // Input: nums = [0,1,0,0]
    // Output: 1
    // Explanation:
    // The only special triplet is (i, j, k) = (0, 2, 3), where:
    // nums[0] = 0, nums[2] = 0, nums[3] = 0
    // nums[0] = nums[2] * 2 = 0 * 2 = 0
    // nums[3] = nums[2] * 2 = 0 * 2 = 0

    vector<int> nums = {0,1,0,0};
    EXPECT_EQ(this->s.specialTriplets(nums), 1);
}

TEST_F(CLASS_NAME, __LINE__)
{
    // Example 3:
    // Input: nums = [8,4,2,8,4]
    // Output: 2
    // Explanation:
    // There are exactly two special triplets:
    // (i, j, k) = (0, 1, 3)
    // nums[0] = 8, nums[1] = 4, nums[3] = 8
    // nums[0] = nums[1] * 2 = 4 * 2 = 8
    // nums[3] = nums[1] * 2 = 4 * 2 = 8
    // (i, j, k) = (1, 2, 4)
    // nums[1] = 4, nums[2] = 2, nums[4] = 4
    // nums[1] = nums[2] * 2 = 2 * 2 = 4
    // nums[4] = nums[2] * 2 = 2 * 2 = 4

    vector<int> nums = {8,4,2,8,4};
    EXPECT_EQ(this->s.specialTriplets(nums), 2);
}


int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
