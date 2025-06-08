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



/* https://leetcode.com/problems/lexicographically-minimum-string-after-removing-stars
 * @lc app=leetcode id=3170 lang=cpp
 * [3170] Lexicographically Minimum String After Removing Stars

You are given a string s. It may contain any number of '*' characters. Your task is to remove all '*' characters.
While there is a '*', do the following operation:
Delete the leftmost '*' and the smallest non-'*' character to its left. If there are several smallest characters, you can delete any of them.
Return the lexicographically smallest resulting string after removing all '*' characters.

문자열 s가 주어집니다. 이 문자열에는 임의의 개수의 '*' 문자가 포함될 수 있습니다. 모든 '*' 문자를 제거하는 것이 당신의 과제입니다.
'*'가 있는 동안 다음 연산을 수행하세요:
가장 왼쪽에 있는 '*'와 그 왼쪽에 있는 가장 작은 '*'가 아닌 문자를 삭제합니다. 가장 작은 문자가 여러 개 있다면, 그 중 아무거나 삭제할 수 있습니다.
모든 '*' 문자를 제거한 후 사전순으로 가장 작은 결과 문자열을 반환하세요.

Constraints:
1 <= s.length <= 10**5
s consists only of lowercase English letters and '*'.
The input is generated such that it is possible to delete all '*' characters.
입력은 모든 '*' 문자를 삭제할 수 있도록 생성됩니다.
 */
// @lc code=start
class Solution {
public:
    string clearStars(string s) {
        vector<vector<int>> char_positions(26);  // 각 알파벳의 위치를 저장하는 스택들
        vector<bool> to_remove(s.size(), false);  // 제거할 문자 위치 마킹

        for (int i = 0; i < s.size(); i++) {
            if (s[i] != '*') {
                char_positions[s[i] - 'a'].push_back(i);
                continue;
            }

            // 가장 작은 알파벳부터 찾아서 제거
            for (int j = 0; j < 26; j++) {
                if (!char_positions[j].empty()) {
                    int pos = char_positions[j].back();
                    char_positions[j].pop_back();
                    to_remove[pos] = true;
                    break;
                }
            }
            to_remove[i] = true;  // '*'도 제거
        }

        string result;
        for (int i = 0; i < s.size(); i++) {
            if (!to_remove[i]) {
                result += s[i];
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
    // Example 1:
    // Input: s = "aaba*"
    // Output: "aab"
    // Explanation:
    // We should delete one of the 'a' characters with '*'. If we choose s[3], s becomes the lexicographically smallest.
    // '*'와 함께 'a' 문자 중 하나를 삭제해야 한다. s[3]을 선택하면 사전순으로 가장 작은 문자열이 된다.

    EXPECT_EQ(this->s.clearStars("aaba*"), "aab");
}

TEST_F(CLASS_NAME, __LINE__)
{
    // Example 2:
    // Input: s = "abc"
    // Output: "abc"
    // Explanation:
    // There is no '*' in the string.

    EXPECT_EQ(this->s.clearStars("abc"), "abc");
}

TEST_F(CLASS_NAME, __LINE__)
{
    EXPECT_EQ(this->s.clearStars("d*o*"), "");
}


int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
