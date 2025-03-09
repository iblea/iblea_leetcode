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



/* https://leetcode.com/problems/alternating-groups-ii/?envType=daily-question&envId=2025-03-09
 * @lc app=leetcode id=3208 lang=cpp
 * [3208] Alternating Groups II

There is a circle of red and blue tiles. You are given an array of integers colors and an integer k. The color of tile i is represented by colors[i]:
colors[i] == 0 means that tile i is red.
colors[i] == 1 means that tile i is blue.
An alternating group is every k contiguous tiles in the circle with alternating colors (each tile in the group except the first and last one has a different color from its left and right tiles).
Return the number of alternating groups.
Note that since colors represents a circle, the first and the last tiles are considered to be next to each other.

빨간색과 파란색 타일로 이루어진 원이 있습니다. 정수 배열 colors와 정수 k가 주어집니다. 타일 i의 색상은 colors[i]로 표현됩니다:
colors[i] == 0은 타일 i가 빨간색임을 의미합니다.
colors[i] == 1은 타일 i가 파란색임을 의미합니다.
교차 그룹은 원 내에서 색상이 번갈아 나타나는 연속된 k개의 타일입니다(그룹 내 첫 번째와 마지막 타일을 제외한 각 타일은 좌우 타일과 다른 색상을 가집니다).
교차 그룹의 수를 반환하세요.
참고로 colors는 원을 나타내므로 첫 번째 타일과 마지막 타일은 서로 인접해 있다고 간주합니다.

Constraints:
3 <= colors.length <= 10**5
0 <= colors[i] <= 1
3 <= k <= colors.length
 */

// @lc code=start
class Solution {
public:
    int numberOfAlternatingGroups(vector<int>& colors, int k) {
        int count = 0;
        int color_size = colors.size();
        vector<int> diff(color_size);

        int tmp = color_size - 1;
        for (int i = 0; i < tmp; i++) {
            diff[i] = colors[i] != colors[i + 1] ? 1 : 0;
        }
        diff[tmp] = colors[tmp] != colors[0] ? 1 : 0;

        int diff_sum = 0;
        for (int i = 0; i < k - 1; i++) {
            diff_sum += diff[i];
        }

        for (int i = 0; i < color_size; i++) {
            diff_sum = diff_sum - diff[i] + diff[(i + k - 1) % color_size];
            if (diff_sum == k - 1) {
                count++;
            }
        }

        return count;
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
    // Input: colors = [0,1,0,1,0], k = 3
    // Output: 3

    vector<int> colors = {0, 1, 0, 1, 0};
    int k = 3;
	EXPECT_EQ(this->s.numberOfAlternatingGroups(colors, k), 3);
}

TEST_F(CLASS_NAME, __LINE__)
{
    // Example 2:
    // Input: colors = [0,1,0,0,1,0,1], k = 6
    // Output: 2

    vector<int> colors = {0, 1, 0, 0, 1, 0, 1};
    int k = 6;
	EXPECT_EQ(this->s.numberOfAlternatingGroups(colors, k), 2);
}

TEST_F(CLASS_NAME, __LINE__)
{
    // Example 3:
    // Input: colors = [1,1,0,1], k = 4
    // Output: 0

    vector<int> colors = {1, 1, 0, 1};
    int k = 4;
	EXPECT_EQ(this->s.numberOfAlternatingGroups(colors, k), 0);
}

TEST_F(CLASS_NAME, __LINE__)
{
    vector<int> colors = {0, 0, 1};
    int k = 3;
	EXPECT_EQ(this->s.numberOfAlternatingGroups(colors, k), 1);
}


int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
