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



/*
 * https://leetcode.com/problems/valid-sudoku/
 * @lc app=leetcode id=36 lang=cpp
 * [36] Valid Sudoku

Determine if a 9 x 9 Sudoku board is valid. Only the filled cells need to be validated according to the following rules:

Each row must contain the digits 1-9 without repetition.
Each column must contain the digits 1-9 without repetition.
Each of the nine 3 x 3 sub-boxes of the grid must contain the digits 1-9 without repetition.

Note:
A Sudoku board (partially filled) could be valid but is not necessarily solvable.
Only the filled cells need to be validated according to the mentioned rules.

⏺ 9x9 스도쿠 보드가 유효한지 확인하라. 채워진 셀만 다음 규칙에 따라 검증하면 된다:

- 각 행은 1-9의 숫자를 중복 없이 포함해야 한다.
- 각 열은 1-9의 숫자를 중복 없이 포함해야 한다.
- 그리드의 9개 3x3 서브박스 각각은 1-9의 숫자를 중복 없이 포함해야 한다.

참고:
스도쿠 보드(부분적으로 채워진)는 유효할 수 있지만 반드시 풀 수 있는 것은 아니다.
언급된 규칙에 따라 채워진 셀만 검증하면 된다.

Constraints:

board.length == 9
board[i].length == 9
board[i][j] is a digit 1-9 or '.'.

 */
// @lc code=start
class Solution {
private:
    static constexpr array<pair<int, int>, 9> three_by_three_box = {{
        {0, 0}, {0, 1}, {0, 2},
        {1, 0}, {1, 1}, {1, 2},
        {2, 0}, {2, 1}, {2, 2}
    }};
public:
    Solution() { }
    bool isValidSudoku(vector<vector<char>>& board) {

        // check row
        for (int i = 0; i < 9; i++) {
            set<int> s;
            for (int j = 0; j < 9; j++) {
                if (board[i][j] == '.') {
                    continue;
                }
                if (s.find(board[i][j]) != s.end()) {
                    return false;
                }
                s.insert(board[i][j]);
            }
        }

        for (int j = 0; j < 9; j++) {
            set<int> s;
            for (int i = 0; i < 9; i++) {
                if (board[i][j] == '.') {
                    continue;
                }
                if (s.find(board[i][j]) != s.end()) {
                    return false;
                }
                s.insert(board[i][j]);
            }
        }

        for (int row = 0; row < 9; row += 3) {

            for (int col = 0; col < 9; col += 3) {
                set<int> s;
                for (pair<int, int> pos : this->three_by_three_box) {
                    if (board[row + pos.first][col + pos.second] == '.') {
                        continue;
                    }
                    if (s.find(board[row + pos.first][col + pos.second]) != s.end()) {
                        return false;
                    }
                    s.insert(board[row + pos.first][col + pos.second]);
                }
            }
        }
        return true;
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
    CLASS_NAME() { }
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
    vector<vector<char>> board = {{'5','3','.','.','7','.','.','.','.'},
                                {'6','.','.','1','9','5','.','.','.'},
                                {'.','9','8','.','.','.','.','6','.'},
                                {'8','.','.','.','6','.','.','.','3'},
                                {'4','.','.','8','.','3','.','.','1'},
                                {'7','.','.','.','2','.','.','.','6'},
                                {'.','6','.','.','.','.','2','8','.'},
                                {'.','.','.','4','1','9','.','.','5'},
                                {'.','.','.','.','8','.','.','7','9'}};
    EXPECT_EQ(this->s.isValidSudoku(board), true);
}

TEST_F(CLASS_NAME, __LINE__)
{
    vector<vector<char>> board = {{'8','3','.','.','7','.','.','.','.'},
                                {'6','.','.','1','9','5','.','.','.'},
                                {'.','9','8','.','.','.','.','6','.'},
                                {'8','.','.','.','6','.','.','.','3'},
                                {'4','.','.','8','.','3','.','.','1'},
                                {'7','.','.','.','2','.','.','.','6'},
                                {'.','6','.','.','.','.','2','8','.'},
                                {'.','.','.','4','1','9','.','.','5'},
                                {'.','.','.','.','8','.','.','7','9'}};
    EXPECT_EQ(this->s.isValidSudoku(board), false);
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
