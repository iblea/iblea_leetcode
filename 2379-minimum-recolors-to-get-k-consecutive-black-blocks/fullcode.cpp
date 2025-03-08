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



/* https://leetcode.com/problems/minimum-recolors-to-get-k-consecutive-black-blocks/?envType=daily-question&envId=2025-03-08
 * @lc app=leetcode id=2379 lang=cpp
 * [2379] Minimum Recolors to Get K Consecutive Black Blocks

You are given a 0-indexed string blocks of length n, where blocks[i] is either 'W' or 'B', representing the color of the ith block. The characters 'W' and 'B' denote the colors white and black, respectively.
You are also given an integer k, which is the desired number of consecutive black blocks.
In one operation, you can recolor a white block such that it becomes a black block.
Return the minimum number of operations needed such that there is at least one occurrence of k consecutive black blocks.

길이가 n인 0-인덱스 문자열 blocks가 주어집니다. 여기서 blocks[i]는 'W' 또는 'B'로, i번째 블록의 색상을 나타냅니다. 문자 'W'와 'B'는 각각 흰색과 검은색을 의미합니다.
또한 연속된 검은색 블록의 원하는 개수인 정수 k가 주어집니다.
한 번의 작업으로 흰색 블록을 검은색 블록으로 변경할 수 있습니다.
k개의 연속된 검은색 블록이 적어도 한 번 나타나도록 하는 데 필요한 최소 작업 수를 반환하세요.

Constraints:
n == blocks.length
1 <= n <= 100
blocks[i] is either 'W' or 'B'.
1 <= k <= n
 */

// @lc code=start
class Solution {
public:
    int minimumRecolors(string blocks, int k) {
        // k개의 공간 중 검은색 블록이 얼마나 많은지를 체크하면 될 듯?
        // 0~6 -> B 몇개?
        // 1-7 -> B 몇개?
        // 2-8 -> B 몇개?
        // ...
        // n~(k-1)+n -> B 몇개?
        // 이중 검은색 블록이 가장 많은 곳을 찾아 (k - (검은색 블록 수))를 반환하면 될 듯
        int max_black = count(blocks.begin(), blocks.begin() + k, 'B');
        int black_count = max_black;
        int check_size = blocks.size() - k;
        for (int i = 1; i < check_size; i++) {
            if (blocks[i-1] == 'B') {
                black_count--;
            }
            if (blocks[i+k-1] == 'B') {
                black_count++;
            }
            max_black = max(max_black, black_count);
        }
        return k - max_black;
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
    // Input: blocks = "WBBWWBBWBW", k = 7
    // Output: 3
    // Explanation:
    // One way to achieve 7 consecutive black blocks is to recolor the 0th, 3rd, and 4th blocks
    // so that blocks = "BBBBBBBWBW".
    // It can be shown that there is no way to achieve 7 consecutive black blocks in less than 3 operations.
    // Therefore, we return 3.

	EXPECT_EQ(this->s.minimumRecolors("WBBWWBBWBW", 7), 3);
}

TEST_F(CLASS_NAME, __LINE__)
{
    // Example 2:
    // Input: blocks = "WBWBBBW", k = 2
    // Output: 0
    // Explanation:
    // No changes need to be made, since 2 consecutive black blocks already exist.
    // Therefore, we return 0.

    EXPECT_EQ(this->s.minimumRecolors("WBWBBBW", 2), 0);
}


int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
