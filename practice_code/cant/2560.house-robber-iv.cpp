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



/* https://leetcode.com/problems/house-robber-iv/?envType=daily-question&envId=2025-03-15
 * @lc app=leetcode id=2560 lang=cpp
 * [2560] House Robber IV

There are several consecutive houses along a street, each of which has some money inside. There is also a robber, who wants to steal money from the homes, but he refuses to steal from adjacent homes.
The capability of the robber is the maximum amount of money he steals from one house of all the houses he robbed.
You are given an integer array nums representing how much money is stashed in each house. More formally, the ith house from the left has nums[i] dollars.
You are also given an integer k, representing the minimum number of houses the robber will steal from. It is always possible to steal at least k houses.
Return the minimum capability of the robber out of all the possible ways to steal at least k houses.

거리를 따라 연속된 여러 집들이 있으며, 각 집에는 일정 금액의 돈이 보관되어 있습니다. 또한 도둑이 있는데, 이 도둑은 집에서 돈을 훔치고 싶지만 인접한 집에서는 훔치지 않기로 했습니다.
도둑의 능력치는 그가 훔친 모든 집 중 한 집에서 훔친 최대 금액으로 정의됩니다.
정수 배열 nums가 주어지며, 이는 각 집에 얼마나 많은 돈이 보관되어 있는지를 나타냅니다. 더 정확히 말하면, 왼쪽에서 i번째 집에는 nums[i] 달러가 있습니다.
또한 정수 k가 주어지는데, 이는 도둑이 훔칠 최소 집의 수를 나타냅니다. 항상 최소 k개의 집을 훔칠 수 있다고 가정합니다.
최소 k개의 집을 훔치는 모든 가능한 방법 중에서 도둑의 최소 능력치를 반환하세요.


Constraints:
1 <= nums.length <= 10**5
1 <= nums[i] <= 10**9
1 <= k <= (nums.length + 1)/2
 */

// @lc code=start
class Solution {
    int n;
    vector<int> *nums;

private:
    bool check(int mid, int k) {
        int count = 0;
        for (int i = 0; i < this->n; i++) {
            if ((*this->nums)[i] <= mid) {
                count++;
                i++;
            }
        }
        return count >= k;
    }

public:
    int minCapability(vector<int>& nums, int k) {
        this->n = nums.size();
        this->nums = &nums;

        int left = *min_element(nums.begin(), nums.end());
        int right = *max_element(nums.begin(), nums.end());

        while (left < right) {
            int mid = (left + right) / 2;
            if (this->check(mid, k)) {
                right = mid;
            } else {
                left = mid + 1;
            }
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
    // Input: nums = [2,3,5,9], k = 2
    // Output: 5
    // Explanation:
    // There are three ways to rob at least 2 houses:
    // - Rob the houses at indices 0 and 2. Capability is max(nums[0], nums[2]) = 5.
    // - 인덱스 0과 2에 있는 집들을 털기. 능력치는 max(nums[0], nums[2]) = 5.
    // - Rob the houses at indices 0 and 3. Capability is max(nums[0], nums[3]) = 9.
    // - Rob the houses at indices 1 and 3. Capability is max(nums[1], nums[3]) = 9.
    // Therefore, we return min(5, 9, 9) = 5.

    vector<int> nums = {2,3,5,9};
    int k = 2;
    int expected = 5;
    EXPECT_EQ(this->s.minCapability(nums, k), expected);
}

TEST_F(CLASS_NAME, __LINE__)
{
    // Example 2:
    // Input: nums = [2,7,9,3,1], k = 2
    // Output: 2
    // Explanation: There are 7 ways to rob the houses. The way which leads to minimum capability is to rob the house at index 0 and 4. Return max(nums[0], nums[4]) = 2.

    vector<int> nums = {2,7,9,3,1};
    int k = 2;
    int expected = 2;
    EXPECT_EQ(this->s.minCapability(nums, k), expected);
}



int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
