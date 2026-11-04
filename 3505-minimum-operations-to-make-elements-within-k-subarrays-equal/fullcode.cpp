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


/*

https://leetcode.com/problems/minimum-operations-to-make-elements-within-k-subarrays-equal/
3505 | Hard |  Minimum Operations to Make Elements Within K Subarrays Equal

You are given an integer array nums and two integers, x and k. You can perform the following operation any number of times (including zero):
	* Increase or decrease any element of nums by 1.
Return the minimum number of operations needed to have at least k non-overlapping subarrays of size exactly x in nums, where all elements within each subarray are equal.

󰛨 Example 1:
Input: nums = [5,-2,1,3,7,3,6,4,-1], x = 3, k = 2
Output: 8
Explanation:
	* Use 3 operations to add 3 to nums[1] and use 2 operations to subtract 2 from nums[3]. The resulting array is [5, 1, 1, 1, 7, 3, 6, 4, -1].
	* Use 1 operation to add 1 to nums[5] and use 2 operations to subtract 2 from nums[6]. The resulting array is [5, 1, 1, 1, 7, 4, 4, 4, -1].
	* Now, all elements within each subarray [1, 1, 1] (from indices 1 to 3) and [4, 4, 4] (from indices 5 to 7) are equal. Since 8 total operations were used, 8 is the output.

󰛨 Example 2:
Input: nums = [9,-2,-2,-2,1,5], x = 2, k = 2
Output: 3
Explanation:
	* Use 3 operations to subtract 3 from nums[4]. The resulting array is [9, -2, -2, -2, -2, 5].
	* Now, all elements within each subarray [-2, -2] (from indices 1 to 2) and [-2, -2] (from indices 3 to 4) are equal. Since 3 operations were used, 3 is the output.

 Constraints:
	* 2 <= nums.length <= 10^5
	* -10^6 <= nums[i] <= 10^6
	* 2 <= x <= nums.length
	* 1 <= k <= 15


https://leetcode.com/problems/minimum-operations-to-make-elements-within-k-subarrays-equal/
3505 | 어려움 |  K개의 부분 배열 내 원소를 같게 만들기 위한 최소 연산 횟수

정수 배열 nums와 두 정수 x, k가 주어집니다. 다음 연산을 원하는 만큼(0번 포함) 수행할 수 있습니다.
	* nums의 임의의 원소를 1만큼 증가시키거나 감소시킵니다.
nums에서 크기가 정확히 x이고 서로 겹치지 않는 부분 배열이 최소 k개 존재하며, 각 부분 배열 내의 모든 원소가 같아지도록 만드는 데 필요한 최소 연산 횟수를 반환하십시오.

󰛨 예제 1:
입력: nums = [5,-2,1,3,7,3,6,4,-1], x = 3, k = 2
출력: 8
설명:
	* 3번의 연산으로 nums[1]에 3을 더하고, 2번의 연산으로 nums[3]에서 2를 뺍니다. 결과 배열은 [5, 1, 1, 1, 7, 3, 6, 4, -1]입니다.
	* 1번의 연산으로 nums[5]에 1을 더하고, 2번의 연산으로 nums[6]에서 2를 뺍니다. 결과 배열은 [5, 1, 1, 1, 7, 4, 4, 4, -1]입니다.
	* 이제 부분 배열 [1, 1, 1](인덱스 1부터 3까지)과 [4, 4, 4](인덱스 5부터 7까지) 각각의 모든 원소가 같습니다. 총 8번의 연산을 사용했으므로 출력은 8입니다.

󰛨 예제 2:
입력: nums = [9,-2,-2,-2,1,5], x = 2, k = 2
출력: 3
설명:
	* 3번의 연산으로 nums[4]에서 3을 뺍니다. 결과 배열은 [9, -2, -2, -2, -2, 5]입니다.
	* 이제 부분 배열 [-2, -2](인덱스 1부터 2까지)와 [-2, -2](인덱스 3부터 4까지) 각각의 모든 원소가 같습니다. 3번의 연산을 사용했으므로 출력은 3입니다.

 제약 조건:
	* 2 <= nums.length <= 10^5
	* -10^6 <= nums[i] <= 10^6
	* 2 <= x <= nums.length
	* 1 <= k <= 15
	* 2 <= k * x <= nums.length
 */

// @leet start
class Solution {
private:
    multiset<int> windowL;
    multiset<int> windowR;
    long long sumL;
    long long sumR;

