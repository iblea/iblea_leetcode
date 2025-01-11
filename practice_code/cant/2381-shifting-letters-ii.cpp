#include <gtest/gtest.h>
#include <iostream>
#include <iomanip>
#include <algorithm>
#include <vector>
#include <string>
#include <map>

using namespace std;


/*
https://leetcode.com/problems/shifting-letters-ii/?envType=daily-question&envId=2025-01-05
 * @lc app=leetcode id=2381 lang=cpp
 * [2381] Shifting Letters II

You are given a string s of lowercase English letters and a 2D integer array shifts where shifts[i] = [starti, endi, directioni]. For every i, shift the characters in s from the index starti to the index endi (inclusive) forward if directioni = 1, or shift the characters backward if directioni = 0.
Shifting a character forward means replacing it with the next letter in the alphabet (wrapping around so that 'z' becomes 'a'). Similarly, shifting a character backward means replacing it with the previous letter in the alphabet (wrapping around so that 'a' becomes 'z').
Return the final string after all such shifts to s are applied.

소문자 영어 문자로 구성된 문자열 s와 2D 정수 배열 shifts가 주어집니다. shifts[i] = [starti, endi, directioni]입니다. 각 i에 대해, directioni가 1이면 s의 starti 인덱스부터 endi 인덱스까지(포함) 문자를 앞으로 이동시키고, directioni가 0이면 문자를 뒤로 이동시킵니다.
문자를 앞으로 이동시키는 것은 알파벳의 다음 문자로 대체하는 것을 의미합니다('z'가 'a'로 순환됨). 마찬가지로, 문자를 뒤로 이동시키는 것은 알파벳의 이전 문자로 대체하는 것을 의미합니다('a'가 'z'로 순환됨).
모든 이동이 s에 적용된 후 최종 문자열을 반환합니다.

Constraints:
1 <= s.length, shifts.length <= 5 * 10**4 (50000)
shifts[i].length == 3
0 <= starti <= endi < s.length
0 <= directioni <= 1
s consists of lowercase English letters.
 */

// @lc code=start
class Solution {
public:
    string shiftingLetters(string s, vector<vector<int>>& shifts) {
        size_t slen = s.size();
        vector<int> shift_index(slen + 1, 0);

        int start, end, direction;
        for (vector<int>& shift : shifts) {
            start = shift[0];
            end = shift[1];
            direction = shift[2];
            if (direction == 1) {
                shift_index[start]++;
                shift_index[end+1]--;
            } else {
                shift_index[start]--;
                shift_index[end+1]++;
            }
        }

        vector<int> shift_count(slen, 0);
        int shift = 0;
        for (int i = 0; i < slen; i++) {
            shift += shift_index[i];
            shift_count[i] = shift;
        }

        string result = s;
        for (int i = 0; i < slen; i++) {
            shift = (s[i] - 'a' + shift_count[i]) % 26;
            if (shift < 0) {
                shift += 26;
            }
            result[i] = shift + 'a';
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
    vector<vector<int>> shifts = {{0,1,0},{1,2,1},{0,2,1}};
	EXPECT_EQ(this->s.shiftingLetters("abc", shifts), "ace");
}

TEST_F(CLASS_NAME, __LINE__)
{
    vector<vector<int>> shifts = {{0,0,0},{1,1,1}};
	EXPECT_EQ(this->s.shiftingLetters("dztz", shifts), "catz");
}


int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}