#include <gtest/gtest.h>
#include <iostream>
#include <iomanip>
#include <algorithm>
#include <vector>
#include <string>
#include <map>

using namespace std;


/*
https://leetcode.com/problems/maximum-beauty-of-an-array-after-applying-operation

2779. Maximum Beauty of an Array After Applying Operation
You are given a 0-indexed array nums and a non-negative integer k.
In one operation, you can do the following:
- Choose an index i that hasn't been chosen before from the range [0, nums.length - 1].
- Replace nums[i] with any integer from the range [nums[i] - k, nums[i] + k].
The beauty of the array is the length of the longest subsequence consisting of equal elements.
Return the maximum possible beauty of the array nums after applying the operation any number of times.
Note that you can apply the operation to each index only once.
A subsequence of an array is a new array generated from the original array by deleting some elements (possibly none) without changing the order of the remaining elements.

Example 1:
Input: nums = [4,6,1,2], k = 2
Output: 3
Explanation: In this example, we apply the following operations:
- Choose index 1, replace it with 4 (from range [4,8]), nums = [4,4,1,2].
- Choose index 3, replace it with 4 (from range [0,4]), nums = [4,4,1,4].
After the applied operations, the beauty of the array nums is 3 (subsequence consisting of indices 0, 1, and 3).
It can be proven that 3 is the maximum possible length we can achieve.

Example 2:
Input: nums = [1,1,1,1], k = 10
Output: 4
Explanation: In this example we don't have to apply any operations.
The beauty of the array nums is 4 (whole array).

Constraints:
1 <= nums.length <= 10**5
0 <= nums[i], k <= 10**5

2779. 배열에 연산을 적용한 후의 최대 아름다움 값

문제 설명: 0부터 시작하는 인덱스를 가진 배열 nums와 음이 아닌 정수 k가 주어집니다. 한 번의 연산에서 다음과 같은 작업을 수행할 수 있습니다:
[0, nums.length - 1] 범위에서 이전에 선택되지 않은 인덱스 i를 선택합니다.
nums[i]를 [nums[i] - k, nums[i] + k] 범위의 임의의 정수로 교체할 수 있습니다.
배열의 아름다움은 동일한 요소로 구성된 가장 긴 부분 수열의 길이입니다. 연산을 여러 번 적용한 후 얻을 수 있는 배열 nums의 최대 아름다움 값을 반환하세요. 각 인덱스에 대해 연산은 한 번만 적용할 수 있습니다.
부분 수열은 원래 배열에서 일부 요소를 삭제하여(또는 삭제하지 않고) 생성된 새 배열이며, 남은 요소들의 순서는 변경되지 않습니다.

예시 1: 입력: nums = [4,6,1,2], k = 2 출력: 3 설명: 다음과 같은 연산을 적용합니다:
인덱스 1을 선택하여 4로 교체 ([4,8] 범위에서), nums = [4,4,1,2]
인덱스 3을 선택하여 4로 교체 ([0,4] 범위에서), nums = [4,4,1,4] 연산 적용 후, 배열의 아름다움은 3입니다 (인덱스 0, 1, 3으로 구성된 부분 수열). 3이 달성할 수 있는 최대 길이임이 증명됩니다.
예시 2: 입력: nums = [1,1,1,1], k = 10 출력: 4 설명: 이 예시에서는 어떤 연산도 적용할 필요가 없습니다. 배열의 아름다움은 4입니다 (전체 배열).
 */

class Solution {
public:
    int maximumBeauty(vector<int>& nums, int k) {
        vector<int> n(nums);
        sort(n.begin(), n.end());
        int similar = k * 2;
        size_t start = 0;
        size_t end = 1;
        size_t len = n.size();
        int ago_pos = -1;
        int answer = 0;
        // sliding window
        // k = 2 일때, 0부터 4까지, 1부터 5까지, 2부터 6까지 ....
        while (start < len) {
            if (end < len && n[end] <= n[start] + similar) {
                end++;
                continue;
            }
            // 넘으면
            int cnt = end - start;
            answer = max(answer, cnt);
            ago_pos = n[start];
            while (start < len and n[start] == ago_pos) {
                start++;
            }
            if (start >= end) {
                end = start + 1;
            }
        }
        return answer;
    }

    int maximumBeauty_1(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int similar = k * 2;
        int answer = 1;
        int ago_pos = -1;
        for (size_t i = 0; i < nums.size(); i++) {
            int pos = nums[i];
            if (pos == ago_pos) {
                continue;
            }
            int cnt = 1;
            for (size_t j = i + 1; j < nums.size(); j++) {
                if (nums[j] <= pos + similar) {
                    cnt++;
                } else {
                    break;
                }
            }
            if (cnt > answer) {
                answer = cnt;
            }
            ago_pos = pos;;
        }
        return answer;
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
    vector<int> arg = {4,6,1,2};
	EXPECT_EQ(this->s.maximumBeauty(arg, 2), 3);
}

TEST_F(CLASS_NAME, __LINE__)
{
    vector<int> arg = {1,1,1,1};
	EXPECT_EQ(this->s.maximumBeauty(arg, 10), 4);
}

TEST_F(CLASS_NAME, __LINE__)
{
    vector<int> arg = {1,3,5,7,9};
	EXPECT_EQ(this->s.maximumBeauty(arg, 2), 3);
}

TEST_F(CLASS_NAME, __LINE__)
{
    vector<int> arg = {9,7,5,3,1};
	EXPECT_EQ(this->s.maximumBeauty(arg, 2), 3);
}


TEST_F(CLASS_NAME, __LINE__)
{
    vector<int> arg = {1,3,0,5,4};
	EXPECT_EQ(this->s.maximumBeauty(arg, 2), 4);
}

TEST_F(CLASS_NAME, __LINE__)
{
    vector<int> arg = {1,2,2,2,5,5,5,6,6,6,6,6,7,10,15,15,15,16,18,19};
	EXPECT_EQ(this->s.maximumBeauty(arg, 1), 9);
}




int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}