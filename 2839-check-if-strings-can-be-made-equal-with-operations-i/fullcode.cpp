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


/* https://leetcode.com/problems/check-if-strings-can-be-made-equal-with-operations-i/
 * 2839. Check if Strings Can be Made Equal With Operations I | Easy

You are given two strings s1 and s2, both of length 4, consisting of lowercase English letters.
You can apply the following operation on any of the two strings any number of times:
    * Choose any two indices i and j such that j - i = 2, then swap the two characters at those indices in the string.
Return true if you can make the strings s1 and s2 equal, and false otherwise.

길이가 4인 두 문자열 s1과 s2가 주어지며, 두 문자열은 영문 소문자로 구성되어 있습니다.
두 문자열 중 어느 것에든 다음 연산을 원하는 횟수만큼 적용할 수 있습니다:
    * j - i = 2를 만족하는 두 인덱스 i와 j를 선택한 후, 문자열에서 해당 인덱스에 위치한 두 문자를 서로 교환합니다.
두 문자열 s1과 s2를 같게 만들 수 있으면 true를, 그렇지 않으면 false를 반환하십시오.


 Constraints:
    * s1.length == s2.length == 4
    * s1 and s2 consist only of lowercase English letters.
 */
// @leet start
class Solution {
public:
    bool canBeEqual(string s1, string s2) {
        if (s1[0] > s1[2]) swap(s1[0], s1[2]);
        if (s2[0] > s2[2]) swap(s2[0], s2[2]);
        if (s1[1] > s1[3]) swap(s1[1], s1[3]);
        if (s2[1] > s2[3]) swap(s2[1], s2[3]);
        return s1 == s2;
    }
};
// @leet end


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
    // 󰛨 Example 1:
    //     Input: s1 = "abcd", s2 = "cdab"
    //     Output: true
    //     Explanation: We can do the following operations on s1:
    //     - Choose the indices i = 0, j = 2. The resulting string is s1 = "cbad".
    //     - Choose the indices i = 1, j = 3. The resulting string is s1 = "cdab" = s2.

    EXPECT_EQ(this->s.canBeEqual("abcd", "cdab"), true);
}

TEST_F(CLASS_NAME, __LINE__)
{
    // 󰛨 Example 2:
    //     Input: s1 = "abcd", s2 = "dacb"
    //     Output: false
    //     Explanation: It is not possible to make the two strings equal.

    EXPECT_EQ(this->s.canBeEqual("abcd", "dacb"), false);
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
