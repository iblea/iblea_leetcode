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



/* https://leetcode.com/problems/check-if-one-string-swap-can-make-strings-equal/?envType=daily-question&envId=2025-02-05
 * @lc app=leetcode id=1790 lang=cpp
 * [1790] Check if One String Swap Can Make Strings Equal

You are given two strings s1 and s2 of equal length. A string swap is an operation where you choose two indices in a string (not necessarily different) and swap the characters at these indices.
Return true if it is possible to make both strings equal by performing at most one string swap on exactly one of the strings. Otherwise, return false.

동일한 길이의 두 문자열 s1과 s2가 주어집니다. 문자열 스왑은 문자열에서 두 개의 인덱스(반드시 서로 달라야 할 필요는 없음)를 선택하여 해당 인덱스의 문자를 교환하는 연산입니다.
정확히 하나의 문자열에 대해 최대 한 번의 문자열 스왑을 수행하여 두 문자열을 동일하게 만들 수 있으면 true를 반환하고, 그렇지 않으면 false를 반환합니다.

Constraints:
1 <= s1.length, s2.length <= 100
s1.length == s2.length
s1 and s2 consist of only lowercase English letters.
 */

// @lc code=start
class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
        int diff_count = 0;
        int diff_idxs[2] = {-1, -1};
        int slen = s1.length();

        for (int i = 0; i < slen; i++) {
            if (s1[i] != s2[i]) {
                if (diff_count >= 2) {
                    return false;
                }
                diff_idxs[diff_count] = i;
                diff_count++;
            }
        }

        switch (diff_count) {
            case 0:
                return true;
            case 1:
                return false;
            case 2:
                return s1[diff_idxs[0]] == s2[diff_idxs[1]] && s1[diff_idxs[1]] == s2[diff_idxs[0]];
        }
        return false;
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
	// Input: s1 = "bank", s2 = "kanb"
	// Output: true
	// Explanation: For example, swap the first character with the last character of s2 to make "bank".

	EXPECT_EQ(this->s.areAlmostEqual("bank", "kanb"), true);
}

TEST_F(CLASS_NAME, __LINE__)
{
	// Example 2:
	// Input: s1 = "attack", s2 = "defend"
	// Output: false
	// Explanation: It is impossible to make them equal with one string swap.

	EXPECT_EQ(this->s.areAlmostEqual("attack", "defend"), false);
}

TEST_F(CLASS_NAME, __LINE__)
{
	// Example 3:
	// Input: s1 = "kelb", s2 = "kelb"
	// Output: true
	// Explanation: The two strings are already equal, so no string swap operation is required.

	EXPECT_EQ(this->s.areAlmostEqual("kelb", "kelb"), true);
}



int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}