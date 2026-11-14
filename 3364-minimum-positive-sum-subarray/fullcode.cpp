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


/* https://leetcode.com/problems/minimum-positive-sum-subarray/
                                            
3364 | Easy | Minimum Positive Sum Subarray 

You are given an integer array nums and two integers l and r. Your task is to find the minimum sum of a subarray whose size is between l and r (inclusive) and whose sum is greater than 0.
Return the minimum sum of such a subarray. If no such subarray exists, return -1.
A subarray is a contiguous non-empty sequence of elements within an array.

󰛨 Example 1:
Input: nums = [3, -2, 1, 4], l = 2, r = 3
Output: 1
Explanation:
The subarrays of length between l = 2 and r = 3 where the sum is greater than 0 are:
	* [3, -2] with a sum of 1
	* [1, 4] with a sum of 5
	* [3, -2, 1] with a sum of 2
	* [-2, 1, 4] with a sum of 3
Out of these, the subarray [3, -2] has a sum of 1, which is the smallest positive sum. Hence, the answer is 1.

󰛨 Example 2:
Input: nums = [-2, 2, -3, 1], l = 2, r = 3
Output: -1
Explanation:
There is no subarray of length between l and r that has a sum greater than 0. So, the answer is -1.

󰛨 Example 3:
Input: nums = [1, 2, 3, 4], l = 2, r = 4
Output: 3
Explanation:
The subarray [1, 2] has a length of 2 and the minimum sum greater than 0. So, the answer is 3.

 Constraints:
	* 1 <= nums.length <= 100
	* 1 <= l <= r <= nums.length
	* -1000 <= nums[i] <= 1000



정수 배열 nums와 두 정수 l, r이 주어집니다. 크기가 l 이상 r 이하이고 합이 0보다 큰 부분 배열의 최소 합을 구하는 것이 과제입니다.
이러한 부분 배열의 최소 합을 반환하십시오. 그러한 부분 배열이 존재하지 않으면 -1을 반환하십시오.
부분 배열이란 배열 내에서 연속하며 비어 있지 않은 원소들의 나열을 말합니다.

󰛨 예제 1:
입력: nums = [3, -2, 1, 4], l = 2, r = 3
출력: 1
설명:
길이가 l = 2 이상 r = 3 이하이면서 합이 0보다 큰 부분 배열은 다음과 같습니다:
	* [3, -2]의 합은 1
	* [1, 4]의 합은 5
	* [3, -2, 1]의 합은 2
	* [-2, 1, 4]의 합은 3
이 중 부분 배열 [3, -2]의 합이 1로, 가장 작은 양수 합입니다. 따라서 답은 1입니다.

󰛨 예제 2:
입력: nums = [-2, 2, -3, 1], l = 2, r = 3
출력: -1
설명:
길이가 l 이상 r 이하이면서 합이 0보다 큰 부분 배열이 존재하지 않습니다. 따라서 답은 -1입니다.

󰛨 예제 3:
입력: nums = [1, 2, 3, 4], l = 2, r = 4
출력: 3
설명:
부분 배열 [1, 2]는 길이가 2이며, 0보다 큰 합 중 최솟값을 가집니다. 따라서 답은 3입니다.

 제약 조건:
	* 1 <= nums.length <= 100
	* 1 <= l <= r <= nums.length
	* -1000 <= nums[i] <= 1000
 */

// @leet start
class Solution {
public:
    int minimumSumSubarray(vector<int>& nums, int l, int r) {
        int min_val = -1;

        for (int i = 0; i < nums.size(); i++) {
            int sum = 0;
            for (int j = i; j < nums.size(); j++) {
                sum += nums[j];
                if (j - i + 1 >= l && j - i + 1 <= r && sum > 0) {
                    if (min_val == -1 || sum < min_val) {
                        min_val = sum;
                    }
                }
            }
        }
        return min_val;
    }
};
// @leet end


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
    vector<int> nums = {3, -2, 1, 4};
    EXPECT_EQ(this->s.minimumSumSubarray(nums, 2, 3), 1);
}

TEST_F(CLASS_NAME, __LINE__)
{
    vector<int> nums = {-2, 2, -3, 1};
    EXPECT_EQ(this->s.minimumSumSubarray(nums, 2, 3), -1);
}

TEST_F(CLASS_NAME, __LINE__)
{
    vector<int> nums = {1, 2, 3, 4};
    EXPECT_EQ(this->s.minimumSumSubarray(nums, 2, 4), 3);
}


int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
