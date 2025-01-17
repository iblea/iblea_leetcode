#include <gtest/gtest.h>
#include <iostream>
#include <iomanip>
#include <algorithm>
#include <vector>
#include <string>
#include <map>

using namespace std;



/* https://leetcode.com/problems/bitwise-xor-of-all-pairings/?envType=daily-question&envId=2025-01-16
 * @lc app=leetcode id=2425 lang=cpp
 * [2425] Bitwise XOR of All Pairings

You are given two 0-indexed arrays, nums1 and nums2, consisting of non-negative integers. There exists another array, nums3, which contains the bitwise XOR of all pairings of integers between nums1 and nums2 (every integer in nums1 is paired with every integer in nums2 exactly once).
Return the bitwise XOR of all integers in nums3.

0-인덱스 기반의 두 배열 nums1과 nums2가 주어지며, 각 배열은 음이 아닌 정수로 구성되어 있습니다. nums1과 nums2 사이의 모든 정수 쌍의 비트 단위 XOR을 포함하는 또 다른 배열 nums3이 존재합니다(nums1의 각 정수는 nums2의 모든 정수와 정확히 한 번씩 쌍을 이룹니다).
nums3의 모든 정수의 비트 단위 XOR을 반환하세요.

Constraints:
- 1 <= nums1.length, nums2.length <= 10**5
- 0 <= nums1[i], nums2[j] <= 10**9
 */

// @lc code=start
class Solution {
public:
    int xorAllNums(vector<int>& nums1, vector<int>& nums2) {
        int result1 = 0;
        int result2 = 0;

        int len1 = nums1.size();
        int len2 = nums2.size();
        if (len1 % 2 != 0) {
            for (int i = 0; i < nums2.size(); i++) {
                result2 ^= nums2[i];
            }
        }
        if (len2 % 2 != 0) {
            for (int i = 0; i < nums1.size(); i++) {
                result1 ^= nums1[i];
            }
        }
        return result1 ^ result2;
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
    vector<int> nums1 = {2,1,3};
    vector<int> nums2 = {10,2,5,0};
    // num1 배열이 홀수면 num2 배열 XOR 한 값 구하면 됨.
    // num2 배열이 홀수면 num1 배열 XOR 한 값 구하면 됨.
    // [8,0,7,2,11,3,4,1,9,1,6,3].

    EXPECT_EQ(this->s.xorAllNums(nums1, nums2), 13);
}

TEST_F(CLASS_NAME, __LINE__)
{
    vector<int> nums1 = {1,2};
    vector<int> nums2 = {3,4};
	EXPECT_EQ(this->s.xorAllNums(nums1, nums2), 0);
}



int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}