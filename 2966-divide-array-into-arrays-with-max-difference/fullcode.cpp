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



/* https://leetcode.com/problems/divide-array-into-arrays-with-max-difference/?envType=daily-question&envId=2025-06-18
 * @lc app=leetcode id=2966 lang=cpp
 * [2966] Divide Array Into Arrays With Max Difference

You are given an integer array nums of size n where n is a multiple of 3 and a positive integer k.
Divide the array nums into n / 3 arrays of size 3 satisfying the following condition:
The difference between any two elements in one array is less than or equal to k.
Return a 2D array containing the arrays. If it is impossible to satisfy the conditions, return an empty array. And if there are multiple answers, return any of them.

크기가 n인 정수 배열 nums가 주어지고 (n은 3의 배수), 양의 정수 k가 주어진다.
배열 nums를 크기가 3인 n / 3개의 배열로 나누되 다음 조건을 만족해야 한다:
한 배열 내의 임의의 두 원소 간의 차이는 k 이하여야 한다.
배열들을 포함하는 2D 배열을 반환하라. 조건을 만족하는 것이 불가능하면 빈 배열을 반환하라. 그리고 여러 답이 있다면 그 중 아무거나 반환하라.

Constraints:
n == nums.length
1 <= n <= 10^5
n is a multiple of 3
1 <= nums[i] <= 10^5
1 <= k <= 10^5
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> divideArray(vector<int>& nums, int k) {
        map<int, int> m;

        for (int i = 0; i < nums.size(); i++) {
            m[nums[i]]++;
        }

        vector<int> v;
        int v_size = m.size();
        for (pair<int, int> p : m) {
            v.push_back(p.first);
        }

        vector<vector<int>> result;
        int i = 0;
        while (i < v_size) {
            int count = 3;
            vector<int> temp;
            int limit = v[i] + k;
            while (count > 0 && i < v_size && v[i] <= limit) {
                if (m[v[i]] > count) {
                    m[v[i]] -= count;
                    for (int j = 0; j < count; j++) {
                        temp.push_back(v[i]);
                    }
                    count = 0;
                } else {
                    count -= m[v[i]];
                    for (int j = 0; j < m[v[i]]; j++) {
                        temp.push_back(v[i]);
                    }
                    m[v[i]] = 0;
                    i++;
                }
            }
            if (temp.size() != 3) {
                return {};
            }
            result.push_back(temp);
        }
        std::cout << "i: " << i << ", v_size: " << v_size << ", m[v[v_size - 1]]: " << m[v[v_size - 1]] << std::endl;
        if (m[v[v_size - 1]] != 0) {
            return {};
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
    // Input: nums = [1,3,4,8,7,9,3,5,1], k = 2
    // Output: [[1,1,3],[3,4,5],[7,8,9]]
    // Explanation:
    // The difference between any two elements in each array is less than or equal to 2.

    vector<int> nums = {1,3,4,8,7,9,3,5,1};
    int k = 2;
    vector<vector<int>> expected = {{1,1,3},{3,4,5},{7,8,9}};
    vector<vector<int>> result = this->s.divideArray(nums, k);
    EXPECT_EQ(result, expected);
}

TEST_F(CLASS_NAME, __LINE__)
{
    // Example 2:
    // Input: nums = [2,4,2,2,5,2], k = 2
    // Output: []
    // Explanation:
    // Different ways to divide nums into 2 arrays of size 3 are:
    // [[2,2,2],[2,4,5]] (and its permutations)
    // [[2,2,4],[2,2,5]] (and its permutations)
    // Because there are four 2s there will be an array with the elements 2 and 5 no matter how we divide it. since 5 - 2 = 3 > k, the condition is not satisfied and so there is no valid division.
    // nums를 크기 3인 2개의 배열로 나누는 다양한 방법들:
    // [[2,2,2],[2,4,5]] (그리고 그 순열들)
    // [[2,2,4],[2,2,5]] (그리고 그 순열들)
    // 2가 4개 있기 때문에 어떻게 나누든 2와 5 요소를 가진 배열이 생길 것이다. 5 - 2 = 3 > k이므로 조건을 만족하지 않아 유효한 분할이 없다.

    vector<int> nums = {2,4,2,2,5,2};
    int k = 2;
    vector<vector<int>> expected = {};
    vector<vector<int>> result = this->s.divideArray(nums, k);
    EXPECT_EQ(result, expected);
}

TEST_F(CLASS_NAME, __LINE__)
{
    // Example 3:
    // Input: nums = [4,2,9,8,2,12,7,12,10,5,8,5,5,7,9,2,5,11], k = 14
    // Output: [[2,2,12],[4,8,5],[5,9,7],[7,8,5],[5,9,10],[11,12,2]]
    // Explanation:
    // The difference between any two elements in each array is less than or equal to 14.

    vector<int> nums = {4,2,9,8,2,12,7,12,10,5,8,5,5,7,9,2,5,11};
    int k = 14;
    vector<vector<int>> expected = {{2,2,12},{4,8,5},{5,9,7},{7,8,5},{5,9,10},{11,12,2}};
    vector<vector<int>> result = this->s.divideArray(nums, k);
    EXPECT_EQ(result, expected);
}


int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