    void initialize() {
        this->windowL.clear();
        this->windowR.clear();
        this->sumL = 0;
        this->sumR = 0;
    }

    void windowBalance() {
        int val;
        while (this->windowL.size() > this->windowR.size() + 1) {
            auto it = prev(this->windowL.end());
            val = *it;
            this->windowR.insert(val);
            this->windowL.erase(it);
            sumL -= val;
            sumR += val;
        }
        while (this->windowL.size() < this->windowR.size()) {
            auto it = this->windowR.begin();
            val = *it;
            this->windowL.insert(val);
            this->windowR.erase(it);
            sumL += val;
            sumR -= val;
        }
    }

    void windowInsert(int n) {
        if (this->windowL.empty() || n <= *(this->windowL).rbegin()) {
            this->windowL.insert(n);
            this->sumL += n;
        } else {
            this->windowR.insert(n);
            this->sumR += n;
        }
        this->windowBalance();
    }
    void windowErase(int n) {
        if (this->windowL.find(n) != this->windowL.end()) {
            this->windowL.erase(this->windowL.find(n));
            this->sumL -= n;
        } else {
            this->windowR.erase(this->windowR.find(n));
            this->sumR -= n;
        }
        this->windowBalance();
    }

    long long windowCost() {
        long long med = *(this->windowL).rbegin();
        return (med * (long long)this->windowL.size() - this->sumL) + (this->sumR - med * (long long)this->windowR.size());
    }

public:
    long long minOperations(vector<int>& nums, int x, int k) {
        vector<long long> costs(nums.size() - x + 1, 0);
        this->initialize();

/*
각 index의 cost 계산 로직
[2,1,2,1,2,-3,2]
[2,1,2]
  [1,2,1]
    [2,1,2]
      [1,2,-3]
        [2,-3,2]
 */

        // 초기값 넣기
        for (int i = 0; i < x; i++) {
            this->windowInsert(nums[i]);
        }
        costs[0] = this->windowCost();

        int repeat_cnt = costs.size() - 1;;
        for (int i = 0; i < repeat_cnt; ++i) {
            this->windowErase(nums[i]);
            this->windowInsert(nums[i + x]);
            costs[i + 1] = this->windowCost();
        }

        // 앞에서 i개의 원소만 봤을 때 길이 x 구간을 j개 만드는 최소 비용
        vector<vector<long long>> dp(nums.size() + 1, vector<long long>(k + 1, -1));

        // AI 리뷰: INF 를 추가하고, 배열 초기값을 INF 로 설정하면, dp 계산할 때, min으로 더 깔끔하게 처리할 수 있다.
        // const long long INF = 1e18;
        // vector<vector<long long>> dp(nums.size() + 1, vector<long long>(k + 1, INF));

        for (int i = 0 ; i < dp.size(); ++i) {
            dp[i][0] = 0;
        }

        // if x = 3 , i = 8 , j = 2
        // [1,2,3,3,4,2,1 | 3]
        // -> [1,2,3,3,4,2,1] (3이 필요없거나) [1,2,3,3,4] [2,1,3] 마지막 x길이만큼의 원소값이 필요하거나
        // min(dp[7][2] , dp[5][1] + cost[5]) -> dp[8][2]
        // dp[i][j] = min(dp[i-1][j], dp[i-x][j-1] + cost[i-x]) -> dp[i][j]

        for (int i = x; i <= nums.size(); ++i) {
            for (int j = 1; j <= k; ++j) {
                long long a = dp[i - 1][j];
                long long b = dp[i - x][j - 1];
                if (b == -1) {
                    dp[i][j] = a;
                    continue;
                } else {
                    dp[i][j] = a == -1 ? b + costs[i - x] : min(a, b + costs[i - x]);
                }
                // dp[i][j] = min(dp[i - 1][j], dp[i - x][j - 1] + costs[i - x]);
            }
        }

        return dp[nums.size()][k];
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
    vector<int> nums = { 5,-2,1,3,7,3,6,4,-1 };
    EXPECT_EQ(this->s.minOperations(nums, 3, 2), 8);
}

TEST_F(CLASS_NAME, __LINE__)
{
    vector<int> nums = { 9,-2,-2,-2,1,5 };
    EXPECT_EQ(this->s.minOperations(nums, 2, 2), 3);
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
