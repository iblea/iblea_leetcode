#include <gtest/gtest.h>
#include <iostream>
#include <iomanip>
#include <algorithm>
#include <vector>
#include <string>
#include <map>

using namespace std;



/*
https://leetcode.com/problems/count-prefix-and-suffix-pairs-i/description/?envType=daily-question&envId=2025-01-08
 * @lc app=leetcode id=3042 lang=cpp
 * [3042] Count Prefix and Suffix Pairs I

You are given a 0-indexed string array words.
Let's define a boolean function isPrefixAndSuffix that takes two strings, str1 and str2:
- isPrefixAndSuffix(str1, str2) returns true if str1 is both a prefix and a suffix of str2, and false otherwise.
For example, isPrefixAndSuffix("aba", "ababa") is true because "aba" is a prefix of "ababa" and also a suffix, but isPrefixAndSuffix("abc", "abcd") is false.
Return an integer denoting the number of index pairs (i, j) such that i < j, and isPrefixAndSuffix(words[i], words[j]) is true.

0-인덱스 문자열 배열 words가 주어집니다.
두 문자열 str1과 str2를 받는 boolean 함수 isPrefixAndSuffix를 정의해 봅시다:
- isPrefixAndSuffix(str1, str2)는 str1이 str2의 접두사이자 접미사인 경우 true를 반환하고, 그렇지 않은 경우 false를 반환합니다.
예를 들어, isPrefixAndSuffix("aba", "ababa")는 "aba"가 "ababa"의 접두사이자 접미사이기 때문에 true를 반환하지만, isPrefixAndSuffix("abc", "abcd")는 false를 반환합니다.
i < j이고 isPrefixAndSuffix(words[i], words[j])가 true인 인덱스 쌍 (i, j)의 수를 나타내는 정수를 반환합니다.

Constraints:
- 1 <= words.length <= 50
- 1 <= words[i].length <= 10
- words[i] consists only of lowercase English letters.
 */

// @lc code=start
class Solution {
public:
    bool isPrefixAndSuffix(const string& str1, const string& str2) {
        return str1.length() <= str2.length() && str1 == str2.substr(0, str1.length()) && str1 == str2.substr(str2.length() - str1.length());
    }
    int countPrefixSuffixPairs(vector<string>& words) {
        int count = 0;
        for (int i = 0; i < words.size(); i++) {
            for (int j = i + 1; j < words.size(); j++) {
                if (this->isPrefixAndSuffix(words[i], words[j])) {
                    count++;
                }
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
    vector<string> words = {"a", "aba", "ababa", "aa"};
    // a aa, a aba, a ababa, aba ababa
	EXPECT_EQ(this->s.countPrefixSuffixPairs(words), 4);
}
TEST_F(CLASS_NAME, __LINE__)
{
    vector<string> words = {"pa", "papa", "ma", "mama"};
	EXPECT_EQ(this->s.countPrefixSuffixPairs(words), 2);
}
TEST_F(CLASS_NAME, __LINE__)
{
    vector<string> words = {"abab", "ab"};
	EXPECT_EQ(this->s.countPrefixSuffixPairs(words), 0);
}



int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}