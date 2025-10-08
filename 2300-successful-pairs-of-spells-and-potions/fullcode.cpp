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



/* https://leetcode.com/problems/successful-pairs-of-spells-and-potions/
 * @lc app=leetcode id=2300 lang=cpp
 * [2300] Successful Pairs of Spells and Potions

You are given two positive integer arrays spells and potions, of length n and m respectively, where spells[i] represents the strength of the ith spell and potions[j] represents the strength of the jth potion.
You are also given an integer success. A spell and potion pair is considered successful if the product of their strengths is at least success.
Return an integer array pairs of length n where pairs[i] is the number of potions that will form a successful pair with the ith spell.

두 개의 양의 정수 배열 spells와 potions가 주어지며, 각각의 길이는 n과 m입니다. 여기서 spells[i]는 i번째 주문의 강도를 나타내고 potions[j]는 j번째 물약의 강도를 나타냅니다.
정수 success도 주어집니다. 주문과 물약 쌍은 그들의 강도의 곱이 최소 success 이상일 때 성공적인 것으로 간주됩니다.
길이 n의 정수 배열 pairs를 반환하며, 여기서 pairs[i]는 i번째 주문과 성공적인 쌍을 이룰 물약의 개수입니다.

Example 1:
Input: spells = [5,1,3], potions = [1,2,3,4,5], success = 7
Output: [4,0,3]
Explanation:
- 0th spell: 5 * [1,2,3,4,5] = [5,10,15,20,25]. 4 pairs are successful.
- 1st spell: 1 * [1,2,3,4,5] = [1,2,3,4,5]. 0 pairs are successful.
- 2nd spell: 3 * [1,2,3,4,5] = [3,6,9,12,15]. 3 pairs are successful.
Thus, [4,0,3] is returned.

설명:
- 0번째 주문: 5 * [1,2,3,4,5] = [5,10,15,20,25]. 4개의 쌍이 성공적입니다.
- 1번째 주문: 1 * [1,2,3,4,5] = [1,2,3,4,5]. 0개의 쌍이 성공적입니다.
- 2번째 주문: 3 * [1,2,3,4,5] = [3,6,9,12,15]. 3개의 쌍이 성공적입니다.
따라서, [4,0,3]이 반환됩니다.

Example 2:
Input: spells = [3,1,2], potions = [8,5,8], success = 16
Output: [2,0,2]
Explanation:
- 0th spell: 3 * [8,5,8] = [24,15,24]. 2 pairs are successful.
- 1st spell: 1 * [8,5,8] = [8,5,8]. 0 pairs are successful.
- 2nd spell: 2 * [8,5,8] = [16,10,16]. 2 pairs are successful.
Thus, [2,0,2] is returned.

설명:
- 0번째 주문: 3 * [8,5,8] = [24,15,24]. 2개의 쌍이 성공적입니다.
- 1번째 주문: 1 * [8,5,8] = [8,5,8]. 0개의 쌍이 성공적입니다.
- 2번째 주문: 2 * [8,5,8] = [16,10,16]. 2개의 쌍이 성공적입니다.
따라서, [2,0,2]가 반환됩니다.

Constraints:
n == spells.length
m == potions.length
1 <= n, m <= 10**5
1 <= spells[i], potions[i] <= 10**5
1 <= success <= 1010
 */

// @lc code=start
class Solution {
private:
    int binarySearch(vector<int>& potions, long long target) {
        int left = 0;
        int right = potions.size() - 1;

        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (potions[mid] < target) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        return left;
    }
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        sort(potions.begin(), potions.end());
        vector<int> answer;
        long long target;

        for (int spell : spells) {
            if (success % spell == 0) {
                target = success / spell;
            } else {
                target = success / spell + 1;
            }
            int index = binarySearch(potions, target);
            answer.push_back(potions.size() - index);
        }

        return answer;
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
    vector<int> spells = {5,1,3};
    vector<int> potions = {1,2,3,4,5};
    long long success = 7;
    vector<int> expect = {4,0,3};
    vector<int> actual = this->s.successfulPairs(spells, potions, success);
    EXPECT_EQ(expect, actual);
}

TEST_F(CLASS_NAME, __LINE__)
{
    vector<int> spells = {3,1,2};
    vector<int> potions = {8,5,8};
    long long success = 16;
    vector<int> expect = {2,0,2};
    vector<int> actual = this->s.successfulPairs(spells, potions, success);
    EXPECT_EQ(expect, actual);
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
