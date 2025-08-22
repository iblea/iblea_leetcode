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



/* https://leetcode.com/problems/number-of-subsequences-that-satisfy-the-given-sum-condition
 * @lc app=leetcode id=1498 lang=cpp
 * [1498] Number of Subsequences That Satisfy the Given Sum Condition

You are given an array of integers nums and an integer target.
Return the number of non-empty subsequences of nums such that the sum of the minimum and maximum element on it is less or equal to target. Since the answer may be too large, return it modulo (10**9) + 7.

정수 배열 nums와 정수 target이 주어진다.
nums의 비어있지 않은 부분수열 중에서 최솟값과 최댓값의 합이 target보다 작거나 같은 부분수열의 개수를 반환해라. 답이 너무 클 수 있으므로 (10**9) + 7로 나눈 나머지를 반환해라.

python3 -c "print(format((10**9)+7,','))"
Constraints: format(10**5,',')
1 <= nums.length <= 10**5 (100,000)
1 <= nums[i] <= 10**6 (1,000,000)
1 <= target <= 10**6 (1,000,000)
 */

// @lc code=start
class Solution {
private:
    static const int MOD = 1000000007;
public:
    int numSubseq(vector<int>& nums, int target) {
        const int n = nums.size();
        const int last_idx = n - 1;
        sort(nums.begin(), nums.end());

        int left = 0, right = last_idx, result = 0;
        vector<long long> pow_array(n);
        pow_array[0] = 1;
        for (int i = 1; i < n; i++) {
            pow_array[i] = (pow_array[i - 1] * 2) % MOD;
        }
        while (left <= right) {
            if (nums[left] + nums[right] <= target) {
                result = (result + pow_array[right - left]) % MOD;
                left++;
            } else {
                right--;
            }
        }

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
    // Input: nums = [3,5,6,7], target = 9
    // Output: 4
    // Explanation: There are 4 subsequences that satisfy the condition.
    // [3] -> Min value + max value <= target (3 + 3 <= 9)
    // [3,5] -> (3 + 5 <= 9)
    // [3,5,6] -> (3 + 6 <= 9)
    // [3,6] -> (3 + 6 <= 9)

    vector<int> nums = {3,5,6,7};
    int target = 9;
    EXPECT_EQ(this->s.numSubseq(nums, target), 4);
}

TEST_F(CLASS_NAME, __LINE__)
{
    // Example 2:
    // Input: nums = [3,3,6,8], target = 10
    // Output: 6
    // Explanation: There are 6 subsequences that satisfy the condition. (nums can have repeated numbers).
    // 설명: 조건을 만족하는 6개의 부분 수열이 있습니다. (nums는 중복된 숫자를 가질 수 있습니다).
    // [3] , [3] , [3,3], [3,6] , [3,6] , [3,3,6]

    vector<int> nums = {3,3,6,8};
    int target = 10;
    EXPECT_EQ(this->s.numSubseq(nums, target), 6);
}

TEST_F(CLASS_NAME, __LINE__)
{
    // Example 3:
    // Input: nums = [2,3,3,4,6,7], target = 12
    // Output: 61
    // Explanation: There are 63 non-empty subsequences, two of them do not satisfy the condition ([6,7], [7]).
    // Number of valid subsequences (63 - 2 = 61).
    // 설명: 63개의 비어있지 않은 부분 수열이 있고, 그 중 2개는 조건을 만족하지 않습니다 ([6,7], [7]).
    // 유효한 부분 수열의 개수 (63 - 2 = 61).

    vector<int> nums = {2,3,3,4,6,7};
    int target = 12;
    EXPECT_EQ(this->s.numSubseq(nums, target), 61);
}

TEST_F(CLASS_NAME, __LINE__)
{
    vector<int> nums = {7,10,7,3,7,5,4};
    int target = 12;
    EXPECT_EQ(this->s.numSubseq(nums, target), 56);
}


int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
