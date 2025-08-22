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
#include <list>

using namespace std;



/* https://leetcode.com/problems/sum-of-k-mirror-numbers
 * @lc app=leetcode id=2081 lang=cpp
 * [2081] Sum of k-Mirror Numbers

A k-mirror number is a positive integer without leading zeros that reads the same both forward and backward in base-10 as well as in base-k.
For example, 9 is a 2-mirror number. The representation of 9 in base-10 and base-2 are 9 and 1001 respectively, which read the same both forward and backward.
On the contrary, 4 is not a 2-mirror number. The representation of 4 in base-2 is 100, which does not read the same both forward and backward.
Given the base k and the number n, return the sum of the n smallest k-mirror numbers.

k-mirror 수는 앞자리 0이 없는 양의 정수로, 10진법과 k진법 모두에서 앞뒤로 읽었을 때 같은 수입니다.
예를 들어, 9는 2-mirror 수입니다. 9를 10진법과 2진법으로 나타내면 각각 9와 1001이며, 둘 다 앞뒤로 읽었을 때 같습니다.
반대로, 4는 2-mirror 수가 아닙니다. 4를 2진법으로 나타내면 100이며, 이는 앞뒤로 읽었을 때 같지 않습니다.
주어진 진법 k와 수 n에 대해, 가장 작은 n개의 k-mirror 수들의 합을 반환하세요.

Constraints:
2 <= k <= 9
1 <= n <= 30
 */
// @lc code=start
class Solution {

    // k 자릿수의 펠린드롬 수를 생성하는 함수
    list<long long> generate_palindromes(int k) {
        list<long long> palindromes;

        if (k == 1) {
            for (int i = 1; i <= 9; i++) {
                palindromes.push_back(i);
            }
            return palindromes;
        }

        // 짝수와 홀수는 펠린드롬 생성이 살짝 다름.
        bool isOdd = (k % 2 == 1);
        int halfLength = (k + 1) / 2;  // 앞쪽 절반 길이

        // 앞쪽 절반의 시작값과 끝값 계산
        long long start = pow(10, halfLength - 1);
        long long end = pow(10, halfLength) - 1;

        for (long long half = start; half <= end; half++) {
            // 앞쪽 절반 자릿수를 통해 펠린드롬 수를 생성함.
            // k = 3
            // makePalindrome(10, 3, true) -> 101
            // makePalindrome(11, 3, true) -> 111
            // makePalindrome(12, 3, true) -> 121
            // ...

            // k = 4
            // makePalindrome(10, 3, true) -> 1001
            // makePalindrome(11, 3, true) -> 1111
            // makePalindrome(12, 3, true) -> 1221
            // ...
            long long palindrome = makePalindrome(half, k, isOdd);
            palindromes.push_back(palindrome);
        }

        return palindromes;
    }
    // 앞쪽 절반으로 전체 팰린드롬 만들기 (이 함수도 추가해야 함)
    long long makePalindrome(long long half, int totalLength, bool isOdd) {
        long long result = half;
        long long temp = half;

        if (isOdd) {
            temp /= 10; // 가운데 자리 제거
        }

        // 뒤쪽 절반을 앞쪽 절반의 역순으로 만들기
        while (temp > 0) {
            result = result * 10 + (temp % 10);
            temp /= 10;
        }

        return result;
    }

    // 십진수 숫자 num을 k진수로 변환하고, 변환된 수가 펠린드롬 수인지 판별하는 함수
    bool check_k_palindrome(long long num, int k) {
        if (num == 0) return true;

        long long original = num;
        long long reversed = 0;

        // k진법으로 뒤집기
        while (num > 0) {
            reversed = reversed * k + (num % k);
            num /= k;
        }

        return original == reversed;
    }

public:
    long long kMirror(int k, int n) {

        int count = 0;
        int digits = 1;
        long long result = 0;
        while (true) {
            list<long long> palindromes = generate_palindromes(digits);
            palindromes.sort();
            for (auto palindrome : palindromes) {
                if (check_k_palindrome(palindrome, k)) {
                    result += palindrome;
                    count++;
                    if (count >= n) {
                        return result;
                    }
                }
            }

            digits++;
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
    // Input: k = 2, n = 5
    // Output: 25
    // Explanation:
    // The 5 smallest 2-mirror numbers and their representations in base-2 are listed as follows:
    //   base-10    base-2
    //     1          1
    //     3          11
    //     5          101
    //     7          111
    //     9          1001
    // Their sum = 1 + 3 + 5 + 7 + 9 = 25.

    EXPECT_EQ(this->s.kMirror(2, 5), 25);
}

TEST_F(CLASS_NAME, __LINE__)
{
    // Example 2:
    // Input: k = 3, n = 7
    // Output: 499
    // Explanation:
    // The 7 smallest 3-mirror numbers are and their representations in base-3 are listed as follows:
    //   base-10    base-3
    //     1          1
    //     2          2
    //     4          11
    //     8          22
    //     121        11111
    //     151        12121
    //     212        21212
    // Their sum = 1 + 2 + 4 + 8 + 121 + 151 + 212 = 499.

    EXPECT_EQ(this->s.kMirror(3, 7), 499);
}

TEST_F(CLASS_NAME, __LINE__)
{
    // Example 3:
    // Input: k = 7, n = 17
    // Output: 20379000
    // Explanation: The 17 smallest 7-mirror numbers are:
    // 1, 2, 3, 4, 5, 6, 8, 121, 171, 242, 292, 16561, 65656, 2137312, 4602064, 6597956, 6958596

    EXPECT_EQ(this->s.kMirror(7, 17), 20379000);
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
