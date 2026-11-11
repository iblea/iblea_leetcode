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


/* https://leetcode.com/problems/minimum-cost-to-acquire-required-items/
3789 | Medium | Minimum Cost to Acquire Required Items

You are given five integers cost1, cost2, costBoth, need1, and need2.
There are three types of items available:
	* An item of type 1 costs cost1 and contributes 1 unit to the type 1 requirement only.
	* An item of type 2 costs cost2 and contributes 1 unit to the type 2 requirement only.
	* An item of type 3 costs costBoth and contributes 1 unit to both type 1 and type 2 requirements.
You must collect enough items so that the total contribution toward type 1 is at least need1 and the total contribution toward type 2 is at least need2.
Return an integer representing the minimum possible total cost to achieve these requirements.

󰛨 Example 1:
Input: cost1 = 3, cost2 = 2, costBoth = 1, need1 = 3, need2 = 2
Output: 3
Explanation:
After buying three type 3 items, which cost 3 * 1 = 3, the total contribution to type 1 is 3 (>= need1 = 3) and to type 2 is 3 (>= need2 = 2).
Any other valid combination would cost more, so the minimum total cost is 3.

󰛨 Example 2:
Input: cost1 = 5, cost2 = 4, costBoth = 15, need1 = 2, need2 = 3
Output: 22
Explanation:
We buy need1 = 2 items of type 1 and need2 = 3 items of type 2: 2 * 5 + 3 * 4 = 10 + 12 = 22.
Any other valid combination would cost more, so the minimum total cost is 22.

󰛨 Example 3:
Input: cost1 = 5, cost2 = 4, costBoth = 15, need1 = 0, need2 = 0
Output: 0
Explanation:
Since no items are required (need1 = need2 = 0), we buy nothing and pay 0.

 Constraints:
	* 1 <= cost1, cost2, costBoth <= 10^6
	* 0 <= need1, need2 <= 10^9

다섯 개의 정수 cost1, cost2, costBoth, need1, need2가 주어집니다.
구매할 수 있는 아이템은 세 가지 타입이 있습니다:
	* 타입 1 아이템은 비용이 cost1이며, 타입 1 요구량에만 1 단위를 기여합니다.
	* 타입 2 아이템은 비용이 cost2이며, 타입 2 요구량에만 1 단위를 기여합니다.
	* 타입 3 아이템은 비용이 costBoth이며, 타입 1과 타입 2 요구량 모두에 각각 1 단위를 기여합니다.
타입 1에 대한 총 기여량이 need1 이상이 되고 타입 2에 대한 총 기여량이 need2 이상이 되도록 충분한 아이템을 모아야 합니다.
이 요구 조건을 만족하는 데 필요한 최소 총 비용을 나타내는 정수를 반환하세요.

󰛨 예제 1:
입력: cost1 = 3, cost2 = 2, costBoth = 1, need1 = 3, need2 = 2
출력: 3
설명:
타입 3 아이템 3개를 3 * 1 = 3의 비용으로 구매하면, 타입 1에 대한 총 기여량은 3 (>= need1 = 3)이 되고 타입 2에 대한 총 기여량은 3 (>= need2 = 2)이 됩니다.
다른 어떤 유효한 조합도 비용이 더 많이 들기 때문에, 최소 총 비용은 3입니다.

󰛨 예제 2:
입력: cost1 = 5, cost2 = 4, costBoth = 15, need1 = 2, need2 = 3
출력: 22
설명:
타입 1 아이템을 need1 = 2개, 타입 2 아이템을 need2 = 3개 구매합니다: 2 * 5 + 3 * 4 = 10 + 12 = 22.
다른 어떤 유효한 조합도 비용이 더 많이 들기 때문에, 최소 총 비용은 22입니다.

󰛨 예제 3:
입력: cost1 = 5, cost2 = 4, costBoth = 15, need1 = 0, need2 = 0
출력: 0
설명:
필요한 아이템이 없으므로 (need1 = need2 = 0), 아무것도 구매하지 않고 0을 지불합니다.

 제약 조건:
	* 1 <= cost1, cost2, costBoth <= 10^6
	* 0 <= need1, need2 <= 10^9
    *
 */

// @leet start
class Solution {
public:
    long long minimumCost(int cost1, int cost2, int costBoth, int need1, int need2) {
        // costBoth >= cost1 + cost2  -> costBoth는 쓰레기값.
        // 경우의 수 1: costBoth 가 아예 필요없는 경우. (낱개로 사는게 더 이득인 경우)
        if (costBoth >= cost1 + cost2) {
            return (long long)cost1 * need1 + (long long)cost2 * need2;
        }

        // 경우의 수 2: costBoth가 필요하되, need1, need2 의 공통 부분만큼만 사는게 이득인 경우.
        // cost1= 1, cost2=100, costBoth=80, need1=2, need2=1
        long long ans;
        if (need1 > need2) {
            ans = (long long)costBoth * need2 + (long long)cost1 * (need1 - need2);
        } else {
            ans = (long long)costBoth * need1 + (long long)cost2 * (need2 - need1);
        }

        // 경우의 수 3: costBoth로 전부 구매하는게 이득인 경우. (cost1= 100, cost2= 99, costBoth=1)
        return min(ans, (long long)costBoth * max(need1, need2));
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
    EXPECT_EQ(this->s.minimumCost(3, 2, 1, 3, 2), 3);
}

TEST_F(CLASS_NAME, __LINE__)
{
    EXPECT_EQ(this->s.minimumCost(5, 4, 15, 2, 3), 22);
}

TEST_F(CLASS_NAME, __LINE__)
{
    EXPECT_EQ(this->s.minimumCost(5, 4, 15, 0, 0), 0);
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
