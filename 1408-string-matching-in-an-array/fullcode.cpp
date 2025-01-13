#include <gtest/gtest.h>
#include <iostream>
#include <iomanip>
#include <algorithm>
#include <vector>
#include <string>
#include <map>

using namespace std;


/*
https://leetcode.com/problems/string-matching-in-an-array/description/?envType=daily-question&envId=2025-01-07
 * @lc app=leetcode id=1408 lang=cpp
 * [1408] String Matching in an Array

Given an array of string words, return all strings in words that is a substring of another word. You can return the answer in any order.
A substring is a contiguous sequence of characters within a string

문자열 배열 words가 주어지면, 다른 단어의 부분 문자열인 모든 문자열을 반환합니다. 답은 어떤 순서로든 반환할 수 있습니다.
부분 문자열은 문자열 내의 연속된 문자 시퀀스입니다.

Constraints:
- 1 <= words.length <= 100
- 1 <= words[i].length <= 30
- words[i] contains only lowercase English letters.
- All the strings of words are unique.
 */

// @lc code=start
class Solution {
public:
    vector<string> stringMatching(vector<string>& words) {

        sort(words.begin(), words.end(), [](string a, string b) {
            return a.length() < b.length();
        });

        vector<string> result;
        for (int i = 0; i < words.size(); i++) {
            for (int j = i + 1; j < words.size(); j++) {
                if (words[j].find(words[i]) != string::npos) {
                    result.push_back(words[i]);
                    break;
                }
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
    vector<string> words = {"mass","as","hero","superhero"};
    vector<string> result = {"as","hero"};
	EXPECT_EQ(this->s.stringMatching(words), result);
}
TEST_F(CLASS_NAME, __LINE__)
{
    vector<string> words = {"leetcode","et","code"};
    vector<string> result = {"et","code"};
	EXPECT_EQ(this->s.stringMatching(words), result);
}
TEST_F(CLASS_NAME, __LINE__)
{
    vector<string> words = {"blue","green","bu"};
    vector<string> result = {};
	EXPECT_EQ(this->s.stringMatching(words), result);
}



int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}