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



/* https://leetcode.com/problems/minimize-the-maximum-difference-of-pairs
 * @lc app=leetcode id=2616 lang=cpp
 * [2616] Minimize the Maximum Difference of Pairs

You are given a 0-indexed integer array nums and an integer p. Find p pairs of indices of nums such that the maximum difference amongst all the pairs is minimized. Also, ensure no index appears more than once amongst the p pairs.
Note that for a pair of elements at the index i and j, the difference of this pair is |nums[i] - nums[j]|, where |x| represents the absolute value of x.
Return the minimum maximum difference among all p pairs. We define the maximum of an empty set to be zero.

0-인덱스 정수 배열 nums와 정수 p가 주어진다. nums의 인덱스들로 p개의 쌍을 찾되, 모든 쌍들 중 최대 차이가 최소화되도록 해야 한다. 또한 p개의 쌍들 중에서 어떤 인덱스도 한 번 이상 나타나지 않도록 해야 한다.
인덱스 i와 j에 있는 요소들의 쌍에 대해, 이 쌍의 차이는 |nums[i] - nums[j]|이며, 여기서 |x|는 x의 절댓값을 나타낸다.
모든 p개 쌍들 중에서 최소 최대 차이를 반환하라. 빈 집합의 최댓값은 0으로 정의한다.

Constraints:
1 <= nums.length <= 10**5
0 <= nums[i] <= 10**9
0 <= p <= (nums.length)/2
 */
// @lc code=start
class Solution {
private:

    bool canMakePairs(vector<int>& nums, int p, int maxDiff) {
        int n = nums.size() - 1;
        int pairs = 0;
        for (int i = 0; i < n; i++) {
            if (nums[i+1] - nums[i] <= maxDiff) {
                pairs++;
                i++;
                if (pairs >= p) {
                    return true;
                }
            }
        }
        return false;
    }
public:
    int minimizeMax(vector<int>& nums, int p) {

        int n = nums.size();
        if (n <= 1 || p == 0) {
            return 0;
        }

        sort(nums.begin(), nums.end());
        int left = 0;
        int right = nums[n - 1] - nums[0];

        while (left < right) {
            int mid = left + (right - left) / 2;
            if (canMakePairs(nums, p, mid)) {
                // mid로 p개 쌍을 만들 수 있으면, 더 작은 값도 시도
                right = mid;
            } else {
                // mid로 p개 쌍을 만들 수 없으면, 더 큰 값 시도
                left = mid + 1;
            }
        }
        return left;
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
    // Input: nums = [10,1,2,7,1,3], p = 2
    // Output: 1
    // Explanation: The first pair is formed from the indices 1 and 4, and the second pair is formed from the indices 2 and 5.
    // The maximum difference is max(|nums[1] - nums[4]|, |nums[2] - nums[5]|) = max(0, 1) = 1. Therefore, we return 1.
    // 설명: 첫 번째 쌍은 인덱스 1과 4로 형성되고, 두 번째 쌍은 인덱스 2와 5로 형성된다.
    // 최대 차이는 max(|nums[1] - nums[4]|, |nums[2] - nums[5]|) = max(0, 1) = 1이다. 따라서 1을 반환한다.

    vector<int> nums = {10,1,2,7,1,3};
    EXPECT_EQ(this->s.minimizeMax(nums, 2), 1);
}

TEST_F(CLASS_NAME, __LINE__)
{
    // Example 2:
    // Input: nums = [4,2,1,2], p = 1
    // Output: 0
    // Explanation: Let the indices 1 and 3 form a pair. The difference of that pair is |2 - 2| = 0, which is the minimum we can attain.
    // 설명: 인덱스 1과 3이 쌍을 이룬다. 그 쌍의 차이는 |2 - 2| = 0이며, 이는 우리가 달성할 수 있는 최솟값이다.

    vector<int> nums = {4,2,1,2};
    EXPECT_EQ(this->s.minimizeMax(nums, 1), 0);
}

TEST_F(CLASS_NAME, __LINE__)
{
    vector<int> nums = {4,6,7,10};
    EXPECT_EQ(this->s.minimizeMax(nums, 2), 3);
}

TEST_F(CLASS_NAME, __LINE__)
{
    vector<int> nums = {1,5,7,8,11};
    EXPECT_EQ(this->s.minimizeMax(nums, 2), 3);
}

TEST_F(CLASS_NAME, __LINE__)
{
    vector<int> nums = {1,11,12,13,17};
    EXPECT_EQ(this->s.minimizeMax(nums, 2), 4);
}


int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
