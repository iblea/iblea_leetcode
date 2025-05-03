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



/*
 * @lc app=leetcode id=1007 lang=cpp
 * [1007] Minimum Domino Rotations For Equal Row

In a row of dominoes, tops[i] and bottoms[i] represent the top and bottom halves of the ith domino. (A domino is a tile with two numbers from 1 to 6 - one on each half of the tile.)
We may rotate the ith domino, so that tops[i] and bottoms[i] swap values.
Return the minimum number of rotations so that all the values in tops are the same, or all the values in bottoms are the same.
If it cannot be done, return -1.

도미노 행에서 tops[i]와 bottoms[i]는 i번째 도미노의 위쪽과 아래쪽 절반을 나타냅니다. (도미노는 1부터 6까지의 숫자 두 개가 있는 타일로, 타일의 각 절반에 하나씩 있습니다.)
우리는 i번째 도미노를 회전시켜 tops[i]와 bottoms[i]의 값을 교환할 수 있습니다.
tops의 모든 값이 같거나 bottoms의 모든 값이 같도록 하는 최소 회전 횟수를 반환하세요.
만약 불가능하다면 -1을 반환하세요.

Example 1:
Input: tops = [2,1,2,4,2,2], bottoms = [5,2,6,2,3,2]
Output: 2
Explanation:
The first figure represents the dominoes as given by tops and bottoms: before we do any rotations.
If we rotate the second and fourth dominoes, we can make every value in the top row equal to 2, as indicated by the second figure.

Example 2:
Input: tops = [3,5,1,2,3], bottoms = [3,6,3,3,4]
Output: -1
Explanation:
In this case, it is not possible to rotate the dominoes to make one row of values equal.

Constraints:
2 <= tops.length <= 2 * 10**4
bottoms.length == tops.length
1 <= tops[i], bottoms[i] <= 6

 */

// @lc code=start
class Solution {
public:
    int minDominoRotations(vector<int>& tops, vector<int>& bottoms) {
        int n = tops.size();

        int count[7] = {0};
        int top_count[7] = {0};
        int bottom_count[7] = {0};
        for (int i = 0; i < n; i++) {
            if (tops[i] == bottoms[i]) {
                count[tops[i]]++;

            } else {
                count[tops[i]]++;
                count[bottoms[i]]++;
            }
            top_count[tops[i]]++;
            bottom_count[bottoms[i]]++;
        }

        for (int i = 1; i <= 6; i++) {
            if (count[i] == n) {
                return n - max(top_count[i], bottom_count[i]);
            }
        }
        return -1;
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
    vector<int> tops = {2,1,2,4,2,2};
    vector<int> bottoms = {5,2,6,2,3,2};
    EXPECT_EQ(this->s.minDominoRotations(tops, bottoms), 2);
}

TEST_F(CLASS_NAME, __LINE__)
{
    vector<int> tops = {3,5,1,2,3};
    vector<int> bottoms = {3,6,3,3,4};
    EXPECT_EQ(this->s.minDominoRotations(tops, bottoms), -1);
}


int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
