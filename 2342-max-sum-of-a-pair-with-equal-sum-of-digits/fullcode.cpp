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



/* https://leetcode.com/problems/max-sum-of-a-pair-with-equal-sum-of-digits/?envType=daily-question&envId=2025-02-12
 * @lc app=leetcode id=2342 lang=cpp
 * [2342] Max Sum of a Pair With Equal Sum of Digits

You are given a 0-indexed array nums consisting of positive integers. You can choose two indices i and j, such that i != j, and the sum of digits of the number nums[i] is equal to that of nums[j].
Return the maximum value of nums[i] + nums[j] that you can obtain over all possible indices i and j that satisfy the conditions.

0부터 시작하는 양의 정수로 이루어진 배열 nums가 주어집니다. 서로 다른 두 개의 인덱스 i와 j를 선택할 수 있는데, 이때 nums[i]의 각 자릿수의 합이 nums[j]의 각 자릿수의 합과 같아야 합니다.
이러한 조건을 만족하는 모든 가능한 인덱스 i와 j에 대해 얻을 수 있는 nums[i] + nums[j]의 최대값을 반환하세요.

Constraints:
1 <= nums.length <= 10**5 (100,000)
1 <= nums[i] <= 10**9 (1,000,000,000)
 */

// @lc code=start
class Solution {

private:
    int get_sum_of_digits(int num) {
        int sum = 0;
        while (num > 0) {
            sum += num % 10;
            num /= 10;
        }
        return sum;
    }

public:
    int maximumSum(vector<int>& nums) {
        // key: 자릿수, value: 해당 자릿수의 제일 큰 숫자
        unordered_map<int, int> sum_map;
        int answer = -1;

        for (int num : nums) {
            int sum = get_sum_of_digits(num);
            if (sum_map.find(sum) == sum_map.end()) {
                sum_map[sum] = num;
                continue;
            }
            answer = max(answer, sum_map[sum] + num);
            if (sum_map[sum] < num) {
                sum_map[sum] = num;
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
    // Example 1:
    // Input: nums = [18,43,36,13,7]
    // Output: 54
    // Explanation: The pairs (i, j) that satisfy the conditions are:
    // - (0, 2), both numbers have a sum of digits equal to 9, and their sum is 18 + 36 = 54.
    // - (1, 4), both numbers have a sum of digits equal to 7, and their sum is 43 + 7 = 50.
    // So the maximum sum that we can obtain is 54.

    vector<int> nums = {18,43,36,13,7};
	EXPECT_EQ(this->s.maximumSum(nums), 54);
}

TEST_F(CLASS_NAME, __LINE__)
{
    // Example 2:
    // Input: nums = [10,12,19,14]
    // Output: -1
    // Explanation: There are no two numbers that satisfy the conditions, so we return -1.

    vector<int> nums = {10,12,19,14};
	EXPECT_EQ(this->s.maximumSum(nums), -1);
}



int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}