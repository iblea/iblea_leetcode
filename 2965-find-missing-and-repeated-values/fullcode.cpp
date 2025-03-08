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



/* https://leetcode.com/problems/find-missing-and-repeated-values/?envType=daily-question&envId=2025-03-06
 * @lc app=leetcode id=2965 lang=cpp
 * [2965] Find Missing and Repeated Values

You are given a 0-indexed 2D integer matrix grid of size n * n with values in the range [1, n**2]. Each integer appears exactly once except a which appears twice and b which is missing. The task is to find the repeating and missing numbers a and b.
Return a 0-indexed integer array ans of size 2 where ans[0] equals to a and ans[1] equals to b.

크기가 n * n인 0-인덱스 기반 2D 정수 행렬 grid가 주어지며, 이 행렬의 값은 [1, n²] 범위 내에 있습니다. 각 정수는 정확히 한 번씩 나타나지만, a는 두 번 나타나고 b는 누락되어 있습니다. 반복되는 숫자 a와 누락된 숫자 b를 찾는 것이 과제입니다.
크기가 2인 0-인덱스 기반 정수 배열 ans를 반환하세요. 여기서 ans[0]은 a와 같고 ans[1]은 b와 같습니다.


Constraints:
2 <= n == grid.length == grid[i].length <= 50
1 <= grid[i][j] <= n * n
For all x that 1 <= x <= n * n there is exactly one x that is not equal to any of the grid members.
For all x that 1 <= x <= n * n there is exactly one x that is equal to exactly two of the grid members.
For all x that 1 <= x <= n * n except two of them there is exatly one pair of i, j that 0 <= i, j <= n - 1 and grid[i][j] == x.
1 <= x <= n * n 범위의 모든 x에 대해, 정확히 하나의 x는 grid의 어떤 원소와도 같지 않습니다.
1 <= x <= n * n 범위의 모든 x에 대해, 정확히 하나의 x는 grid의 원소 중 정확히 두 개와 같습니다.
1 <= x <= n * n 범위의 모든 x에 대해, 두 개의 x를 제외하고는 0 <= i, j <= n - 1인 정확히 하나의 i, j 쌍이 존재하여 grid[i][j] == x를 만족합니다.
 */

// @lc code=start
class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        int a = 0, b = 0;

        set<int> s = {};
        int n = grid.size();
        int value = 0;
        generate_n(inserter(s, s.begin()), n * n, [&value]() { value++; return value; });

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (s.erase(grid[i][j]) == 0) {
                    a = grid[i][j];
                }
            }
        }

        b = *s.begin();
        return vector<int>{a, b};
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
    // Input: grid = [[1,3],[2,2]]
    // Output: [2,4]
    // Explanation: Number 2 is repeated and number 4 is missing so the answer is [2,4].

    vector<vector<int>> grid = {{1,3},{2,2}};
    vector<int> expected = {2,4};

    EXPECT_EQ(this->s.findMissingAndRepeatedValues(grid), expected);
}

TEST_F(CLASS_NAME, __LINE__)
{
    // Example 2:
    // Input: grid = [[9,1,7],[8,9,2],[3,4,6]]
    // Output: [9,5]
    // Explanation: Number 9 is repeated and number 5 is missing so the answer is [9,5].

    vector<vector<int>> grid = {{9,1,7},{8,9,2},{3,4,6}};
    vector<int> expected = {9,5};

    EXPECT_EQ(this->s.findMissingAndRepeatedValues(grid), expected);
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
