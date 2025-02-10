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

using namespace std;



/* https://leetcode.com/problems/find-the-number-of-distinct-colors-among-the-balls/?envType=daily-question&envId=2025-02-07
 * @lc app=leetcode id=3160 lang=cpp
 * [3160] Find the Number of Distinct Colors Among the Balls

You are given an integer limit and a 2D array queries of size n x 2.
There are limit + 1 balls with distinct labels in the range [0, limit]. Initially, all balls are uncolored. For every query in queries that is of the form [x, y], you mark ball x with the color y. After each query, you need to find the number of distinct colors among the balls.
Return an array result of length n, where result[i] denotes the number of distinct colors after ith query.
Note that when answering a query, lack of a color will not be considered as a color.

정수 limit와 n x 2 크기의 2차원 배열 queries가 주어집니다.
[0, limit] 범위에서 고유한 라벨이 있는 limit + 1개의 공이 있습니다. 처음에는 모든 공이 색칠되어 있지 않습니다. [x, y] 형태의 queries의 각 쿼리에 대해, x번 공을 y색으로 칠합니다. 각 쿼리 후에 공들 중에서 서로 다른 색상의 개수를 찾아야 합니다.
길이가 n인 배열 result를 반환하세요. 여기서 result[i]는 i번째 쿼리 후의 서로 다른 색상의 개수를 나타냅니다.
참고로 쿼리에 응답할 때 색상이 없는 것은 색상으로 간주되지 않습니다.

Constraints:
1 <= limit <= 10**9
1 <= n == queries.length <= 10**5
queries[i].length == 2
0 <= queries[i][0] <= limit
1 <= queries[i][1] <= 10**9

 */

// @lc code=start
class Solution {
    // key - color, value - balls
    unordered_map<int, set<int>> color_map;
    unordered_map<int, int> balls;
private:
    void add_color(int x, int y) {
        if (this->balls.find(x) != this->balls.end()) {
            int ago_color = this->balls[x];
            this->color_map[ago_color].erase(x);
            if (this->color_map[ago_color].size() == 0) {
                this->color_map.erase(ago_color);
            }
        }
        this->color_map[y].insert(x);
        this->balls[x] = y;
    }
public:
    vector<int> queryResults(int limit, vector<vector<int>>& queries) {
        vector<int> result = vector<int>(queries.size());
        this->balls = unordered_map<int, int>();
        this->color_map = unordered_map<int, set<int>>();

        for (int i = 0; i < queries.size(); i++) {
            this->add_color(queries[i][0], queries[i][1]);
            result[i] = this->color_map.size();
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
    // Example 1:
    // Input: limit = 4, queries = [[1,4],[2,5],[1,3],[3,4]]
    // Output: [1,2,2,3]
    // Explanation:
    // After query 0, ball 1 has color 4.
    // After query 1, ball 1 has color 4, and ball 2 has color 5.
    // After query 2, ball 1 has color 3, and ball 2 has color 5.
    // After query 3, ball 1 has color 3, ball 2 has color 5, and ball 3 has color 4.

    int limit = 4;
    vector<vector<int>> queries = {{1,4},{2,5},{1,3},{3,4}};
    vector<int> expected = {1,2,2,3};
	EXPECT_EQ(this->s.queryResults(limit, queries), expected);
}

TEST_F(CLASS_NAME, __LINE__)
{
    // Example 2:
    // Input: limit = 4, queries = [[0,1],[1,2],[2,2],[3,4],[4,5]]
    // Output: [1,2,2,3,4]
    // Explanation:
    // After query 0, ball 0 has color 1.
    // After query 1, ball 0 has color 1, and ball 1 has color 2.
    // After query 2, ball 0 has color 1, and balls 1 and 2 have color 2.
    // After query 3, ball 0 has color 1, balls 1 and 2 have color 2, and ball 3 has color 4.
    // After query 4, ball 0 has color 1, balls 1 and 2 have color 2, ball 3 has color 4, and ball 4 has color 5.

    int limit = 4;
    vector<vector<int>> queries = {{0,1},{1,2},{2,2},{3,4},{4,5}};
    vector<int> expected = {1,2,2,3,4};
	EXPECT_EQ(this->s.queryResults(limit, queries), expected);
}


int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}