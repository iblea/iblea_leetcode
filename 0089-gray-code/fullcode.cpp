#include <gtest/gtest.h>
#include <iostream>
#include <iomanip>
#include <algorithm>
#include <vector>
#include <string>
#include <map>

using namespace std;


/*
https://leetcode.com/problems/gray-code

89. Gray Code
An n-bit gray code sequence is a sequence of 2n integers where:
Every integer is in the inclusive range [0, 2n - 1],
The first integer is 0,
An integer appears no more than once in the sequence,
The binary representation of every pair of adjacent integers differs by exactly one bit, and
The binary representation of the first and last integers differs by exactly one bit.
Given an integer n, return any valid n-bit gray code sequence.

Example 1:
Input: n = 2
Output: [0,1,3,2]
Explanation:
The binary representation of [0,1,3,2] is [00,01,11,10].
- 00 and 01 differ by one bit
- 01 and 11 differ by one bit
- 11 and 10 differ by one bit
- 10 and 00 differ by one bit
[0,2,3,1] is also a valid gray code sequence, whose binary representation is [00,10,11,01].
- 00 and 10 differ by one bit
- 10 and 11 differ by one bit
- 11 and 01 differ by one bit
- 01 and 00 differ by one bit

Example 2:
Input: n = 1
Output: [0,1]

Constraints:
1 <= n <= 16

n-비트 그레이 코드 수열은 다음 조건을 만족하는 2^n개의 정수로 이루어진 수열입니다:

모든 정수는 [0, 2^n - 1] 범위 내에 있어야 합니다.
첫 번째 정수는 0입니다.
각 정수는 수열에서 한 번만 나타납니다.
인접한 두 정수의 이진 표현은 정확히 한 비트만 다릅니다.
첫 번째와 마지막 정수의 이진 표현도 정확히 한 비트만 달라야 합니다.
주어진 정수 n에 대해, 유효한 n-비트 그레이 코드 수열을 반환하면 됩니다.

예제 1: 입력: n = 2 출력: [0,1,3,2]

설명: [0,1,3,2]의 이진 표현은 [00,01,11,10]입니다.

00과 01은 한 비트만 다릅니다
01과 11은 한 비트만 다릅니다
11과 10은 한 비트만 다릅니다
10과 00은 한 비트만 다릅니다
[0,2,3,1]도 유효한 그레이 코드 수열이며, 이진 표현은 [00,10,11,01]입니다.

00과 10은 한 비트만 다릅니다
10과 11은 한 비트만 다릅니다
11과 01은 한 비트만 다릅니다
01과 00은 한 비트만 다릅니다

 */

class Solution {
public:
    vector<int> grayCode(int n) {
        if (n == 1) {
            return { 0, 1 };
        }
        vector<int> answer = { 0, 1 };

        for (int i = 1; i < n; i++) {
            int pow = 1 << i;

            int arrlen = answer.size();
            for (int j = arrlen - 1; j >= 0; j--) {
                answer.push_back(answer[j] + pow);
            }
        }
        return answer;

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
    vector<int> res = this->s.grayCode(2);
    vector<int> answer1 = { 0, 1, 3, 2 };
    vector<int> answer2 = { 0, 2, 3, 1 };
    if (res == answer1) {
        EXPECT_EQ(res, answer1);
        return ;
    } else if (res == answer2) {
        EXPECT_EQ(res, answer2);
        return ;
    } else {
        EXPECT_EQ(res, answer1);
        EXPECT_EQ(res, answer2);
    }
}

TEST_F(CLASS_NAME, __LINE__)
{
    vector<int> answer = { 0, 1 };
	EXPECT_EQ(this->s.grayCode(1), answer);
}


TEST_F(CLASS_NAME, __LINE__)
{
    vector<int> answer = { 0, 1, 3, 2, 6, 7, 5, 4 };
	EXPECT_EQ(this->s.grayCode(3), answer);
}

TEST_F(CLASS_NAME, __LINE__)
{
    vector<int> answer = { 0, 1, 3, 2, 6, 7, 5, 4, 12, 13, 15, 14, 10, 11, 9, 8 };
	EXPECT_EQ(this->s.grayCode(4), answer);
}



int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
