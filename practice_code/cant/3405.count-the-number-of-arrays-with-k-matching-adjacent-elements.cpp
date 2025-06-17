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



/* https://leetcode.com/problems/count-the-number-of-arrays-with-k-matching-adjacent-elements
 * @lc app=leetcode id=3405 lang=cpp
 * [3405] Count the Number of Arrays with K Matching Adjacent Elements

You are given three integers n, m, k. A good array arr of size n is defined as follows:
Each element in arr is in the inclusive range [1, m].
Exactly k indices i (where 1 <= i < n) satisfy the condition arr[i - 1] == arr[i].
Return the number of good arrays that can be formed.
Since the answer may be very large, return it modulo (10**9) + 7.

세 개의 정수 n, m, k가 주어집니다. 크기가 n인 좋은 배열 arr은 다음과 같이 정의됩니다:
arr의 각 원소는 [1, m] 범위에 포함됩니다.
정확히 k개의 인덱스 i (1 <= i < n)가 arr[i - 1] == arr[i] 조건을 만족합니다.
형성할 수 있는 좋은 배열의 개수를 반환하세요.
답이 매우 클 수 있으므로, (10**9) + 7로 나눈 나머지를 반환하세요.

Constraints:
1 <= n <= 10**5
1 <= m <= 10**5
0 <= k <= n - 1
 */
// @lc code=start
class Solution {
private:
    static const int MOD = 1000000007;

    // 빠른 거듭제곱 (O(log n))
    long long power(long long base, long long exp, long long mod) {
        long long result = 1;
        while (exp > 0) {
            if (exp % 2 == 1) {
                result = (result * base) % mod;
            }
            base = (base * base) % mod;
            exp /= 2;
        }
        return result;
    }

    // 팩토리얼과 역원 계산
    long long factorial(int n) {
        long long result = 1;
        for (int i = 1; i <= n; i++) {
            result = (result * i) % MOD;
        }
        return result;
    }

    // nCr 계산 (조합)
    long long combination(int n, int r) {
        if (r > n || r < 0) return 0;
        if (r == 0 || r == n) return 1;

        long long num = factorial(n);
        long long den = (factorial(r) * factorial(n - r)) % MOD;
        long long inv_den = power(den, MOD - 2, MOD); // 페르마의 소정리

        return (num * inv_den) % MOD;
    }

public:
    // 수학적 솔루션 (O(log n))
    int countGoodArrays(int n, int m, int k) {
        if (k > n - 1) return 0;

        /*
        조합론적 접근 상세 설명:

        예시: n=4, m=3, k=2 (배열 크기 4, 값 범위 1~3, 같은 쌍 2개)

        1단계: 인접한 위치들 파악
        배열: [a, b, c, d]
        인접 위치: (a,b), (b,c), (c,d) → 총 n-1 = 3개

        2단계: k개 위치를 "같은 값"으로 설정
        3개 위치 중 2개를 선택: C(3,2) = 3가지
        - (a,b), (b,c) 선택 → a=b=c, d는 다름
        - (a,b), (c,d) 선택 → a=b, c=d, b≠c
        - (b,c), (c,d) 선택 → b=c=d, a는 다름

        3단계: 각 경우의 수 계산
        경우 1: a=b=c≠d
        - a 선택: m가지 (1,2,3 중 아무거나)
        - d 선택: (m-1)가지 (a와 달라야 함)
        - 총: m × (m-1) = 3 × 2 = 6가지

        경우 2: a=b≠c=d
        - a 선택: m가지
        - c 선택: (m-1)가지 (a와 달라야 함)
        - 총: m × (m-1) = 6가지

        경우 3: a≠b=c=d
        - b 선택: m가지
        - a 선택: (m-1)가지 (b와 달라야 함)
        - 총: m × (m-1) = 6가지

        결과: C(3,2) × m × (m-1)^1 = 3 × 3 × 2 = 18
        */

        // 핵심 공식: C(n-1, k) × m × (m-1)^(n-1-k)
        // - C(n-1, k): n-1개 인접 위치 중 k개를 "같은 값"으로 선택
        // - m: 첫 번째 원소(또는 첫 번째 "같은 그룹")의 값 선택
        // - (m-1)^(n-1-k): 나머지 (n-1-k)개 "다른 값" 위치들의 선택

        long long ways = combination(n - 1, k);
        ways = (ways * m) % MOD;
        ways = (ways * power(m - 1, n - 1 - k, MOD)) % MOD;

        return (int)ways;
    }

