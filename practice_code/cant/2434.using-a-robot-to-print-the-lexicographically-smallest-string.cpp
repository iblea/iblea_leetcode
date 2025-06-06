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



/* https://leetcode.com/problems/using-a-robot-to-print-the-lexicographically-smallest-string
 * @lc app=leetcode id=2434 lang=cpp
 * [2434] Using a Robot to Print the Lexicographically Smallest String

You are given a string s and a robot that currently holds an empty string t. Apply one of the following operations until s and t are both empty:
- Remove the first character of a string s and give it to the robot. The robot will append this character to the string t.
- Remove the last character of a string t and give it to the robot. The robot will write this character on paper.
Return the lexicographically smallest string that can be written on the paper.

문자열 s와 현재 빈 문자열 t를 가지고 있는 로봇이 주어집니다. s와 t가 모두 비워질 때까지 다음 작업 중 하나를 적용하세요:
- 문자열 s의 첫 번째 문자를 제거하고 로봇에게 줍니다. 로봇은 이 문자를 문자열 t에 추가합니다.
- 문자열 t의 마지막 문자를 제거하고 로봇에게 줍니다. 로봇은 이 문자를 종이에 씁니다.
종이에 쓸 수 있는 사전순으로 가장 작은 문자열을 반환하세요.

Constraints:
- 1 <= s.length <= 10**5
- s consists of only English lowercase letters.
 */
// @lc code=start
class Solution {
public:
    string robotWithString(string s) {
        int n = s.length();

        // 각 위치에서 그 위치부터 끝까지의 최소 문자 계산
        vector<char> minSuffix(n);
        minSuffix[n-1] = s[n-1];
        for (int i = n-2; i >= 0; i--) {
            minSuffix[i] = min(s[i], minSuffix[i+1]);
        }

        string result = "";
        string t = "";  // 스택 역할
        int i = 0;  // s의 현재 인덱스

        while (i < n || !t.empty()) {
            // 스택이 비어있지 않고, 스택의 top이 앞으로 올 최소값보다 작거나 같으면 pop
            if (!t.empty() && (i >= n || t.back() <= minSuffix[i])) {
                result += t.back();
                t.pop_back();
                continue;
            }
            // 그렇지 않으면 s에서 문자를 가져와서 스택에 push
            t += s[i];
            i++;
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
    // Input: s = "zza"
    // Output: "azz"
    // Explanation: Let p denote the written string.
    // Initially p="", s="zza", t="".
    // Perform first operation three times p="", s="", t="zza".
    // Perform second operation three times p="azz", s="", t="".
    EXPECT_EQ(this->s.robotWithString("zza"), "azz");
}

TEST_F(CLASS_NAME, __LINE__)
{
    // Input: s = "bac"
    // Output: "abc"
    // Explanation: Let p denote the written string.
    // Perform first operation twice p="", s="c", t="ba".
    // Perform second operation twice p="ab", s="c", t="".
    // Perform first operation p="ab", s="", t="c".
    // Perform second operation p="abc", s="", t="".
    EXPECT_EQ(this->s.robotWithString("bac"), "abc");
}

TEST_F(CLASS_NAME, __LINE__)
{
    // Input: s = "bdda"
    // Output: "addb"
    // Explanation: Let p denote the written string.
    // Initially p="", s="bdda", t="".
    // Perform first operation four times p="", s="", t="bdda".
    // Perform second operation four times p="addb", s="", t="".
    EXPECT_EQ(this->s.robotWithString("bdda"), "addb");
}

TEST_F(CLASS_NAME, __LINE__)
{
    EXPECT_EQ(this->s.robotWithString("bbbabba"), "abbabbb");
}

TEST_F(CLASS_NAME, __LINE__)
{
    EXPECT_EQ(this->s.robotWithString("bbabbba"), "abbabbb");
}




int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
