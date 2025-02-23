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



/* https://leetcode.com/problems/perfect-squares/
 * @lc app=leetcode id=279 lang=cpp
 * [279] Perfect Squares

Given an integer n, return the least number of perfect square numbers that sum to n.
A perfect square is an integer that is the square of an integer; in other words, it is the product of some integer with itself. For example, 1, 4, 9, and 16 are perfect squares while 3 and 11 are not.

정수 n이 주어졌을 때, n을 만들 수 있는 완전제곱수들의 최소 개수를 반환하세요.
완전제곱수는 어떤 정수를 자기 자신과 곱한 결과입니다. 다시 말해, 어떤 정수의 제곱입니다. 예를 들어, 1, 4, 9, 16은 완전제곱수이지만 3과 11은 완전제곱수가 아닙니다.

Constraints:
1 <= n <= 10**4
 */

// @lc code=start
class Solution {
public:
    int numSquares(int n) {
        vector<int> dp(n + 1, INT_MAX);
        dp[0] = 0;

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j * j <= i; j++) {
                dp[i] = min(dp[i], dp[i - (j * j)] + 1);
            }
        }
        return dp[n];
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
	// Input: n = 12
	// Output: 3
	// Explanation: 12 = 4 + 4 + 4.

	EXPECT_EQ(this->s.numSquares(12), 3);
}

TEST_F(CLASS_NAME, __LINE__)
{
	// Example 2:
	// Input: n = 13
	// Output: 2
	// Explanation: 13 = 4 + 9.

	EXPECT_EQ(this->s.numSquares(13), 2);
}


int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
