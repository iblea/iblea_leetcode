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



/* https://leetcode.com/problems/maximum-total-damage-with-spell-casting/description/?envType=daily-question&envId=2025-10-11
 * @lc app=leetcode id=3186 lang=cpp
 * [3186] Maximum Total Damage With Spell Casting

A magician has various spells.
You are given an array power, where each element represents the damage of a spell. Multiple spells can have the same damage value.
It is a known fact that if a magician decides to cast a spell with a damage of power[i], they cannot cast any spell with a damage of power[i] - 2, power[i] - 1, power[i] + 1, or power[i] + 2.
Each spell can be cast only once.
Return the maximum possible total damage that a magician can cast.

마법사는 다양한 주문을 가지고 있습니다.
power 배열이 주어지며, 각 요소는 주문의 피해량을 나타냅니다. 여러 주문이 동일한 피해량을 가질 수 있습니다.
마법사가 power[i]의 피해량을 가진 주문을 시전하기로 결정하면, power[i] - 2, power[i] - 1, power[i] + 1, 또는 power[i] + 2의 피해량을 가진 어떤 주문도 시전할 수 없다는 것은 알려진 사실입니다.
각 주문은 한 번만 시전할 수 있습니다.
마법사가 시전할 수 있는 최대 총 피해량을 반환하세요.


Example 1:
Input: power = [1,1,3,4]
Output: 6
Explanation:
The maximum possible damage of 6 is produced by casting spells 0, 1, 3 with damage 1, 1, 4.
최대 가능한 피해량 6은 피해량이 1, 1, 4인 주문 0, 1, 3을 시전하여 생성됩니다.

Example 2:
Input: power = [7,1,6,6]
Output: 13
Explanation:
The maximum possible damage of 13 is produced by casting spells 1, 2, 3 with damage 1, 6, 6.
최대 가능한 피해량 13은 피해량이 1, 6, 6인 주문 1, 2, 3을 시전하여 생성됩니다.

Constraints:
1 <= power.length <= 10**5
1 <= power[i] <= 10**9

 */

// @lc code=start
class Solution {
public:
    long long maximumTotalDamage(vector<int>& power) {
        // 1. 빈도수 계산
        map<int, long long> freq;
        for (int p : power) {
            freq[p] += p;  // 값 × 빈도 를 저장
        }

        // 2. 유니크한 값들을 배열로 변환
        vector<pair<int, long long>> unique_vals;  // (값, 총 데미지)
        for (auto& [val, total] : freq) {
            unique_vals.push_back({val, total});
        }

        // { 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 6, 6, 6, 6, 8, 9, 9, 9} -> 5: 50, 9: 27
        // 5와 8을 선택하는 것이 6, 9보다 더 이득.
        // 각 숫자를 모두 선택한 값을 저장해둔 뒤, dp 진행해야 한다.

        int n = unique_vals.size();
        if (n == 0) return 0;
        if (n == 1) return unique_vals[0].second;

        // 3. DP 수행
        vector<long long> dp(n);
        dp[0] = unique_vals[0].second;

        for (int i = 1; i < n; i++) {
            // 선택 안 함
            long long skip = dp[i-1];

            // 선택함 - 제약에 걸리지 않는 가장 가까운 j 찾기
            long long take = unique_vals[i].second;
            for (int j = i - 1; j >= 0; j--) {
                if (unique_vals[i].first - unique_vals[j].first > 2) {
                    take += dp[j];
                    break;
                }
            }

            dp[i] = max(skip, take);
        }

        return dp[n-1];
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
    vector<int> power = {1,1,3,4};
    long long expect = 6;
    long long actual = this->s.maximumTotalDamage(power);
    EXPECT_EQ(expect, actual);
}

TEST_F(CLASS_NAME, __LINE__)
{
    vector<int> power = {7,1,6,6};
    long long expect = 13;
    long long actual = this->s.maximumTotalDamage(power);
    EXPECT_EQ(expect, actual);
}

TEST_F(CLASS_NAME, __LINE__)
{
    vector<int> power = {5,9,2,10,2,7,10,9,3,8};
    long long expect = 31;
    long long actual = this->s.maximumTotalDamage(power);
    EXPECT_EQ(expect, actual);
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

/* 점화식 힌트
"i번째 값을 선택하면, 어느 위치까지 안전하게 돌아갈 수 있을까?"

예를 들어보자:
인덱스: 0   1   2   3   4
값:     1   3   4   6   7

- 인덱스 4 (값=7)을 선택하면?
  - 7-2=5, 7-1=6 이므로 값 6(인덱스 3)과 값 5는 못 씀
  - 값 4(인덱스 2)는? 7-4=3이니까... 괜찮아! ✅
- 인덱스 3 (값=6)을 선택하면?
  - 6-2=4이므로 값 4(인덱스 2)는 못 씀
  - 값 3(인덱스 1)은? 6-3=3이니까... 괜찮아! ✅

패턴이 보이지? 선택한 값에서 -3 이상 떨어진 값들은 안전해!

Step 4: 점화식의 뼈대

dp[i] = i번째까지 고려했을 때 최대 데미지

경우 1: i번째를 선택하지 않음
dp[i] = dp[i-1]
간단하지? 그냥 이전 최적값을 그대로 가져와.

경우 2: i번째를 선택함
dp[i] = (값[i] × 빈도[i]) + dp[j]
여기서 j는 뭘까? 🤔

Step 5: 핵심! j를 어떻게 찾을까?

j는 **"i를 선택해도 제약에 걸리지 않는 가장 가까운 이전 인덱스"**야.

조건: 값[j] < 값[i] - 2

예시로 다시 보자:
인덱스: 0   1   2   3   4
값:     1   3   4   6   7

- i=4 (값=7)일 때
  - 7-2=5이므로 값이 5 미만인 것을 찾아
  - 값 4? 4<5 ✅ → j=2
- i=3 (값=6)일 때
  - 6-2=4이므로 값이 4 미만인 것을 찾아
  - 값 3? 3<4 ✅ → j=1

Step 6: 완성된 점화식 구조

dp[i] = max(
    dp[i-1],                          // i를 선택 안 함
    값[i] × 빈도[i] + dp[j]          // i를 선택함 (j는 안전한 위치)
)

여기서:
- j는 값[j] < 값[i] - 2를 만족하는 가장 큰 인덱스
- 만약 그런 j가 없으면? → dp[j] = 0으로 생각하면 돼
*/