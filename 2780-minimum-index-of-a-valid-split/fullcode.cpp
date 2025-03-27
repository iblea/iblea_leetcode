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


/* https://leetcode.com/problems/minimum-index-of-a-valid-split/?envType=daily-question&envId=2025-03-27
 * @lc app=leetcode id=2780 lang=cpp
 * [2780] Minimum Index of a Valid Split

An element x of an integer array arr of length m is dominant if more than half the elements of arr have a value of x.
You are given a 0-indexed integer array nums of length n with one dominant element.
You can split nums at an index i into two arrays nums[0, ..., i] and nums[i + 1, ..., n - 1], but the split is only valid if:

- 0 <= i < n - 1
- nums[0, ..., i], and nums[i + 1, ..., n - 1] have the same dominant element.
Here, nums[i, ..., j] denotes the subarray of nums starting at index i and ending at index j, both ends being inclusive. Particularly, if j < i then nums[i, ..., j] denotes an empty subarray.

Return the minimum index of a valid split. If no valid split exists, return -1.

길이가 m인 정수 배열 arr에서 요소 x는 arr의 요소 중 절반 이상이 값 x를 가질 때 지배적(dominant)이라고 합니다.
길이가 n인 0-인덱스 정수 배열 nums가 주어지며, 이 배열에는 하나의 지배적 요소가 있습니다.
인덱스 i에서 nums를 두 배열 nums[0, ..., i]와 nums[i + 1, ..., n - 1]로 분할할 수 있지만, 다음 조건을 만족해야만 분할이 유효합니다:

- 0 <= i < n - 1
- nums[0, ..., i]와 nums[i + 1, ..., n - 1]가 동일한 지배적 요소를 가집니다.
여기서 nums[i, ..., j]는 인덱스 i에서 시작하여 인덱스 j에서 끝나는 부분 배열을 나타내며, 양쪽 끝을 포함합니다. 특히, j < i인 경우 nums[i, ..., j]는 빈 부분 배열을 나타냅니다.

유효한 분할의 최소 인덱스를 반환하세요. 유효한 분할이 없으면 -1을 반환하세요.

Constraints:
1 <= nums.length <= 10**5
1 <= nums[i] <= 10**9
nums has exactly one dominant element.
 */

// @lc code=start
class Solution {
public:
    int minimumIndex(vector<int>& nums) {
        int n = nums.size();
        int dominant = 0;
        int dominant_count = 0;
        // counter로 nums 요소의 개수를 세고, 지배적 요소를 찾는다.
        unordered_map<int, int> counter;
        for (int num : nums) {
            counter[num]++;
        }
        for (auto [num, count] : counter) {
            if (count > n / 2) {
                if (dominant > 0) {
                    return -1;
                }
                dominant = num;
                dominant_count = count;
            }
        }
        if (dominant <= 0) {
            return -1;
        }

        int left = 0;
        int right = dominant_count;
        int m = n - 1;
        for (int i = 0; i < m; i++) {
            if (nums[i] == dominant) {
                left++;
                right--;
            }
            if ((left * 2 > i + 1) && (right * 2 > m - i)) {
                return i;
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
    // Example 1:
    // Input: nums = [1,2,2,2]
    // Output: 2
    // Explanation: We can split the array at index 2 to obtain arrays [1,2,2] and [2].
    // In array [1,2,2], element 2 is dominant since it occurs twice in the array and 2 * 2 > 3.
    // In array [2], element 2 is dominant since it occurs once in the array and 1 * 2 > 1.
    // Both [1,2,2] and [2] have the same dominant element as nums, so this is a valid split.
    // It can be shown that index 2 is the minimum index of a valid split.
    // 설명: 인덱스 2에서 배열을 분할하여 [1,2,2]와 [2] 배열을 얻을 수 있습니다.
    // [1,2,2] 배열에서는 요소 2가 배열에서 두 번 발생하고 2 * 2 > 3이므로 지배적입니다.
    // [2] 배열에서는 요소 2가 배열에서 한 번 발생하고 1 * 2 > 1이므로 지배적입니다.
    // [1,2,2]와 [2] 모두 nums와 동일한 지배적 요소를 가지므로 이는 유효한 분할입니다.
    // 인덱스 2가 유효한 분할의 최소 인덱스임을 보여줄 수 있습니다.

    vector<int> nums = {1,2,2,2};
    EXPECT_EQ(this->s.minimumIndex(nums), 2);
}

TEST_F(CLASS_NAME, __LINE__)
{
    // Example 2:
    // Input: nums = [2,1,3,1,1,1,7,1,2,1]
    // Output: 4
    // Explanation: We can split the array at index 4 to obtain arrays [2,1,3,1,1] and [1,7,1,2,1].
    // In array [2,1,3,1,1], element 1 is dominant since it occurs thrice in the array and 3 * 2 > 5.
    // In array [1,7,1,2,1], element 1 is dominant since it occurs thrice in the array and 3 * 2 > 5.
    // Both [2,1,3,1,1] and [1,7,1,2,1] have the same dominant element as nums, so this is a valid split.
    // It can be shown that index 4 is the minimum index of a valid split.
    // 설명: 인덱스 4에서 배열을 분할하여 [2,1,3,1,1]과 [1,7,1,2,1] 배열을 얻을 수 있습니다.
    // [2,1,3,1,1] 배열에서는 요소 1이 배열에서 세 번 발생하고 3 * 2 > 5이므로 지배적입니다.
    // [1,7,1,2,1] 배열에서는 요소 1이 배열에서 세 번 발생하고 3 * 2 > 5이므로 지배적입니다.
    // [2,1,3,1,1]과 [1,7,1,2,1] 모두 nums와 동일한 지배적 요소를 가지므로 이는 유효한 분할입니다.
    // 인덱스 4가 유효한 분할의 최소 인덱스임을 보여줄 수 있습니다.

    vector<int> nums = {2,1,3,1,1,1,7,1,2,1};
    EXPECT_EQ(this->s.minimumIndex(nums), 4);
}

TEST_F(CLASS_NAME, __LINE__)
{
    // Example 3:
    // Input: nums = [3,3,3,3,7,2,2]
    // Output: -1
    // Explanation: It can be shown that there is no valid split.

    vector<int> nums = {3,3,3,3,7,2,2};
    EXPECT_EQ(this->s.minimumIndex(nums), -1);
}

TEST_F(CLASS_NAME, __LINE__)
{
    vector<int> nums = {1,2,1,2,3};
    EXPECT_EQ(this->s.minimumIndex(nums), -1);
}

TEST_F(CLASS_NAME, __LINE__)
{
    vector<int> nums = {8,9,9,9,9,4,9,9,9};
    EXPECT_EQ(this->s.minimumIndex(nums), 2);
}



int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
