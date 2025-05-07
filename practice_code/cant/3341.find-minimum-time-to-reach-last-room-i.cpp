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



/* https://leetcode.com/problems/find-minimum-time-to-reach-last-room-i/
 * @lc app=leetcode id=3341 lang=cpp
 * [3341] Find Minimum Time to Reach Last Room I

There is a dungeon with n x m rooms arranged as a grid.
You are given a 2D array moveTime of size n x m, where moveTime[i][j] represents the minimum time in seconds when you can start moving to that room. You start from the room (0, 0) at time t = 0 and can move to an adjacent room. Moving between adjacent rooms takes exactly one second.
Return the minimum time to reach the room (n - 1, m - 1).
Two rooms are adjacent if they share a common wall, either horizontally or vertically.

n x m 방으로 이루어진 던전이 격자 형태로 배열되어 있습니다.
크기가 n x m인 2D 배열 moveTime이 주어지는데, moveTime[i][j]는 해당 방으로 이동을 시작할 수 있는 최소 시간(초)을 나타냅니다. 당신은 시간 t = 0에 방 (0, 0)에서 시작하며 인접한 방으로 이동할 수 있습니다. 인접한 방 사이를 이동하는 데는 정확히 1초가 걸립니다.
방 (n - 1, m - 1)에 도달하는 최소 시간을 반환하세요.
두 방은 수평 또는 수직으로 공통 벽을 공유하는 경우 인접해 있습니다.

Constraints:
2 <= n == moveTime.length <= 50
2 <= m == moveTime[i].length <= 50
0 <= moveTime[i][j] <= 10**9
 */

// 클래스 외부에 일반 함수로 구현
bool compare(const array<int, 3>& a, const array<int, 3>& b) {
    if (a[0] != b[0]) {
        return a[0] > b[0];
    }
    if (a[1] != b[1]) {
        return a[1] > b[1];
    }
    return a[2] > b[2];
}

// @lc code=start
class Solution {
private:
    static bool compare(const array<int, 3>& a, const array<int, 3>& b) {
        if (a[0] != b[0]) {
            return a[0] > b[0];
        }
        if (a[1] != b[1]) {
            return a[1] > b[1];
        }
        return a[2] > b[2];
    }

public:
    int minTimeToReach(vector<vector<int>>& moveTime) {

        const int n = moveTime.size();
        const int m = moveTime[0].size();
        const int goal_n = n - 1;
        const int goal_m = m - 1;

        vector<pair<int, int>> directions = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

        // priority_queue<array<int, 3>, vector<array<int, 3>>, greater<array<int, 3>>> pq;
        // 사용자 정의 비교자 (custom priority queue) (greater 대신 사용)
        auto comp = [](const array<int, 3>& a, const array<int, 3>& b) {
            if (a[0] != b[0]) {
                return a[0] > b[0];
            }
            if (a[1] != b[1]) {
                return a[1] > b[1];
            }
            return a[2] > b[2];
        };
        // std::bind나 람다를 사용해 비교자 전달
        priority_queue<array<int, 3>, vector<array<int, 3>>, decltype(comp)> pq(comp);
        auto comp1 = std::bind(&Solution::compare, this, std::placeholders::_1, std::placeholders::_2);
        priority_queue<array<int, 3>, vector<array<int, 3>>, decltype(comp1)> pq1(comp1);
        // 외부함수 사용
        priority_queue<array<int, 3>, vector<array<int, 3>>, decltype(&compare)> pq2(compare);
        // 멤버함수의 사용은 불가능
        priority_queue<array<int, 3>, vector<array<int, 3>>, decltype(&Solution::compare)> pq3(Solution::compare);

        vector<vector<bool>> visited(n, vector<bool>(m, false));

        // { time, x, y }
        pq.push({0, 0, 0});
        while (!pq.empty()) {
            auto [time, x, y] = pq.top();
            pq.pop();
            if (x == goal_n && y == goal_m) {
                return time;
            }

            if (visited[x][y]) {
                continue;
            }

            visited[x][y] = true;
            for (auto [dx, dy] : directions) {
                int nx = x + dx;
                int ny = y + dy;
                if (nx < 0 || nx >= n || ny < 0 || ny >= m) {
                    continue;
                }
                if (visited[nx][ny]) {
                    continue;
                }
                pq.push({max(time + 1, moveTime[nx][ny] + 1), nx, ny});
            }
        }
        return -1;
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
    // Explanation:
    // The minimum time required is 6 seconds.
    // At time t == 4, move from room (0, 0) to room (1, 0) in one second.
    // At time t == 5, move from room (1, 0) to room (1, 1) in one second.
    vector<vector<int>> moveTime = {{0,4}, {4, 4}};
    EXPECT_EQ(this->s.minTimeToReach(moveTime), 6);
}

TEST_F(CLASS_NAME, __LINE__)
{
    // Explanation:
    // The minimum time required is 3 seconds.
    // At time t == 0, move from room (0, 0) to room (1, 0) in one second.
    // At time t == 1, move from room (1, 0) to room (1, 1) in one second.
    // At time t == 2, move from room (1, 1) to room (1, 2) in one second.
    vector<vector<int>> moveTime = {{0, 0, 0}, {0, 0, 0}};
    EXPECT_EQ(this->s.minTimeToReach(moveTime), 3);
}

TEST_F(CLASS_NAME, __LINE__)
{
    vector<vector<int>> moveTime = {{0, 1}, {1, 2}};
    EXPECT_EQ(this->s.minTimeToReach(moveTime), 3);
}



int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
