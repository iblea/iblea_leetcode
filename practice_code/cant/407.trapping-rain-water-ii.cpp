#include <gtest/gtest.h>
#include <iostream>
#include <iomanip>
#include <algorithm>
#include <vector>
#include <string>
#include <map>
#include <array>

using namespace std;



/* https://leetcode.com/problems/trapping-rain-water-ii/description/?envType=daily-question&envId=2025-01-19
 * @lc app=leetcode id=407 lang=cpp
 * [407] Trapping Rain Water II

Given an m x n integer matrix heightMap representing the height of each unit cell in a 2D elevation map, return the volume of water it can trap after raining.
2D 고도 지도에서 각 단위 셀의 높이를 나타내는 m x n 정수 행렬 heightMap이 주어졌을 때, 비가 온 후 가둘 수 있는 물의 부피를 반환하세요.

Constraints:
- m == heightMap.length
- n == heightMap[i].length
- 1 <= m, n <= 200
- 0 <= heightMap[i][j] <= 2 * 10**4
 */
// @lc code=start
class Solution {
public:
    int trapRainWater(vector<vector<int>>& heightMap) {
        // 행렬의 크기가 2 이하라면 물을 가둘 수 없음.
        if (heightMap.size() <= 2) {
            return 0;
        }

        int ylen = heightMap.size();
        int xlen = heightMap[0].size();

        // 높이(값), 행, 열
        // 높이가 낮은 순서대로 리턴함. (높이가 같다면, 행, 행이 같다면 열 순서대로 리턴)
        priority_queue<array<int, 3>, vector<array<int, 3>>, greater<array<int, 3>>> pq;
        vector<vector<bool>> visited(ylen, vector<bool>(xlen, false));

        for (int i = 0; i < xlen; ++i) {
            pq.push({heightMap[0][i], 0, i});
            visited[0][i] = true;
            pq.push({heightMap[ylen - 1][i], ylen- 1, i});
            visited[ylen - 1][i] = true;
        }
        for (int i = 1; i < ylen - 1; ++i) {
            pq.push({heightMap[i][0], i, 0});
            visited[i][0] = true;
            pq.push({heightMap[i][xlen - 1], i, xlen - 1});
            visited[i][xlen - 1] = true;
        }

        vector<pair<int, int>> directions = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        int result = 0;
        int max_height = 0;
        while (!pq.empty()) {
            auto [height, y, x] = pq.top();
            pq.pop();
            max_height = max(max_height, height);

            for (auto [dy, dx] : directions) {
                int nx = x + dx;
                int ny = y + dy;
                if (nx < 0 || ny < 0 || nx >= xlen || ny >= ylen) {
                    continue;
                }
                if (!visited[ny][nx]) {
                    visited[ny][nx] = true;
                    if (heightMap[ny][nx] < max_height) {
                        result += max_height - heightMap[ny][nx];
                    }
                    pq.push({heightMap[ny][nx], ny, nx});
                }
            }
        }
        return result;
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
    // Input: heightMap = [[1,4,3,1,3,2],[3,2,1,3,2,4],[2,3,3,2,3,1]]
    // Output: 4
    // Explanation: After the rain, water is trapped between the blocks.
    // We have two small ponds 1 and 3 units trapped.
    // The total volume of water trapped is 4.
	vector<vector<int>> heightMap = {{1,4,3,1,3,2},{3,2,1,3,2,4},{2,3,3,2,3,1}};
	EXPECT_EQ(this->s.trapRainWater(heightMap), 4);
}

TEST_F(CLASS_NAME, __LINE__)
{
    // Input: heightMap = [[3,3,3,3,3],[3,2,2,2,3],[3,2,1,2,3],[3,2,2,2,3],[3,3,3,3,3]]
    // Output: 10
    vector<vector<int>> heightMap = {{3,3,3,3,3},{3,2,2,2,3},{3,2,1,2,3},{3,2,2,2,3},{3,3,3,3,3}};
	EXPECT_EQ(this->s.trapRainWater(heightMap), 10);

}

TEST_F(CLASS_NAME, __LINE__)
{
    vector<vector<int>> heightMap = {{3,3,3,3,3},{3,2,2,2,3}};
	EXPECT_EQ(this->s.trapRainWater(heightMap), 0);

}


int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}