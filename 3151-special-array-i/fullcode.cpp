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



/* https://leetcode.com/problems/special-array-i/?envType=daily-question&envId=2025-02-01
 * @lc app=leetcode id=3151 lang=cpp
 * [3151] Special Array I

An array is considered special if every pair of its adjacent elements contains two numbers with different parity.
You are given an array of integers nums. Return true if nums is a special array, otherwise, return false.

배열의 인접한 모든 원소 쌍이 서로 다른 홀짝성을 가진 숫자를 포함하고 있을 때 해당 배열을 특별하다고 합니다.
정수 배열 nums가 주어졌을 때, nums가 특별한 배열이면 true를, 그렇지 않으면 false를 반환하세요.

Constraints:
1 <= nums.length <= 100
1 <= nums[i] <= 100
 */

// @lc code=start
class Solution {
public:
    bool isArraySpecial(vector<int>& nums) {
        int size = nums.size();
        if (size == 1) return true;

        int ago = nums[0] % 2;
        for (int i = 1; i < size; i++) {
            if (nums[i] % 2 == ago) {
                return false;
            }
            ago = nums[i] % 2;
        }
        return true;
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
    // Input: nums = [1]
    // Output: true
    // Explanation: There is only one element. So the answer is true.
    vector<int> nums = {1};
	EXPECT_EQ(this->s.isArraySpecial(nums), true);
}

TEST_F(CLASS_NAME, __LINE__)
{
    // Example 2:
    // Input: nums = [2,1,4]
    // Output: true
    // Explanation: There is only two pairs: (2,1) and (1,4), and both of them contain numbers with different parity. So the answer is true.
    vector<int> nums2 = {2,1,4};
	EXPECT_EQ(this->s.isArraySpecial(nums2), true);
}

TEST_F(CLASS_NAME, __LINE__)
{
    // Example 3:
    // Input: nums = [4,3,1,6]
    // Output: false
   // Explanation: nums[1] and nums[2] are both odd. So the answer is false.
    vector<int> nums3 = {4,3,1,6};
	EXPECT_EQ(this->s.isArraySpecial(nums3), false);
}



int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}