#include <gtest/gtest.h>
#include <iostream>
#include <iomanip>
#include <algorithm>
#include <vector>
#include <string>
#include <map>

using namespace std;


/* https://leetcode.com/problems/map-of-highest-peak/?envType=daily-question&envId=2025-01-22
 * @lc app=leetcode id=1765 lang=cpp
 * [1765] Map of Highest Peak

You are given an integer matrix isWater of size m x n that represents a map of land and water cells.
- If isWater[i][j] == 0, cell (i, j) is a land cell.
- If isWater[i][j] == 1, cell (i, j) is a water cell.
You must assign each cell a height in a way that follows these rules:
- The height of each cell must be non-negative.
- If the cell is a water cell, its height must be 0.
- Any two adjacent cells must have an absolute height difference of at most 1. A cell is adjacent to another cell if the former is directly north, east, south, or west of the latter (i.e., their sides are touching).
Find an assignment of heights such that the maximum height in the matrix is maximized.
Return an integer matrix height of size m x n where height[i][j] is cell (i, j)'s height. If there are multiple solutions, return any of them.

m x n 크기의 정수 행렬 isWater가 주어지며, 이는 땅과 물 셀의 지도를 나타냅니다.
- isWater[i][j] == 0인 경우, 셀 (i, j)는 땅 셀입니다.
- isWater[i][j] == 1인 경우, 셀 (i, j)는 물 셀입니다.
다음 규칙에 따라 각 셀에 높이를 할당해야 합니다:
- 각 셀의 높이는 음수가 아니어야 합니다.
- 물 셀인 경우 높이는 0이어야 합니다.
- 인접한 두 셀의 높이 차이는 최대 1이어야 합니다. 셀은 다른 셀의 북쪽, 동쪽, 남쪽 또는 서쪽에 직접 위치할 때 인접한 것으로 간주됩니다(즉, 변이 맞닿아 있을 때).
행렬의 최대 높이가 최대화되도록 높이를 할당하세요.
m x n 크기의 정수 행렬 height를 반환하세요. 여기서 height[i][j]는 셀 (i, j)의 높이입니다. 여러 해결책이 있는 경우 그 중 하나를 반환하세요.

Constraints:
- m == isWater.length
- n == isWater[i].length
- 1 <= m, n <= 1000
- isWater[i][j] is 0 or 1.
- There is at least one water cell.

Note: This question is the same as 542: https://leetcode.com/problems/01-matrix/
 */

// @lc code=start
class Solution {
private:
    int ylen;
    int xlen;

    bool is_valid(int x, int y) {
        if (x < 0 || x >= this->xlen || y < 0 || y >= this->ylen) {
            return false;
        }
        return true;
    }

public:
    vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {
        this->ylen = isWater.size();
        this->xlen = isWater[0].size();

        vector<vector<int>> height(this->ylen, vector<int>(this->xlen, 1));
        vector<vector<bool>> visited(this->ylen, vector<bool>(this->xlen, 0));
        vector<pair<int, int>> directions = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        priority_queue<array<int, 3>, vector<array<int, 3>>, greater<array<int, 3>>> pq;

        int nx, ny ;
        for (int y = 0; y < this->ylen; y++) {
            for (int x = 0; x < this->xlen; x++) {
                if (isWater[y][x] == 0) {
                    continue;
                }
                height[y][x] = 0;
                visited[y][x] = true;
                for (auto& dir : directions) {
                    nx = x + dir.first;
                    ny = y + dir.second;
                    if (this->is_valid(nx, ny) && visited[ny][nx] == false) {
                        pq.push({height[y][x] + 1, nx, ny});
                    }
                }
            }
        }

        int max_height;
        while (!pq.empty()) {
            auto [h, x, y] = pq.top();
            pq.pop();
            if (! this->is_valid(x, y)) {
                continue;
            }
            if (visited[y][x]) {
                continue;
            }
            visited[y][x] = true;
            height[y][x] = h;
            for (auto& dir : directions) {
                nx = x + dir.first;
                ny = y + dir.second;
                if (this->is_valid(nx, ny)) {
                    if (visited[ny][nx] == false) {
                        pq.push({height[y][x] + 1, nx, ny});
                    }
                }
            }
        }
        return height;
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
    // Input: isWater = [[0,1],[0,0]]
    // Output: [[1,0],[2,1]]
    // Explanation: The image shows the assigned heights of each cell.
    // The blue cell is the water cell, and the green cells are the land cells.

    // 1 0
    // 2 1

    vector<vector<int>> isWater = {{0,1},{0,0}};
    vector<vector<int>> expected = {{1,0},{2,1}};
    EXPECT_EQ(this->s.highestPeak(isWater), expected);
}

TEST_F(CLASS_NAME, __LINE__)
{
    // Example 2:
    // Input: isWater = [[0,0,1],[1,0,0],[0,0,0]]
    // Output: [[1,1,0],[0,1,1],[1,2,2]]
    // Explanation: A height of 2 is the maximum possible height of any assignment.
    // Any height assignment that has a maximum height of 2 while still meeting the rules will also be accepted.

    // 1 1 0
    // 0 1 1
    // 1 2 2

    vector<vector<int>> isWater = {{0,0,1},{1,0,0},{0,0,0}};
    vector<vector<int>> expected = {{1,1,0},{0,1,1},{1,2,2}};
    EXPECT_EQ(this->s.highestPeak(isWater), expected);
}



int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}