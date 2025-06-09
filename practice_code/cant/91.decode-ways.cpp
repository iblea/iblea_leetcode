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



/* https://leetcode.com/problems/decode-ways
 * @lc app=leetcode id=91 lang=cpp
 * [91] Decode Ways

You have intercepted a secret message encoded as a string of numbers. The message is decoded via the following mapping:

"1" -> 'A'
"2" -> 'B'
...
"25" -> 'Y'
"26" -> 'Z'

However, while decoding the message, you realize that there are many different ways you can decode the message because some codes are contained in other codes ("2" and "5" vs "25").
For example, "11106" can be decoded into:
"AAJF" with the grouping (1, 1, 10, 6)
"KJF" with the grouping (11, 10, 6)
The grouping (1, 11, 06) is invalid because "06" is not a valid code (only "6" is valid).

Note: there may be strings that are impossible to decode.
Given a string s containing only digits, return the number of ways to decode it. If the entire string cannot be decoded in any valid way, return 0.
The test cases are generated so that the answer fits in a 32-bit integer.

당신은 숫자 문자열로 인코딩된 비밀 메시지를 가로챘습니다. 메시지는 다음 매핑을 통해 디코딩됩니다:

"1" -> 'A'
"2" -> 'B'
...
"25" -> 'Y'
"26" -> 'Z'

그러나 메시지를 디코딩하는 동안, 일부 코드가 다른 코드에 포함되어 있기 때문에 메시지를 디코딩하는 방법이 여러 가지가 있다는 것을 깨닫게 됩니다 ("2"와 "5" 대 "25").
예를 들어, "11106"은 다음과 같이 디코딩될 수 있습니다:
그룹화 (1, 1, 10, 6)로 "AAJF"
그룹화 (11, 10, 6)로 "KJF"
그룹화 (1, 11, 06)는 "06"이 유효한 코드가 아니기 때문에 유효하지 않습니다 ("6"만 유효함).

참고: 디코딩이 불가능한 문자열이 있을 수 있습니다.
숫자만 포함하는 문자열 s가 주어졌을 때, 이를 디코딩하는 방법의 수를 반환하세요. 전체 문자열을 어떤 유효한 방법으로도 디코딩할 수 없다면 0을 반환하세요.
테스트 케이스는 답이 32비트 정수에 맞도록 생성됩니다.


Constraints:
1 <= s.length <= 100
s contains only digits and may contain leading zero(s).
 */
