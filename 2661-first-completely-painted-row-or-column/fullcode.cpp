#include <gtest/gtest.h>
#include <iostream>
#include <iomanip>
#include <algorithm>
#include <vector>
#include <string>
#include <map>

using namespace std;


/* https://leetcode.com/problems/first-completely-painted-row-or-column/?envType=daily-question&envId=2025-01-20
 * @lc app=leetcode id=2661 lang=cpp
 * [2661] First Completely Painted Row or Column

You are given a 0-indexed integer array arr, and an m x n integer matrix mat. arr and mat both contain all the integers in the range [1, m * n].
Go through each index i in arr starting from index 0 and paint the cell in mat containing the integer arr[i].
Return the smallest index i at which either a row or a column will be completely painted in mat.

0-인덱스 정수 배열 arr과 m x n 정수 행렬 mat이 주어집니다. arr과 mat는 모두 [1, m * n] 범위의 모든 정수를 포함합니다.
인덱스 0부터 시작하여 arr의 각 인덱스 i를 순회하면서 arr[i] 정수를 포함하는 mat의 셀을 칠합니다.
mat에서 행이나 열이 완전히 칠해지는 가장 작은 인덱스 i를 반환합니다.

Constraints:
- m == mat.length
- n = mat[i].length
- arr.length == m * n
- 1 <= m, n <= 10**5
- 1 <= m * n <= 10**5
- 1 <= arr[i], mat[r][c] <= m * n
- All the integers of arr are unique.
- All the integers of mat are unique.
 */
// @lc code=start
class Solution {
public:
    int firstCompleteIndex(vector<int>& arr, vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();
        int total = m * n;
        vector<pair<int, int>> matpos(total + 1, {0, 0});
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                matpos[mat[i][j]] = {i, j};
            }
        }

        vector<int> rowcnt(m, 0); // rowcnt[i] == n
        vector<int> colcnt(n, 0); // colcnt[i] == m
        pair<int, int> pos;
        int i = 0;
        for (i = 0; i < total; i++) {
            pos = matpos[arr[i]];
            rowcnt[pos.first]++;
            colcnt[pos.second]++;
            if (rowcnt[pos.first] == n || colcnt[pos.second] == m) {
                break;
            }
        }
        return i;
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
    // Input: arr = [1,3,4,2], mat = [[1,4],[2,3]]
    // Output: 2
    // Explanation: The moves are shown in order, and both the first row and second column of the matrix become fully painted at arr[2].
    // 설명: 이동이 순서대로 표시되며, 행렬의 첫 번째 행과 두 번째 열이 모두 arr[2]에서 완전히 칠해집니다.

    vector<int> arr = {1,3,4,2};
    vector<vector<int>> mat = {{1,4},{2,3}};
	EXPECT_EQ(this->s.firstCompleteIndex(arr, mat), 2);
}

TEST_F(CLASS_NAME, __LINE__)
{
    // Example 2:
    // Input: arr = [2,8,7,4,1,3,5,6,9], mat = [[3,2,5],[1,4,6],[8,7,9]]
    // Output: 3
    // Explanation: The second column becomes fully painted at arr[3].

    vector<int> arr = {2,8,7,4,1,3,5,6,9};
    vector<vector<int>> mat = {{3,2,5},{1,4,6},{8,7,9}};
	EXPECT_EQ(this->s.firstCompleteIndex(arr, mat), 3);
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}