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



/* https://leetcode.com/problems/avoid-flood-in-the-city/
 * @lc app=leetcode id=1488 lang=cpp
 * [1488] Avoid Flood in The City

Your country has an infinite number of lakes. Initially, all the lakes are empty, but when it rains over the nth lake, the nth lake becomes full of water. If it rains over a lake that is full of water, there will be a flood. Your goal is to avoid floods in any lake.
Given an integer array rains where:
- rains[i] > 0 means there will be rains over the rains[i] lake.
- rains[i] == 0 means there are no rains this day and you can choose one lake this day and dry it.
Return an array ans where:
- ans.length == rains.length
- ans[i] == -1 if rains[i] > 0.
- ans[i] is the lake you choose to dry in the ith day if rains[i] == 0.
If there are multiple valid answers return any of them. If it is impossible to avoid flood return an empty array.
Notice that if you chose to dry a full lake, it becomes empty, but if you chose to dry an empty lake, nothing changes.

당신의 나라에는 무한한 수의 호수가 있습니다. 처음에는 모든 호수가 비어 있지만, n번째 호수에 비가 내리면 n번째 호수가 물로 가득 차게 됩니다. 물로 가득 찬 호수에 비가 내리면 홍수가 발생합니다. 당신의 목표는 어떤 호수에서도 홍수를 피하는 것입니다.
정수 배열 rains가 주어지며:
- rains[i] > 0은 rains[i] 호수에 비가 내릴 것을 의미합니다.
- rains[i] == 0은 이 날 비가 없으며 이 날 하나의 호수를 선택하여 물을 뺄 수 있음을 의미합니다.
배열 ans를 반환하며:
- ans.length == rains.length
- rains[i] > 0이면 ans[i] == -1입니다.
- rains[i] == 0이면 ans[i]는 i번째 날에 물을 뺄 호수입니다.
여러 개의 유효한 답이 있으면 그 중 아무거나 반환하십시오. 홍수를 피하는 것이 불가능하면 빈 배열을 반환하십시오.
물로 가득 찬 호수의 물을 빼면 비게 되지만, 빈 호수의 물을 빼도 아무 것도 변하지 않습니다.


Example 1:
Input: rains = [1,2,3,4]
Output: [-1,-1,-1,-1]
Explanation: After the first day full lakes are [1]
After the second day full lakes are [1,2]
After the third day full lakes are [1,2,3]
After the fourth day full lakes are [1,2,3,4]
There's no day to dry any lake and there is no flood in any lake.

설명: 첫째 날 이후 가득 찬 호수는 [1]입니다
둘째 날 이후 가득 찬 호수는 [1,2]입니다
셋째 날 이후 가득 찬 호수는 [1,2,3]입니다
넷째 날 이후 가득 찬 호수는 [1,2,3,4]입니다
호수의 물을 뺄 날이 없으며 어떤 호수에서도 홍수가 발생하지 않습니다.

Example 2:
Input: rains = [1,2,0,0,2,1]
Output: [-1,-1,2,1,-1,-1]
Explanation: After the first day full lakes are [1]
After the second day full lakes are [1,2]
After the third day, we dry lake 2. Full lakes are [1]
After the fourth day, we dry lake 1. There is no full lakes.
After the fifth day, full lakes are [2].
After the sixth day, full lakes are [1,2].
It is easy that this scenario is flood-free. [-1,-1,1,2,-1,-1] is another acceptable scenario.

설명: 첫째 날 이후 가득 찬 호수는 [1]입니다
둘째 날 이후 가득 찬 호수는 [1,2]입니다
셋째 날, 우리는 호수 2의 물을 뺍니다. 가득 찬 호수는 [1]입니다
넷째 날, 우리는 호수 1의 물을 뺍니다. 가득 찬 호수가 없습니다.
다섯째 날 이후, 가득 찬 호수는 [2]입니다.
여섯째 날 이후, 가득 찬 호수는 [1,2]입니다.
이 시나리오는 홍수가 없음이 명백합니다. [-1,-1,1,2,-1,-1]도 다른 허용 가능한 시나리오입니다.

Example 3:
Input: rains = [1,2,0,1,2]
Output: []
Explanation: After the second day, full lakes are  [1,2]. We have to dry one lake in the third day.
After that, it will rain over lakes [1,2]. It's easy to prove that no matter which lake you choose to dry in the 3rd day, the other one will flood.

설명: 둘째 날 이후, 가득 찬 호수는 [1,2]입니다. 우리는 셋째 날에 하나의 호수를 말려야 합니다.
그 후, 호수 [1,2]에 비가 내릴 것입니다. 3일째에 어느 호수를 말리든 다른 호수에서 홍수가 발생할 것임을 증명하기는 쉽습니다.


Constraints:
1 <= rains.length <= 10**5
0 <= rains[i] <= 10**9
 */

