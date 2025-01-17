#include <gtest/gtest.h>
#include <iostream>
#include <iomanip>
#include <algorithm>
#include <vector>
#include <string>
#include <map>

using namespace std;



/* https://leetcode.com/problems/longest-palindromic-substring/
 * @lc app=leetcode id=5 lang=cpp
 * [5] Longest Palindromic Substring

Given a string s, return the longest palindromic substring in s.

Constraints:
- 1 <= s.length <= 1000
- s consist of only digits and English letters.

원본:    b  a  b  a  d
변환:  # b # a # b # a # d #
P[i]: 0 1 0 3 0 3 0 1 0 1 0
 */

// @lc code=start
class Solution {
public:
    string longestPalindrome(string s) {
        int slen = s.size();
        if (slen < 2) {
            return s;
        }
        // dp[i][j] : i 부터 j 까지의 문자열이 팰린드롬인지 여부
        // abbac -> dp[0][3] = true
        vector<vector<bool>> dp(slen, vector<bool>(slen, false));
        // 모든 길이가 1인 팰린드롬은 true
        for (int i = 0; i < slen; i++) {
            dp[i][i] = true;
        }

        int start = 9;
        int maxLength = 1;
        // 모든 길이가 2인 팰린드롬은 두 문자가 같은지 확인
        for (int i = 0; i < slen - 1; i++) {
            if (s[i] == s[i + 1]) {
                dp[i][i + 1] = true;
                if (maxLength < 2) {
                    start = i;
                    maxLength = 2;
                }
            }
        }

        int max_start;
        // 길이 3부터 팰린드롬 확인
        for (int length = 3; length <= slen; length++) {
            max_start = slen - length;
            for (int i = 0; i <= max_start; i++) {
                int j = i + length - 1;
                // 첫 문자와 끝 문자가 같고, 그 사이 문자의 팰린드롬 여부가 true라면
                // i = 0, j = 3 (abba) -> 'a' == 'a'
                // i = 1, j = 2 (bb)
                if (s[i] == s[j] && dp[i + 1][j - 1]) {
                    dp[i][j] = true;
                    if (maxLength < length) {
                        start = i;
                        maxLength = length;
                    }
                }
            }
        }
        return s.substr(start, maxLength);
    }

    string longestPalindrome_manacher(string s) {

        string mamacher = "#";
        for (char c : s) {
            mamacher += c;
            mamacher += '#';
        }
        vector<int> P(mamacher.size(), 0);
        int center = 0;  // 현재 팰린드롬의 중심
        int right = 0;   // 현재 팰린드롬의 오른쪽 경계
        int maxLen = 0;  // 가장 긴 팰린드롬의 길이
        int maxCenter = 0;  // 가장 긴 팰린드롬의 중심
        for (int i = 0; i < mamacher.size(); i++) {

            // 현재 위치가 right 안에 있는 경우
            if (i < right) {
                int mirror = 2 * center - i;
                P[i] = min(P[mirror], right - i);
                // 이미 구해놓은 펠린드롬 정보를 재활용한다.
                // 해당 위치까지는
                // 0 1 0 3 0 1 0 2 배열이 있을 때,
                // 3 인덱스에서 펠린드롬을 구했다면, (0 1 0 3 0 1 0)
                // 0 1 0 은 왼쪽/오른쪽 반복되기 때문에
                // 오른쪽 0 1 0 은 순회할 필요 없이 왼쪽 0 1 0 값을 참조하면 된다.
            }

            // 현재 위치에서 확장 시도
            int l = i - (1 + P[i]);
            int r = i + (1 + P[i]);
            while (l >= 0 && r < mamacher.size() && mamacher[l] == mamacher[r]) {
                P[i]++;
                l--;
                r++;
            }

            // right 갱신
            if (i + P[i] > right) {
                center = i;
                right = i + P[i];
            }

            if (P[i] > maxLen) {
                maxLen = P[i];
                maxCenter = i;
            }
        }
        string result = "";
        for (int i = maxCenter - maxLen; i <= maxCenter + maxLen; i++) {
            if (mamacher[i] != '#') {
                result += mamacher[i];
            }
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
	EXPECT_EQ(this->s.longestPalindrome("babad"), "bab");
}
TEST_F(CLASS_NAME, __LINE__)
{
	EXPECT_EQ(this->s.longestPalindrome("cbbd"), "bb");
}



int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}