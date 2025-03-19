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



/* https://leetcode.com/problems/minimum-operations-to-make-binary-array-elements-equal-to-one-i/?envType=daily-question&envId=2025-03-19
 * @lc app=leetcode id=3191 lang=cpp
 * [3191] Minimum Operations to Make Binary Array Elements Equal to One I

You are given a binary array nums. Binary array contains only 0 and 1.
You can do the following operation on the array any number of times (possibly zero):
Choose any 3 consecutive elements from the array and flip all of them.
Flipping an element means changing its value from 0 to 1, and from 1 to 0.
Return the minimum number of operations required to make all elements in nums equal to 1. If it is impossible, return -1.

이진 배열 nums가 주어집니다. 이진 배열은 0과 1만 포함합니다.
배열에 대해 다음 연산을 원하는 횟수만큼(0번 포함) 수행할 수 있습니다:
배열에서 연속된 3개의 요소를 선택하고 모두 뒤집습니다.
요소를 뒤집는다는 것은 값을 0에서 1로, 1에서 0으로 변경하는 것을 의미합니다.
nums의 모든 요소를 1로 만들기 위해 필요한 최소 연산 횟수를 반환하세요. 불가능한 경우 -1을 반환하세요.

Constraints:
3 <= nums.length <= 10**5
0 <= nums[i] <= 1
 */

// @lc code=start
class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;

        int m = n - 2;
        for (int i = 0; i < m; i++) {
            if (nums[i] == 0) {
                nums[i] = 1;
                nums[i+1] = !(nums[i+1]);
                nums[i+2] = !(nums[i+2]);
                ans++;
            }
        }
        if (nums[n-1] != 1 || nums[n-2] != 1) {
            return -1;
        }
        return ans;
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
    // Input: nums = [0,1,1,1,0,0]
    // Output: 3
    // Explanation:
    // We can do the following operations:
    // Choose the elements at indices 0, 1 and 2. The resulting array is nums = [1,0,0,1,0,0].
    // Choose the elements at indices 1, 2 and 3. The resulting array is nums = [1,1,1,0,0,0].
    // Choose the elements at indices 3, 4 and 5. The resulting array is nums = [1,1,1,1,1,1].

    vector<int> nums = {0,1,1,1,0,0};
    EXPECT_EQ(this->s.minOperations(nums), 3);
}

TEST_F(CLASS_NAME, __LINE__)
{
    // Example 2:
    // Input: nums = [0,1,1,1]
    // Output: -1
    // Explanation:
    // It is impossible to make all elements equal to 1.

    vector<int> nums = {0,1,1,1};
    EXPECT_EQ(this->s.minOperations(nums), -1);
}

TEST_F(CLASS_NAME, __LINE__)
{

    vector<int> nums = {1,0,0,1,1,0,1,1,1,0,0,0,1,0,1};
    EXPECT_EQ(this->s.minOperations(nums), 9);
}



int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
