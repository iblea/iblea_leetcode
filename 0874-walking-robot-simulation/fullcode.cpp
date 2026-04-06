#include <gtest/gtest.h>
#include <iostream>
#include <iomanip>
#include <algorithm>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <unordered_set>
#include <queue>
#include <array>
#include <any>

using namespace std;


/* https://leetcode.com/problems/walking-robot-simulation/
 * 874. Walking Robot Simulation | Medium

A robot on an infinite XY-plane starts at point (0, 0) facing north. The robot receives an array of integers commands, which represents a sequence of moves that it needs to execute. There are only three possible types of instructions the robot can receive:

	* -2: Turn left 90 degrees.
	* -1: Turn right 90 degrees.
	* 1 <= k <= 9: Move forward k units, one unit at a time.

Some of the grid squares are obstacles. The i^th obstacle is at grid point obstacles[i] = (x_i, y_i). If the robot runs into an obstacle, it will stay in its current location (on the block adjacent to the obstacle) and move onto the next command.
Return the maximum squared Euclidean distance that the robot reaches at any point in its path (i.e. if the distance is 5, return 25).

Note:
	* There can be an obstacle at (0, 0). If this happens, the robot will ignore the obstacle until it has moved off the origin. However, it will be unable to return to (0, 0) due to the obstacle.
	* North means +Y direction.
	* East means +X direction.
	* South means -Y direction.
	* West means -X direction.


무한한 XY 평면 위의 로봇이 점 (0, 0)에서 북쪽을 향한 채 시작합니다. 로봇은 실행해야 할 일련의 이동을 나타내는 정수 배열 commands를 입력받습니다. 로봇이 받을 수 있는 명령의 종류는 다음 세 가지뿐입니다:

	* -2: 왼쪽으로 90도 회전합니다.
	* -1: 오른쪽으로 90도 회전합니다.
	* 1 <= k <= 9: 한 번에 한 칸씩 k칸 앞으로 이동합니다.

격자의 일부 칸에는 장애물이 있습니다. i번째 장애물은 격자점 obstacles[i] = (x_i, y_i)에 위치합니다. 로봇이 장애물에 부딪히면 현재 위치(장애물에 인접한 칸)에 머무르고 다음 명령을 수행합니다.
로봇이 경로상의 어느 지점에서든 도달하는 유클리드 거리 제곱의 최댓값을 반환하십시오 (즉, 거리가 5이면 25를 반환합니다).

참고:
	* (0, 0)에 장애물이 있을 수 있습니다. 이 경우 로봇은 원점에서 벗어날 때까지 해당 장애물을 무시합니다. 그러나 장애물로 인해 (0, 0)으로 되돌아올 수는 없습니다.
	* 북쪽은 +Y 방향을 의미합니다.
	* 동쪽은 +X 방향을 의미합니다.
	* 남쪽은 -Y 방향을 의미합니다.
	* 서쪽은 -X 방향을 의미합니다.


 Constraints:
	* 1 <= commands.length <= 10^4
	* commands[i] is either -2, -1, or an integer in the range [1, 9].
	* 0 <= obstacles.length <= 10^4
	* -3 * 10^4 <= x_i, y_i <= 3 * 10^4
	* The answer is guaranteed to be less than 2^31.

 */
// @leet start
class Solution {
private:
    // 00: 북, 1: 동, 2: 남, 3: 서
    int direction;
    pair<int, int> current_position;
    void distance_change(int change_direction) {
        this->direction = (this->direction + 4 + change_direction) % 4;
    }
    void move_distance() {
        switch (this->direction) {
            case 0: this->current_position.second++; break;
            case 1: this->current_position.first++; break;
            case 2: this->current_position.second--; break;
            case 3: this->current_position.first--; break;
        }
    }
    void move_distance_reverse() {
        switch (this->direction) {
            case 0: this->current_position.second--; break;
            case 1: this->current_position.first--; break;
            case 2: this->current_position.second++; break;
            case 3: this->current_position.first++; break;
        }
    }

    int get_euclidean_distance() {
        return (this->current_position.first * this->current_position.first) + (this->current_position.second * this->current_position.second);
    }

    long long coord_hash(int x, int y) {
        return (long long)x * 60001 + y;
    }

public:
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        this->direction = 0;
        this->current_position = {0, 0};
        int max_distance = 0;

        unordered_set<long long> obstacle_set;
        for (auto &obstacle : obstacles) {
            obstacle_set.insert(coord_hash(obstacle[0], obstacle[1]));
        }

        for (auto command : commands) {
            if (command == -2) {
                this->distance_change(-1);
                continue;
            } else if (command == -1) {
                this->distance_change(1);
                continue;
            }

            int move_count = command;
            while (move_count--) {
                this->move_distance();
                if (obstacle_set.count(coord_hash(this->current_position.first, this->current_position.second))) {
                    this->move_distance_reverse();
                    break;
                }
            }
            max_distance = max(max_distance, get_euclidean_distance());
        }
        return max_distance;
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
    // Input: commands = [4,-1,3], obstacles = []
    // Output: 25
    // Explanation: 
    // The robot starts at (0, 0):
    // 	1. Move north 4 units to (0, 4).
    // 	2. Turn right.
    // 	3. Move east 3 units to (3, 4).
    // The furthest point the robot ever gets from the origin is (3, 4), which squared is 3^2 + 4^2 = 25 units away.

    vector<int> commands = {4,-1,3};
    vector<vector<int>> obstacles = {};
    EXPECT_EQ(this->s.robotSim(commands, obstacles), 25);
}

TEST_F(CLASS_NAME, __LINE__)
{
    // 󰛨 Example 2:
    // Input: commands = [4,-1,4,-2,4], obstacles = [[2,4]]
    // Output: 65
    // Explanation:
    // The robot starts at (0, 0):
    // 	1. Move north 4 units to (0, 4).
    // 	2. Turn right.
    // 	3. Move east 1 unit and get blocked by the obstacle at (2, 4), robot is at (1, 4).
    // 	4. Turn left.
    // 	5. Move north 4 units to (1, 8).
    // The furthest point the robot ever gets from the origin is (1, 8), which squared is 1^2 + 8^2 = 65 units away.

    vector<int> commands = {4,-1,4,-2,4};
    vector<vector<int>> obstacles = {{2,4}};
    EXPECT_EQ(this->s.robotSim(commands, obstacles), 65);
}

TEST_F(CLASS_NAME, __LINE__)
{
    // 󰛨 Example 3:
    // Input: commands = [6,-1,-1,6], obstacles = [[0,0]]
    // Output: 36
    // Explanation:
    // The robot starts at (0, 0):
    // 	1. Move north 6 units to (0, 6).
    // 	2. Turn right.
    // 	3. Turn right.
    // 	4. Move south 5 units and get blocked by the obstacle at (0,0), robot is at (0, 1).
    // The furthest point the robot ever gets from the origin is (0, 6), which squared is 6^2 = 36 units away.

    vector<int> commands = {6,-1,-1,6};
    vector<vector<int>> obstacles = {{0,0}};
    EXPECT_EQ(this->s.robotSim(commands, obstacles), 36);
}


int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
