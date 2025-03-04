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



/* https://leetcode.com/problems/check-if-number-is-a-sum-of-powers-of-three/?envType=daily-question&envId=2025-03-04
 * @lc app=leetcode id=1780 lang=cpp
 * [1780] Check if Number is a Sum of Powers of Three

Given an integer n, return true if it is possible to represent n as the sum of distinct powers of three. Otherwise, return false.
An integer y is a power of three if there exists an integer x such that y == 3x.

정수 n이 주어졌을 때, n을 서로 다른 3의 거듭제곱의 합으로 표현할 수 있으면 true를 반환하고, 그렇지 않으면 false를 반환합니다.
정수 y가 3의 거듭제곱이라는 것은 y == 3^x를 만족하는 정수 x가 존재한다는 것을 의미합니다.

Constraints:
1 <= n <= 10**7 (10,000,000)
 */

// @lc code=start
class Solution {
private:
    static const int MAX_POWER = 10000000;
    vector<int> powers;
    bool dp(int n, int idx) {
        if (n == 0) return true;
        if (n < 0) return false;
        if (idx >= this->powers.size()) return false;
        // int sum = 0;
        // for (int i = idx; i < this->powers.size(); i++) {
        //     sum += this->powers[i];
        // }
        // if (sum == n) return true;
        // if (sum > n) return false;

        if (dp(n - this->powers[idx], idx + 1)) return true;
        if (dp(n, idx + 1)) return true;
        return false;
    }
public:
    bool checkPowersOfThree(int n) {
        int power = 1;
        while (power <= this->MAX_POWER) {
            this->powers.insert(this->powers.begin(), power);
            power *= 3;
        }
        int i;
        for (i = 0; i < this->powers.size(); i++) {
            if (this->powers[i] == n) {
                return true;
            }
            if (this->powers[i] < n) {
                break;
            }
        }
        return dp(n, i);
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
	// Output: true
	// Explanation: 12 = (3**1) + (3**2)
    EXPECT_EQ(this->s.checkPowersOfThree(12), true);
}

TEST_F(CLASS_NAME, __LINE__)
{
	// Example 2:
	// Input: n = 91
	// Output: true
	// Explanation: 91 = (3**0) + (3**2) + (3**4)
    EXPECT_EQ(this->s.checkPowersOfThree(91), true);
}

TEST_F(CLASS_NAME, __LINE__)
{
	// Example 3:
	// Input: n = 21
	// Output: false
    EXPECT_EQ(this->s.checkPowersOfThree(21), false);
}


int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
