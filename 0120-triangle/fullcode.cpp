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



/* https://leetcode.com/problems/triangle/
 * @lc app=leetcode id=120 lang=cpp
 * [120] Triangle

Given a triangle array, return the minimum path sum from top to bottom.
For each step, you may move to an adjacent number of the row below. More formally, if you are on index i on the current row, you may move to either index i or index i + 1 on the next row.

삼각형 배열이 주어졌을 때, 위에서 아래로 가는 최소 경로 합을 반환하세요.
각 단계에서 아래 행의 인접한 숫자로 이동할 수 있습니다. 더 자세히 말하면, 현재 행의 인덱스 i에 있을 때 다음 행의 인덱스 i 또는 인덱스 i + 1로 이동할 수 있습니다.

Constraints:
1 <= triangle.length <= 200
triangle[0].length == 1
triangle[i].length == triangle[i - 1].length + 1
-10**4 <= triangle[i][j] <= 10**4
 */

// @lc code=start
class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        vector<vector<int>> dp;
        for (int i = 0; i < n; i++) {
            dp.push_back(vector<int>(i + 1, 0));
        }
        dp[0][0] = triangle[0][0];
        for (int i = 1; i < n; i++) {
            dp[i][0] = dp[i -1][0] + triangle[i][0];
            dp[i][i] = dp[i - 1][i - 1] + triangle[i][i];
            for (int j = 1; j < i; j++) {
                dp[i][j] = min(dp[i - 1][j - 1], dp[i - 1][j]) + triangle[i][j];
            }
        }
        int res = dp[n - 1][0];
        for (int i = 1; i < n; i++) {
            res = min(res, dp[n - 1][i]);
        }
        return res;
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
    // Input: triangle = [[2],[3,4],[6,5,7],[4,1,8,3]]
    // Output: 11
    // Explanation: The triangle looks like:
    //    2
    //   3 4
    //  6 5 7
    // 4 1 8 3
    // The minimum path sum from top to bottom is 2 + 3 + 5 + 1 = 11 (underlined above).

	vector<vector<int>> triangle = {{2},{3,4},{6,5,7},{4,1,8,3}};
	EXPECT_EQ(this->s.minimumTotal(triangle), 11);
}

TEST_F(CLASS_NAME, __LINE__)
{
    // Example 2:
    // Input: triangle = [[-10]]
    // Output: -10

	vector<vector<int>> triangle = {{-10}};
	EXPECT_EQ(this->s.minimumTotal(triangle), -10);
}



int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
