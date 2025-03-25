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



/* https://leetcode.com/problems/check-if-grid-can-be-cut-into-sections/?envType=daily-question&envId=2025-03-25
 * @lc app=leetcode id=3394 lang=cpp
 * [3394] Check if Grid can be Cut into Sections

You are given an integer n representing the dimensions of an n x n grid, with the origin at the bottom-left corner of the grid. You are also given a 2D array of coordinates rectangles, where rectangles[i] is in the form [startx, starty, endx, endy], representing a rectangle on the grid. Each rectangle is defined as follows:
(startx, starty): The bottom-left corner of the rectangle.
(endx, endy): The top-right corner of the rectangle.
Note that the rectangles do not overlap. Your task is to determine if it is possible to make either two horizontal or two vertical cuts on the grid such that:
Each of the three resulting sections formed by the cuts contains at least one rectangle.
Every rectangle belongs to exactly one section.
Return true if such cuts can be made; otherwise, return false.

정수 n이 주어지며, 이는 n x n 그리드의 크기를 나타냅니다. 그리드의 원점은 좌측 하단 모서리에 있습니다. 또한 2D 좌표 배열인 rectangles가 주어지는데, rectangles[i]는 [startx, starty, endx, endy] 형태로 그리드 위의 직사각형을 나타냅니다. 각 직사각형은 다음과 같이 정의됩니다:
(startx, starty): 직사각형의 좌측 하단 모서리.
(endx, endy): 직사각형의 우측 상단 모서리.
직사각형들은 서로 겹치지 않습니다. 당신의 임무는 그리드에 두 개의 수평 또는 두 개의 수직 절단선을 만들어 다음 조건을 만족하는지 확인하는 것입니다:
절단선으로 형성된 세 개의 구역 각각에 최소 하나의 직사각형이 포함되어야 합니다.
모든 직사각형은 정확히 하나의 구역에 속해야 합니다.
이러한 절단이 가능하면 true를, 그렇지 않으면 false를 반환하세요.

Constraints:
- 3 <= n <= 10**9
- 3 <= rectangles.length <= 10**5
- 0 <= rectangles[i][0] < rectangles[i][2] <= n
- 0 <= rectangles[i][1] < rectangles[i][3] <= n
- No two rectangles overlap. (두 개의 직사각형이 서로 겹치지 않습니다.)
 */

// @lc code=start
class Solution {
private:
    bool check(vector<pair<int, int>>& ranges) {
        sort(ranges.begin(), ranges.end(), [](const pair<int, int>& a, const pair<int, int>& b) {
            if (a.first == b.first) return a.second < b.second;
            return a.first < b.first;
        });
        int section = 0;
        int max_end = ranges[0].second;
        for (auto& range : ranges) {
            if (max_end <= range.first) {
                section++;
                if (section >= 2) {
                    return true;
                }
            }
            max_end = max(max_end, range.second);
        }
        return false;
    }

public:
    bool checkValidCuts(int n, vector<vector<int>>& rectangles) {

        vector<pair<int, int>> x_ranges;
        vector<pair<int, int>> y_ranges;

        for (auto& rect : rectangles) {
            x_ranges.push_back({rect[0], rect[2]});
            y_ranges.push_back({rect[1], rect[3]});
        }

        return check(x_ranges) || check(y_ranges);
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
    // Input: n = 5, rectangles = [[1,0,5,2],[0,2,2,4],[3,2,5,3],[0,4,4,5]]
    // Output: true
    // Explanation:
    // The grid is shown in the diagram. We can make horizontal cuts at y = 2 and y = 4. Hence, output is true.

    vector<vector<int>> rectangles = {{1,0,5,2},{0,2,2,4},{3,2,5,3},{0,4,4,5}};
    EXPECT_EQ(this->s.checkValidCuts(5, rectangles), true);
}

TEST_F(CLASS_NAME, __LINE__)
{
    // Example 2:
    // Input: n = 4, rectangles = [[0,0,1,1],[2,0,3,4],[0,2,2,3],[3,0,4,3]]
    // Output: true
    // Explanation:
    // We can make vertical cuts at x = 2 and x = 3. Hence, output is true.

    vector<vector<int>> rectangles = {{0,0,1,1},{2,0,3,4},{0,2,2,3},{3,0,4,3}};
    EXPECT_EQ(this->s.checkValidCuts(4, rectangles), true);
}

TEST_F(CLASS_NAME, __LINE__)
{
    // Example 3:
    // Input: n = 4, rectangles = [[0,2,2,4],[1,0,3,2],[2,2,3,4],[3,0,4,2],[3,2,4,4]]
    // Output: false
    // Explanation:
    // We cannot make two horizontal or two vertical cuts that satisfy the conditions. Hence, output is false.

    vector<vector<int>> rectangles = {{0,2,2,4},{1,0,3,2},{2,2,3,4},{3,0,4,2},{3,2,4,4}};
    EXPECT_EQ(this->s.checkValidCuts(4, rectangles), false);
}
int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
