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



/* https://leetcode.com/problems/count-servers-that-communicate/description/?envType=daily-question&envId=2025-01-23
 * @lc app=leetcode id=1267 lang=cpp
 * [1267] Count Servers that Communicate

You are given a map of a server center, represented as a m * n integer matrix grid, where 1 means that on that cell there is a server and 0 means that it is no server. Two servers are said to communicate if they are on the same row or on the same column.
Return the number of servers that communicate with any other server.

서버 센터의 지도가 m * n 정수 행렬 grid로 주어집니다. 여기서 1은 해당 셀에 서버가 있음을 의미하고 0은 서버가 없음을 의미합니다. 두 서버가 같은 행이나 같은 열에 있을 때 서로 통신할 수 있다고 합니다.
다른 서버와 통신할 수 있는 서버의 수를 반환하세요.

Example 1:
Input: grid = [[1,0],[0,1]]
Output: 0
Explanation: No servers can communicate with others.

Example 2:
Input: grid = [[1,0],[1,1]]
Output: 3
Explanation: All three servers can communicate with at least one other server.

Example 3:
Input: grid = [[1,1,0,0],[0,0,1,0],[0,0,1,0],[0,0,0,1]]
Output: 4
Explanation: The two servers in the first row can communicate with each other. The two servers in the third column can communicate with each other. The server at right bottom corner can't communicate with any other server.

Constraints:
- m == grid.length
- n == grid[i].length
- 1 <= m <= 250
- 1 <= n <= 250
- grid[i][j] == 0 or 1

 */

// @lc code=start
class Solution {
public:
    int countServers(vector<vector<int>>& grid) {

        int count = 0;
        int ylen = grid.size();
        int xlen = grid[0].size();

        vector<int> x_can_communicate(xlen, 0);
        vector<int> y_can_communicate(ylen, 0);
        vector<pair<int, int>> server_pos;

        for (int y = 0; y < ylen; y++) {
            for (int x = 0; x < xlen; x++) {
                if (grid[y][x] == 1) {
                    server_pos.push_back({x, y});
                    x_can_communicate[x]++;
                    y_can_communicate[y]++;
                }
            }
        }

        for (auto [x, y] : server_pos) {
            if (x_can_communicate[x] > 1 || y_can_communicate[y] > 1) {
                count++;
            }
        }
        return count;
    }
    int countServers_ONLY_인접(vector<vector<int>>& grid) {
        int count = 0;
        int ylen = grid.size();
        int xlen = grid[0].size();

        vector<vector<bool>> visited(ylen, vector<bool>(xlen, false));
        queue<pair<int, int>> q;
        q.push({0, 0});
        visited[0][0] = true;
        vector<pair<int, int>> directions = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        int nx, ny;
        bool near1 = false;
        while (!q.empty()) {
            auto [y, x] = q.front();
            q.pop();
            near1 = false;
            for (auto [dx, dy] : directions) {
                nx = x + dx;
                ny = y + dy;
                if (nx < 0 || nx >= xlen || ny < 0 || ny >= ylen) {
                    // abnormal check
                    continue;
                }
                if (grid[ny][nx] == 1) {
                    near1 = true;
                }
                if (visited[ny][nx]) {
                    continue;
                }
                q.push({ny, nx});
                visited[ny][nx] = true;
            }
            if (grid[y][x] == 1 && near1) {
                count++;
            }
        }

        return count;
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
    // Input: grid = [[1,0],[0,1]]
    // Output: 0
    // Explanation: No servers can communicate with others.
	vector<vector<int>> grid = {{1,0},{0,1}};
	EXPECT_EQ(this->s.countServers(grid), 0);
}

TEST_F(CLASS_NAME, __LINE__)
{
    // Example 2:
    // Input: grid = [[1,0],[1,1]]
    // Output: 3
    // Explanation: All three servers can communicate with at least one other server.
	vector<vector<int>> grid = {{1,0},{1,1}};
	EXPECT_EQ(this->s.countServers(grid), 3);
}

TEST_F(CLASS_NAME, __LINE__)
{
    // Example 3:
    // Input: grid = [[1,1,0,0],[0,0,1,0],[0,0,1,0],[0,0,0,1]]
    // Output: 4
    // Explanation: The two servers in the first row can communicate with each other. The two servers in the third column can communicate with each other. The server at right bottom corner can't communicate with any other server.
    vector<vector<int>> grid = {{1,1,0,0},{0,0,1,0},{0,0,1,0},{0,0,0,1}};
	EXPECT_EQ(this->s.countServers(grid), 4);
}
TEST_F(CLASS_NAME, __LINE__)
{
    vector<vector<int>> grid = {{1,0,0,0,0}, {0,1,0,0,0}, {0,0,1,0,0}, {0,0,0,1,0}, {0,0,0,0,1}};
	EXPECT_EQ(this->s.countServers(grid), 0);
}


int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}