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



/* https://leetcode.com/problems/tuple-with-same-product/?envType=daily-question&envId=2025-02-06
 * @lc app=leetcode id=1726 lang=cpp
 * [1726] Tuple with Same Product

Given an array nums of distinct positive integers, return the number of tuples (a, b, c, d) such that a * b = c * d where a, b, c, and d are elements of nums, and a != b != c != d.

서로 다른 양의 정수로 이루어진 배열 nums가 주어졌을 때, nums의 원소인 a, b, c, d에 대해 a * b = c * d이고 a != b != c != d를 만족하는 튜플 (a, b, c, d)의 개수를 반환하세요.

Constraints:
1 <= nums.length <= 1000
1 <= nums[i] <= 10**4
All elements in nums are distinct. (nums의 모든 원소는 서로 다릅니다.)
 */

// @lc code=start
class Solution {
public:
    int tupleSameProduct(vector<int>& nums) {
        int count = 0;

        // 4개의 원소를 통해 동일한 곱셈 결과를 만들 수 있다면,
        // 추가로 구할 필요 없이 *8 진행하면 된다.
        // 예를 들어서 1,2,4,5,10 이라는 배열은, 4개의원소를 통해 10(1,10/2,5), 20(2,10/4,5) 이렇게 2개의 튜플을 만들 수 있다.
        // 따라서 2 * 8 = 16 이라는 결과값을 얻을 수 있다.

        // (1,2,3,4,6,12) -> (1/6, 2/3) (1/12,2/6,3/4), (4/6, 2/12)
        // n쌍이라면 n(n-1)/2 만큼의 튜플을 만들 수 있다.

        unordered_map<int, int> product_count;

        for (int i = 0; i < nums.size(); i++) {
            for (int j = i + 1; j < nums.size(); j++) {
                if (product_count.find(nums[i] * nums[j]) != product_count.end()) {
                    product_count[nums[i] * nums[j]]++;
                } else {
                    product_count[nums[i] * nums[j]] = 1;
                }
            }
        }

        for (auto& [product, cnt] : product_count) {
            count += cnt * (cnt - 1) / 2;
        }
        return count * 8;
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
    // Input: nums = [2,3,4,6]
    // Output: 8
    // Explanation: There are 8 valid tuples:
    // (2,6,3,4) , (2,6,4,3) , (6,2,3,4) , (6,2,4,3)
    // (3,4,2,6) , (4,3,2,6) , (3,4,6,2) , (4,3,6,2)

    vector<int> nums = {2,3,4,6};
	EXPECT_EQ(this->s.tupleSameProduct(nums), 8);
}

TEST_F(CLASS_NAME, __LINE__)
{
    // Example 2:
    // Input: nums = [1,2,4,5,10]
    // Output: 16
    // Explanation: There are 16 valid tuples:
    // (1,10,2,5) , (1,10,5,2) , (10,1,2,5) , (10,1,5,2)
    // (2,5,1,10) , (2,5,10,1) , (5,2,1,10) , (5,2,10,1)
    // (2,10,4,5) , (2,10,5,4) , (10,2,4,5) , (10,2,5,4)
    // (4,5,2,10) , (4,5,10,2) , (5,4,2,10) , (5,4,10,2)

    vector<int> nums = {1,2,4,5,10};
	EXPECT_EQ(this->s.tupleSameProduct(nums), 16);
}



int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}