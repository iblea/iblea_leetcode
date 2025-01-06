#include <gtest/gtest.h>
#include <iostream>
#include <iomanip>
#include <algorithm>
#include <vector>
#include <string>
#include <map>

using namespace std;


/*
 * @lc app=leetcode id=2270 lang=cpp
 *
 * https://leetcode.com/problems/number-of-ways-to-split-array/description/?envType=daily-question&envId=2025-01-03
 * [2270] Number of Ways to Split Array

You are given a 0-indexed integer array nums of length n.
nums contains a valid split at index i if the following are true:
The sum of the first i + 1 elements is greater than or equal to the sum of the last n - i - 1 elements.
There is at least one element to the right of i. That is, 0 <= i < n - 1.
Return the number of valid splits in nums.

길이가 n인 0-인덱스 정수 배열 nums가 주어집니다.
다음 조건이 참일 때, nums는 인덱스 i에서 유효한 분할을 포함합니다:
1. 처음 i + 1개 원소들의 합이 마지막 n - i - 1개 원소들의 합보다 크거나 같아야 합니다.
2. i의 오른쪽에 최소한 하나의 원소가 있어야 합니다. 즉, 0 <= i < n - 1 입니다.
nums에서 가능한 유효한 분할의 개수를 반환하세요.
예시를 통해 더 자세히 설명하자면:
nums = [10,4,-8,7] 인 경우, 인덱스 0과 1에서 유효한 분할이 가능하며 총 2개의 유효한 분할이 있습니다.
nums = [2,3,1,0] 인 경우, 인덱스 1과 2에서 유효한 분할이 가능하며 총 2개의 유효한 분할이 있습니다.
이 문제는 주어진 배열을 두 부분으로 나누었을 때, 왼쪽 부분의 합이 오른쪽 부분의 합보다 크거나 같은 경우의 수를 찾는 것입니다.

Example 1:
Input: nums = [10,4,-8,7]
Output: 2
Explanation:
There are three ways of splitting nums into two non-empty parts:
- Split nums at index 0. Then, the first part is [10], and its sum is 10. The second part is [4,-8,7], and its sum is 3. Since 10 >= 3, i = 0 is a valid split.
- Split nums at index 1. Then, the first part is [10,4], and its sum is 14. The second part is [-8,7], and its sum is -1. Since 14 >= -1, i = 1 is a valid split.
- Split nums at index 2. Then, the first part is [10,4,-8], and its sum is 6. The second part is [7], and its sum is 7. Since 6 < 7, i = 2 is not a valid split.
Thus, the number of valid splits in nums is 2.

Example 2:
Input: nums = [2,3,1,0]
Output: 2
Explanation:
There are two valid splits in nums:
- Split nums at index 1. Then, the first part is [2,3], and its sum is 5. The second part is [1,0], and its sum is 1. Since 5 >= 1, i = 1 is a valid split.
- Split nums at index 2. Then, the first part is [2,3,1], and its sum is 6. The second part is [0], and its sum is 0. Since 6 >= 0, i = 2 is a valid split.

Constraints:
2 <= nums.length <= 10**5
-10**5 <= nums[i] <= 10**5
 */

// @lc code=start
class Solution {
public:
    int waysToSplitArray(vector<int>& nums) {

        int answer = 0;

        int end_idx = nums.size() - 1;
        long long left_sum = 0;
        long long right_sum = 0;
        for_each(nums.begin(), nums.end(), [&](int num){
            right_sum += num;
        });

        for(int i = 0; i < end_idx; i++){
            left_sum += nums[i];
            right_sum -= nums[i];
            if(left_sum >= right_sum){
                answer++;
            }
        }

        return answer;
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
    vector<int> nums = {10, 4, -8, 7};
	EXPECT_EQ(this->s.waysToSplitArray(nums), 2);
}

TEST_F(CLASS_NAME, __LINE__)
{
    vector<int> nums = {2, 3, 1, 0};
	EXPECT_EQ(this->s.waysToSplitArray(nums), 2);
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
