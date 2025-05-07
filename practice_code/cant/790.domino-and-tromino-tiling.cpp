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



/* https://leetcode.com/problems/domino-and-tromino-tiling/
 * @lc app=leetcode id=790 lang=cpp
 * [790] Domino and Tromino Tiling

You have two types of tiles: a 2 x 1 domino shape and a tromino shape. You may rotate these shapes.

Given an integer n, return the number of ways to tile an 2 x n board. Since the answer may be very large, return it modulo 109 + 7.

In a tiling, every square must be covered by a tile. Two tilings are different if and only if there are two 4-directionally adjacent cells on the board such that exactly one of the tilings has both squares occupied by a tile.

당신은 두 가지 타입의 타일을 가지고 있습니다: 2 x 1 도미노 모양과 트로미노 모양입니다. 이 모양들을 회전시킬 수 있습니다.

정수 n이 주어졌을 때, 2 x n 보드를 타일로 채우는 방법의 수를 반환하세요. 답이 매우 클 수 있으므로, 10^9 + 7로 나눈 나머지를 반환하세요.

타일링에서 모든 정사각형은 타일로 덮여 있어야 합니다. 두 타일링이 서로 다른 경우는 보드에 4방향으로 인접한 두 셀이 있어 정확히 하나의 타일링만 두 정사각형 모두 타일로 덮여 있는 경우입니다.

Constraints:

1 <= n <= 1000

n = 1, 1
n = 2, 2
n = 3, 5
n = 4, 9 (1*3 2*2)
n = 5, 10 + 8 (18)


|||||
|||=
||=|
|=||
=|||
|==
=|=
==|

 */

// @lc code=start
class Solution {
public:
    int numTilings(int n) {

        const int MOD = 1000000007;

        if (n <= 2) {
            return n;
        }
        vector<array<long long, 3>>dp(n + 1, {0, 0, 0});

        dp[1][0] = 1; // | 모양
        dp[1][1] = 0; // 만들 수 없음
        dp[1][2] = 0; // 만들 수 없음

        dp[2][0] = 2; // || = 모양
        dp[2][1] = 1; // ㄴ 모양
        dp[2][2] = 1; // ㄱ 모양

        for (int i = 3; i < n; i++) {
            dp[i][0] = (dp[i-1][0] + dp[i-2][0] + dp[i-1][1] + dp[i-1][2]) % MOD;
            dp[i][1] = (dp[i-2][0] + dp[i-1][2]) % MOD;
            dp[i][2] = (dp[i-2][0] + dp[i-1][1]) % MOD;
        }

        return (dp[n-1][0] + dp[n-2][0] + dp[n-1][1] + dp[n-1][2]) % MOD;
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
    EXPECT_EQ(this->s.numTilings(3), 5);
}

TEST_F(CLASS_NAME, __LINE__)
{
    EXPECT_EQ(this->s.numTilings(1), 1);
}


int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
