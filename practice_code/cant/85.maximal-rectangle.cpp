#include <gtest/gtest.h>
#include <iostream>
#include <iomanip>
#include <algorithm>
#include <vector>
#include <string>
#include <map>

using namespace std;



/*
https://leetcode.com/problems/maximal-rectangle/description/
 * @lc app=leetcode id=85 lang=cpp
 * [85] Maximal Rectangle

Given a rows x cols binary matrix filled with 0's and 1's, find the largest rectangle containing only 1's and return its area.

행 x 열 크기의 0과 1로 채워진 이진 행렬이 주어지면, 1로만 이루어진 가장 큰 직사각형을 찾아 그 면적을 반환하세요.

Example 1:
Input: matrix = [["1","0","1","0","0"],["1","0","1","1","1"],["1","1","1","1","1"],["1","0","0","1","0"]]
Output: 6
Explanation: The maximal rectangle is shown in the above picture.

Example 2:
Input: matrix = [["0"]]
Output: 0

Example 3:
Input: matrix = [["1"]]
Output: 1

Constraints:
- rows == matrix.length
- cols == matrix[i].length
- 1 <= row, cols <= 200
- matrix[i][j] is '0' or '1'.
 */

// @lc code=start
class Solution {
public:

    int ySize;
    int xSize;

    int maximalRectangle1(vector<vector<char>>& matrix) {

        this->ySize = matrix.size();
        this->xSize = matrix[0].size();

        int maxArea = 0;
        vector<vector<pair<int, int>>> dp(this->ySize, vector<pair<int, int>>(this->xSize, {0, 0}));

        if (matrix[0][0] == '1') {
            dp[0][0] = {1, 1};
        }

        for (int y = 1; y < this->ySize; y++) {
            if (matrix[y][0] == '1') {
                if (dp[y-1][0].first == 0) {
                    dp[y][0].first = 1;
                    dp[y][0].second = 1;
                } else {
                    dp[y][0].first = dp[y-1][0].first + 1;
                    dp[y][0].second = 1;
                }
            }
        }
        for (int x = 0; x < this->xSize; x++) {
            if (matrix[0][x] == '1') {
                if (dp[0][x-1].first == 0) {
                    dp[0][x].first = 1;
                    dp[0][x].second = 1;
                } else {
                    dp[0][x].first = 1;
                    dp[0][x].second = dp[0][x-1].second + 1;
                }
            }
        }


        return maxArea;
    }


    /*
    The DP solution proceeds row by row, starting from the first row. Let the maximal rectangle area at row i and column j be computed by [right(i,j) - left(i,j)]*height(i,j).
    All the 3 variables left, right, and height can be determined by the information from previous row, and also information from the current row. So it can be regarded as a DP solution. The transition equations are:
    left(i,j) = max(left(i-1,j), cur_left), cur_left can be determined from the current row
    right(i,j) = min(right(i-1,j), cur_right), cur_right can be determined from the current row
    height(i,j) = height(i-1,j) + 1, if matrix[i][j]=='1';
    height(i,j) = 0, if matrix[i][j]=='0'
    The code is as below. The loops can be combined for speed but I separate them for more clarity of the algorithm.
    */
    int maximalRectangle(vector<vector<char> > &matrix) {
        if(matrix.empty()) return 0;
        const int sizeY = matrix.size();
        const int sizeX = matrix[0].size();
        int left[sizeX], right[sizeX], height[sizeX];
        fill_n(left,sizeX,0); fill_n(right,sizeX,sizeX); fill_n(height,sizeX,0);
        int maxA = 0;
        // for (int i = 0; i < sizeY; i++) {
        //     for (int j = 0; j < sizeX; j++) {
        //         cout << matrix[i][j] << " ";
        //     }
        //     cout << endl;
        // }
        // cout << endl;
        for (int i = 0; i < sizeY; i++) {
            int cur_left = 0, cur_right = sizeX;
            for (int j = 0; j < sizeX; j++) { // compute height (can do this from either side)
                if (matrix[i][j] == '1') {
                    height[j]++;
                } else {
                    height[j] = 0;
                }
            }
            for (int j = 0; j < sizeX; j++) { // compute left (from left to right)
                if (matrix[i][j] == '1') {
                    left[j] = max(left[j],cur_left);
                } else {
                    left[j] = 0;
                    cur_left = j + 1;
                }
            }
            // compute right (from right to left)
            for (int j = sizeX - 1; j >= 0; j--) {
                if (matrix[i][j] == '1') {
                    right[j] = min(right[j], cur_right);
                } else {
                    right[j] = sizeX;
                    cur_right = j;
                }
            }
            for (int j = 0; j < sizeX; j++) {
                maxA = max(maxA, (right[j] - left[j]) * height[j]);
            }
        }
        return maxA;
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
    // 1 0 1 0 0
    // 1 0 1 1 1
    // 1 1 1 1 1
    // 1 0 0 1 0
    vector<vector<char>> matrix = {{'1','0','1','0','0'}, {'1','0','1','1','1'}, {'1','1','1','1','1'}, {'1','0','0','1','0'}};
	EXPECT_EQ(this->s.maximalRectangle(matrix), 6);
}
TEST_F(CLASS_NAME, __LINE__)
{
    vector<vector<char>> matrix = {{'0'}};
	EXPECT_EQ(this->s.maximalRectangle(matrix), 0);
}
TEST_F(CLASS_NAME, __LINE__)
{
    vector<vector<char>> matrix = {{'1'}};
	EXPECT_EQ(this->s.maximalRectangle(matrix), 1);
}

TEST_F(CLASS_NAME, __LINE__)
{
    // 1 1 1 1 1
    // 0 1 1 1 1
    // 0 0 1 1 1
    vector<vector<char>> matrix = {{'1','1','1','1','1'}, {'0','1','1','1','1'}, {'0','0','1','1','1'}};
	EXPECT_EQ(this->s.maximalRectangle(matrix), 9);
}

TEST_F(CLASS_NAME, __LINE__)
{
    // 0 1 0 0
    // 1 1 1 1
    // 1 1 1 0
    // 0 1 1 0
    vector<vector<char>> matrix = {{'0','1','0','0'}, {'1','1','1','1'}, {'1','1','1','0'}, {'0','1','1','0'}};
	EXPECT_EQ(this->s.maximalRectangle(matrix), 6);
}

TEST_F(CLASS_NAME, __LINE__)
{
    // 0 1 0 0
    // 1 1 1 1
    // 1 1 1 0
    // 0 0 1 0
    vector<vector<char>> matrix = {{'0','1','0','0'}, {'1','1','1','1'}, {'1','1','1','0'}, {'0','0','1','0'}};
	EXPECT_EQ(this->s.maximalRectangle(matrix), 6);
}



int main(int argc, char **argv)
{
    printf("hello\n");
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}