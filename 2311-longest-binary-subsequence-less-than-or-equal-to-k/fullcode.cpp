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



/* https://leetcode.com/problems/longest-binary-subsequence-less-than-or-equal-to-k
 * @lc app=leetcode id=2311 lang=cpp
 * [2311] Longest Binary Subsequence Less Than or Equal to K

You are given a binary string s and a positive integer k.
Return the length of the longest subsequence of s that makes up a binary number less than or equal to k.
Note:
- The subsequence can contain leading zeroes.
- The empty string is considered to be equal to 0.
- A subsequence is a string that can be derived from another string by deleting some or no characters without changing the order of the remaining characters.

이진 문자열 s와 양의 정수 k가 주어집니다.
k보다 작거나 같은 이진수를 만드는 s의 가장 긴 부분 수열의 길이를 반환하세요.
참고:
- 부분 수열은 앞에 0이 와도 됩니다.
- 빈 문자열은 0과 같다고 간주됩니다.
- 부분 수열은 원래 문자열에서 일부 문자를 삭제하거나 삭제하지 않고, 나머지 문자들의 순서를 바꾸지 않고 만들 수 있는 문자열입니다.

Constraints:
1 <= s.length <= 1000
s[i] is either '0' or '1'.
1 <= k <= 10**9
 */

// @lc code=start
class Solution {
public:

    int longestSubsequence(string s, int k) {
        int n = s.size();
        int zeros = 0, ones = 0;
        long long value = 0, pow = 1;

        for (char c : s) {
            if (c == '0') {
                zeros++;
            }
        }

        for (int i = n - 1; i >= 0; i--) {
            if (s[i] == '1') {
                if (value + pow > k) {
                    goto out;  // Skip this '1' as it would exceed k
                }
                value += pow;
                ones++;
            }

            pow <<= 1;
            if (pow > k) break;  // Further bits would exceed k
        }

out:
        return zeros + ones;
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
    // Input: s = "1001010", k = 5
    // Output: 5
    // Explanation: The longest subsequence of s that makes up a binary number less than or equal to 5 is "00010", as this number is equal to 2 in decimal.
    // Note that "00100" and "00101" are also possible, which are equal to 4 and 5 in decimal, respectively.
    // The length of this subsequence is 5, so 5 is returned.
    // 설명: 5 이하의 이진수를 만드는 s의 가장 긴 부분수열은 "00010"이며, 이 수는 십진수로 2와 같다.
    // "00100"과 "00101"도 가능하며, 이들은 각각 십진수로 4와 5와 같다는 점에 주목하라.
    // 이 부분수열의 길이는 5이므로, 5가 반환된다.

    EXPECT_EQ(this->s.longestSubsequence("1001010", 5), 5);
}

TEST_F(CLASS_NAME, __LINE__)
{
    // Example 2:
    // Input: s = "00101001", k = 1
    // Output: 6
    // Explanation: "000001" is the longest subsequence of s that makes up a binary number less than or equal to 1, as this number is equal to 1 in decimal.
    // The length of this subsequence is 6, so 6 is returned.
    // 설명: "000001"은 1 이하의 이진수를 만드는 s의 가장 긴 부분수열이며, 이 수는 십진수로 1과 같다.
    // 이 부분수열의 길이는 6이므로, 6이 반환된다.

    EXPECT_EQ(this->s.longestSubsequence("00101001", 1), 6);
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
