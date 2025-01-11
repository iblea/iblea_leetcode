#include <gtest/gtest.h>
#include <iostream>
#include <iomanip>
#include <algorithm>
#include <vector>
#include <string>
#include <map>

using namespace std;


/*
https://leetcode.com/problems/unique-length-3-palindromic-subsequences/description/?envType=daily-question&envId=2025-01-04
 * @lc app=leetcode id=1930 lang=cpp
 * [1930] Unique Length-3 Palindromic Subsequences

Given a string s, return the number of unique palindromes of length three that are a subsequence of s.
Note that even if there are multiple ways to obtain the same subsequence, it is still only counted once.
A palindrome is a string that reads the same forwards and backwards.
A subsequence of a string is a new string generated from the original string with some characters (can be none) deleted without changing the relative order of the remaining characters.
For example, "ace" is a subsequence of "abcde".

문자열 s가 주어지면, s의 부분 수열인 길이 3의 고유한 회문 수를 반환합니다.
같은 부분 수열을 얻는 여러 가지 방법이 있더라도 한 번만 계산됩니다.
회문은 앞뒤로 읽어도 동일한 문자열입니다.
문자열의 부분 수열은 원래 문자열에서 일부 문자를 삭제하여 생성된 새로운 문자열로, 남은 문자의 상대적 순서를 변경하지 않습니다.
예를 들어, "ace"는 "abcde"의 부분 수열입니다.

3 <= s.length <= 10**5
s consists of only lowercase English letters.
 */

// @lc code=start
class Solution {
public:
    int countPalindromicSubsequence(string s) {
        int alphabets[26] = {0,};
        int first_index[26] = {-1,};
        int last_index[26] = {-1,};
        size_t slen = s.size();
        char c;
        for (int i = 0; i < slen; i++) {
            c = s[i];
            alphabets[c - 'a']++;
            if (alphabets[c - 'a'] == 1) {
                first_index[c - 'a'] = i;
            }
            last_index[c - 'a'] = i;
        }

        int first_idx;
        int last_idx;
        int answer = 0;
        for (int i = 0; i < 26; i++) {
            if (alphabets[i] < 2) {
                continue;
            }
            first_idx = first_index[i];
            last_idx = last_index[i];
            bool visited[26] = {false,};
            for (int j = first_idx + 1; j < last_idx; j++) {
                if (visited[s[j] - 'a']) {
                    continue;
                }
                visited[s[j] - 'a'] = true;
                answer++;
            }
        }
        return answer;
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
	EXPECT_EQ(this->s.countPalindromicSubsequence("aabca"), 3);
	EXPECT_EQ(this->s.countPalindromicSubsequence("abc"), 0);
	EXPECT_EQ(this->s.countPalindromicSubsequence("aaa"), 1);
    EXPECT_EQ(this->s.countPalindromicSubsequence("bbcbaba"), 4);
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}