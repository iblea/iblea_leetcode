#include <gtest/gtest.h>
#include <iostream>
#include <iomanip>
#include <algorithm>
#include <vector>
#include <string>
#include <map>

using namespace std;


/*
https://leetcode.com/problems/jump-game-ii/description/?envType=problem-list-v2&envId=dynamic-programming
 * @lc app=leetcode id=45 lang=cpp
 * [45] Jump Game II

You are given a 0-indexed array of integers nums of length n. You are initially positioned at nums[0].
Each element nums[i] represents the maximum length of a forward jump from index i. In other words, if you are at nums[i], you can jump to any nums[i + j] where:
- 0 <= j <= nums[i] and
- i + j < n
Return the minimum number of jumps to reach nums[n - 1]. The test cases are generated such that you can reach nums[n - 1].

0부터 시작하는 정수 배열 nums가 주어집니다. 당신은 처음에 nums[0]에 위치해 있습니다.
각 요소 nums[i]는 인덱스 i에서 앞으로 점프할 수 있는 최대 길이를 나타냅니다. 즉, nums[i]에 있으면 nums[i + j]로 점프할 수 있습니다. 여기서:
- 0 <= j <= nums[i] 그리고
- i + j < n
nums[n - 1]에 도달하기 위한 최소 점프 횟수를 반환하세요. 테스트 케이스는 nums[n - 1]에 도달할 수 있도록 생성됩니다.

Constraints:
1 <= nums.length <= 10**4
0 <= nums[i] <= 1000
It's guaranteed that you can reach nums[n - 1].
 */

// @lc code=start
class Solution {
public:
    int jump(vector<int>& nums) {
        if (nums.size() == 1) return 0;
        if (nums.size() == 2) return 1;

        int target = nums.size() - 1;
        vector<int> memo(nums.size() - 1, 2147483647);
        for (int curr = nums.size() - 2; curr >= 0; curr--) {
            if (nums[curr] == 0) {
                continue;
            }
            for (int i = 1; i <= nums[curr]; i++) {
                if (curr + i >= target) {
                    memo[curr] = 0;
                    for (int j = curr + 1; j < memo.size(); j++) {
                        memo[j] = 1;
                    }
                    break;
                }
                memo[curr] = min(memo[curr], memo[curr + i]);
            }
            if (memo[curr] == 2147483647) {
                continue;
            }
            memo[curr]++;
        }
        // if (memo[0] == 2147483647) return -1;
        return memo[0];
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
    vector<int> nums = {2,3,1,1,4};
	EXPECT_EQ(this->s.jump(nums), 2);
}
TEST_F(CLASS_NAME, __LINE__)
{
    vector<int> nums = {2,3,0,1,4};
	EXPECT_EQ(this->s.jump(nums), 2);
}



int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}