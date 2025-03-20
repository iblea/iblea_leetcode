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



/* https://leetcode.com/problems/zero-array-transformation-ii/?envType=daily-question&envId=2025-03-13
 * @lc app=leetcode id=3356 lang=cpp
 * [3356] Zero Array Transformation II

You are given an integer array nums of length n and a 2D array queries where queries[i] = [li, ri, vali].
Each queries[i] represents the following action on nums:
Decrement the value at each index in the range [li, ri] in nums by at most vali.
The amount by which each value is decremented can be chosen independently for each index.
A Zero Array is an array with all its elements equal to 0.
Return the minimum possible non-negative value of k, such that after processing the first k queries in sequence, nums becomes a Zero Array. If no such k exists, return -1.

길이가 n인 정수 배열 nums와 2D 배열 queries가 주어집니다. queries[i] = [li, ri, vali]입니다.
각 queries[i]는 nums에 대한 다음 작업을 나타냅니다:
nums의 [li, ri] 범위 내 각 인덱스의 값을 최대 vali만큼 감소시킵니다.
각 인덱스의 값이 감소되는 양은 각 인덱스마다 독립적으로 선택할 수 있습니다.
Zero Array는 모든 요소가 0인 배열입니다.
쿼리를 순서대로 처리했을 때, nums가 Zero Array가 되는 최소 비음수 값 k를 반환하세요. 그런 k가 존재하지 않으면 -1을 반환하세요.

Constraints:
1 <= nums.length <= 10**5
0 <= nums[i] <= 5 * 10**5
1 <= queries.length <= 10**5
queries[i].length == 3
0 <= li <= ri < nums.length
1 <= vali <= 5 * 10**5
 */

// @lc code=start
class Solution {
public:
    int minZeroArray_my(vector<int>& nums, vector<vector<int>>& queries) {
        long long sums = 0;
        int q = queries.size();

        for (int num : nums) {
            sums += num;
        }
        if (sums <= 0) {
            return 0;
        }

        for (int i = 0; i < q; i++) {
            int l = queries[i][0];
            int r = queries[i][1];
            int val = queries[i][2];
            for (int j = l; j <= r; j++) {
                if (nums[j] <= 0) {
                    continue;
                }
                if (nums[j] - val < 0) {
                    sums -= nums[j];
                    nums[j] = 0;
                } else {
                    sums -= val;
                    nums[j] -= val;
                }
                if (sums <= 0) {
                    return i + 1;
                }
            }
        }
        return -1;
    }
    int minZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        auto canMakeZeroArray = [&](int k) {
            vector<int> diff(n + 1, 0);
            for (int i = 0; i < k; i++) {
                int left = queries[i][0], right = queries[i][1], val = queries[i][2];
                diff[left] += val;
                diff[right + 1] -= val;
            }
            int currVal = 0;
            for (int i = 0; i < n; i++) {
                currVal += diff[i];
                if (currVal < nums[i]) return false;
            }
            return true;
        };
        // 모든 요소가 0이면, 바로 0 반환
        if (all_of(nums.begin(), nums.end(), [](int x) { return x == 0; })) return 0;

        int left = 1, right = queries.size();
        if (!canMakeZeroArray(right)) return -1;
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (canMakeZeroArray(mid)) right = mid;
            else left = mid + 1;
        }
        return left;
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
    // Input: nums = [2,0,2], queries = [[0,2,1],[0,2,1],[1,1,3]]
    // Output: 2
    // Explanation:
    // For i = 0 (l = 0, r = 2, val = 1):
    // Decrement values at indices [0, 1, 2] by [1, 0, 1] respectively.
    // The array will become [1, 0, 1].
    // For i = 1 (l = 0, r = 2, val = 1):
    // Decrement values at indices [0, 1, 2] by [1, 0, 1] respectively.
    // The array will become [0, 0, 0], which is a Zero Array. Therefore, the minimum value of k is 2.

    // i = 0일 때 (l = 0, r = 2, val = 1):
    // 인덱스 [0, 1, 2]의 값을 각각 [1, 0, 1]만큼 감소시킵니다.
    // 배열은 [1, 0, 1]이 됩니다.
    // i = 1일 때 (l = 0, r = 2, val = 1):
    // 인덱스 [0, 1, 2]의 값을 각각 [1, 0, 1]만큼 감소시킵니다.
    // 배열은 [0, 0, 0]이 되어 Zero Array가 됩니다. 따라서 k의 최소값은 2입니다.

    vector<int> nums = {2, 0, 2};
    vector<vector<int>> queries = {{0, 2, 1}, {0, 2, 1}, {1, 1, 3}};
	EXPECT_EQ(this->s.minZeroArray(nums, queries), 2);
}

TEST_F(CLASS_NAME, __LINE__)
{
    // Example 2:
    // Input: nums = [4,3,2,1], queries = [[1,3,2],[0,2,1]]
    // Output: -1
    // Explanation:
    // For i = 0 (l = 1, r = 3, val = 2):
    // Decrement values at indices [1, 2, 3] by [2, 2, 1] respectively.
    // The array will become [4, 1, 0, 0].
    // For i = 1 (l = 0, r = 2, val = 1):
    // Decrement values at indices [0, 1, 2] by [1, 1, 0] respectively.
    // The array will become [3, 0, 0, 0], which is not a Zero Array.

    // i = 0일 때 (l = 1, r = 3, val = 2):
    // 인덱스 [1, 2, 3]의 값을 각각 [2, 2, 1]만큼 감소시킵니다.
    // 배열은 [4, 1, 0, 0]이 됩니다.
    // i = 1일 때 (l = 0, r = 2, val = 1):
    // 인덱스 [0, 1, 2]의 값을 각각 [1, 1, 0]만큼 감소시킵니다.
    // 배열은 [3, 0, 0, 0]이 되어 Zero Array가 아닙니다.

    vector<int> nums = {4, 3, 2, 1};
    vector<vector<int>> queries = {{1, 3, 2}, {0, 2, 1}};
	EXPECT_EQ(this->s.minZeroArray(nums, queries), -1);
}



int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
