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

using namespace std;


/* https://leetcode.com/problems/edit-distance/
 * @lc app=leetcode id=72 lang=cpp
 * [72] Edit Distance

Given two strings word1 and word2, return the minimum number of operations required to convert word1 to word2.
You have the following three operations permitted on a word:
- Insert a character
- Delete a character
- Replace a character

Example 2:
Input: word1 = "intention", word2 = "execution"
Output: 5
Explanation:
intention -> inention (remove 't')
inention -> enention (replace 'i' with 'e')
enention -> exention (replace 'n' with 'x')
exention -> exection (replace 'n' with 'c')
exection -> execution (insert 'u')

Constraints:
- 0 <= word1.length, word2.length <= 500
- word1 and word2 consist of lowercase English letters.
 */

// @lc code=start
class Solution {
public:
    int minDistance(string word1, string word2) {
        int word1_len = word1.length();
        int word2_len = word2.length();

        if (word1_len == 0) return word2_len;
        if (word2_len == 0) return word1_len;
        // dp[i][j] : word1의 처음 i개 문자를 word2의 처음 j개 문자로 변환하는 최소 횟수
        vector<vector<int>> dp(word1_len + 1, vector<int>(word2_len + 1, 0));
        dp[0][0] = 0;

        for (int i = 1; i <= word1_len; i++) {
            dp[i][0] = i;
        }
        for (int j = 1; j <= word2_len; j++) {
            dp[0][j] = j;
        }

        int _insert, _delete, _replace;
        for (int i = 1; i <= word1_len; i++) {
            for (int j = 1; j <= word2_len; j++) {
                // 해당 포지션에 같은 문자이므로 추가 변경할 필요 없다.
                // aa, ba 상태에서 a,b 1 변경, aa, ba는 a가 같으므로 변경 필요 없다.
                if (word1[i-1] == word2[j-1]) {
                    dp[i][j] = dp[i-1][j-1];
                    continue;
                }

                _insert = dp[i][j-1] + 1;
                _delete = dp[i-1][j] + 1;
                _replace = dp[i-1][j-1] + 1;
                dp[i][j] = min(_insert, min(_delete, _replace));
            }
        }
        return dp[word1_len][word2_len];
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
    // Input: word1 = "horse", word2 = "ros"
    // Output: 3
    // Explanation:
    // horse -> rorse (replace 'h' with 'r')
    // rorse -> rose (remove 'r')
    // rose -> ros (remove 'e')

	EXPECT_EQ(this->s.minDistance("horse", "ros"), 3);
}

TEST_F(CLASS_NAME, __LINE__)
{
    // Example 2:
    // Input: word1 = "intention", word2 = "execution"
    // Output: 5
    // Explanation:
    // intention -> inention (remove 't')
    // inention -> enention (replace 'i' with 'e')
    // enention -> exention (replace 'n' with 'x')
    // exention -> exection (replace 'n' with 'c')
    // exection -> execution (insert 'u')
	EXPECT_EQ(this->s.minDistance("intention", "execution"), 5);
}


int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}