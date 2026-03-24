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


/* https://leetcode.com/problems/construct-product-matrix/
 * 2906. Construct Product Matrix | Medium

Given a 0-indexed 2D integer matrix grid of size n * m, we define a 0-indexed 2D matrix p of size n * m as the product matrix of grid if the following condition is met:
    * Each element p[i][j] is calculated as the product of all elements in grid except for the element grid[i][j]. This product is then taken modulo 12345.
Return the product matrix of grid.

크기가 n * m인 0-인덱스 2D 정수 행렬 grid가 주어질 때, 다음 조건을 만족하면 크기가 n * m인 0-인덱스 2D 행렬 p를 grid의 곱 행렬로 정의합니다:
    * 각 원소 p[i][j]는 grid[i][j]를 제외한 grid의 모든 원소의 곱으로 계산됩니다. 이 곱은 12345로 나눈 나머지를 취합니다.
grid의 곱 행렬을 반환하십시오.

 Constraints:
    * 1 <= n == grid.length <= 10^5
    * 1 <= m == grid[i].length <= 10^5
    * 2 <= n * m <= 10^5
    * 1 <= grid[i][j] <= 10^9

 */
// @leet start
class Solution {
private:
    static constexpr int MOD = 12345;
public:
    vector<vector<int>> constructProductMatrix(vector<vector<int>>& grid) {

        // 2차원 배열을 1차원 배열로 변환
        vector<int> arr;
        int y = grid.size();
        int x = grid[0].size();
        for (int i = 0; i < y; ++i) {
            for (int j = 0; j < x; ++j) {
                arr.push_back(grid[i][j]);
            }
        }
        size_t n = arr.size();

        vector<int> prefix(n, 1);
        vector<int> suffix(n, 1);
        for (size_t i = 1; i < n; ++i) {
            prefix[i] = (long long)prefix[i - 1] * arr[i - 1] % MOD;
            suffix[n-i-1] = (long long)suffix[n-i] * arr[n-i] % MOD;
        }

        vector<vector<int>> result(y, vector<int>(x, 0));
        for (int i = 0; i < y; ++i) {
            for (int j = 0; j < x; ++j) {
                result[i][j] = (prefix[i * x + j] * suffix[i * x + j]) % MOD;
            }
        }
        return result;
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
    //     │ Input: grid = [[1,2],[3,4]]
    //     │ Output: [[24,12],[8,6]]
    //     │ Explanation: p[0][0] = grid[0][1] * grid[1][0] * grid[1][1] = 2 * 3 * 4 = 24
    //     │ p[0][1] = grid[0][0] * grid[1][0] * grid[1][1] = 1 * 3 * 4 = 12
    //     │ p[1][0] = grid[0][0] * grid[0][1] * grid[1][1] = 1 * 2 * 4 = 8
    //     │ p[1][1] = grid[0][0] * grid[0][1] * grid[1][0] = 1 * 2 * 3 = 6
    //     │ So the answer is [[24,12],[8,6]].

    vector<vector<int>> grid = {{1,2},{3,4}};
    vector<vector<int>> answer = this->s.constructProductMatrix(grid);
    vector<vector<int>> expected = {{24,12},{8,6}};
    EXPECT_EQ(answer, expected);
}

TEST_F(CLASS_NAME, __LINE__)
{
    // 󰛨 Example 2:
    //     │ Input: grid = [[12345],[2],[1]]
    //     │ Output: [[2],[0],[0]]
    //     │ Explanation: p[0][0] = grid[0][1] * grid[0][2] = 2 * 1 = 2.
    //     │ p[0][1] = grid[0][0] * grid[0][2] = 12345 * 1 = 12345. 12345 % 12345 = 0. So p[0][1] = 0.
    //     │ p[0][2] = grid[0][0] * grid[0][1] = 12345 * 2 = 24690. 24690 % 12345 = 0. So p[0][2] = 0.
    //     │ So the answer is [[2],[0],[0]].

    vector<vector<int>> grid = {{12345},{2},{1}};
    vector<vector<int>> answer = this->s.constructProductMatrix(grid);
    vector<vector<int>> expected = {{2},{0},{0}};
    EXPECT_EQ(answer, expected);
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
