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



/* https://leetcode.com/problems/partition-array-such-that-maximum-difference-is-k/
 * @lc app=leetcode id=2294 lang=cpp
 * [2294] Partition Array Such That Maximum Difference Is K

You are given an integer array nums and an integer k. You may partition nums into one or more subsequences such that each element in nums appears in exactly one of the subsequences.
Return the minimum number of subsequences needed such that the difference between the maximum and minimum values in each subsequence is at most k.
A subsequence is a sequence that can be derived from another sequence by deleting some or no elements without changing the order of the remaining elements.

정수 배열 nums와 정수 k가 주어집니다. nums의 각 요소가 정확히 하나의 부분 수열에만 나타나도록 nums를 하나 이상의 부분 수열로 분할할 수 있습니다.
각 부분 수열에서 최댓값과 최솟값의 차이가 최대 k가 되도록 하는 데 필요한 최소 부분 수열 개수를 반환하세요.
부분 수열은 나머지 요소들의 순서를 변경하지 않고 일부 또는 전체 요소를 삭제하여 다른 수열에서 파생될 수 있는 수열입니다.

Constraints:
1 <= nums.length <= 10**5
0 <= nums[i] <= 10**5
0 <= k <= 10**5
 */

// @lc code=start
class Solution {
public:
    int partitionArray(vector<int>& nums, int k) {

        sort(nums.begin(), nums.end());
        int count = 1;
        int start = nums[0];
        int n = nums.size();

        for (int i = 1; i < n; i++) {
            if (nums[i] - start > k) {
                count++;
                start = nums[i];
            }
        }

        return count;
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
    // Input: nums = [3,6,1,2,5], k = 2
    // Output: 2
    // Explanation:
    // We can partition nums into the two subsequences [3,1,2] and [6,5].
    // The difference between the maximum and minimum value in the first subsequence is 3 - 1 = 2.
    // The difference between the maximum and minimum value in the second subsequence is 6 - 5 = 1.
    // Since two subsequences were created, we return 2. It can be shown that 2 is the minimum number of subsequences needed.

    vector<int> nums = {3,6,1,2,5};
    int k = 2;
    EXPECT_EQ(this->s.partitionArray(nums, k), 2);
}

TEST_F(CLASS_NAME, __LINE__)
{
    // Example 2:
    // Input: nums = [1,2,3], k = 1
    // Output: 2
    // Explanation:
    // We can partition nums into the two subsequences [1,2] and [3].
    // The difference between the maximum and minimum value in the first subsequence is 2 - 1 = 1.
    // The difference between the maximum and minimum value in the second subsequence is 3 - 3 = 0.
    // Since two subsequences were created, we return 2. Note that another optimal solution is to partition nums into the two subsequences [1] and [2,3].

    vector<int> nums = {1,2,3};
    int k = 1;
    EXPECT_EQ(this->s.partitionArray(nums, k), 2);
}

TEST_F(CLASS_NAME, __LINE__)
{
    // Example 3:
    // Input: nums = [2,2,4,5], k = 0
    // Output: 3
    // Explanation:
    // We can partition nums into the three subsequences [2,2], [4], and [5].
    // The difference between the maximum and minimum value in the first subsequences is 2 - 2 = 0.
    // The difference between the maximum and minimum value in the second subsequences is 4 - 4 = 0.
    // The difference between the maximum and minimum value in the third subsequences is 5 - 5 = 0.
    // Since three subsequences were created, we return 3. It can be shown that 3 is the minimum number of subsequences needed.

    vector<int> nums = {2,2,4,5};
    int k = 0;
    EXPECT_EQ(this->s.partitionArray(nums, k), 3);
}



int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
