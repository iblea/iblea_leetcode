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
 * @lc app=leetcode id=152 lang=cpp
 * [152] Maximum Product Subarray

Given an integer array nums, find a subarray that has the largest product, and return the product.
The test cases are generated so that the answer will fit in a 32-bit integer.

정수 배열 nums가 주어졌을 때, 가장 큰 곱을 가진 부분 배열을 찾아 그 곱을 반환하세요.
테스트 케이스는 답이 32비트 정수 범위 내에 맞도록 생성됩니다.

Constraints:
1 <= nums.length <= 2 * 10**4
-10 <= nums[i] <= 10
The product of any subarray of nums is guaranteed to fit in a 32-bit integer.
 */

// @lc code=start
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int result = nums[0];
        int maxval = nums[0];
        int minval = nums[0];

        int curr;
        int cur_max;
        int cur_min;

        for (int i = 1; i < nums.size(); i++) {
            curr = nums[i];
            cur_max = max({curr, maxval * curr, minval * curr});
            cur_min = min({curr, maxval * curr, minval * curr});
            maxval = cur_max;
            minval = cur_min;
            // std::cout << curr << " maxval: " << maxval << ", minval: " << minval << std::endl;

            result = max(result, maxval);
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
    // Input: nums = [2,3,-2,4]
    // Output: 6
    // Explanation: [2,3] has the largest product 6.
    vector<int> nums = {2,3,-2,4};
    EXPECT_EQ(this->s.maxProduct(nums), 6);
}

TEST_F(CLASS_NAME, __LINE__)
{
    // Example 2:
    // Input: nums = [-2,0,-1]
    // Output: 0
    // Explanation: The result cannot be 2, because [-2,-1] is not a subarray.
    vector<int> nums = {-2,0,-1};
    EXPECT_EQ(this->s.maxProduct(nums), 0);
}


int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
