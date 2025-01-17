#include <gtest/gtest.h>
#include <iostream>
#include <iomanip>
#include <algorithm>
#include <vector>
#include <string>
#include <list>
#include <map>

using namespace std;



/*
https://leetcode.com/problems/regular-expression-matching/
 * @lc app=leetcode id=10 lang=cpp
 * [10] Regular Expression Matching
Given an input string s and a pattern p, implement regular expression matching with support for '.' and '*' where:
- '.' Matches any single character.​​​​
- '*' Matches zero or more of the preceding element.
The matching should cover the entire input string (not partial).

Constraints:
- 1 <= s.length <= 20
- 1 <= p.length <= 20
- s contains only lowercase English letters.
- p contains only lowercase English letters, '.', and '*'.
- It is guaranteed for each appearance of the character '*', there will be a previous valid character to match.
- '*' 문자가 나타날 때마다 매칭할 수 있는 유효한 이전 문자가 있음이 보장됩니다.
 */

// @lc code=start
class Solution {

public:
    bool isMatch(string s, string p) {

        // 1. DP 테이블 정의
        // dp[i][j]: s의 처음부터 i번째까지의 부분문자열이 p의 처음부터 j번째까지의 패턴과 매칭되는지 여부
        int slen = s.size();
        int plen = p.size();
        vector<vector<bool>> dp(slen + 1, vector<bool>(plen + 1, false));

        // 2. 초기 조건
        // s가 비어있고 p가 비어있는 경우
        dp[0][0] = true;

        // 3. 패턴에 *가 있는 경우 (비어있는 경우를 체크하기 위해 * 다음 문자에 대한 flag를 체크한다.)
        for (int i = 2; i <= plen; i++) {
            if (p[i - 1] == '*') {
                // 패턴에 *가 있는 경우, 이전 문자에 대한 * 패턴을 체크한다.
                // a*b* -> 빈 문자도 매칭됨.
                // 0: [true, false, true, false, true]
                dp[0][i] = dp[0][i - 2];
            }
        }

        // aaaabbbaaa
        // a*bb*aa*
        // 101000000
        // 000000000
        // 000000000
        // 000000000
        // 000000000
        // 000000000
        // 000000000
        // 000000000
        // 000000000
        // 000000000
        // 000000000


        // abaaaaacdd
        //  ab.*c*
        // 1000000 ""
        // 0101000 a
        // 0011100 b
        // 0001100 a
        // 0000100 a
        // 0000100 a
        // 0000100 a
        // 0000100 a
        // 0000111 c
        // 0000101 d
        // 0000101 d
        for (int i = 1; i <= slen; i++) {
            for (int j = 1; j <= plen; j++) {
                // s인덱스 i까지에 대해 패턴인덱스 j까지에 대해 매칭되는지 체크
                if (p[j - 1] == '*') {
                    // if (j - 2 < 0)  continue;

                    // * 이전 문자를 0번 사용
                    if (dp[i][j-2]) {
                        dp[i][j] = true;
                        continue;
                    }
                    // * 이전 문자를 1번이상 사용.
                    // dp[i-1][j]가 매칭되어야 이전 문자까지 정규식이 맞다는 것을 보장하기 때문임.
                    if (dp[i-1][j] && (s[i-1] == p[j-2] || p[j-2] == '.')) {
                        dp[i][j] = true;
                        continue;
                    }
                    dp[i][j] = false;
                    // break;
                } else {
                    if (dp[i-1][j-1] && (s[i-1] == p[j-1] || p[j-1] == '.')) {
                        dp[i][j] = true;
                        continue;
                    }
                    dp[i][j] = false;
                    // break;
                }
            }
        }
        return dp[slen][plen];
    }

