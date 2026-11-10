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


/*
https://leetcode.com/problems/climbing-stairs-ii/
3693 | Medium | Climbing Stairs II

You are climbing a staircase with n + 1 steps, numbered from 0 to n.
You are also given a 1-indexed integer array costs of length n, where costs[i] is the cost of step i.
From step i, you can jump only to step i + 1, i + 2, or i + 3. The cost of jumping from step i to step j is defined as: costs[j] + (j - i)^2
You start from step 0 with cost = 0.
Return the minimum total cost to reach step n.

󰛨 Example 1:
Input: n = 4, costs = [1,2,3,4]
Output: 13
Explanation:
One optimal path is 0  1  2  4

Jump
Cost Calculation
Cost
0  1
costs[1] + (1 - 0)^2 = 1 + 1
2
1  2
costs[2] + (2 - 1)^2 = 2 + 1
3
2  4
costs[4] + (4 - 2)^2 = 4 + 4
8
Thus, the minimum total cost is 2 + 3 + 8 = 13

󰛨 Example 2:
Input: n = 4, costs = [5,1,6,2]
Output: 11
Explanation:
One optimal path is 0  2  4

Jump
Cost Calculation
Cost
0  2
costs[2] + (2 - 0)^2 = 1 + 4
5
2  4
costs[4] + (4 - 2)^2 = 2 + 4
6
Thus, the minimum total cost is 5 + 6 = 11

󰛨 Example 3:
Input: n = 3, costs = [9,8,3]
Output: 12
Explanation:
The optimal path is 0  3 with total cost = costs[3] + (3 - 0)^2 = 3 + 9 = 12


 Constraints:
	* 1 <= n == costs.length <= 10^5
	* 1 <= costs[i] <= 10^4


0부터 n까지 번호가 매겨진 n + 1개의 계단을 오르고 있습니다.
또한 길이가 n인 1-indexed 정수 배열 costs가 주어지며, costs[i]는 계단 i의 비용입니다.
계단 i에서는 계단 i + 1, i + 2, i + 3으로만 점프할 수 있습니다. 계단 i에서 계단 j로 점프하는 비용은 다음과 같이 정의됩니다: costs[j] + (j - i)^2
계단 0에서 cost = 0으로 시작합니다.
계단 n에 도달하기 위한 최소 총 비용을 반환하십시오.

󰛨 예제 1:
입력: n = 4, costs = [1,2,3,4]
출력: 13
설명:
최적 경로 중 하나는 0  1  2  4입니다.

점프
비용 계산
비용
0  1
costs[1] + (1 - 0)^2 = 1 + 1
2
1  2
costs[2] + (2 - 1)^2 = 2 + 1
3
2  4
costs[4] + (4 - 2)^2 = 4 + 4
8
따라서 최소 총 비용은 2 + 3 + 8 = 13입니다.

󰛨 예제 2:
입력: n = 4, costs = [5,1,6,2]
출력: 11
설명:
최적 경로 중 하나는 0  2  4입니다.

점프
비용 계산
비용
0  2
costs[2] + (2 - 0)^2 = 1 + 4
5
2  4
costs[4] + (4 - 2)^2 = 2 + 4
6
따라서 최소 총 비용은 5 + 6 = 11입니다.

󰛨 예제 3:
입력: n = 3, costs = [9,8,3]
출력: 12
설명:
최적 경로는 0  3이며, 총 비용 = costs[3] + (3 - 0)^2 = 3 + 9 = 12입니다.


 제약 조건:
	* 1 <= n == costs.length <= 10^5
	* 1 <= costs[i] <= 10^4


 */

// @leet start
class Solution {
public:
    int climbStairs(int n, vector<int>& costs) {
        long long steps[3] = {INT_MAX, INT_MAX, INT_MAX};
        steps[0] = costs[0] + 1;
        if (n >= 2) {
            steps[1] = min(steps[0] + costs[1] + 1, costs[1] + 4LL);
        } else {
            return (int)steps[0];
        }
        if (n >= 3) {
            steps[2] = min<long long>({steps[1] + costs[2] + 1, steps[0] + costs[2] + 4, costs[2] + 9});
        } else {
            return (int)steps[1];
        }
        long long curr;
        for (int i = 3; i < n; ++i) {
            // steps[0]: 3번째 전
            // steps[1]: 2번째 전
            // steps[2]: 1번째 전
            // curr: 현재 계단
            curr = costs[i] + min({ steps[0] + 9, steps[1] + 4, steps[2] + 1 });
            steps[0] = steps[1];
            steps[1] = steps[2];
            steps[2] = curr;
        }
        return (int)steps[2];
    }
};
// @leet end


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
    vector<int> costs = {1, 2, 3, 4};
    EXPECT_EQ(this->s.climbStairs(4, costs), 13);
}

TEST_F(CLASS_NAME, __LINE__)
{
    vector<int> costs = {5, 1, 6, 2};
    EXPECT_EQ(this->s.climbStairs(4, costs), 11);
}

TEST_F(CLASS_NAME, __LINE__)
{
    vector<int> costs = {9, 8, 3};
    EXPECT_EQ(this->s.climbStairs(3, costs), 12);
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
