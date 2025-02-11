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



/* https://leetcode.com/problems/remove-all-occurrences-of-a-substring/?envType=daily-question&envId=2025-02-11
 * @lc app=leetcode id=1910 lang=cpp
 *
 * [1910] Remove All Occurrences of a Substring

Given two strings s and part, perform the following operation on s until all occurrences of the substring part are removed:
Find the leftmost occurrence of the substring part and remove it from s.
Return s after removing all occurrences of part.
A substring is a contiguous sequence of characters in a string.

두 개의 문자열 s와 part가 주어지면, part 부분 문자열의 모든 발생이 제거될 때까지 s에 대해 다음 작업을 수행하세요:
s에서 part 부분 문자열의 가장 왼쪽 발생을 찾아 제거합니다.
part의 모든 발생을 제거한 후의 s를 반환하세요.
부분 문자열은 문자열에서 연속된 문자들의 시퀀스입니다.

Constraints:
1 <= s.length <= 1000
1 <= part.length <= 1000
s​​​​​​ and part consists of lowercase English letters.
 */

// @lc code=start
class Solution {
public:
    string removeOccurrences(string s, string part) {
        string result = "";
        int part_size = part.size();

        for (char c : s) {
            result.push_back(c);
            if (result.size() >= part_size && result.substr(result.size() - part_size) == part) {
                result.erase(result.size() - part_size);
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
    // Input: s = "daabcbaabcbc", part = "abc"
    // Output: "dab"
    // Explanation: The following operations are done:
    // - s = "daabcbaabcbc", remove "abc" starting at index 2, so s = "dabaabcbc".
    // - s = "dabaabcbc", remove "abc" starting at index 4, so s = "dababc".
    // - s = "dababc", remove "abc" starting at index 3, so s = "dab".
    // Now s has no occurrences of "abc".

	EXPECT_EQ(this->s.removeOccurrences("daabcbaabcbc", "abc"), "dab");
}

TEST_F(CLASS_NAME, __LINE__)
{
    // Example 2:
    // Input: s = "axxxxyyyyb", part = "xy"
    // Output: "ab"
    // Explanation: The following operations are done:
    // - s = "axxxxyyyyb", remove "xy" starting at index 4 so s = "axxxyyyb".
    // - s = "axxxyyyb", remove "xy" starting at index 3 so s = "axxyyb".
    // - s = "axxyyb", remove "xy" starting at index 2 so s = "axyb".
    // - s = "axyb", remove "xy" starting at index 1 so s = "ab".
    // Now s has no occurrences of "xy".

	EXPECT_EQ(this->s.removeOccurrences("axxxxyyyyb", "xy"), "ab");
}



int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}