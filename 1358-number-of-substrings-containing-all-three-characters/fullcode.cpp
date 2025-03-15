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



/* https://leetcode.com/problems/number-of-substrings-containing-all-three-characters/?envType=daily-question&envId=2025-03-11
 * @lc app=leetcode id=1358 lang=cpp
 * [1358] Number of Substrings Containing All Three Characters

Given a string s consisting only of characters a, b and c.
Return the number of substrings containing at least one occurrence of all these characters a, b and c.

문자 a, b, c로만 구성된 문자열 s가 주어집니다.
이 문자들 a, b, c가 각각 적어도 한 번씩 포함된 부분 문자열의 개수를 반환하세요.

Constraints:
3 <= s.length <= 5 x 10^4
s only consists of a, b or c characters.
 */

// @lc code=start
class Solution {
public:
    int numberOfSubstrings(string s) {
        int len = s.length();
        int count = 0;
        int a_count = 0;
        int b_count = 0;
        int c_count = 0;

        int left = 0;
        int right = 0;
        while (true) {
            while (right < len && !(a_count > 0 && b_count > 0 && c_count > 0)) {
                if (s[right] == 'a') a_count++;
                else if (s[right] == 'b') b_count++;
                else if (s[right] == 'c') c_count++;
                right++;
            }
            if (a_count > 0 && b_count > 0 && c_count > 0) {
                count += len - right + 1;
            }

            if (right >= len && left >= len) break;
            if (s[left] == 'a') a_count--;
            else if (s[left] == 'b') b_count--;
            else if (s[left] == 'c') c_count--;
            left++;
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
    // Example 1:
    // Input: s = "abcabc"
    // Output: 10
    // Explanation: The substrings containing at least one occurrence of the characters a, b and c are "abc", "abca", "abcab", "abcabc", "bca", "bcab", "bcabc", "cab", "cabc" and "abc" (again).

	EXPECT_EQ(this->s.numberOfSubstrings("abcabc"), 10);
}

TEST_F(CLASS_NAME, __LINE__)
{
    // Example 2:
    // Input: s = "aaacb"
    // Output: 3
    // Explanation: The substrings containing at least one occurrence of the characters a, b and c are "aaacb", "aacb" and "acb".

	EXPECT_EQ(this->s.numberOfSubstrings("aaacb"), 3);
}

TEST_F(CLASS_NAME, __LINE__)
{
    // Example 3:
    // Input: s = "abc"
    // Output: 1

    EXPECT_EQ(this->s.numberOfSubstrings("abc"), 1);
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
