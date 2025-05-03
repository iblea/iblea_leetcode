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



/* https://leetcode.com/problems/count-good-numbers/?envType=daily-question&envId=2025-04-13
 * @lc app=leetcode id=1922 lang=cpp
 * [1922] Count Good Numbers

A digit string is good if the digits (0-indexed) at even indices are even and the digits at odd indices are prime (2, 3, 5, or 7).

For example, "2582" is good because the digits (2 and 8) at even positions are even and the digits (5 and 2) at odd positions are prime. However, "3245" is not good because 3 is at an even index but is not even.
Given an integer n, return the total number of good digit strings of length n. Since the answer may be large, return it modulo 109 + 7.

A digit string is a string consisting of digits 0 through 9 that may contain leading zeros.



Example 1:

Input: n = 1
Output: 5
Explanation: The good numbers of length 1 are "0", "2", "4", "6", "8".
Example 2:

Input: n = 4
Output: 400
Example 3:

Input: n = 50
Output: 564908303


Constraints:

1 <= n <= 10**15
 */

// @lc code=start
class Solution {
private:
    // 지수 모듈러 연산의 최적화 알고리즘
    // base^exp % mod
    // 예) 20^500 % 1007 -> modPow(20,500,1007)
    // 500 -> 111110100(2)
    // 2로 나눠가면서 짝짝홀(계산)짝홀(계산)홀(계산)홀(계산)홀(계산)홀(계산)
    // 과 같이 계산해 값을 구함
    long long modPow(long long base, long long exp, long long mod) {
        long long result = 1;
        while (exp > 0) {
            if (exp % 2 == 1) {
                result = (result * base) % mod;
            }
            base = (base * base) % mod;
            exp /= 2;
        }
        return result;
    };
public:
    int countGoodNumbers(long long n) {
        // 1,100,10000 -> 짝홀짝홀짝 (1,3,5...)
        // 10, 1000, 100000 -> 짝홀짝홀짝홀 (2,4,6...)
        long long mod = pow(10, 9) + 7;
        long long result = modPow(20, n / 2, mod);

        if (n % 2 != 0) {
            result *= 5;
            result %= mod;
        }

        return (int)result;
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
	EXPECT_EQ(this->s.countGoodNumbers(1), 5);
}

TEST_F(CLASS_NAME, __LINE__)
{
	EXPECT_EQ(this->s.countGoodNumbers(4), 400);
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
