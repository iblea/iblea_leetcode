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


/* https://leetcode.com/problems/equal-sum-grid-partition-i/
 * 3546. Equal Sum Grid Partition I | Medium

You are given an m x n matrix grid of positive integers. Your task is to determine if it is possible to make either one horizontal or one vertical cut on the grid such that:
	* Each of the two resulting sections formed by the cut is non-empty.
	* The sum of the elements in both sections is equal.
Return true if such a partition exists; otherwise return false.

m x n 크기의 양의 정수로 이루어진 행렬 grid가 주어집니다. 격자에 수평 또는 수직으로 한 번 잘라서 다음 조건을 만족할 수 있는지 판별하는 것이 과제입니다:
	* 잘라서 만들어진 두 영역이 각각 비어 있지 않아야 합니다.
	* 두 영역의 원소 합이 서로 같아야 합니다.
이러한 분할이 존재하면 true를 반환하고, 그렇지 않으면 false를 반환하십시오.

 Constraints:
	* 1 <= m == grid.length <= 10^5
	* 1 <= n == grid[i].length <= 10^5
	* 2 <= m * n <= 10^5
	* 1 <= grid[i][j] <= 10^5

 */
// @leet start
class Solution {
public:
    bool canPartitionGrid(vector<vector<int>>& grid) {
		long long total = 0;
		int ysize = grid.size();
		int xsize = grid[0].size();
		vector<long long> row_total(ysize, 0);
		vector<long long> column_total(xsize, 0);

		for (int y = 0; y < ysize; ++y) {
			for (int x = 0; x < xsize; ++x) {
				row_total[y] += grid[y][x];
				column_total[x] += grid[y][x];
				total += grid[y][x];
			}
		}

		// 가로 자르기
		long long tmp1 = 0;
		long long tmp2 = total;
		for (int y = 0; y < ysize - 1; ++y) {
			tmp1 += row_total[y];
			tmp2 -= row_total[y];
			if (tmp1 == tmp2) {
				return true;
			}
		}

		// 세로 자르기
		tmp1 = 0;
		tmp2 = total;
		for (int x = 0; x < xsize - 1; ++x) {
			tmp1 += column_total[x];
			tmp2 -= column_total[x];
			if (tmp1 == tmp2) {
				return true;
			}
		}
		return false;
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
    // 󰛨 Example 1:
    // Input: grid = [[1,4],[2,3]]
    // Output: true
    // Explanation:
    // [img](https://assets.leetcode.com/uploads/2025/03/30/lc.png)
    // [img](https://assets.leetcode.com/uploads/2025/03/30/lc.jpeg)
    // A horizontal cut between row 0 and row 1 results in two non-empty sections, each with a sum of 5. Thus, the answer is true.

	vector<vector<int>> grid = {{1,4},{2,3}};
    EXPECT_EQ(this->s.canPartitionGrid(grid), true);
}

TEST_F(CLASS_NAME, __LINE__)
{
    // 󰛨 Example 2:
    // Input: grid = [[1,3],[2,4]]
    // Output: false
    // Explanation:
    // No horizontal or vertical cut results in two non-empty sections with equal sums. Thus, the answer is false.

	vector<vector<int>> grid = {{1,3},{2,4}};
    EXPECT_EQ(this->s.canPartitionGrid(grid), false);
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
