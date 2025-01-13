#include <gtest/gtest.h>
#include <iostream>
#include <iomanip>
#include <algorithm>
#include <vector>
#include <string>
#include <map>

using namespace std;



/*
https://leetcode.com/problems/minimum-length-of-string-after-operations/description/?envType=daily-question&envId=2025-01-13
 * @lc app=leetcode id=3223 lang=cpp
 * [3223] Minimum Length of String After Operations

You are given a string s.
You can perform the following process on s any number of times:
- Choose an index i in the string such that there is at least one character to the left of index i that is equal to s[i], and at least one character to the right that is also equal to s[i].
- Delete the closest character to the left of index i that is equal to s[i].
- Delete the closest character to the right of index i that is equal to s[i].
Return the minimum length of the final string s that you can achieve.

문자열 s가 주어집니다.
다음 과정을 s에 대해 여러 번 수행할 수 있습니다:
- 문자열에서 인덱스 i를 선택합니다. 이때 인덱스 i의 왼쪽에 s[i]와 같은 문자가 적어도 하나 있고, 오른쪽에도 s[i]와 같은 문자가 적어도 하나 있어야 합니다.
- 인덱스 i의 왼쪽에서 s[i]와 같은 가장 가까운 문자를 삭제합니다.
- 인덱스 i의 오른쪽에서 s[i]와 같은 가장 가까운 문자를 삭제합니다.
최종 문자열 s의 최소 길이를 반환합니다.

Constraints:
- 1 <= s.length <= 2 * 10**5
- s consists only of lowercase English letters.
 */

// @lc code=start
class Solution {
public:
    int minimumLength(string s) {
        int slen = s.length();
        if (slen <= 2) return slen;

        int alphabets[26] = {0, };
        for (char c : s) {
            alphabets[c - 'a']++;
        }
        for (int i = 0; i < 26; i++) {
            if (alphabets[i] >= 3) {
                while (alphabets[i] >= 3) {
                    alphabets[i] -= 2;
                }
            }
        }
        int result = 0;
        for (int i = 0; i < 26; i++) {
            result += alphabets[i];
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
	EXPECT_EQ(this->s.minimumLength("abaacbcbb"), 5);
}

TEST_F(CLASS_NAME, __LINE__)
{
	EXPECT_EQ(this->s.minimumLength("aa"), 2);
}



int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}