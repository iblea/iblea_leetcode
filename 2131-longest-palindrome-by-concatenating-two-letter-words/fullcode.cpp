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



/* https://leetcode.com/problems/longest-palindrome-by-concatenating-two-letter-words
 * @lc app=leetcode id=2131 lang=cpp
 * [2131] Longest Palindrome by Concatenating Two Letter Words

You are given an array of strings words. Each element of words consists of two lowercase English letters.
Create the longest possible palindrome by selecting some elements from words and concatenating them in any order. Each element can be selected at most once.
Return the length of the longest palindrome that you can create. If it is impossible to create any palindrome, return 0.
A palindrome is a string that reads the same forward and backward.

문자열 배열 words가 주어진다. words의 각 요소는 두 개의 소문자 영어 글자로 구성된다.
words에서 일부 요소들을 선택하고 임의의 순서로 연결하여 가능한 가장 긴 회문을 만든다. 각 요소는 최대 한 번만 선택할 수 있다.
만들 수 있는 가장 긴 회문의 길이를 반환한다. 회문을 만들 수 없다면 0을 반환한다.
회문은 앞에서 읽든 뒤에서 읽든 같은 문자열이다.

Constraints:

1 <= words.length <= 10**5
words[i].length == 2
words[i] consists of lowercase English letters.
 */

// @lc code=start
class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        map<string, int> word_count;
        int only_onepair = 0;

        for (auto &word : words) {
            if (word_count.find(word) == word_count.end()) {
                word_count[word] = 1;
            } else {
                word_count[word]++;
            }
        }

        int count = 0;
        // word_count의 키를 순회한다.
        for (auto &word : word_count) {
            if (word.first[0] == word.first[1]) {
                if (only_onepair == 0 && word.second % 2 != 0) {
                    only_onepair = 1;
                }
                count += (word.second / 2) * 2;
                continue;
            } else {
                if (word.second == 0) {
                    continue;
                }
                string reverse_key = string(1, word.first[1]) + string(1, word.first[0]);
                if (word_count.find(reverse_key) == word_count.end()) {
                    // 반대 키를 못찾으면 스킵
                    continue;
                }
                int min_count = min(word.second, word_count[reverse_key]);
                count += (min_count * 2);
                word_count[word.first] = 0;
                word_count[reverse_key] = 0;
            }
        }

        return (count * 2) + (only_onepair * 2);
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
    // Input: words = ["lc","cl","gg"]
    // Output: 6
    // Explanation: One longest palindrome is "lc" + "gg" + "cl" = "lcggcl", of length 6.
    // Note that "clgglc" is another longest palindrome that can be created.
    vector<string> words = {"lc","cl","gg"};
    EXPECT_EQ(this->s.longestPalindrome(words), 6);
}

TEST_F(CLASS_NAME, __LINE__)
{
    // Input: words = ["ab","ty","yt","lc","cl","ab"]
    // Output: 8
    // Explanation: One longest palindrome is "ty" + "lc" + "cl" + "yt" = "tylcclyt", of length 8.
    // Note that "lcyttycl" is another longest palindrome that can be created.
    vector<string> words = {"ab","ty","yt","lc","cl","ab"};
    EXPECT_EQ(this->s.longestPalindrome(words), 8);
}

TEST_F(CLASS_NAME, __LINE__)
{
    // Input: words = ["cc","ll","xx"]
    // Output: 2
    // Explanation: One longest palindrome is "cc", of length 2.
    // Note that "ll" is another longest palindrome that can be created, and so is "xx".
    vector<string> words = {"cc","ll","xx"};
    EXPECT_EQ(this->s.longestPalindrome(words), 2);
}

TEST_F(CLASS_NAME, __LINE__)
{
    vector<string> words = {"ab","cd","ef"};
    EXPECT_EQ(this->s.longestPalindrome(words), 0);
}

TEST_F(CLASS_NAME, __LINE__)
{
    vector<string> words = {"ll","ll","ll"};
    EXPECT_EQ(this->s.longestPalindrome(words), 6);
}

TEST_F(CLASS_NAME, __LINE__)
{
    vector<string> words = {"ab","ba","cd", "dc"};
    EXPECT_EQ(this->s.longestPalindrome(words), 8);
}

TEST_F(CLASS_NAME, __LINE__)
{
    vector<string> words = {"bb","bb"};
    EXPECT_EQ(this->s.longestPalindrome(words), 4);
}







int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