// @lc code=start
class Solution {
public:
    int numDecodings(string s) {
        if (s[0] == '0') {
            return 0;
        }

        int n = s.length();

        // dp[i] = dp[i-1](if 1~9) + dp[i-2](if 10~26)
        vector<int> dp(n + 1, 0);
        dp[0] = dp[1] = 1;

        // 1 -> 1
        // 11 -> 2
        // 111 -> 3
        // 1111 -> 5
        // 11111 -> 8
        // 111111 -> 13
        // 11111412 -> 26 (1,1,1,1,1,4,1,2) (1,1,1,1,1,4,12)

        for (int i = 2; i <= n; i++) {
            int one = s[i - 1] - '0';
            int two = stoi(s.substr(i - 2, 2));

            if (1 <= one && one <= 9) {
                dp[i] += dp[i - 1];
            }
            if (10 <= two && two <= 26) {
                dp[i] += dp[i - 2];
            }
        }
        return dp[n];
    }
    int numDecodings1(string s) {

        // 61 -> 1 (6,1)
        // 11 -> 2 (1,1) (11)
        // 17 -> 2 (1,7) (17)
        // 171 -> 2 (1,7,1) (17,1)
        // 1717 -> 4 (1,7,1,7) (17,1,7) (1,7,17) (17,17)
        // 117 -> 3 (1,1,7) (11,7) (1,17)
        // 1176 -> 3 (1,1,7,6) (11,7,6) (1,17,6)
        // 11768 -> 3 (1,1,7,6,8) (11,7,6,8) (1,17,6,8)
        // 1171 -> 3 (1,1,7,1) (11,7,1) (1,17,1)
        // 11711 -> 5 (1,1,7,1,1) (11,7,1,1) (11,7,11) (1,17,1,1) (1,17,11)
        // 1 -> 1 (1)
        // 11 -> 2 (1,1) (11)
        // 111 -> 3 (1,1,1) (11,1) (1,11)
        // 1111 -> 5 (1,1,1,1) (11,1,1) (1,11,1) (1,1,11) (11,11)
        // 11111 -> 8 (1,1,1,1,1) (11,1,1,1) (1,11,1,1) (1,1,11,1) (1,1,1,11) (11,11,1) (11,1,11) (1,11,11)
        // 111111 -> 13 (1,1,1,1,1,1) (11,1,1,1,1) (1,11,1,1,1) (1,1,11,1,1) (1,1,1,11,1) (1,1,1,1,11) (11,11,1,1) (11,1,11,1) (11,1,1,11) (1,11,11,1) (1,11,1,11) (1,1,11,11), (11,11,11)


        // 1,2가 연속되어 나오면 피보나치(n) 만큼 가짓수가 많아진다.
        // 조건1: 1인경우 0~9, 2인경우 다음 숫자가 0~6 까지 피보나치 수를 더할 수 있다.
        // 1,2가 지속 나올 경우 피보나치를 더하고, 기타 숫자가 나올 경우 조건1을 체크하고 피보나치 수를 더할 수 있는 숫자이면 더한 뒤, 가짓수에 추가, 그렇지 못하면 지금까지 구한 숫자를 더한다. ex: (229) 는 2,29 로 디코딩이 불가능함.

        if (s[0] == '0') {
            return 0;
        }

        int n = s.length();
        vector<int> dp(n + 1, 1);
        int count = 1;

        vector<string> divide;
        // 가능한 조각으로 먼저 나눈 뒤에 조각을 하나씩 더해가며 디코딩 가능한지 확인 (0 때문에 디코딩이 가능한 경우인지 확인해야 한다.)
        for (int i = 0; i < n; i++) {
            if (s[i] != '0') {
                divide.push_back(string(1, s[i]));
                continue;
            }
            if (s[i] == '0') {
                int div_size = divide.size() - 1;
                divide[div_size] += s[i];
                if (divide[div_size] == "10" || divide[div_size] == "20") {
                    continue;
                } else {
                    return 0;
                }
            }
        }

        int div_size = divide.size();
        for (int i = 1; i < div_size; i++) {
            if (divide[i-1] == "1") {
                if (divide[i].length() > 1) {
                    // 10, 20
                    if (dp[i] > 1) {
                        count *= dp[i];
                    }
                    continue;
                } else if (divide[i] == "1" || divide[i] == "2") {
                    // 1,2
                    dp[i + 1] = dp[i] == 1 ? 2 : dp[i-1] + dp[i];
                    if (i == div_size - 1) {
                        count *= dp[i+1];
                    }
                    continue;
                } else {
                    // 3,4,5,6,7,8,9
                    dp[i + 1] = dp[i] == 1 ? 2 : dp[i-1] + dp[i];
                    count *= dp[i+1];
                    continue;
                }
            }
            if (divide[i-1] == "2") {
                if (divide[i].length() > 1 || divide[i] > "6") {
                    // 10,20,7,8,9
                    if (dp[i] > 1) {
                        count *= dp[i];
                    }
                    continue;
                } else if ((divide[i] == "1" || divide[i] == "2")) {
                    // 1,2
                    dp[i + 1] = dp[i] == 1 ? 2 : dp[i-1] + dp[i];
                    if (i == div_size - 1) {
                        count *= dp[i+1];
                    }
                } else {
                    // 3,4,5,6
                    dp[i + 1] = dp[i] == 1 ? 2 : dp[i-1] + dp[i];
                    count *= dp[i+1];
                }
            }
            continue;
        }
        return count == 0 ? 1 : count;
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
    // Input: s = "12"
    // Output: 2
    // Explanation:
    // "12" could be decoded as "AB" (1 2) or "L" (12).
    // "12"는 "AB" (1 2) 또는 "L" (12)로 디코딩될 수 있다.

    EXPECT_EQ(this->s.numDecodings("12"), 2);
}

TEST_F(CLASS_NAME, __LINE__)
{
    // Example 2:
    // Input: s = "226"
    // Output: 3
    // Explanation:
    // "226" could be decoded as "BZ" (2 26), "VF" (22 6), or "BBF" (2 2 6).
    // "226"은 "BZ" (2 26), "VF" (22 6), 또는 "BBF" (2 2 6)로 디코딩될 수 있다.

    EXPECT_EQ(this->s.numDecodings("226"), 3);
}

TEST_F(CLASS_NAME, __LINE__)
{
    // Example 3:
    // Input: s = "06"
    // Output: 0
    // Explanation:
    // "06" cannot be mapped to "F" because of the leading zero ("6" is different from "06"). In this case, the string is not a valid encoding, so return 0.
    // "06"은 선두 0("6"은 "06"과 다름) 때문에 "F"로 매핑될 수 없습니다. 이 경우 문자열은 유효한 인코딩이 아니므로 0을 반환합니다.

    EXPECT_EQ(this->s.numDecodings("06"), 0);
}

TEST_F(CLASS_NAME, __LINE__)
{
    EXPECT_EQ(this->s.numDecodings("10"), 1);
}

TEST_F(CLASS_NAME, __LINE__)
{
    EXPECT_EQ(this->s.numDecodings("2101"), 1);
}

TEST_F(CLASS_NAME, __LINE__)
{
    EXPECT_EQ(this->s.numDecodings("2601"), 0);
}

TEST_F(CLASS_NAME, __LINE__)
{
    EXPECT_EQ(this->s.numDecodings("21001"), 0);
}

TEST_F(CLASS_NAME, __LINE__)
{
    // 1, 20, 1, 2, 3, 4
    // 1, 20, 12, 3, 4
    // 1, 20, 1, 23, 4
    EXPECT_EQ(this->s.numDecodings("1201234"), 3);
}

TEST_F(CLASS_NAME, __LINE__)
{
    // 123123
    // (1,2,3,1,2,3) (12,3,1,2,3)(1,23,1,2,3)(1,2,3,12,3)(1,2,3,1,23)
    // (12,3,12,3) (12,3,1,23) (1,23,12,3) (1,23,1,23)
    EXPECT_EQ(this->s.numDecodings("123123"), 9);
}






int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
