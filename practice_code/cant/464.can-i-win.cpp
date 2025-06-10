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



/* https://leetcode.com/problems/can-i-win
 * @lc app=leetcode id=464 lang=cpp
 * [464] Can I Win

In the "100 game" two players take turns adding, to a running total, any integer from 1 to 10. The player who first causes the running total to reach or exceed 100 wins.
What if we change the game so that players cannot re-use integers?
For example, two players might take turns drawing from a common pool of numbers from 1 to 15 without replacement until they reach a total >= 100.
Given two integers maxChoosableInteger and desiredTotal, return true if the first player to move can force a win, otherwise, return false. Assume both players play optimally.

"100 게임"에서 두 플레이어가 번갈아 가면서 누적 합계에 1부터 10까지의 정수를 더합니다. 누적 합계를 100 이상으로 만드는 첫 번째 플레이어가 승리합니다.
플레이어들이 정수를 재사용할 수 없도록 게임을 변경하면 어떨까요?
예를 들어, 두 플레이어가 1부터 15까지의 공통 숫자 풀에서 번갈아 가면서 중복 없이 뽑아서 총합이 >= 100이 될 때까지 게임을 진행합니다.
두 정수 maxChoosableInteger와 desiredTotal이 주어졌을 때, 첫 번째로 움직이는 플레이어가 승리를 강제할 수 있으면 true를, 그렇지 않으면 false를 반환하세요. 두 플레이어 모두 최적으로 플레이한다고 가정합니다.

Constraints:
1 <= maxChoosableInteger <= 20
0 <= desiredTotal <= 300
 */
// @lc code=start
class Solution {
private:
    unordered_map<int, bool> memo;

    // 이러한 방식의 알고리즘을 mini-max (MiniMax 미니맥스 미니 맥스) 알고리즘이라고 한다.
    // 각 플레이어가 최선의 선택을 하면서 게임을 진행한다고 가정할 때 동작하는 게임 이론 알고리즘이다.
    bool func(int maxChoosableInteger, int desiredTotal, int state) {
        if (this->memo.find(state) != this->memo.end()) {
            return this->memo[state];
        }

        int bit;
        for (int i = 1; i <= maxChoosableInteger; i++) {

            bit = 1 << (i - 1);

            if (state & bit) {
                continue;
            }

            if (i >= desiredTotal) {
                this->memo[state] = true;
                return true;
            }
            if (!func(maxChoosableInteger, desiredTotal - i, state | bit)) {
                this->memo[state] = true;
                return true;
            }
        }

        this->memo[state] = false;
        return false;
    }

public:
    bool canIWin(int maxChoosableInteger, int desiredTotal) {
        if (desiredTotal <= maxChoosableInteger) {
            return true;
        }

        // 1부터 maxChoosableInteger까지의 합이 desiredTotal보다 크면 첫 번째 플레이어가 이길 수 없음
        int maxval = (1 + maxChoosableInteger) * maxChoosableInteger / 2;
        if (maxval == desiredTotal) {
            // 모든 숫자를 더한 합이 desiredTotal과 같으면 해당 값이 홀수인지, 짝수인지에 따라 승자가 결정됨.
            // ex) 1,2,3,4,5,6  21 이면 후수 필승
            // ex) 1,2,3,4,5    15 이면 선수 필승
            return maxChoosableInteger % 2 == 1;
        } else if (maxval > desiredTotal) {
            // 이 경우는 애초에 경기가 불가능함. (모든 숫자를 다 더해도 desiredTotal을 못 넘음)
            return false;
        }

        // 내가 이길 수 있는 경우를 단 하나라도 찾으면 된다.

        // 사용 가능한 숫자를 하나씩 시도
        // 그 숫자로 바로 이길 수 있으면 true
        // 아니면 상대 턴으로 넘어감. 상대 턴에서 상대가 이길 수 있는 경우의 수가 존재할 경우 false (상대가 지는 경우의 수가 존재하면 true)

        // 이렇게 해서 모든 경우에서 상대방이 이기면 false
        this->memo.clear();
        return func(maxChoosableInteger, desiredTotal, 0);
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
    // Input: maxChoosableInteger = 10, desiredTotal = 11
    // Output: false
    // Explanation:
    // No matter which integer the first player choose, the first player will lose.
    // The first player can choose an integer from 1 up to 10.
    // If the first player choose 1, the second player can only choose integers from 2 up to 10.
    // The second player will win by choosing 10 and get a total = 11, which is >= desiredTotal.
    // Same with other integers chosen by the first player, the second player will always win.

    // 첫 번째 플레이어가 어떤 정수를 선택하든 첫 번째 플레이어가 질 것입니다.
    // 첫 번째 플레이어는 1부터 10까지의 정수를 선택할 수 있습니다.
    // 첫 번째 플레이어가 1을 선택하면, 두 번째 플레이어는 2부터 10까지의 정수만 선택할 수 있습니다.
    // 두 번째 플레이어는 10을 선택하여 합계 = 11을 만들어 이기게 됩니다. 이는 >= desiredTotal입니다.
    // 첫 번째 플레이어가 선택하는 다른 정수들도 마찬가지로, 두 번째 플레이어가 항상 이기게 됩니다.

    EXPECT_EQ(this->s.canIWin(10, 11), false);
}

TEST_F(CLASS_NAME, __LINE__)
{
    // Example 2:
    // Input: maxChoosableInteger = 10, desiredTotal = 0
    // Output: true

    EXPECT_EQ(this->s.canIWin(10, 0), true);
}

TEST_F(CLASS_NAME, __LINE__)
{
    // Example 3:
    // Input: maxChoosableInteger = 10, desiredTotal = 1
    // Output: true

    EXPECT_EQ(this->s.canIWin(10, 1), true);
}




int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