// @lc code=start
class Solution {
public:
    vector<int> avoidFlood(vector<int>& rains) {
        // key: 호수 번호, value: 마지막으로 비가 온 날
        unordered_map<int, int> lake_map;
        // 물을 뺄 수 있는 날
        set<int> dry_days;
        vector<int> result(rains.size(), 1);

        for (int i = 0; i < rains.size(); ++i) {
            int lake = rains[i];

            // 비가 안옴.
            if (lake == 0) {
                // 물을 뺄 수 있는 날로 추가
                dry_days.insert(i);
                continue;
            }

            // 비가 옴.
            result[i] = -1;
            if (lake_map.find(lake) != lake_map.end()) {
                // 이미 비가 온 적이 있는 호수라면, 물을 뺄 날을 찾아야 함
                auto it = dry_days.lower_bound(lake_map[lake]);
                if (it == dry_days.end()) {
                    // 물을 뺄 날이 없음 -> 홍수 발생
                    return {};
                }

                // 해당 날에 물을 빼는 것으로 처리하고, 물 뺀 날 제거
                result[*it] = lake;
                dry_days.erase(it);
            }
            lake_map[lake] = i;
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
    vector<int> rains = {1,2,0,0,2,1};
    vector<int> expected = {-1,-1,2,1,-1,-1};
    EXPECT_EQ(this->s.avoidFlood(rains), expected);
}

TEST_F(CLASS_NAME, __LINE__)
{
    vector<int> rains = {1,2,3,4};
    vector<int> expected = {-1,-1,-1,-1};
    EXPECT_EQ(this->s.avoidFlood(rains), expected);
}

TEST_F(CLASS_NAME, __LINE__)
{
    vector<int> rains = {1,2,0,1,2};
    vector<int> expected = {};
    EXPECT_EQ(this->s.avoidFlood(rains), expected);
}

TEST_F(CLASS_NAME, __LINE__)
{
    vector<int> rains = {69,0,0,0,69};
    vector<int> expected = {-1,69,1,1,-1};
    EXPECT_EQ(this->s.avoidFlood(rains), expected);
    /*
    🐛 문제 발견!

    핵심 이슈

    사용하지 않은 건조 날(인덱스 2, 3)이 -1로 남아있어!

    문제 요구사항 재확인

    - rains[i] == 0 means there are no rains this day
      and you can choose one lake this day and dry it.

    건조 날(rains[i] == 0)에는 반드시 어떤 호수를 선택해야 해!
    - 홍수 방지에 꼭 필요한 날: 실제 호수 번호
    - 필요 없는 날: 아무 호수나 (예: 1)

    왜 expected가 {-1, 69, 1, 1, -1}일까?

    - 인덱스 0: 비 → -1 ✅
    - 인덱스 1: 건조 날, 호수 69 말림 → 69 ✅
    - 인덱스 2: 건조 날, 사용 안 함 → 1 (아무 호수) ✅
    - 인덱스 3: 건조 날, 사용 안 함 → 1 (아무 호수) ✅
    - 인덱스 4: 비 → -1 ✅
    */
}


int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
