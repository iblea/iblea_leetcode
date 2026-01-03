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



/* https://leetcode.com/problems/last-day-where-you-can-still-cross
 * @lc app=leetcode id=1970 lang=cpp
 * [1970] Last Day Where You Can Still Cross

There is a 1-based binary matrix where 0 represents land and 1 represents water. You are given integers row and col representing the number of rows and columns in the matrix, respectively.
Initially on day 0, the entire matrix is land. However, each day a new cell becomes flooded with water. You are given a 1-based 2D array cells, where cells[i] = [(r)i, (c)i] represents that on the (i)th day, the cell on the ((r)i)th row and ((c)i)th column (1-based coordinates) will be covered with water (i.e., changed to 1).
You want to find the last day that it is possible to walk from the top to the bottom by only walking on land cells. You can start from any cell in the top row and end at any cell in the bottom row. You can only travel in the four cardinal directions (left, right, up, and down).
Return the last day where it is possible to walk from the top to the bottom by only walking on land cells.

0은 땅을, 1은 물을 나타내는 1-기반 이진 행렬이 있습니다. 행렬의 행과 열의 개수를 나타내는 정수 row와 col이 주어집니다.
처음 0일차에는 전체 행렬이 땅입니다. 그러나 매일 새로운 셀이 물에 잠기게 됩니다. 1-기반 2D 배열 cells가 주어지며, cells[i] = [(r)i, (c)i]는 i번째 날에 (r)i번째 행과 (c)i번째 열(1-기반 좌표)의 셀이 물로 덮인다는 것을 나타냅니다(즉, 1로 변경됨).
땅 셀만 밟고 맨 위에서 맨 아래까지 걸어갈 수 있는 마지막 날을 찾고자 합니다. 맨 위 행의 어느 셀에서든 출발할 수 있고, 맨 아래 행의 어느 셀에서든 도착할 수 있습니다. 네 가지 기본 방향(왼쪽, 오른쪽, 위, 아래)으로만 이동할 수 있습니다.
땅 셀만 밟고 맨 위에서 맨 아래까지 걸어갈 수 있는 마지막 날을 반환하세요.

Constraints:
2 <= row, col <= 2 * 10^4
4 <= row * col <= 2 * 10^4
cells.length == row * col
1 <= (r)i <= row
1 <= (c)i <= col
All the values of cells are unique.
 */
// @lc code=start
class Solution {
public:
    vector<int> parent, rank_;

    int find(int x) {
        if (parent[x] != x) {
            parent[x] = find(parent[x]);
        }
        return parent[x];
    }

    void unite(int x, int y) {
        int px = find(x), py = find(y);
        if (px == py) return;
        if (rank_[px] < rank_[py]) swap(px, py);
        parent[py] = px;
        if (rank_[px] == rank_[py]) rank_[px]++;
    }

    int latestDayToCross(int row, int col, vector<vector<int>>& cells) {
        // 맨 마지막 날부터 역순으로 진행하면서 union-find를 이용해 땅 셀만 밟고 맨 위에서 맨 아래까지 걸어갈 수 있는지 구한다.
        // 즉, union-find를 이용해 마지막 행과 첫 번째 행이 union으로 연결되는 시점이 곧 땅 셀만 밟고 맨 위에서 맨 아래까지 걸어갈 수 있는 마지막 날이라고 판단할 수 있다.

        int n = row * col;
        int top = n;        // 가상 노드: 첫 번째 행과 연결
        int bottom = n + 1; // 가상 노드: 마지막 행과 연결

        parent.resize(n + 2);
        rank_.resize(n + 2, 0);
        for (int i = 0; i < n + 2; i++) parent[i] = i;

        vector<vector<int>> grid(row, vector<int>(col, 1)); // 모든 셀이 물(1)
        int dirs[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

        // 역순으로 물을 빼면서 연결 확인
        for (int day = n - 1; day >= 0; day--) {
            int r = cells[day][0] - 1; // 0-indexed로 변환
            int c = cells[day][1] - 1;
            grid[r][c] = 0; // 땅으로 복원

            int idx = r * col + c;

            // 첫 번째 행이면 top과 연결
            if (r == 0) unite(idx, top);
            // 마지막 행이면 bottom과 연결
            if (r == row - 1) unite(idx, bottom);

            // 인접한 땅 셀과 연결
            for (auto& d : dirs) {
                int nr = r + d[0], nc = c + d[1];
                if (nr >= 0 && nr < row && nc >= 0 && nc < col && grid[nr][nc] == 0) {
                    unite(idx, nr * col + nc);
                }
            }

            // top과 bottom이 연결되면 이 날이 답
            if (find(top) == find(bottom)) {
                return day;
            }
        }

        return 0;
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
    // Input: row = 2, col = 2, cells = [[1,1],[2,1],[1,2],[2,2]]
    // Output: 2
    // Explanation: The above image depicts how the matrix changes each day starting from day 0.
    // The last day where it is possible to cross from top to bottom is on day 2.
    // 설명: 위 이미지는 0일차부터 시작하여 매일 행렬이 어떻게 변화하는지를 보여줍니다.
    // 위에서 아래로 건널 수 있는 마지막 날은 2일차입니다.

    vector<vector<int>> cells = { {1,1},{2,1},{1,2},{2,2} };
    EXPECT_EQ(this->s.latestDayToCross(2, 2, cells), 2);
}

TEST_F(CLASS_NAME, __LINE__)
{
    // Example 2:
    // Input: row = 2, col = 2, cells = [[1,1],[1,2],[2,1],[2,2]]
    // Output: 1
    // Explanation: The above image depicts how the matrix changes each day starting from day 0.
    // The last day where it is possible to cross from top to bottom is on day 1.
    // 설명: 위 이미지는 0일차부터 시작하여 매일 행렬이 어떻게 변하는지를 보여줍니다.
    // 위에서 아래로 건널 수 있는 마지막 날은 1일차입니다.

    vector<vector<int>> cells = { {1,1},{1,2},{2,1},{2,2} };
    EXPECT_EQ(this->s.latestDayToCross(2, 2, cells), 1);
}

TEST_F(CLASS_NAME, __LINE__)
{
    // Example 3:
    // Input: row = 3, col = 3, cells = [[1,2],[2,1],[3,3],[2,2],[1,1],[1,3],[2,3],[3,2],[3,1]]
    // Output: 3
    // Explanation: The above image depicts how the matrix changes each day starting from day 0.
    // The last day where it is possible to cross from top to bottom is on day 3.
    // 설명: 위 이미지는 0일차부터 시작하여 매일 행렬이 어떻게 변하는지를 보여줍니다.
    // 위에서 아래로 건널 수 있는 마지막 날은 3일차입니다.

    vector<vector<int>> cells = { {1,2},{2,1},{3,3},{2,2},{1,1},{1,3},{2,3},{3,2},{3,1} };
    EXPECT_EQ(this->s.latestDayToCross(3, 3, cells), 3);
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
