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
 * @lc app=leetcode id=960 lang=cpp
 * [960] Delete Columns to Make Sorted III

You are given an array of n strings strs, all of the same length.
We may choose any deletion indices, and we delete all the characters in those indices for each string.
For example, if we have strs = ["abcdef","uvwxyz"] and deletion indices {0, 2, 3}, then the final array after deletions is ["bef", "vyz"].
Suppose we chose a set of deletion indices answer such that after deletions, the final array has every string (row) in lexicographic order. (i.e., (strs[0][0] <= strs[0][1] <= ... <= strs[0][strs[0].length - 1]), and (strs[1][0] <= strs[1][1] <= ... <= strs[1][strs[1].length - 1]), and so on). Return the minimum possible value of answer.length.

당신에게 n개의 문자열 배열 strs가 주어지며, 모든 문자열은 동일한 길이를 가집니다.
우리는 임의의 삭제 인덱스를 선택할 수 있으며, 각 문자열에서 해당 인덱스들에 있는 모든 문자를 삭제합니다.
예를 들어, strs = ["abcdef","uvwxyz"]이고 삭제 인덱스가 {0, 2, 3}이면, 삭제 후 최종 배열은 ["bef", "vyz"]가 됩니다.
삭제 후 최종 배열의 모든 문자열(행)이 사전순으로 정렬되도록 삭제 인덱스 집합 answer를 선택했다고 가정합시다. (즉, (strs[0][0] <= strs[0][1] <= ... <= strs[0][strs[0].length - 1]), 그리고 (strs[1][0] <= strs[1][1] <= ... <= strs[1][strs[1].length - 1]), 이런 식으로 계속). answer.length의 최소 가능한 값을 반환하세요.

Constraints:
n == strs.length
1 <= n <= 100
1 <= strs[i].length <= 100
strs[i] consists of lowercase English letters.
 */
// @lc code=start
class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        int n = strs.size();
        int m = strs[0].size();

        // arr[x] 로 끝나는 LIS
        vector<int> dp(m, 1);
        for (int j = 0; j < m; j++) {
            for (int i = 0; i < j; i++) {
                bool LIS = true;

                for (int k = 0; k < n; k++) {
                    if (strs[k][i] > strs[k][j]) {
                        LIS = false;
                        break;
                    }
                }
                if (LIS) {
                    dp[j] = max(dp[j], dp[i] + 1);
                }

            }
        }
        int max_keep = *max_element(dp.begin(), dp.end());
        return m - max_keep;
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
    // Input: strs = ["babca","bbazb"]
    // Output: 3
    // Explanation: After deleting columns 0, 1, and 4, the final array is strs = ["bc", "az"].
    // Both these rows are individually in lexicographic order (ie. strs[0][0] <= strs[0][1] and strs[1][0] <= strs[1][1]).
    // Note that strs[0] > strs[1] - the array strs is not necessarily in lexicographic order.

    vector<string> str = { "babca", "bbazb" };
    EXPECT_EQ(this->s.minDeletionSize(str), 3);
}

TEST_F(CLASS_NAME, __LINE__)
{
    // Example 2:
    // Input: strs = ["edcba"]
    // Output: 4
    // Explanation: If we delete less than 4 columns, the only row will not be lexicographically sorted.

    vector<string> str = { "edcba" };
    EXPECT_EQ(this->s.minDeletionSize(str), 4);
}

TEST_F(CLASS_NAME, __LINE__)
{
    // Example 3:
    // Input: strs = ["ghi","def","abc"]
    // Output: 0
    // Explanation: All rows are already lexicographically sorted.

    vector<string> str = { "ghi", "def", "abc" };
    EXPECT_EQ(this->s.minDeletionSize(str), 0);
}

TEST_F(CLASS_NAME, __LINE__)
{
    // Example 4:
    vector<string> str = { "abbba" };
    EXPECT_EQ(this->s.minDeletionSize(str), 1);
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
