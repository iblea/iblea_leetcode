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



/* https://leetcode.com/problems/partition-array-according-to-given-pivot/description/?envType=daily-question&envId=2025-03-03
 * @lc app=leetcode id=2161 lang=cpp
 * [2161] Partition Array According to Given Pivot

You are given a 0-indexed integer array nums and an integer pivot. Rearrange nums such that the following conditions are satisfied:
Every element less than pivot appears before every element greater than pivot.
Every element equal to pivot appears in between the elements less than and greater than pivot.
The relative order of the elements less than pivot and the elements greater than pivot is maintained.
More formally, consider every pi, pj where pi is the new position of the ith element and pj is the new position of the jth element. If i < j and both elements are smaller (or larger) than pivot, then pi < pj.
Return nums after the rearrangement.

0-인덱스 정수 배열 nums와 정수 pivot이 주어집니다. 다음 조건을 만족하도록 nums를 재배열하세요:
pivot보다 작은 모든 원소는 pivot보다 큰 모든 원소보다 앞에 나타납니다.
pivot과 같은 모든 원소는 pivot보다 작은 원소들과 큰 원소들 사이에 나타납니다.
pivot보다 작은 원소들과 큰 원소들의 상대적인 순서는 유지됩니다.
더 자세히 설명하면, pi는 i번째 원소의 새로운 위치이고 pj는 j번째 원소의 새로운 위치일 때, i < j이고 두 원소가 모두 pivot보다 작거나(또는 크면) pi < pj입니다.
재배열된 nums를 반환하세요.

Constraints:
1 <= nums.length <= 10**5
-10**6 <= nums[i] <= 10**6
pivot equals to an element of nums.
 */
// @lc code=start
class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        vector<int> result(nums.size());
        int res_size = 0;
        vector<int> tmp(nums.size());
        int tmp_size = 0;

        int same_count = 0;

        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] < pivot) {
                result[res_size++] = nums[i];
            }
            else if (nums[i] == pivot) {
                same_count++;
            }
            else {
                tmp[tmp_size++] = nums[i];
            }
        }

        while (same_count > 0) {
            result[res_size++] = pivot;
            same_count--;
        }

        for (int i = 0; i < tmp_size; i++) {
            result[res_size++] = tmp[i];
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
    // Input: nums = [9,12,5,10,14,3,10], pivot = 10
    // Output: [9,5,3,10,10,12,14]
    // Explanation:
    // The elements 9, 5, and 3 are less than the pivot so they are on the left side of the array.
    // The elements 12 and 14 are greater than the pivot so they are on the right side of the array.
    // The relative ordering of the elements less than and greater than pivot is also maintained. [9, 5, 3] and [12, 14] are the respective orderings.
    // 원소 9, 5, 3은 pivot보다 작으므로 배열의 왼쪽에 위치합니다.
    // 원소 12와 14는 pivot보다 크므로 배열의 오른쪽에 위치합니다.
    // pivot보다 작은 원소들과 큰 원소들의 상대적 순서도 유지됩니다. [9, 5, 3]과 [12, 14]가 각각의 순서입니다.

    vector<int> nums = {9,12,5,10,14,3,10};
    int pivot = 10;
    vector<int> expected = {9,5,3,10,10,12,14};
    vector<int> result = this->s.pivotArray(nums, pivot);
    EXPECT_EQ(result, expected);
}

TEST_F(CLASS_NAME, __LINE__)
{
    // Example 2:
    // Input: nums = [-3,4,3,2], pivot = 2
    // Output: [-3,2,4,3]
    // Explanation:
    // The element -3 is less than the pivot so it is on the left side of the array.
    // The elements 4 and 3 are greater than the pivot so they are on the right side of the array.
    // The relative ordering of the elements less than and greater than pivot is also maintained. [-3] and [4, 3] are the respective orderings.
    // 원소 -3은 pivot보다 작으므로 배열의 왼쪽에 위치합니다.
    // 원소 4와 3은 pivot보다 크므로 배열의 오른쪽에 위치합니다.
    // pivot보다 작은 원소들과 큰 원소들의 상대적 순서도 유지됩니다. [-3]과 [4, 3]이 각각의 순서입니다.

    vector<int> nums = {-3,4,3,2};
    int pivot = 2;
    vector<int> expected = {-3,2,4,3};
    vector<int> result = this->s.pivotArray(nums, pivot);
    EXPECT_EQ(result, expected);
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
