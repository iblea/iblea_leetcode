#include <gtest/gtest.h>
#include <iostream>
#include <iomanip>
#include <algorithm>
#include <vector>
#include <string>
#include <map>
#include <queue>

using namespace std;


/*
https://leetcode.com/problems/final-array-state-after-k-multiplication-operations-i/?envType=daily-question&envId=2024-12-16

3264. Final Array State After K Multiplication Operations I

You are given an integer array nums, an integer k, and an integer multiplier.
You need to perform k operations on nums. In each operation:
Find the minimum value x in nums. If there are multiple occurrences of the minimum value, select the one that appears first.
Replace the selected minimum value x with x * multiplier.
Return an integer array denoting the final state of nums after performing all k operations.

정수 배열 nums, 정수 k, 그리고 정수 multiplier가 주어집니다.
nums에 대해 k번의 연산을 수행해야 합니다. 각 연산에서:
nums에서 최소값 x를 찾습니다. 최소값이 여러 번 나타나는 경우, 처음 나타나는 것을 선택합니다.
선택한 최소값 x를 x * multiplier로 대체합니다.
모든 k번의 연산을 수행한 후 nums의 최종 상태를 나타내는 정수 배열을 반환합니다.


Example 1:
Input: nums = [2,1,3,5,6], k = 5, multiplier = 2
Output: [8,4,6,5,6]
Explanation:
Operation	Result
After operation 1	[2, 2, 3, 5, 6]
After operation 2	[4, 2, 3, 5, 6]
After operation 3	[4, 4, 3, 5, 6]
After operation 4	[4, 4, 6, 5, 6]
After operation 5	[8, 4, 6, 5, 6]

Example 2:
Input: nums = [1,2], k = 3, multiplier = 4
Output: [16,8]
Explanation:
Operation	Result
After operation 1	[4, 2]
After operation 2	[4, 8]
After operation 3	[16, 8]


Constraints:

1 <= nums.length <= 100
1 <= nums[i] <= 100
1 <= k <= 10
1 <= multiplier <= 5
 *
 */

class Solution {
public:
    vector<int> getFinalState(vector<int>& nums, int k, int multiplier) {

        // nums 배열을복사
        vector<int> result = nums;
        // 우선순위 큐를 사용해 value와 해당 index를 저장한다.
        // 우선순위 큐는 첫 번째 인덱스의 값이 작은 순서대로 정렬된다.
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

        for (int i = 0; i < nums.size(); i++) {
            pq.push({nums[i], i});
        }

        // int min_val;
        for (int i = 0; i < k; i++) {
            auto [value, index] = pq.top();
            // min_val = value;
            pq.pop();
            // 최소값을 찾아 곱한 뒤 다시 우선순위 큐에 넣는다.
            // 이후 이를 배열에도 반영한다.
            pq.push({value * multiplier, index});
            result[index] = value * multiplier;

            #if 0
            // 우선순위 큐에 있는 최소값이 같은 경우 반복적으로 처리한다.
            while (!pq.empty() && pq.top().first == min_val) {
                auto [value, index] = pq.top();
                std::cout << pq.top().first << ", " << pq.top().second << std::endl;
                pq.pop();
                result[index] = value * multiplier;
                pq.push({value * multiplier, index});
            }
            #endif
        }
        return result;
    }
};



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
    vector<int> nums = {2,1,3,5,6};
    int k = 5;
    int multiplier = 2;
    vector<int> expected = {8,4,6,5,6};
	EXPECT_EQ(this->s.getFinalState(nums, k, multiplier), expected);
}

TEST_F(CLASS_NAME, __LINE__)
{
    vector<int> nums = {1,2};
    int k = 3;
    int multiplier = 4;
    vector<int> expected = {16,8};
	EXPECT_EQ(this->s.getFinalState(nums, k, multiplier), expected);
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}