    // 기존 DP 솔루션 (O(n*k))
    int countGoodArrays_dp(int n, int m, int k) {
        vector<vector<long long>> dp(n + 1, vector<long long>(k + 1, 0));
        // dp[i][j]: i번째 원소까지 배치했을 때 j개의 인접한 같은 쌍을 가진 배열의 개수
        dp[1][0] = m;
        // 첫 번쨰 원소로는 k >= 1 을 절대로 만족시킬 수 없다.
        for (int j = 1; j <= k; j++) {
            dp[1][j] = 0;
        }
        for (int i = 2; i <= n; i++) {
            // i = 2, k = 0, m = 3
            // [1] -> [1](2,3)
            // [2] -> [2](1,3)
            // [3] -> [3](1,2)
            dp[i][0] = (dp[i-1][0] * (long long)(m - 1)) % MOD;
            for (int j = 1; j <= k; j++) {
                // 같은 쌍을 만족시켜서 k를 1증가 또는
                // 1,2,3(3)
                // 1,3,2(2)
                // ...
                // 이전 만족되는 쌍에서 다른 값을 추가시켜 k 증가X
                // 1,2,2(1,3)
                dp[i][j] = (dp[i-1][j-1] + (dp[i-1][j] * (long long)(m - 1)) % MOD) % MOD;
            }
        }

        return (int)dp[n][k];
    }

    // 공간 최적화된 DP (O(n*k) 시간, O(k) 공간)
    int countGoodArraysOptimized(int n, int m, int k) {
        vector<long long> prev(k + 1, 0);
        vector<long long> curr(k + 1, 0);

        prev[0] = m;  // 첫 번째 원소

        for (int i = 2; i <= n; i++) {
            curr[0] = (prev[0] * (long long)(m - 1)) % MOD;

            for (int j = 1; j <= k; j++) {
                curr[j] = (prev[j - 1] + (prev[j] * (long long)(m - 1)) % MOD) % MOD;
            }

            swap(prev, curr);
            // prev = curr;
            // fill(curr.begin(), curr.end(), 0);
        }

        return (int)prev[k];
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
    // Input: n = 3, m = 2, k = 1
    // Output: 4
    // Explanation:
    // There are 4 good arrays. They are [1, 1, 2], [1, 2, 2], [2, 1, 1] and [2, 2, 1].
    // Hence, the answer is 4.

    EXPECT_EQ(this->s.countGoodArrays(3, 2, 1), 4);
    EXPECT_EQ(this->s.countGoodArraysMath(3, 2, 1), 4);
    EXPECT_EQ(this->s.countGoodArraysOptimized(3, 2, 1), 4);
}

TEST_F(CLASS_NAME, __LINE__)
{
    // Example 2:
    // Input: n = 4, m = 2, k = 2
    // Output: 6
    // Explanation:
    // The good arrays are [1, 1, 1, 2], [1, 1, 2, 2], [1, 2, 2, 2], [2, 1, 1, 1], [2, 2, 1, 1] and [2, 2, 2, 1].
    // Hence, the answer is 6.

    EXPECT_EQ(this->s.countGoodArrays(4, 2, 2), 6);
    EXPECT_EQ(this->s.countGoodArraysMath(4, 2, 2), 6);
    EXPECT_EQ(this->s.countGoodArraysOptimized(4, 2, 2), 6);
}

TEST_F(CLASS_NAME, __LINE__)
{
    // Example 3:
    // Input: n = 5, m = 2, k = 0
    // Output: 2
    // Explanation:
    // The good arrays are [1, 2, 1, 2, 1] and [2, 1, 2, 1, 2]. Hence, the answer is 2.

    EXPECT_EQ(this->s.countGoodArrays(5, 2, 0), 2);
    EXPECT_EQ(this->s.countGoodArraysMath(5, 2, 0), 2);
    EXPECT_EQ(this->s.countGoodArraysOptimized(5, 2, 0), 2);
}

TEST_F(CLASS_NAME, __LINE__)
{
    // 조합론적 접근 검증 테스트
    // n=4, m=3, k=2의 상세 분석

    /*
    수학적 계산:
    C(4-1, 2) × 3 × (3-1)^(4-1-2) = C(3,2) × 3 × 2^1 = 3 × 3 × 2 = 18

    실제 경우들:
    경우 1: a=b=c≠d (인접쌍: ab, bc)
    [1,1,1,2], [1,1,1,3], [2,2,2,1], [2,2,2,3], [3,3,3,1], [3,3,3,2] → 6개

    경우 2: a=b≠c=d (인접쌍: ab, cd)
    [1,1,2,2], [1,1,3,3], [2,2,1,1], [2,2,3,3], [3,3,1,1], [3,3,2,2] → 6개

    경우 3: a≠b=c=d (인접쌍: bc, cd)
    [1,2,2,2], [1,3,3,3], [2,1,1,1], [2,3,3,3], [3,1,1,1], [3,2,2,2] → 6개

    총합: 6 + 6 + 6 = 18개
    */

    EXPECT_EQ(this->s.countGoodArrays(4, 3, 2), 18);
    EXPECT_EQ(this->s.countGoodArraysMath(4, 3, 2), 18);
    EXPECT_EQ(this->s.countGoodArraysOptimized(4, 3, 2), 18);
}


int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
