#include <gtest/gtest.h>
#include <iostream>
#include <iomanip>
#include <algorithm>
#include <vector>
#include <string>
#include <map>

using namespace std;


/* https://leetcode.com/problems/grid-game/?envType=daily-question&envId=2025-01-21
 * @lc app=leetcode id=2017 lang=cpp
 * [2017] Grid Game

You are given a 0-indexed 2D array grid of size 2 x n, where grid[r][c] represents the number of points at position (r, c) on the matrix. Two robots are playing a game on this matrix.
Both robots initially start at (0, 0) and want to reach (1, n-1). Each robot may only move to the right ((r, c) to (r, c + 1)) or down ((r, c) to (r + 1, c)).
At the start of the game, the first robot moves from (0, 0) to (1, n-1), collecting all the points from the cells on its path. For all cells (r, c) traversed on the path, grid[r][c] is set to 0. Then, the second robot moves from (0, 0) to (1, n-1), collecting the points on its path. Note that their paths may intersect with one another.
The first robot wants to minimize the number of points collected by the second robot. In contrast, the second robot wants to maximize the number of points it collects. If both robots play optimally, return the number of points collected by the second robot.

크기가 2 x n인 0-인덱스 2D 배열 grid가 주어지며, grid[r][c]는 행렬의 위치 (r, c)에서의 점수를 나타냅니다. 두 로봇이 이 행렬에서 게임을 하고 있습니다.
두 로봇은 모두 (0, 0)에서 시작하여 (1, n-1)에 도달하려고 합니다. 각 로봇은 오른쪽((r, c)에서 (r, c + 1))이나 아래((r, c)에서 (r + 1, c))로만 이동할 수 있습니다.
게임 시작 시, 첫 번째 로봇이 (0, 0)에서 (1, n-1)로 이동하면서 경로상의 모든 셀에서 점수를 수집합니다. 경로상의 모든 셀 (r, c)에 대해 grid[r][c]는 0으로 설정됩니다. 그 다음, 두 번째 로봇이 (0, 0)에서 (1, n-1)로 이동하면서 경로상의 점수를 수집합니다. 두 로봇의 경로는 서로 교차할 수 있습니다.
첫 번째 로봇은 두 번째 로봇이 수집하는 점수를 최소화하려고 하고, 반대로 두 번째 로봇은 자신이 수집하는 점수를 최대화하려고 합니다. 두 로봇이 최적의 플레이를 한다고 할 때, 두 번째 로봇이 수집하는 점수를 반환하세요.

Constraints:
- grid.length == 2
- n == grid[r].length
- 1 <= n <= 5 * 10**4
- 1 <= grid[r][c] <= 10**5
 */

// @lc code=start
class Solution {
public:
    long long gridGame(vector<vector<int>>& grid) {
        int n = grid[0].size();
        vector<long long> top_sum(n + 1, 0);
        vector<long long> bottom_sum(n + 1, 0);
        for (int i = 0; i < n; i++) {
            top_sum[i + 1] = grid[0][i] + top_sum[i];
            bottom_sum[i + 1] = grid[1][i] + bottom_sum[i];
        }

        long long answer = LLONG_MAX;
        for (int i = 0; i < n; i++) {
            answer = min(answer, max(top_sum[n] - top_sum[i + 1], bottom_sum[i]));
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
    // Example 1:
    // Input: grid = [[2,5,4],[1,5,1]]
    // Output: 4
    // Explanation: The optimal path taken by the first robot is shown in red, and the optimal path taken by the second robot is shown in blue.
    // The cells visited by the first robot are set to 0.
    // The second robot will collect 0 + 0 + 4 + 0 = 4 points.
    vector<vector<int>> grid = {{2,5,4},{1,5,1}};
	EXPECT_EQ(this->s.gridGame(grid), 4);

    // 2 5 4
    // 1 5 1

    // 0 5 4
    // 0 0 0

    // 0 0 4
    // 1 0 0
    // 0 0 0
    // 1 5 0
}

TEST_F(CLASS_NAME, __LINE__)
{
    // Example 2:
    // Input: grid = [[3,3,1],[8,5,2]]
    // Output: 4
    // Explanation: The optimal path taken by the first robot is shown in red, and the optimal path taken by the second robot is shown in blue.
    // The cells visited by the first robot are set to 0.
    // The second robot will collect 0 + 3 + 1 + 0 = 4 points.
    vector<vector<int>> grid = {{3,3,1},{8,5,2}};
	EXPECT_EQ(this->s.gridGame(grid), 4);
}

TEST_F(CLASS_NAME, __LINE__)
{
    // Example 3:
    // Input: grid = [[1,3,1,15],[1,3,3,1]]
    // Output: 7
    // Explanation: The optimal path taken by the first robot is shown in red, and the optimal path taken by the second robot is shown in blue.
    // The cells visited by the first robot are set to 0.
    // The second robot will collect 0 + 1 + 3 + 3 + 0 = 7 points.

    vector<vector<int>> grid = {{1,3,1,15},{1,3,3,1}};
	EXPECT_EQ(this->s.gridGame(grid), 7);
}


int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}