    /*
Intuition :
To solve the problem of regex matching with . and *, we utilize dynamic programming (DP). We define a DP table dp[i][j] where dp[i][j] is True if the first i characters of s match the first j characters of p, and False otherwise.

Approach :
1. Base Case: An empty pattern matches an empty string, so dp[0][0] = True.
2. Pattern with *: For patterns like a*, .*, or b*, * matches zero or more of the preceding element:
    - Zero Occurrence: dp[i][j] = dp[i][j-2] (skip * and its preceding element).
    - One or More Occurrences: dp[i][j] = dp[i-1][j] if s[i-1] matches p[j-2].
3. Pattern with .: A single . matches any character.
4. Character Match: When p[j-1] and s[i-1] are the same, we can directly match them.

Steps :
1. Initialize dp[0][0] as True and handle patterns with * that can match an empty string in the first row.
2. Populate dp[i][j] based on whether p[j-1] is *, . or a direct character match.
3. The final result is in dp[m][n], indicating whether the full s matches p.
    */

    bool isMatch_answer(string s, string p) {
        int m = s.size(), n = p.size();
        vector<vector<bool>> dp(m + 1, vector<bool>(n + 1, false));
        dp[0][0] = true;
        for (int j = 2; j <= n; j++) {
            if (p[j - 1] == '*') {
                dp[0][j] = dp[0][j - 2];
            }
        }
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                if (p[j - 1] == '*') {
                    dp[i][j] = dp[i][j - 2] || (dp[i - 1][j] && (s[i - 1] == p[j - 2] || p[j - 2] == '.'));
                } else {
                    dp[i][j] = dp[i - 1][j - 1] && (s[i - 1] == p[j - 1] || p[j - 1] == '.');
                }
            }
        }
        return dp[m][n];
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
	EXPECT_EQ(this->s.isMatch("aa", "a"), false);
}

TEST_F(CLASS_NAME, __LINE__)
{
	EXPECT_EQ(this->s.isMatch("aa", "a*"), true);
}

TEST_F(CLASS_NAME, __LINE__)
{
	EXPECT_EQ(this->s.isMatch("ab", ".*"), true);
}


TEST_F(CLASS_NAME, __LINE__)
{
	EXPECT_EQ(this->s.isMatch("abaaaaaddcd", "ab.*c"), false);
}

TEST_F(CLASS_NAME, __LINE__)
{
	EXPECT_EQ(this->s.isMatch("abaaaaaddcd", "ab.*cd"), true);
}

TEST_F(CLASS_NAME, __LINE__)
{
	EXPECT_EQ(this->s.isMatch("abaaaaaddcd", "ab.*d"), true);
}

TEST_F(CLASS_NAME, __LINE__)
{
	EXPECT_EQ(this->s.isMatch("abaaaaacddc", "ab.*c*"), true);
}

TEST_F(CLASS_NAME, __LINE__)
{
	EXPECT_EQ(this->s.isMatch("abaaaaaaaaaa", "ab.*aa"), true);
}

TEST_F(CLASS_NAME, __LINE__)
{
	EXPECT_EQ(this->s.isMatch("abaaaaaaaaaa", "ab.*aaaaaaa"), true);
}

TEST_F(CLASS_NAME, __LINE__)
{
	EXPECT_EQ(this->s.isMatch("abaaaaaaaaaa", "ab.*a"), true);
}

TEST_F(CLASS_NAME, __LINE__)
{
	EXPECT_EQ(this->s.isMatch("abaaaaaaaaaa", "ab.*ab"), false);
}

TEST_F(CLASS_NAME, __LINE__)
{
	EXPECT_EQ(this->s.isMatch("abaaaaacdd", "ab.*c*"), true);
}

TEST_F(CLASS_NAME, __LINE__)
{
	EXPECT_EQ(this->s.isMatch("abaaaaaddceeeed", "ab.*d.*d"), true);
}

TEST_F(CLASS_NAME, __LINE__)
{
	EXPECT_EQ(this->s.isMatch("abaaaaaddceeeed", "ab.*d.*e"), false);
}

TEST_F(CLASS_NAME, __LINE__)
{
	EXPECT_EQ(this->s.isMatch("abaaaaaddceeeed", "ab.*d.*ed*"), true);
}




int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}