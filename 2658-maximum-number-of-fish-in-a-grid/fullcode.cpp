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

using namespace std;



/* https://leetcode.com/problems/maximum-number-of-fish-in-a-grid/description/?envType=daily-question&envId=2025-01-28
 * @lc app=leetcode id=2658 lang=cpp
 * [2658] Maximum Number of Fish in a Grid

You are given a 0-indexed 2D matrix grid of size m x n, where (r, c) represents:
- A land cell if grid[r][c] = 0, or
- A water cell containing grid[r][c] fish, if grid[r][c] > 0.
A fisher can start at any water cell (r, c) and can do the following operations any number of times:
- Catch all the fish at cell (r, c), or
- Move to any adjacent water cell.
Return the maximum number of fish the fisher can catch if he chooses his starting cell optimally, or 0 if no water cell exists.
An adjacent cell of the cell (r, c), is one of the cells (r, c + 1), (r, c - 1), (r + 1, c) or (r - 1, c) if it exists.

m x n 크기의 0-인덱스 2D 행렬 grid가 주어지며, (r, c)는 다음을 나타냅니다:
- grid[r][c] = 0인 경우 육지 셀
- grid[r][c] > 0인 경우 grid[r][c]마리의 물고기가 있는 물 셀
어부는 아무 물 셀(r, c)에서 시작할 수 있으며 다음 작업을 원하는 만큼 수행할 수 있습니다:
- 셀(r, c)의 모든 물고기를 잡거나
- 인접한 물 셀로 이동
어부가 시작 셀을 최적으로 선택할 때 잡을 수 있는 최대 물고기 수를 반환하거나, 물 셀이 없는 경우 0을 반환합니다.
셀(r, c)의 인접 셀은 존재하는 경우 셀(r, c + 1), (r, c - 1), (r + 1, c) 또는 (r - 1, c) 중 하나입니다.

Constraints:
- m == grid.length
- n == grid[i].length
- 1 <= m, n <= 10
- 0 <= grid[i][j] <= 10
 */

// @lc code=start
class Solution {
private:
    vector<pair<int, int>> directions = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    int xlen;
    int ylen;

    int dfs(vector<vector<int>>* grid, vector<vector<bool>>* visited, int x, int y) {
        int dx, dy;
        queue<pair<int, int>> q;
        q.push({x, y});
        (*visited)[y][x] = true;
        int fish = 0;
        while (!q.empty()) {
            auto [nx, ny] = q.front();
            q.pop();
            fish += (*grid)[ny][nx];
            for (auto& dir : directions) {
                dx = nx + dir.first;
                dy = ny + dir.second;
                if (dx < 0 || dx >= this->xlen || dy < 0 || dy >= this->ylen) {
                    continue;
                }
                if ((*visited)[dy][dx]) {
                    continue;
                }
                if ((*grid)[dy][dx] == 0) {
                    continue;
                }
                q.push({dx, dy});
                (*visited)[dy][dx] = true;
            }
        }
        return fish;
    }
public:
    int findMaxFish(vector<vector<int>>& grid) {
        this->xlen = grid[0].size();
        this->ylen = grid.size();
        int maxFish = 0;

        vector<vector<bool>> visited(ylen, vector<bool>(xlen, false));
        for (int y = 0; y < ylen; y++) {
            for (int x = 0; x < xlen; x++) {
                if (grid[y][x] == 0 || visited[y][x]) {
                    continue;
                }
                maxFish = max(maxFish, dfs(&grid, &visited, x, y));
            }
        }


        return maxFish;
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
    // Input: grid = [[0,2,1,0],[4,0,0,3],[1,0,0,4],[0,3,2,0]]
    // Output: 7
    // Explanation: The fisher can start at cell (1,3) and collect 3 fish, then move to cell (2,3) and collect 4 fish.
    vector<vector<int>> grid = {{0,2,1,0},{4,0,0,3},{1,0,0,4},{0,3,2,0}};
    EXPECT_EQ(this->s.findMaxFish(grid), 7);
}
TEST_F(CLASS_NAME, __LINE__)
{
    // Input: grid = [[1,0,0,0],[0,0,0,0],[0,0,0,0],[0,0,0,1]]
    // Output: 1
    // Explanation: The fisher can start at cells (0,0) or (3,3) and collect a single fish.
    vector<vector<int>> grid = {{1,0,0,0},{0,0,0,0},{0,0,0,0},{0,0,0,1}};
    EXPECT_EQ(this->s.findMaxFish(grid), 1);
}
TEST_F(CLASS_NAME, __LINE__)
{
    // Input: grid = [[1,0,0,0],[0,0,0,0],[0,0,0,0],[0,0,0,1]]
    // Output: 1
    // Explanation: The fisher can start at cells (0,0) or (3,3) and collect a single fish.
    vector<vector<int>> grid = {{10, 9}};
    EXPECT_EQ(this->s.findMaxFish(grid), 19);
}
TEST_F(CLASS_NAME, __LINE__)
{
    // Input: grid = [[1,0,0,0],[0,0,0,0],[0,0,0,0],[0,0,0,1]]
    // Output: 1
    // Explanation: The fisher can start at cells (0,0) or (3,3) and collect a single fish.
    vector<vector<int>> grid = {{8, 6}, {2, 6}};
    EXPECT_EQ(this->s.findMaxFish(grid), 22);
}


int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}