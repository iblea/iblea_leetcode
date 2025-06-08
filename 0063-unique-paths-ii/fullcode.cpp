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



/* https://leetcode.com/problems/unique-paths-ii
 * @lc app=leetcode id=63 lang=cpp
 * [63] Unique Paths II

You are given an m x n integer array grid. There is a robot initially located at the top-left corner (i.e., grid[0][0]). The robot tries to move to the bottom-right corner (i.e., grid[m - 1][n - 1]). The robot can only move either down or right at any point in time.
An obstacle and space are marked as 1 or 0 respectively in grid. A path that the robot takes cannot include any square that is an obstacle.
Return the number of possible unique paths that the robot can take to reach the bottom-right corner.
The testcases are generated so that the answer will be less than or equal to (2 * (10**9)).

m x n 정수 배열 grid가 주어집니다. 로봇이 처음에 왼쪽 상단 모서리(즉, grid[0][0])에 위치합니다. 로봇은 오른쪽 하단 모서리(즉, grid[m - 1][n - 1])로 이동하려고 합니다. 로봇은 언제든지 아래쪽 또는 오른쪽으로만 이동할 수 있습니다.
장애물과 공간은 grid에서 각각 1 또는 0으로 표시됩니다. 로봇이 취하는 경로는 장애물인 사각형을 포함할 수 없습니다.
로봇이 오른쪽 하단 모서리에 도달하기 위해 취할 수 있는 가능한 고유 경로의 수를 반환합니다.
테스트 케이스는 답이 (2 * (10**9)) 이하가 되도록 생성됩니다.

Constraints:
m == obstacleGrid.length
n == obstacleGrid[i].length
1 <= m, n <= 100
obstacleGrid[i][j] is 0 or 1.
 */
// @lc code=start
class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();

        if (obstacleGrid[0][0] == 1) {
            return 0;
        }

        if (n == 1 || m == 1) {
            for (int i = 0; i < m; i++) {
                // 중간에 장애물이 있으면 경로가 없음
                if (obstacleGrid[i][0] == 1) {
                    return 0;
                }
            }
            for (int i = 0; i < n; i++) {
                if (obstacleGrid[0][i] == 1) {
                    return 0;
                }
            }
            return 1;
        }

        vector<vector<int>> dp(m, vector<int>(n, 0));
        dp[0][0] = 1;
        for (int i = 1; i < m; i++) {
            if (obstacleGrid[i][0] == 1) {
                break;
            }
            dp[i][0] = 1;
        }
        for (int i = 1; i < n; i++) {
            if (obstacleGrid[0][i] == 1) {
                break;
            }
            dp[0][i] = 1;
        }

        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                if (obstacleGrid[i][j] != 1) {
                    dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
                }
            }
        }
        return dp[m - 1][n - 1];
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
    // Input: obstacleGrid = [[0,0,0],[0,1,0],[0,0,0]]
    // Output: 2
    // Explanation: There is one obstacle in the middle of the 3x3 grid above.
    // There are two ways to reach the bottom-right corner:
    // 1. Right -> Right -> Down -> Down
    // 2. Down -> Down -> Right -> Right

    vector<vector<int>> obstacleGrid = {{0,0,0},{0,1,0},{0,0,0}};
    EXPECT_EQ(this->s.uniquePathsWithObstacles(obstacleGrid), 2);
}

TEST_F(CLASS_NAME, __LINE__)
{
    //Example 2:
    //Input: obstacleGrid = [[0,1],[0,0]]
    //Output: 1

    vector<vector<int>> obstacleGrid = {{0,1},{0,0}};
    EXPECT_EQ(this->s.uniquePathsWithObstacles(obstacleGrid), 1);
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
