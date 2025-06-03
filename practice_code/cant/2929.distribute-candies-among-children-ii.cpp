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



/* https://leetcode.com/problems/distribute-candies-among-children-ii/
 * @lc app=leetcode id=2929 lang=cpp
 * [2929] Distribute Candies Among Children II

You are given two positive integers n and limit.
Return the total number of ways to distribute n candies among 3 children such that no child gets more than limit candies.

두 개의 양의 정수 n과 limit가 주어집니다.
3명의 아이들에게 n개의 캔디를 나누어 주되, 어떤 아이도 limit개보다 많은 캔디를 받지 않도록 하는 모든 방법의 수를 반환하세요.

Constraints:
1 <= n <= 10**6
1 <= limit <= 10**6
 */
// @lc code=start
class Solution {
private:
    // Helper function to calculate combinations C(n, r)
    long long combination(long long n, long long r) {
        if (r > n || r < 0) return 0;
        if (r == 0 || r == n) return 1;

        if (r > n - r) r = n - r;

        long long result = 1;
        for (long long i = 0; i < r; i++) {
            result = result * (n - i) / (i + 1);
        }
        return result;
    }
public:
    long long distributeCandies(int n, int limit) {

        long long result = 0;
        int minval = min(n, limit);
        int other;
        for (int i = 0; i <= minval; i++) {
            other = n - i;
            if (other <= 2 * limit) {
                // 두 번째 아이가 받을 수 있는 캔디 개수의 범위
                // 최소 : max(0, other - limit) (세 번째 아이가 limit 개 받고 남은 것)
                // 최대 : min(other, limit) (두 번째 아이가 받을 수 있는 최대 개수)
                // 따라서 최대 - 최소 + 1
                result += min(other, limit) - max(0, other - limit) + 1;
            }
        }
        return result;
    }
    long long distributeCandies_stars_and_bars(int n, int limit) {
        long long total = this->combination(n + 2, 2);

        // 최소 한 명의 아이가 limit보다 많은 캔디를 받는 경우를 빼기
        // 아이 i가 limit보다 많이 받는다면, 먼저 (limit+1)개를 주고 나머지를 분배
        long long subtract1 = 0;
        if (n - (limit + 1) >= 0) {
            subtract1 = 3 * this->combination(n - (limit + 1) + 2, 2);
        }

        // 최소 두 명의 아이가 limit보다 많은 캔디를 받는 경우를 다시 더하기
        long long add2 = 0;
        if (n - 2 * (limit + 1) >= 0) {
            add2 = 3 * this->combination(n - 2 * (limit + 1) + 2, 2);
        }

        // 세 명의 아이가 모두 limit보다 많은 캔디를 받는 경우를 빼기
        long long subtract3 = 0;
        if (n - 3 * (limit + 1) >= 0) {
            subtract3 = this->combination(n - 3 * (limit + 1) + 2, 2);
        }

        return total - subtract1 + add2 - subtract3;
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
    // Input: n = 5, limit = 2
    // Output: 3
    // Explanation: There are 3 ways to distribute 5 candies such that no child gets more than 2 candies: (1, 2, 2), (2, 1, 2) and (2, 2, 1).
    EXPECT_EQ(this->s.distributeCandies(5, 2), 3);
}

TEST_F(CLASS_NAME, __LINE__)
{
    // Example 2:
    // Input: n = 3, limit = 3
    // Output: 10
    // Explanation: There are 10 ways to distribute 3 candies such that no child gets more than 3 candies: (0, 0, 3), (0, 1, 2), (0, 2, 1), (0, 3, 0), (1, 0, 2), (1, 1, 1), (1, 2, 0), (2, 0, 1), (2, 1, 0) and (3, 0, 0).
    EXPECT_EQ(this->s.distributeCandies(3, 3), 10);
}



int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
