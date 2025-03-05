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



/* https://leetcode.com/problems/count-total-number-of-colored-cells/?envType=daily-question&envId=2025-03-05
 * @lc app=leetcode id=2579 lang=cpp
 * [2579] Count Total Number of Colored Cells

There exists an infinitely large two-dimensional grid of uncolored unit cells. You are given a positive integer n, indicating that you must do the following routine for n minutes:
At the first minute, color any arbitrary unit cell blue.
Every minute thereafter, color blue every uncolored cell that touches a blue cell.
Below is a pictorial representation of the state of the grid after minutes 1, 2, and 3.
Return the number of colored cells at the end of n minutes.

무한히 큰 2차원 격자에 색칠되지 않은 단위 셀이 존재합니다. 양의 정수 n이 주어지며, n분 동안 다음 루틴을 수행해야 합니다:
첫 번째 분에는 임의의 단위 셀을 파란색으로 색칠합니다.
그 이후 매 분마다 파란색 셀과 접촉하는 모든 색칠되지 않은 셀을 파란색으로 색칠합니다.
아래는 1분, 2분, 3분 후 격자 상태의 그림 표현입니다.
n분이 끝난 후 색칠된 셀의 수를 반환하세요.

Example 2:
Input: n = 2
Output: 5
Explanation: After 2 minutes, there are 4 colored cells on the boundary and 1 in the center, so we return 5.

Constraints:
1 <= n <= 10**5
 */

// @lc code=start
class Solution {
public:
    long long coloredCells(int n) {
        // 1, 5, 13, 25, 41
        // 1, 2, 3,  4,  5
        // 0, 4, 8, 12,  16

        long long sum = 1;
        long long diff = 4;
        for (int i = 1; i < n; i++) {
            sum += diff;
            diff += 4;
        }
        return sum;
        // return 1 + ((4 * n * (n - 1)) / 2);
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
	// Input: n = 1
	// Output: 1
	// Explanation: After 1 minute, there is only 1 blue cell, so we return 1.
	EXPECT_EQ(this->s.coloredCells(1), 1);
}

TEST_F(CLASS_NAME, __LINE__)
{
	// Example 2:
	// Input: n = 2
	// Output: 5
	// Explanation: After 2 minutes, there are 4 colored cells on the boundary and 1 in the center, so we return 5.
	EXPECT_EQ(this->s.coloredCells(2), 5);
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
