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


/* https://leetcode.com/problems/maximum-non-negative-product-in-a-matrix/
 * 1594. Maximum Non Negative Product in a Matrix | Medium

You are given a m x n matrix grid. Initially, you are located at the top-left corner (0, 0), and in each step, you can only move right or down in the matrix.
Among all possible paths starting from the top-left corner (0, 0) and ending in the bottom-right corner (m - 1, n - 1), find the path with the maximum non-negative product. The product of a path is the product of all integers in the grid cells visited along the path.
Return the maximum non-negative product modulo 10^9 + 7. If the maximum product is negative, return -1.
Notice that the modulo is performed after getting the maximum product.

m x n 크기의 행렬 grid가 주어집니다. 처음에는 왼쪽 상단 모서리 (0, 0)에 위치하며, 각 단계에서 행렬 내에서 오른쪽 또는 아래로만 이동할 수 있습니다.
왼쪽 상단 모서리 (0, 0)에서 시작하여 오른쪽 하단 모서리 (m - 1, n - 1)에서 끝나는 모든 가능한 경로 중에서, 음이 아닌 곱이 최대가 되는 경로를 찾으십시오. 경로의 곱은 해당 경로를 따라 방문한 모든 격자 칸에 있는 정수들의 곱입니다.
음이 아닌 최대 곱을 10^9 + 7로 나눈 나머지를 반환하십시오. 최대 곱이 음수인 경우 -1을 반환하십시오.
나머지 연산은 최대 곱을 구한 후에 수행된다는 점에 유의하십시오.

 Constraints:
    * m == grid.length
    * n == grid[i].length
    * 1 <= m, n <= 15
    * -4 <= grid[i][j] <= 4

    최대값 4^(15*15) = 4^225 ???
 */
// @leet start
class Solution {
private:
    static constexpr int MOD = 1e9 + 7;
public:
    int maxProductPath(vector<vector<int>>& grid) {
        int y = grid.size();
        int x = grid[0].size();
        vector<vector<long long>> dp_max(y, vector<long long>(x, 0));
        vector<vector<long long>> dp_min(y, vector<long long>(x, 0));

        // 초기 값 설정
        dp_max[0][0] = grid[0][0];
        dp_min[0][0] = grid[0][0];
        for (int i = 1; i < y; ++i) {
            dp_max[i][0] = dp_max[i-1][0] * grid[i][0];
            dp_min[i][0] = dp_min[i-1][0] * grid[i][0];
        }
        for (int j = 1; j < x; ++j) {
            dp_max[0][j] = dp_max[0][j-1] * grid[0][j];
            dp_min[0][j] = dp_min[0][j-1] * grid[0][j];
        }

        // dp 시작
        for (int i = 1; i < y; ++i) {
            for (int j = 1; j < x; ++j) {
                long long maxup = dp_max[i-1][j] * grid[i][j];
                long long maxleft = dp_max[i][j-1] * grid[i][j];
                long long minup = dp_min[i-1][j] * grid[i][j];
                long long minleft = dp_min[i][j-1] * grid[i][j];
                dp_max[i][j] = max({maxup, maxleft, minup, minleft});
                dp_min[i][j] = min({maxup, maxleft, minup, minleft});
            }
        }

        long long result = dp_max[y-1][x-1];
        if (result < 0) {
            return -1;
        }
        return result % MOD;
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
    // 󰛨 Example 1:
    // [img](https://assets.leetcode.com/uploads/2021/12/23/product1.jpg)
    //     Input: grid = [[-1,-2,-3],[-2,-3,-3],[-3,-3,-2]]
    //     Output: -1
    //     Explanation: It is not possible to get non-negative product in the path from (0, 0) to (2, 2), so return -1.


    vector<vector<int>> grid = {{-1,-2,-3},{-2,-3,-3},{-3,-3,-2}};
    EXPECT_EQ(this->s.maxProductPath(grid), -1);
}

TEST_F(CLASS_NAME, __LINE__)
{
    // 󰛨 Example 2:
    // [img](https://assets.leetcode.com/uploads/2021/12/23/product2.jpg)
    //     Input: grid = [[1,-2,1],[1,-2,1],[3,-4,1]]
    //     Output: 8
    //     Explanation: Maximum non-negative product is shown (1 * 1 * -2 * -4 * 1 = 8).

    vector<vector<int>> grid = {{1,-2,1},{1,-2,1},{3,-4,1}};
    EXPECT_EQ(this->s.maxProductPath(grid), 8);
}

TEST_F(CLASS_NAME, __LINE__)
{
    // 󰛨 Example 3:
    // [img](https://assets.leetcode.com/uploads/2021/12/23/product3.jpg)
    //     Input: grid = [[1,3],[0,-4]]
    //     Output: 0
    //     Explanation: Maximum non-negative product is shown (1 * 0 * -4 = 0).

    vector<vector<int>> grid = {{1,3},{0,-4}};
    EXPECT_EQ(this->s.maxProductPath(grid), 0);
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
