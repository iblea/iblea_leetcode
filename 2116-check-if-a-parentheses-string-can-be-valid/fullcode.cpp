#include <gtest/gtest.h>
#include <iostream>
#include <iomanip>
#include <algorithm>
#include <vector>
#include <string>
#include <map>

using namespace std;


/*
 * https://leetcode.com/problems/check-if-a-parentheses-string-can-be-valid/description/?envType=daily-question&envId=2025-01-12
 * @lc app=leetcode id=2116 lang=cpp
 *
 * [2116] Check if a Parentheses String Can Be Valid
A parentheses string is a non-empty string consisting only of '(' and ')'. It is valid if any of the following conditions is true:
It is ().
It can be written as AB (A concatenated with B), where A and B are valid parentheses strings.
It can be written as (A), where A is a valid parentheses string.
You are given a parentheses string s and a string locked, both of length n. locked is a binary string consisting only of '0's and '1's. For each index i of locked,
If locked[i] is '1', you cannot change s[i].
But if locked[i] is '0', you can change s[i] to either '(' or ')'.
Return true if you can make s a valid parentheses string. Otherwise, return false.

괄호 문자열은 '('와 ')'로만 구성된 비어 있지 않은 문자열입니다. 다음 조건 중 하나라도 참이면 유효합니다:
그것은 ()입니다.
AB로 쓸 수 있습니다 (A와 B가 연결된 경우), 여기서 A와 B는 유효한 괄호 문자열입니다.
(A)로 쓸 수 있습니다, 여기서 A는 유효한 괄호 문자열입니다.
괄호 문자열 s와 길이가 n인 문자열 locked가 주어집니다. locked는 '0'과 '1'로만 구성된 이진 문자열입니다. locked의 각 인덱스 i에 대해,
locked[i]가 '1'이면 s[i]를 변경할 수 없습니다.
하지만 locked[i]가 '0'이면 s[i]를 '(' 또는 ')'로 변경할 수 있습니다.
s를 유효한 괄호 문자열로 만들 수 있으면 true를 반환합니다. 그렇지 않으면 false를 반환합니다.

Constraints:
n == s.length == locked.length
1 <= n <= 10**5
s[i] is either '(' or ')'.
locked[i] is either '0' or '1'.
 */

// @lc code=start
class Solution {
public:
    bool canBeValid(string s, string locked) {
        cout << "s: " << s << endl;
        size_t slen = s.size();
        if (slen % 2 == 1) return false;

        int open_count = 0;
        int close_count = 0;

        int total_count = 0;
        for (int i = 0; i < slen; i++) {
            if (locked[i] == '1') {
                if (s[i] == ')') close_count++;
            }
            total_count = i + 1;
            if (total_count - close_count < close_count) {
                return false;
            }
        }
        for (int i = slen - 1; i >= 0; i--) {
            if (locked[i] == '1') {
                if (s[i] == '(') open_count++;
            }
            total_count = slen - i;
            if (total_count - open_count < open_count) {
                return false;
            }
        }

        return true;
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
	EXPECT_EQ(this->s.canBeValid("))()))", "010100"), true);
}

TEST_F(CLASS_NAME, __LINE__)
{
	EXPECT_EQ(this->s.canBeValid("()()", "0000"), true);
}

TEST_F(CLASS_NAME, __LINE__)
{
	EXPECT_EQ(this->s.canBeValid(")", "0"), false);
}

TEST_F(CLASS_NAME, __LINE__)
{
	EXPECT_EQ(this->s.canBeValid("(", "0"), false);
}


TEST_F(CLASS_NAME, __LINE__)
{
	EXPECT_EQ(this->s.canBeValid(")(", "00"), true);
}

TEST_F(CLASS_NAME, __LINE__)
{
	EXPECT_EQ(this->s.canBeValid(")(", "01"), false);
}

TEST_F(CLASS_NAME, __LINE__)
{
	EXPECT_EQ(this->s.canBeValid(")(", "10"), false);
}



int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}