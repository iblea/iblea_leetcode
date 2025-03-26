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



/* https://leetcode.com/problems/minimum-operations-to-make-a-uni-value-grid/?envType=daily-question&envId=2025-03-26
 * @lc app=leetcode id=2033 lang=cpp
 * [2033] Minimum Operations to Make a Uni-Value Grid

You are given a 2D integer grid of size m x n and an integer x. In one operation, you can add x to or subtract x from any element in the grid.
A uni-value grid is a grid where all the elements of it are equal.
Return the minimum number of operations to make the grid uni-value. If it is not possible, return -1.

m x n 크기의 2D 정수 그리드와 정수 x가 주어집니다. 한 번의 연산으로 그리드의 임의의 요소에 x를 더하거나 뺄 수 있습니다.
단일 값 그리드는 모든 요소가 동일한 그리드입니다.
그리드를 단일 값으로 만들기 위한 최소 연산 횟수를 반환하세요. 불가능한 경우 -1을 반환하세요.

Constraints:
m == grid.length
n == grid[i].length
1 <= m, n <= 10**5
1 <= m * n <= 10**5
1 <= x, grid[i][j] <= 10**4
 */

// @lc code=start
class Solution {
public:
    int minOperations(vector<vector<int>>& grid, int x) {
        int m = grid.size();
        int n = grid[0].size();
        vector<int> nums;
        // grid 배열을 1차원 배열로 변환한다.
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                nums.push_back(grid[i][j]);
            }
        }

        // 정렬한 뒤
        sort(nums.begin(), nums.end());
        // 1차원 배열의 요소 값의 차이가 x의 배수인지 확인한다.
        for (int i = 1; i < nums.size(); i++) {
            if ((nums[i] - nums[i-1]) % x != 0) {
                return -1;
            }
        }

        // 최소 연산 횟수를 계산한다.
        // 최소 연산 횟수를 구하기 위해서는, 중간 값을 기준으로 최소 연산 횟수를 계산한다.
        int target = nums[nums.size() / 2];
        int operations = 0;
        for (int num : nums) {
            operations += abs(num - target) / x;
        }
        return operations;

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
    // Input: grid = [[2,4],[6,8]], x = 2
    // Output: 4
    // Explanation: We can make every element equal to 4 by doing the following:
    // - Add x to 2 once.
    // - Subtract x from 6 once.
    // - Subtract x from 8 twice.
    // A total of 4 operations were used.
    // 설명: 다음과 같이 모든 요소를 4로 만들 수 있습니다:
    // - 2에 x를 한 번 더합니다.
    // - 6에서 x를 한 번 뺍니다.
    // - 8에서 x를 두 번 뺍니다.
    // 총 4번의 연산이 사용되었습니다.

    vector<vector<int>> grid = {{2,4},{6,8}};
    int x = 2;
    EXPECT_EQ(this->s.minOperations(grid, x), 4);
}

TEST_F(CLASS_NAME, __LINE__)
{
    // Example 2:
    // Input: grid = [[1,5],[2,3]], x = 1
    // Output: 5
    // Explanation: We can make every element equal to 3.

    vector<vector<int>> grid = {{1,5},{2,3}};
    int x = 1;
    EXPECT_EQ(this->s.minOperations(grid, x), 5);
}

TEST_F(CLASS_NAME, __LINE__)
{
    // Example 3:
    // Input: grid = [[1,2],[3,4]], x = 2
    // Output: -1
    // Explanation: It is impossible to make every element equal.

    vector<vector<int>> grid = {{1,2},{3,4}};
    int x = 2;
    EXPECT_EQ(this->s.minOperations(grid, x), -1);
}


int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
