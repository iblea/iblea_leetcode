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



/* https://leetcode.com/problems/largest-submatrix-with-rearrangements/
   1727. Largest Submatrix With Rearrangements | Medium 

You are given a binary matrix matrix of size m x n, and you are allowed to rearrange the columns of the matrix in any order.
Return the area of the largest submatrix within matrix where every element of the submatrix is 1 after reordering the columns optimally.

m x n 크기의 이진 행렬 matrix가 주어지며, 행렬의 열을 임의의 순서로 재배열할 수 있습니다.
열을 최적으로 재배열한 후, 모든 원소가 1인 가장 큰 부분 행렬의 넓이를 반환하시오.


 Constraints:
* m == matrix.length
* n == matrix[i].length
* 1 <= m * n <= 10^5
* matrix[i][j] is either 0 or 1.

 */
class Solution {
public:
    int largestSubmatrix(vector<vector<int>>& matrix) {
		int m = matrix.size();
		int n = matrix[0].size();
		vector<vector<int>> arr(m, vector<int>(n, 0));
		int result = 0;
		for (int i = 0; i < n; i++) {
			arr[0][i] = matrix[0][i];
		}

		// 높이 계산
		for (int i = 1; i < m; i++) {
			for (int j = 0; j < n; j++) {
				if (matrix[i][j] == 1) {
					// 위의 열 중에 1이 연속된 개수를 구한다.
					arr[i][j] = arr[i - 1][j] + 1;
				}
			}
		}

		for (int i = 0; i < m; i++) {
			sort(arr[i].begin(), arr[i].end(), greater<int>());
			for (int j = 0; j < n; j++) {
				// 높이 * (j + 1) = 넓이
				// arr[i][j] = 해당 열까지에 대해 1로 만들 수 있는 최대 높이
				// (j+1) = 해당 너비까지를 사용했을 때
				// arr[i][j] * (j+1) -> 넓이
				result = max(result, arr[i][j] * (j + 1));
			}
		}
        return result;
    }
};



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
    // [img](https://assets.leetcode.com/uploads/2020/12/29/screenshot-2020-12-30-at-40536-pm.png)
    // Input: matrix = [[0,0,1],[1,1,1],[1,0,1]]
    // Output: 4
    // Explanation: You can rearrange the columns as shown above.
    // The largest submatrix of 1s, in bold, has an area of 4.
    // 설명: 위에 보여진 것과 같이 열을 재배열할 수 있습니다.
    // 굵게 표시된 1로 이루어진 가장 큰 부분 행렬의 넓이는 4입니다.

    vector<vector<int>> matrix = {{0,0,1},{1,1,1},{1,0,1}};
    EXPECT_EQ(this->s.largestSubmatrix(matrix), 4);
}

TEST_F(CLASS_NAME, __LINE__)
{
    // 󰛨 Example 2:
    // [img](https://assets.leetcode.com/uploads/2020/12/29/screenshot-2020-12-30-at-40852-pm.png)
    // Input: matrix = [[1,0,1,0,1]]
    // Output: 3
    // Explanation: You can rearrange the columns as shown above.
    // The largest submatrix of 1s, in bold, has an area of 3.
    // 설명: 위에 표시된 것과 같이 열을 재배열할 수 있습니다.
    // 굵게 표시된 1로 이루어진 가장 큰 부분 행렬의 넓이는 3입니다.

    vector<vector<int>> matrix = {{1,0,1,0,1}};
    EXPECT_EQ(this->s.largestSubmatrix(matrix), 3);
}

TEST_F(CLASS_NAME, __LINE__)
{
    // 󰛨 Example 3:
    // Input: matrix = [[1,1,0],[1,0,1]]
    // Output: 2
    // Explanation: Notice that you must rearrange entire columns, and there is no way to make a submatrix of 1s larger than an area of 2.
    // 설명: 열 전체를 재배열해야 하며, 넓이가 2보다 큰 1로 이루어진 부분 행렬을 만들 수 있는 방법은 없습니다.

    vector<vector<int>> matrix = {{1,1,0},{1,0,1}};
    EXPECT_EQ(this->s.largestSubmatrix(matrix), 2);
}


int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
