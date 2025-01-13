#include <gtest/gtest.h>
#include <iostream>
#include <iomanip>
#include <algorithm>
#include <vector>
#include <string>
#include <map>

using namespace std;


/*
https://leetcode.com/problems/counting-words-with-a-given-prefix/description/?envType=daily-question&envId=2025-01-09
 * @lc app=leetcode id=2185 lang=cpp
 * [2185] Counting Words With a Given Prefix

You are given an array of strings words and a string pref.
Return the number of strings in words that contain pref as a prefix.
A prefix of a string s is any leading contiguous substring of s.

주어진 문자열 배열 words와 문자열 pref가 있습니다.
words에서 pref를 접두사로 포함하는 문자열의 수를 반환하세요.
문자열 s의 접두사는 s의 선행 연속 부분 문자열입니다.

Constraints:
1 <= words.length <= 100
1 <= words[i].length, pref.length <= 100
words[i] and pref consist of lowercase English letters.
 */

// @lc code=start
class Solution {
public:
    int prefixCount(vector<string>& words, string pref) {
        size_t pref_len = pref.length();
        int count = 0;
        for (const auto& word : words) {
            string substr = word.substr(0, pref_len);
            if (substr == pref) {
                count++;
            }
        }
        return count;
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
    vector<string> words = {"pay","attention","practice","attend"};
    string pref = "at";
	EXPECT_EQ(this->s.prefixCount(words, pref), 2);
}
TEST_F(CLASS_NAME, __LINE__)
{
    vector<string> words = {"leetcode","win","loops","success"};
    string pref = "code";
	EXPECT_EQ(this->s.prefixCount(words, pref), 0);
}



int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}