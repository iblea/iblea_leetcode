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



/* https://leetcode.com/problems/maximal-square/description/
 * @lc app=leetcode id=221 lang=cpp
 * [221] Maximal Square

Given an m x n binary matrix filled with 0's and 1's, find the largest square containing only 1's and return its area.

Constraints:
m == matrix.length
n == matrix[i].length
1 <= m, n <= 300
matrix[i][j] is '0' or '1'.
 */

// @lc code=start
class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int largest_square = 0;

        int ylen = matrix.size();
        int xlen = matrix[0].size();

        // dp[i][j]는 (i,j)를 우측 하단 꼭지점으로 하는 최대 정사각형의 한 변의 길이
        vector<vector<int>> dp(ylen, vector<int>(xlen, 0));

        for (int i = 0; i < ylen; i++) {
            dp[i][0] = matrix[i][0] - '0';
            largest_square = max(largest_square, dp[i][0]);
        }
        for (int i = 0; i < xlen; i++) {
            dp[0][i] = matrix[0][i] - '0';
            largest_square = max(largest_square, dp[0][i]);
        }

        for (int i = 1; i < ylen; i++) {
            for (int j = 1; j < xlen; j++) {
                if (matrix[i][j] == '1') {
                    dp[i][j] = min({dp[i-1][j], dp[i][j-1], dp[i-1][j-1]}) + 1;
                    largest_square = max(largest_square, dp[i][j]);
                }
            }
        }
        return largest_square * largest_square;
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
    // Input: matrix = [["1","0","1","0","0"],["1","0","1","1","1"],["1","1","1","1","1"],["1","0","0","1","0"]]
    // Output: 4

    vector<vector<char>> matrix = {
        {'1', '0', '1', '0', '0'},
        {'1', '0', '1', '1', '1'},
        {'1', '1', '1', '1', '1'},
        {'1', '0', '0', '1', '0'}
    };
	EXPECT_EQ(this->s.maximalSquare(matrix), 4);
}

TEST_F(CLASS_NAME, __LINE__)
{
    // Example 2:
    // Input: matrix = [["0","1"],["1","0"]]
    // Output: 1

    vector<vector<char>> matrix = {
        {'0', '1'},
        {'1', '0'}
    };
    EXPECT_EQ(this->s.maximalSquare(matrix), 1);
}

TEST_F(CLASS_NAME, __LINE__)
{
    // Example 3:
    // Input: matrix = [["0"]]
    // Output: 0

    vector<vector<char>> matrix = {
        {'0'}
    };
    EXPECT_EQ(this->s.maximalSquare(matrix), 0);
}



int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
