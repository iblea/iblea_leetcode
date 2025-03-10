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
#include <unordered_map>
#include <unordered_set>

using namespace std;



/* https://leetcode.com/problems/count-of-substrings-containing-every-vowel-and-k-consonants-ii/?envType=daily-question&envId=2025-03-10
 * @lc app=leetcode id=3306 lang=cpp
 * [3306] Count of Substrings Containing Every Vowel and K Consonants II

You are given a string word and a non-negative integer k.
Return the total number of substrings of word that contain every vowel ('a', 'e', 'i', 'o', and 'u') at least once and exactly k consonants.

문자열 word와 음이 아닌 정수 k가 주어집니다.
모든 모음('a', 'e', 'i', 'o', 'u')을 각각 최소 한 번씩 포함하고 정확히 k개의 자음을 포함하는 word의 부분 문자열의 총 개수를 반환하세요.

Constraints:
5 <= word.length <= 2 * 10**5
word consists only of lowercase English letters.
0 <= k <= word.length - 5
 */

// @lc code=start
class Solution {
public:
    bool isVowel(char ch) {
        return (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u');
    }

    long long countOfSubstrings(string word, int k) {
        int n = word.size();
        unordered_map<char, int> vowels;
        int consonantCount = 0;
        long long result = 0;

        // Precompute next consonant positions
        vector<int> nextConsonant(n);
        int lastConsonant = n;
        for (int i = n - 1; i >= 0; i--) {
            nextConsonant[i] = lastConsonant;
            // 연속되는 모음이 있으면, 연속되는 모음의 마지막 위치를 저장
            if (!isVowel(word[i])) lastConsonant = i;
        }

        // Sliding window
        int left = 0, right = 0;
        while (right < n) {
            // Expand window
            if (isVowel(word[right])) {
                vowels[word[right]]++;
            } else {
                consonantCount++;
            }

            // Shrink window if too many consonants
            while (left <= right && consonantCount > k) {
                if (isVowel(word[left])) {
                    if (--vowels[word[left]] == 0) vowels.erase(word[left]);
                } else {
                    consonantCount--;
                }
                left++;
            }

            // Count valid substrings
            while (left < right && vowels.size() == 5 && consonantCount == k) {
                // 모음이 5개가 있으므로, 이후에는 모음이 몇개든 상관이 없다.
                // 따라서 연속되는 모음의 개수만큼 부분 문자열을 만들 수 있으므로, 그만큼 모두 더해야 한다.
                result += (nextConsonant[right] - right);
                if (isVowel(word[left])) {
                    vowels[word[left]]--;
                    if (vowels[word[left]] == 0) vowels.erase(word[left]);
                } else {
                    consonantCount--;
                }
                left++;
            }

            right++;
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
    // Example 1:
    // Input: word = "aeioqq", k = 1
    // Output: 0
    // Explanation:
    // There is no substring with every vowel.

    string word = "aeioqq";
    int k = 1;
    EXPECT_EQ(this->s.countOfSubstrings(word, k), 0);
}

TEST_F(CLASS_NAME, __LINE__)
{
    // Example 2:
    // Input: word = "aeiou", k = 0
    // Output: 1
    // Explanation:
    // The only substring with every vowel and zero consonants is word[0..4], which is "aeiou".

    string word = "aeiou";
    int k = 0;
    EXPECT_EQ(this->s.countOfSubstrings(word, k), 1);
}

TEST_F(CLASS_NAME, __LINE__)
{
    // Example 3:
    // Input: word = "ieaouqqieaouqq", k = 1
    // Output: 3
    // Explanation:
    // The substrings with every vowel and one consonant are:
    // word[0..5], which is "ieaouq".
    // word[6..11], which is "qieaou".
    // word[7..12], which is "ieaouq".

    string word = "ieaouqqieaouqq";
    int k = 1;
    EXPECT_EQ(this->s.countOfSubstrings(word, k), 3);
}

TEST_F(CLASS_NAME, __LINE__)
{
    string word = "kkaeiouk";
    int k = 1;
    EXPECT_EQ(this->s.countOfSubstrings(word, k), 2);
}

TEST_F(CLASS_NAME, __LINE__)
{
    string word = "kaeibouk";
    int k = 1;
    EXPECT_EQ(this->s.countOfSubstrings(word, k), 1);
}

TEST_F(CLASS_NAME, __LINE__)
{
    string word = "kaeiboauk";
    int k = 1;
    EXPECT_EQ(this->s.countOfSubstrings(word, k), 2);
}

TEST_F(CLASS_NAME, __LINE__)
{
    string word = "kaeiouuk";
    int k = 1;
    EXPECT_EQ(this->s.countOfSubstrings(word, k), 3);
}

TEST_F(CLASS_NAME, __LINE__)
{
    string word = "aeiokua";
    int k = 1;
    EXPECT_EQ(this->s.countOfSubstrings(word, k), 3);
}








int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
