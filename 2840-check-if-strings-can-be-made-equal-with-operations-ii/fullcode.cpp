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


/* https://leetcode.com/problems/check-if-strings-can-be-made-equal-with-operations-ii/
 * 2840. Check if Strings Can be Made Equal With Operations II | Medium

You are given two strings s1 and s2, both of length n, consisting of lowercase English letters.
You can apply the following operation on any of the two strings any number of times:
    * Choose any two indices i and j such that i < j and the difference j - i is even, then swap the two characters at those indices in the string.
Return true if you can make the strings s1 and s2 equal, and false otherwise.

길이가 n인 두 문자열 s1과 s2가 주어지며, 두 문자열은 영어 소문자로 구성되어 있습니다.
두 문자열 중 어느 것에든 다음 연산을 원하는 횟수만큼 적용할 수 있습니다:
    * i < j이고 j - i의 차이가 짝수인 두 인덱스 i와 j를 선택한 다음, 문자열에서 해당 인덱스에 있는 두 문자를 교환합니다.
문자열 s1과 s2를 같게 만들 수 있으면 true를 반환하고, 그렇지 않으면 false를 반환하세요.

 Constraints:
    * n == s1.length == s2.length
    * 1 <= n <= 10^5
    * s1 and s2 consist only of lowercase English letters.

 */
// @leet start
class Solution {
public:
    bool checkStrings(string s1, string s2) {
        // odd
        vector<int> odd(26, 0);
        // even
        vector<int> even(26, 0);

        size_t arrlen = s1.length();
        for (size_t i = 0; i < arrlen; i+=2) {
            even[s1[i] - 'a']++;
            even[s2[i] - 'a']--;
        }
        for (size_t i = 1; i < arrlen; i+=2) {
            odd[s1[i] - 'a']++;
            odd[s2[i] - 'a']--;
        }

        for (size_t i = 0; i < 26; i++) {
            if (odd[i] != 0 || even[i] != 0) {
                return false;
            }
        }
        return true;
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
    //     Input: s1 = "abcdba", s2 = "cabdab"
    //     Output: true
    //     Explanation: We can apply the following operations on s1:
    //     - Choose the indices i = 0, j = 2. The resulting string is s1 = "cbadba".
    //     - Choose the indices i = 2, j = 4. The resulting string is s1 = "cbbdaa".
    //     - Choose the indices i = 1, j = 5. The resulting string is s1 = "cabdab" = s2.

    EXPECT_EQ(this->s.checkStrings("abcdba", "cabdab"), true);
}

TEST_F(CLASS_NAME, __LINE__)
{
    // 󰛨 Example 2:
    //     Input: s1 = "abe", s2 = "bea"
    //     Output: false
    //     Explanation: It is not possible to make the two strings equal.

    EXPECT_EQ(this->s.checkStrings("abe", "bea"), false);
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
