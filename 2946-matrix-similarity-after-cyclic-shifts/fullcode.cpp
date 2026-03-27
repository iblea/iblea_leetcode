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


/* https://leetcode.com/problems/matrix-similarity-after-cyclic-shifts/
 * 2946. Matrix Similarity After Cyclic Shifts | Easy

You are given an m x n integer matrix mat and an integer k. The matrix rows are 0-indexed.
The following proccess happens k times:

    * Even-indexed rows (0, 2, 4, ...) are cyclically shifted to the left.
[img](https://assets.leetcode.com/uploads/2024/05/19/lshift.jpg)

    * Odd-indexed rows (1, 3, 5, ...) are cyclically shifted to the right.
[img](https://assets.leetcode.com/uploads/2024/05/19/rshift-stlone.jpg)

Return true if the final modified matrix after k steps is identical to the original matrix, and false otherwise.

정수로 이루어진 m x n 행렬 mat과 정수 k가 주어집니다. 행렬의 행은 0부터 인덱싱됩니다.
다음 과정이 k번 반복됩니다:

    * 짝수 인덱스 행 (0, 2, 4, ...)은 왼쪽으로 순환 이동합니다.

    * 홀수 인덱스 행 (1, 3, 5, ...)은 오른쪽으로 순환 이동합니다.

k번의 과정을 거친 후 최종 변환된 행렬이 원래 행렬과 동일하면 true를, 그렇지 않으면 false를 반환하십시오.


 Constraints:
    * 1 <= mat.length <= 25
    * 1 <= mat[i].length <= 25
    * 1 <= mat[i][j] <= 25
    * 1 <= k <= 50
 */
// @leet start
class Solution {
public:
    bool areSimilar(vector<vector<int>>& mat, int k) {
        int m = mat.size();
        int n = mat[0].size();
        int modk = k%n;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (i % 2 == 0) {
                    // 왼쪽 순환 이동 공식은 (j+k)%n
                    if (mat[i][j] != mat[i][(j+modk)%n]) {
                        return false;
                    }
                } else {
                    // 오른쪽 순환 이동 공식은 (j+n-k)%n
                    if (mat[i][j] != mat[i][(j+n-modk)%n]) {
                        return false;
                    }
                }
            }
        }
        return true;
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
    // Input: mat = [[1,2,3],[4,5,6],[7,8,9]], k = 4
    // Output: false
    // Explanation:
    // In each step left shift is applied to rows 0 and 2 (even indices), and right shift to row 1 (odd index).
    // [img](https://assets.leetcode.com/uploads/2024/05/19/t1-2.jpg)

    vector<vector<int>> mat = {{1,2,3},{4,5,6},{7,8,9}};
    int k = 4;
    EXPECT_EQ(this->s.areSimilar(mat, k), false);
}

TEST_F(CLASS_NAME, __LINE__)
{
    // 󰛨 Example 2:
    // Input: mat = [[1,2,1,2],[5,5,5,5],[6,3,6,3]], k = 2
    // Output: true
    // Explanation:
    // [img](https://assets.leetcode.com/uploads/2024/05/19/t1-3.jpg)

    vector<vector<int>> mat = {{1,2,1,2},{5,5,5,5},{6,3,6,3}};
    int k = 2;
    EXPECT_EQ(this->s.areSimilar(mat, k), true);
}

TEST_F(CLASS_NAME, __LINE__)
{
    // 󰛨 Example 3:
    // Input: mat = [[2,2],[2,2]], k = 3
    // Output: true
    // Explanation:
    // As all the values are equal in the matrix, even after performing cyclic shifts the matrix will remain the same.

    vector<vector<int>> mat = {{2,2},{2,2}};
    int k = 3;
    EXPECT_EQ(this->s.areSimilar(mat, k), true);
}


int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
