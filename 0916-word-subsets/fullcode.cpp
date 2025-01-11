#include <gtest/gtest.h>
#include <iostream>
#include <iomanip>
#include <algorithm>
#include <vector>
#include <string>
#include <map>

using namespace std;


/*
 *
 */

/*
https://leetcode.com/problems/word-subsets/?envType=daily-question&envId=2025-01-10
 * @lc app=leetcode id=916 lang=cpp
 * [916] Word Subsets

You are given two string arrays words1 and words2.
A string b is a subset of string a if every letter in b occurs in a including multiplicity.
For example, "wrr" is a subset of "warrior" but is not a subset of "world".
A string a from words1 is universal if for every string b in words2, b is a subset of a.
Return an array of all the universal strings in words1. You may return the answer in any order.

두 개의 문자열 배열 words1과 words2가 주어집니다.
문자열 b가 문자열 a의 부분 집합이 되려면 b의 모든 문자가 a에 포함되어야 하며, 중복도 포함됩니다.
예를 들어, "wrr"은 "warrior"의 부분 집합이지만 "world"의 부분 집합은 아닙니다.
words1의 문자열 a가 보편적이려면 words2의 모든 문자열 b가 a의 부분 집합이어야 합니다.
words1의 모든 보편적인 문자열 배열을 반환하세요. 답은 어떤 순서로든 반환할 수 있습니다.

Constraints:
1 <= words1.length, words2.length <= 10**4
1 <= words1[i].length, words2[i].length <= 10
words1[i] and words2[i] consist only of lowercase English letters.
All the strings of words1 are unique.
 */

// @lc code=start
class Solution {
    vector<char> get_char_count(const string& str) {
        vector<char> count(26, 0);
        for (char c : str) {
            count[c - 'a']++;
        }
        return count;
    }

    bool is_subset(const vector<char>& big, const vector<char>& small) {
        for (int i = 0; i < 26; i++) {
            if (big[i] >= small[i]) {
                continue;
            }
            return false;
        }
        return true;
    }

public:
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
        vector<string> answer;
        sort(words2.begin(), words2.end(), [](const string& a, const string& b) {
            return a.length() > b.length();
        });
        map<string, vector<char>> words2_map;
        for (string str : words2) {
            vector<char> count = this->get_char_count(str);
            bool is_subset = false;
            for (const auto& p : words2_map) {
                if (this->is_subset(p.second, count)) {
                    is_subset = true;
                    break;
                }
            }
            if (!is_subset) {
                words2_map[str] = count;
            }
        }

        for (string str : words1) {
            bool subset = true;
            vector<char> str_count = this->get_char_count(str);
            for (const auto& p : words2_map) {
                if (!this->is_subset(str_count, p.second)) {
                    subset = false;
                    break;
                }
            }
            if (subset) {
                answer.push_back(str);
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
    vector<string> words1 = {"amazon","apple","facebook","google","leetcode"};
    vector<string> words2 = {"e","o"};
    vector<string> expected = {"facebook","google","leetcode"};
	EXPECT_EQ(this->s.wordSubsets(words1, words2), expected);
}

TEST_F(CLASS_NAME, __LINE__)
{
    vector<string> words1 = {"amazon","apple","facebook","google","leetcode"};
    vector<string> words2 = {"l","e"};
    vector<string> expected = {"apple","google","leetcode"};
	EXPECT_EQ(this->s.wordSubsets(words1, words2), expected);
}

TEST_F(CLASS_NAME, __LINE__)
{
    vector<string> words1 = { "error", "arrer", "arrar" };
    vector<string> words2 = { "e","r", "er", "rr", "err" };
    vector<string> expected = { "error", "arrer" };
	EXPECT_EQ(this->s.wordSubsets(words1, words2), expected);
}

TEST_F(CLASS_NAME, __LINE__)
{
    vector<string> words1 = { "amazon","apple","facebook","google","leetcode" };
    vector<string> words2 = { "lo","eo" };
    vector<string> expected = { "google", "leetcode"};
	EXPECT_EQ(this->s.wordSubsets(words1, words2), expected);
}




int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}