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


/* https://leetcode.com/problems/maximum-amount-of-money-robot-can-earn/
 * 3418. Maximum Amount of Money Robot Can Earn | Medium

You are given an m x n grid. A robot starts at the top-left corner of the grid (0, 0) and wants to reach the bottom-right corner (m - 1, n - 1). The robot can move either right or down at any point in time.
The grid contains a value coins[i][j] in each cell:
	* If coins[i][j] >= 0, the robot gains that many coins.
	* If coins[i][j] < 0, the robot encounters a robber, and the robber steals the absolute value of coins[i][j] coins.
The robot has a special ability to neutralize robbers in at most 2 cells on its path, preventing them from stealing coins in those cells.

Note: The robot's total coins can be negative.
Return the maximum profit the robot can gain on the route.

m x n 격자가 주어집니다. 로봇은 격자의 왼쪽 상단 모서리 (0, 0)에서 출발하여 오른쪽 하단 모서리 (m - 1, n - 1)에 도달하고자 합니다. 로봇은 어느 시점에서든 오른쪽 또는 아래쪽으로 이동할 수 있습니다.
격자의 각 칸에는 coins[i][j] 값이 포함되어 있습니다:
	* coins[i][j] >= 0인 경우, 로봇은 해당 수만큼의 코인을 획득합니다.
	* coins[i][j] < 0인 경우, 로봇은 강도를 만나게 되며, 강도는 coins[i][j]의 절댓값만큼의 코인을 훔쳐 갑니다.
로봇은 경로상에서 최대 2개의 칸에 있는 강도를 무력화하여 해당 칸에서 코인을 빼앗기지 않도록 하는 특수 능력을 가지고 있습니다.

참고: 로봇의 총 코인 수는 음수가 될 수 있습니다.
로봇이 경로에서 얻을 수 있는 최대 이익을 반환하십시오.


 Constraints:
	* m == coins.length
	* n == coins[i].length
	* 1 <= m, n <= 500
	* -1000 <= coins[i][j] <= 1000

 */

// @leet start
class Solution {
public:
    int maximumAmount(vector<vector<int>>& coins) {
        const int NEG_INF = -1e9; // INF_MIN 안주는 이유, INF_MIN - 값 하면 언더플로우로 터짐.
        int ylen = coins.size();
        int xlen = coins[0].size();
        vector<vector<array<int, 3>>> dp(ylen, vector<array<int, 3>>(xlen, {NEG_INF, NEG_INF, NEG_INF}));

        dp[0][0][0] = coins[0][0];
        dp[0][0][1] = coins[0][0] < 0 ? 0 : NEG_INF;
        for (int i = 1; i < ylen; i++) {
            dp[i][0][0] = dp[i-1][0][0] + coins[i][0];
            if (coins[i][0] < 0) {
                int beaten, neutralize;

                // 2번 무력화부터
                beaten = dp[i-1][0][2] + coins[i][0];
                neutralize = dp[i-1][0][1];
                dp[i][0][2] = max(beaten, neutralize);
                // 1번 무력화 구함
                beaten = dp[i-1][0][1] + coins[i][0];
                neutralize = dp[i-1][0][0];
                dp[i][0][1] = max(beaten, neutralize);
            } else {
                dp[i][0][1] = dp[i-1][0][1] + coins[i][0];
                dp[i][0][2] = dp[i-1][0][2] + coins[i][0];
            }
        }
        for (int i = 1; i < xlen; i++) {
            dp[0][i][0] = dp[0][i-1][0] + coins[0][i];
            if (coins[0][i] < 0) {
                int beaten, neutralize;
                
                // 2번 무력화부터
                beaten = dp[0][i-1][2] + coins[0][i];
                neutralize = dp[0][i-1][1];
                dp[0][i][2] = max(beaten, neutralize);
                // 1번 무력화 구함
                beaten = dp[0][i-1][1] + coins[0][i];
                neutralize = dp[0][i-1][0];
                dp[0][i][1] = max(beaten, neutralize);
            } else {
                dp[0][i][1] = dp[0][i-1][1] + coins[0][i];
                dp[0][i][2] = dp[0][i-1][2] + coins[0][i];
            }
        }
        int cur_coin;
        int max_2;
        int max_1;
        for (int i = 1; i < ylen; i++) {
            for (int j = 1; j < xlen; j++) {
                cur_coin = coins[i][j];
                dp[i][j][0] = max(dp[i-1][j][0], dp[i][j-1][0]) + cur_coin;
                if (coins[i][j] < 0) {
                    // 2번 무력화부터
                    max_2 = max(dp[i-1][j][2], dp[i][j-1][2]) + cur_coin;
                    max_1 = max(dp[i-1][j][1], dp[i][j-1][1]);
                    dp[i][j][2] = max(max_2, max_1);
                    // 1번 무력화 구함
                    max_2 = max(dp[i-1][j][1], dp[i][j-1][1]) + cur_coin;
                    max_1 = max(dp[i-1][j][0], dp[i][j-1][0]);
                    dp[i][j][1] = max(max_2, max_1);
                } else {
                    dp[i][j][1] = max(dp[i-1][j][1], dp[i][j-1][1]) + cur_coin;
                    dp[i][j][2] = max(dp[i-1][j][2], dp[i][j-1][2]) + cur_coin;
                }
            }
        }

        return max(dp[ylen-1][xlen-1][0], max(dp[ylen-1][xlen-1][1], dp[ylen-1][xlen-1][2]));
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
    // Input: coins = [[0,1,-1],[1,-2,3],[2,-3,4]]
    // Output: 8
    // Explanation:
    // An optimal path for maximum coins is:
    // 	1. Start at (0, 0) with 0 coins (total coins = 0).
    // 	2. Move to (0, 1), gaining 1 coin (total coins = 0 + 1 = 1).
    // 	3. Move to (1, 1), where there's a robber stealing 2 coins. The robot uses one neutralization here, avoiding the robbery (total coins = 1).
    // 	4. Move to (1, 2), gaining 3 coins (total coins = 1 + 3 = 4).
    // 	5. Move to (2, 2), gaining 4 coins (total coins = 4 + 4 = 8).

    vector<vector<int>> coins = {{0,1,-1},{1,-2,3},{2,-3,4}};
    EXPECT_EQ(this->s.maximumAmount(coins), 8);
}

TEST_F(CLASS_NAME, __LINE__)
{
    // 󰛨 Example 2:
    // Input: coins = [[10,10,10],[10,10,10]]
    // Output: 40
    // Explanation:
    // An optimal path for maximum coins is:
    // 	1. Start at (0, 0) with 10 coins (total coins = 10).
    // 	2. Move to (0, 1), gaining 10 coins (total coins = 10 + 10 = 20).
    // 	3. Move to (0, 2), gaining another 10 coins (total coins = 20 + 10 = 30).
    // 	4. Move to (1, 2), gaining the final 10 coins (total coins = 30 + 10 = 40).

    vector<vector<int>> coins = {{10,10,10},{10,10,10}};
    EXPECT_EQ(this->s.maximumAmount(coins), 40);
}


int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
