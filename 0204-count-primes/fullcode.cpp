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



/* https://leetcode.com/problems/count-primes/
 * @lc app=leetcode id=204 lang=cpp
 * [204] Count Primes

Given an integer n, return the number of prime numbers that are strictly less than n.
정수 n이 주어졌을 때, n보다 작은 소수의 개수를 반환하세요.

Constraints:
0 <= n <= 5 * (10**6)
 */

// @lc code=start
class Solution {
public:
    int countPrimes(int n) {
        if (n <= 2) return 0;

        vector<bool> isPrime(n, true);
        isPrime[0] = isPrime[1] = false;

        for (int i = 2; i * i < n; i++) {
            if (isPrime[i]) {
                for (int j = i * i; j < n; j += i) {
                    isPrime[j] = false;
                }
            }
        }
        return count(isPrime.begin(), isPrime.end(), true);
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
	// Input: n = 10
	// Output: 4
	// Explanation: There are 4 prime numbers less than 10, they are 2, 3, 5, 7.

	EXPECT_EQ(this->s.countPrimes(10), 4);
}

TEST_F(CLASS_NAME, __LINE__)
{
	// Example 2:
	// Input: n = 0
	// Output: 0

	EXPECT_EQ(this->s.countPrimes(0), 0);
}

TEST_F(CLASS_NAME, __LINE__)
{
	// Example 3:
	// Input: n = 1
	// Output: 0

	EXPECT_EQ(this->s.countPrimes(1), 0);
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
