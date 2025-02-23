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



/* https://leetcode.com/problems/count-numbers-with-unique-digits/
 * @lc app=leetcode id=357 lang=cpp
 * [357] Count Numbers with Unique Digits

Given an integer n, return the count of all numbers with unique digits, x, where 0 <= x < 10**n.
정수 n이 주어졌을 때, 0 <= x < 10**n 범위에서 모든 자릿수가 서로 다른 숫자 x의 개수를 반환하세요.

Constraints:
0 <= n <= 8
 */

// @lc code=start
class Solution {
public:
    int countNumbersWithUniqueDigits(int n) {
        // 0 -> 1 (0)
        // 1 -> 10 (0)
        // 2 -> 91 (9) (11,22,33,44,55,66,77,88,99)
        // 3 ->  (111, 121, 112, 211)

        if (n == 0) return 1;
        if (n == 1) return 10;

        int result = 10;
        int uniqueDigits = 9;
        int availableDigits = 9;


        for (int i = 2; i <= n; i++) {
            uniqueDigits *= availableDigits;
            result += uniqueDigits;
            availableDigits--;
        }
        return result;
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
    // Input: n = 2
    // Output: 91
    // Explanation: The answer should be the total numbers in the range of 0 ≤ x < 100, excluding 11,22,33,44,55,66,77,88,99

	EXPECT_EQ(this->s.countNumbersWithUniqueDigits(2), 91);
}

TEST_F(CLASS_NAME, __LINE__)
{
    // Example 2:
    // Input: n = 0
    // Output: 1

	EXPECT_EQ(this->s.countNumbersWithUniqueDigits(0), 1);
}


int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
