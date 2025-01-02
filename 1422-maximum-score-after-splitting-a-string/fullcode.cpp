#include <gtest/gtest.h>
#include <iostream>
#include <iomanip>
#include <algorithm>
#include <vector>
#include <string>
#include <map>

using namespace std;


/*
https://leetcode.com/problems/maximum-score-after-splitting-a-string/description/?envType=daily-question&envId=2025-01-01

1422. Maximum Score After Splitting a String
Given a string s of zeros and ones, return the maximum score after splitting the string into two non-empty substrings (i.e. left substring and right substring).
The score after splitting a string is the number of zeros in the left substring plus the number of ones in the right substring.

0과 1로 이루어진 문자열 s가 주어질 때, 이 문자열을 두 개의 비어있지 않은 부분 문자열(즉, 왼쪽 부분 문자열과 오른쪽 부분 문자열)로 나눈 후의 최대 점수를 반환하세요.
문자열을 나눈 후의 점수는 왼쪽 부분 문자열에 있는 0의 개수와 오른쪽 부분 문자열에 있는 1의 개수의 합입니다.

Example 1:
Input: s = "011101"
Output: 5
Explanation:
All possible ways of splitting s into two non-empty substrings are:
left = "0" and right = "11101", score = 1 + 4 = 5
left = "01" and right = "1101", score = 1 + 3 = 4
left = "011" and right = "101", score = 1 + 2 = 3
left = "0111" and right = "01", score = 1 + 1 = 2
left = "01110" and right = "1", score = 2 + 1 = 3

Example 2:
Input: s = "00111"
Output: 5
Explanation: When left = "00" and right = "111", we get the maximum score = 2 + 3 = 5
Example 3:

Input: s = "1111"
Output: 3

Constraints:
2 <= s.length <= 500
The string s consists of characters '0' and '1' only.
*/


class Solution {
public:
    int maxScore(string s) {
        int max_score = 0;
        int zero_count = 0;
        int one_count = 0;
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == '1') {
                one_count++;
            }
        }

        int n = s.length() - 1;
        for (int l = 0; l < n; l++) {
            if (s[l] == '0') {
                zero_count++;
            } else {
                one_count--;
            }

            max_score = max(max_score, zero_count + one_count);
        }
        return max_score;
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
	EXPECT_EQ(this->s.maxScore("011101"), 5);
}

TEST_F(CLASS_NAME, __LINE__)
{
	EXPECT_EQ(this->s.maxScore("00111"), 5);
}

TEST_F(CLASS_NAME, __LINE__)
{
	EXPECT_EQ(this->s.maxScore("1111"), 3);
}

TEST_F(CLASS_NAME, __LINE__)
{
	EXPECT_EQ(this->s.maxScore("010"), 2);
}

TEST_F(CLASS_NAME, __LINE__)
{
	EXPECT_EQ(this->s.maxScore("0011100011"), 7);
}

TEST_F(CLASS_NAME, __LINE__)
{
	EXPECT_EQ(this->s.maxScore("00000"), 4);
}

TEST_F(CLASS_NAME, __LINE__)
{
	EXPECT_EQ(this->s.maxScore("11111"), 4);
}



int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}