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


/* https://leetcode.com/problems/get-biggest-three-rhombus-sums-in-a-grid/
 * 1878. Get Biggest Three Rhombus Sums in a Grid

You are given an m x n integer matrix grid.
A rhombus sum is the sum of the elements that form the border of a regular rhombus shape in grid. The rhombus must have the shape of a square rotated 45 degrees with each of the corners centered in a grid cell. Below is an image of four valid rhombus shapes with the corresponding colored cells that should be included in each rhombus sum:
Note that the rhombus can have an area of 0, which is depicted by the purple rhombus in the bottom right corner.
Return the biggest three distinct rhombus sums in the grid in descending order. If there are less than three distinct values, return all of them.

(한국어)
m x n 정수 행렬 grid가 주어진다.
마름모 합(rhombus sum)은 grid에서 정규 마름모 형태의 테두리를 이루는 요소들의 합이다. 마름모는 45도 회전한 정사각형 모양이어야 하며, 각 꼭짓점은 격자 셀의 중심에 위치해야 한다.
마름모의 넓이는 0일 수 있으며, 이는 오른쪽 하단의 보라색 마름모로 표시되어 있다.
grid에서 가장 큰 서로 다른 마름모 합 3개를 내림차순으로 반환하라. 서로 다른 값이 3개 미만이면 모두 반환하라.


 Constraints:
* m == grid.length
* n == grid[i].length
* 1 <= m, n <= 50
* 1 <= grid[i][j] <= 10^5

*/
class Solution {
private:
    set<int> top3;
    void insert_top3(int value) {
        top3.insert(value);
        if (top3.size() > 3) {
            top3.erase(top3.begin());
        }
    }
public:
    vector<int> getBiggestThree(vector<vector<int>>& grid) {

        int m = grid.size();
        int n = grid[0].size();

        // 1. kmax 계산
        int kmax = min(m, n) / 2;
        top3 = set<int>();

        // 2. k = 0 일 때의 마름모 (셀 자체) 계산
        for (int y = 0; y < m; y++) {
            for (int x = 0; x < n; x++) {
                this->insert_top3(grid[y][x]);
            }
        }

        // 3. k >= 1 일 때의 마름모 변을 더해 top3에 추가
        for (int k = 1; k <= kmax; k++) {
			int center_y_max = m - k;
			int center_x_max = n - k;
            for (int y = 0 + k; y < center_y_max; y++) {
                for (int x = 0 + k; x < center_x_max; x++) {
                    // TODO: 마름모 변 더하기
					int sum = 0;
					for (int i = 0; i < k; i++) {
						// 상
						sum += grid[y - k + i][x - i];
						// 좌
						sum += grid[y + i][x - k + i];
						// 하
						sum += grid[y + k - i][x + i];
						// 우
						sum += grid[y - i][x + k - i];
					}
					this->insert_top3(sum);
                }
            }
        }

        // 4. top3 vector로 변환해 리턴 (내림차순 반환)
        return vector<int>(this->top3.rbegin(), this->top3.rend());
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
    // Input: grid = [[3,4,5,1,3],[3,3,4,2,3],[20,30,200,40,10],[1,5,5,4,1],[4,3,2,2,5]]
    // Output: [228,216,211]
    // Explanation: The rhombus shapes for the three biggest distinct rhombus sums are depicted above.
    // - Blue: 20 + 3 + 200 + 5 = 228
    // - Red: 200 + 2 + 10 + 4 = 216
    // - Green: 5 + 200 + 4 + 2 = 211

    // (한국어)
    // 󰛨 예제 1:
    // 입력: grid = [
    //     [  3, 4,  5, 1, 3 ],
    //     [  3, 3,  4, 2, 3 ],
    //     [ 20,30,200,40,10 ],
    //     [  1, 5,  5, 4, 1 ],
    //     [  4, 3,  2, 2, 5 ]
    // ]
    // 출력: [228,216,211]
    // 설명: 가장 큰 서로 다른 세 개의 마름모 합에 대한 마름모 모양이 위에 표시되어 있다.
    // - 파란색: 20 + 3 + 200 + 5 = 228
    // - 빨간색: 200 + 2 + 10 + 4 = 216
    // - 초록색: 5 + 200 + 4 + 2 = 211

    vector<vector<int>> grid1 = {{3,4,5,1,3},{3,3,4,2,3},{20,30,200,40,10},{1,5,5,4,1},{4,3,2,2,5}};
    vector<int> expected1 = {228,216,211};
    EXPECT_EQ(this->s.getBiggestThree(grid1), expected1);
}

TEST_F(CLASS_NAME, __LINE__)
{
    // 󰛨 Example 2:
    // Input: grid = [[1,2,3],[4,5,6],[7,8,9]]
    // Output: [20,9,8]
    // Explanation: The rhombus shapes for the three biggest distinct rhombus sums are depicted above.
    // - Blue: 4 + 2 + 6 + 8 = 20
    // - Red: 9 (area 0 rhombus in the bottom right corner)
    // - Green: 8 (area 0 rhombus in the bottom middle)

    // (한국어)
    // 󰛨 예제 2:
    // 입력: grid = [[1,2,3],[4,5,6],[7,8,9]]
    // 출력: [20,9,8]
    // 설명: 가장 큰 서로 다른 세 개의 마름모 합에 대한 마름모 형태가 위에 표시되어 있다.
    // - 파란색: 4 + 2 + 6 + 8 = 20
    // - 빨간색: 9 (오른쪽 하단 모서리의 넓이 0 마름모)
    // - 초록색: 8 (하단 중앙의 넓이 0 마름모)

    vector<vector<int>> grid2 = {{1,2,3},{4,5,6},{7,8,9}};
    vector<int> expected2 = {20,9,8};
    EXPECT_EQ(this->s.getBiggestThree(grid2), expected2);
}

TEST_F(CLASS_NAME, __LINE__)
{
    // 󰛨 Example 3:
    // Input: grid = [[7,7,7]]
    // Output: [7]
    // Explanation: All three possible rhombus sums are the same, so return [7].

    // (한국어)
    // 󰛨 예제 3:
    // 입력: grid = [[7,7,7]]
    // 출력: [7]
    // 설명: 가능한 세 개의 마름모 합이 모두 동일하므로, [7]을 반환한다.

    vector<vector<int>> grid3 = {{7,7,7}};
    vector<int> expected3 = {7};
    EXPECT_EQ(this->s.getBiggestThree(grid3), expected3);
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
