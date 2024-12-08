#include <gtest/gtest.h>
#include <iostream>
#include <iomanip>
#include <algorithm>
#include <vector>
#include <string>
#include <map>

using namespace std;


/*
Given an integer n, break it into the sum of k positive integers, where k >= 2, and maximize the product of those integers.
Return the maximum product you can get.

Constraints:

2 <= n <= 58

정수 n이 주어졌을 때, 이를 k개의 양의 정수의 합으로 나누고(단, k는 2 이상), 이 정수들의 곱이 최대가 되도록 하는 문제입니다. 이때 얻을 수 있는 최대 곱을 반환하면 됩니다.

예를 들어 설명하면:

n = 4인 경우

4 = 2 + 2 → 곱은 2 × 2 = 4
4 = 1 + 3 → 곱은 1 × 3 = 3
따라서 최대 곱은 4
n = 10인 경우

10 = 3 + 3 + 4 → 곱은 3 × 3 × 4 = 36
10 = 2 + 4 + 4 → 곱은 2 × 4 × 4 = 32
10 = 2 + 3 + 5 → 곱은 2 × 3 × 5 = 30
등등...
여러 가지 경우 중 최대 곱은 36
이처럼 주어진 수를 2개 이상의 정수로 분해하여 그 곱이 최대가 되는 값을 찾는 문제입니다.

 */

class Solution {
public:
    int integerBreak(int n) {

        // 2보다 작은 경우는 1을 반환
        if (n <= 2) return 1;

        // 3보다 작은 경우는 2를 반환
        if (n == 3) return 2;

        // 4보다 작은 경우는 4를 반환
        if (n == 4) return 4;


        // 5보다 큰 경우는 3으로 나누어서 곱을 계산
        // 3 으로 나누어서 곱을 계산한 값이 제일 큰 값

        // 3으로 나누어서 4가 나올 경우, 3 * 3 * 2 * 2 가 제일 큰 값

        if (n % 3 == 0) {
            return pow(3, n / 3);
        } else if (n % 3 == 1) {
            return 4 * pow(3, (n - 4) / 3);
        } else {
            return 2 * pow(3, (n - 2) / 3);
        }
    }
};



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
	EXPECT_EQ(this->s.integerBreak(2), 1);
}

TEST_F(CLASS_NAME, __LINE__)
{
	EXPECT_EQ(this->s.integerBreak(10), 36);
}


int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}