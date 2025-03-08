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



/* https://leetcode.com/problems/closest-prime-numbers-in-range/description/?envType=daily-question&envId=2025-03-07
 * @lc app=leetcode id=2523 lang=cpp
 * [2523] Closest Prime Numbers in Range

Given two positive integers left and right, find the two integers num1 and num2 such that:
left <= num1 < num2 <= right .
Both num1 and num2 are prime numbers.
num2 - num1 is the minimum amongst all other pairs satisfying the above conditions.
Return the positive integer array ans = [num1, num2]. If there are multiple pairs satisfying these conditions, return the one with the smallest num1 value. If no such numbers exist, return [-1, -1].

두 양의 정수 left와 right가 주어졌을 때, 다음 조건을 만족하는 두 정수 num1과 num2를 찾으세요:
1. left <= num1 < num2 <= right
2. num1과 num2는 모두 소수입니다.
3. num2 - num1은 위 조건을 만족하는 다른 모든 쌍들 중에서 최소값입니다.
양의 정수 배열 ans = [num1, num2]를 반환하세요. 이러한 조건을 만족하는 쌍이 여러 개 있다면, num1 값이 가장 작은 쌍을 반환하세요. 그러한 숫자가 존재하지 않는다면 [-1, -1]을 반환하세요.

제약 조건:
1 <= left <= right <= 10^6
Constraints:
1 <= left <= right <= 10**6
 */

// @lc code=start
class Solution {
public:
    vector<int> closestPrimes(int left, int right) {
        // 에라토스테네스의 체?
        int diff = INT_MAX;
        vector<bool> isPrime(right + 1, true);
        // diff = min(diff, num2 - num1)
        // 소수를 찾아야 하는데 어떻게 찾음?
        isPrime[0] = isPrime[1] = false;
        int i;
        for (i = 2; i * i <= right; i++) {
            if (! isPrime[i]) continue;

            for (int j = i * i; j <= right; j += i) {
                isPrime[j] = false;
            }
        }

        vector<int> primes;
        int num1 = 0;
        int num2 = 0;
        vector<int> ans = {-1, -1};
        for (i = left; i <= right; i++) {
            if (! isPrime[i]) continue;

            num2 = i;
            i++;
            break;
        }

        int absval = 0;
        for (; i <= right; i++) {
            if (! isPrime[i]) continue;

            num1 = num2;
            num2 = i;
            absval = num2 - num1;
            if (absval < diff) {
                diff = absval;
                ans = {num1, num2};
            }
            i++;
        }
        return ans;
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
    // Input: left = 10, right = 19
    // Output: [11,13]
    // Explanation: The prime numbers between 10 and 19 are 11, 13, 17, and 19.
    // The closest gap between any pair is 2, which can be achieved by [11,13] or [17,19].
    // Since 11 is smaller than 17, we return the first pair.

    vector<int> result = this->s.closestPrimes(10, 19);
    EXPECT_EQ(result, vector<int>({11, 13}));
}

TEST_F(CLASS_NAME, __LINE__)
{
    // Example 2:
    // Input: left = 4, right = 6
    // Output: [-1,-1]
    // Explanation: There exists only one prime number in the given range, so the conditions cannot be satisfied.

    vector<int> result = this->s.closestPrimes(4, 6);
    EXPECT_EQ(result, vector<int>({-1, -1}));
}

TEST_F(CLASS_NAME, __LINE__)
{
    vector<int> result = this->s.closestPrimes(20, 40);
    EXPECT_EQ(result, vector<int>({29, 31}));
    // 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61 ...
    // 23, 29, 31, 37 -> 29, 31 (2)
}


int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
