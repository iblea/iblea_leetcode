#include <gtest/gtest.h>
#include <iostream>
#include <iomanip>
#include <algorithm>
#include <vector>
#include <string>
#include <map>
#include <array>
#include <queue>
using namespace std;



/* https://leetcode.com/problems/minimum-cost-to-make-at-least-one-valid-path-in-a-grid/description/?envType=daily-question&envId=2025-01-18
 * @lc app=leetcode id=1368 lang=cpp
 * [1368] Minimum Cost to Make at Least One Valid Path in a Grid

Given an m x n grid. Each cell of the grid has a sign pointing to the next cell you should visit if you are currently in this cell. The sign of grid[i][j] can be:
1 which means go to the cell to the right. (i.e go from grid[i][j] to grid[i][j + 1]) '→'
2 which means go to the cell to the left. (i.e go from grid[i][j] to grid[i][j - 1]) '←'
3 which means go to the lower cell. (i.e go from grid[i][j] to grid[i + 1][j]) '↓'
4 which means go to the upper cell. (i.e go from grid[i][j] to grid[i - 1][j]) '↑'
Notice that there could be some signs on the cells of the grid that point outside the grid.
You will initially start at the upper left cell (0, 0). A valid path in the grid is a path that starts from the upper left cell (0, 0) and ends at the bottom-right cell (m - 1, n - 1) following the signs on the grid. The valid path does not have to be the shortest.
You can modify the sign on a cell with cost = 1. You can modify the sign on a cell one time only.
Return the minimum cost to make the grid have at least one valid path.

m x n 그리드가 주어집니다. 그리드의 각 셀에는 현재 셀에서 방문해야 할 다음 셀을 가리키는 표시가 있습니다. grid[i][j]의 표시는 다음과 같습니다:
1은 오른쪽 셀로 이동하라는 의미입니다. (즉, grid[i][j]에서 grid[i][j + 1]로 이동) '→'
2는 왼쪽 셀로 이동하라는 의미입니다. (즉, grid[i][j]에서 grid[i][j - 1]로 이동) '←'
3은 아래쪽 셀로 이동하라는 의미입니다. (즉, grid[i][j]에서 grid[i + 1][j]로 이동) '↓'
4는 위쪽 셀로 이동하라는 의미입니다. (즉, grid[i][j]에서 grid[i - 1][j]로 이동) '↑'
그리드의 일부 셀에 있는 표시가 그리드 밖을 가리킬 수 있다는 점에 유의하세요.
처음에는 왼쪽 상단 셀(0, 0)에서 시작합니다. 그리드에서 유효한 경로는 왼쪽 상단 셀(0, 0)에서 시작하여 그리드의 표시를 따라 오른쪽 하단 셀(m - 1, n - 1)에서 끝나는 경로입니다. 유효한 경로가 반드시 최단 경로일 필요는 없습니다.
비용 1로 셀의 표시를 수정할 수 있습니다. 각 셀의 표시는 한 번만 수정할 수 있습니다.
그리드에 최소 하나의 유효한 경로를 만들기 위한 최소 비용을 반환하세요.

Constraints:
- m == grid.length
- n == grid[i].length
- 1 <= m, n <= 100
- 1 <= grid[i][j] <= 4
 */

// @lc code=start
class Solution {

    int ylen = 0;
    int xlen = 0;
    vector<vector<int>> cost;
    vector<pair<int, int>> move_pos = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    priority_queue<array<int, 3>, vector<array<int, 3>>, greater<array<int, 3>>> pq;
    pair<int, int> move(int direction) {
        // x, y
        switch(direction) {
            case 1: return {1, 0};
            case 2: return {-1, 0};
            case 3: return {0, 1};
            case 4: return {0, -1};
        }
        return {0, 0};
    };

    bool is_valid(int x, int y) {
        if (x < 0 || x >= xlen || y < 0 || y >= ylen) {
            return false;
        }
        return true;
    };

    void move_zerocost(vector<vector<int>> &grid, int x, int y, int c) {
        int nx, ny;
        while(is_valid(x, y)) {
            if (this->cost[y][x] <= c) {
                // 무한루프 방지를 위해 이미 방문한 셀을 참조하는 경우 종료한다.
                break;
            }
            this->cost[y][x] = c;
            pair<int, int> move_dir = move(grid[y][x]);
            for (auto dir : this->move_pos) {
                nx = x + dir.first;
                ny = y + dir.second;
                this->pq.push({c + 1, nx, ny});
            }
            x += move_dir.first;
            y += move_dir.second;
        }
    };

public:
    int minCost(vector<vector<int>>& grid) {
        this->ylen = grid.size();
        this->xlen = grid[0].size();

        this->cost = vector<vector<int>>(ylen, vector<int>(xlen, INT_MAX));
        this->pq = priority_queue<array<int, 3>, vector<array<int, 3>>, greater<array<int, 3>>>();
        pq.push({0, 0, 0});

        // 0 이동 가능한 셀을 찾아서 4방향으로 이동(이동이 가능한 경우이거나, 이동한 이후 cost[y][x]가 최소인 경우)하는 큐를 만들어서 큐에 넣는다.
        // 큐에서 빼낸 셀의 좌표를 기준으로 0 이동이 가능한 셀을 찾아 4방향으로 이동(이동이 가능한 경우이거나, 이동한 이후 cost[y][x]가 최소인 경우)하는 큐를 만들어서 큐에 넣는다.
        // 이하 반복...
        while (!pq.empty()) {
            auto [c, x, y] = pq.top();
            pq.pop();
            move_zerocost(grid, x, y, c);
        }
        return this->cost[this->ylen - 1][this->xlen - 1];
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
    // Input: grid = [[1,1,1,1],[2,2,2,2],[1,1,1,1],[2,2,2,2]]
    // Output: 3
    // Explanation: You will start at point (0, 0).
    // The path to (3, 3) is as follows. (0, 0) --> (0, 1) --> (0, 2) --> (0, 3) change the arrow to down with cost = 1 --> (1, 3) --> (1, 2) --> (1, 1) --> (1, 0) change the arrow to down with cost = 1 --> (2, 0) --> (2, 1) --> (2, 2) --> (2, 3) change the arrow to down with cost = 1 --> (3, 3)
    // The total cost = 3.

    vector<vector<int>> grid = {{1,1,1,1},{2,2,2,2},{1,1,1,1},{2,2,2,2}};
    EXPECT_EQ(this->s.minCost(grid), 3);
}
TEST_F(CLASS_NAME, __LINE__)
{
    vector<vector<int>> grid = {{1,1,3},{3,2,2},{1,1,4}};
    EXPECT_EQ(this->s.minCost(grid), 0);
}
TEST_F(CLASS_NAME, __LINE__)
{
    vector<vector<int>> grid = {{1,2},{4,3}};
    EXPECT_EQ(this->s.minCost(grid), 1);
}
TEST_F(CLASS_NAME, __LINE__)
{
    vector<vector<int>> grid = {{2,2,2},{2,2,2}};
    EXPECT_EQ(this->s.minCost(grid), 3);
}



int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}