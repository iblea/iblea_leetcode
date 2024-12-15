#include <gtest/gtest.h>
#include <iostream>
#include <iomanip>
#include <algorithm>
#include <vector>
#include <string>
#include <map>
#include <set>

using namespace std;


/*
https://leetcode.com/problems/continuous-subarrays/description/?envType=daily-question&envId=2024-12-14

You are given a 0-indexed integer array nums. A subarray of nums is called continuous if:
Let i, i + 1, ..., j be the indices in the subarray. Then, for each pair of indices i <= i1, i2 <= j, 0 <= |nums[i1] - nums[i2]| <= 2.
Return the total number of continuous subarrays.
A subarray is a contiguous non-empty sequence of elements within an array.

Example 1:
Input: nums = [5,4,2,4]
Output: 8
Explanation:
Continuous subarray of size 1: [5], [4], [2], [4].
Continuous subarray of size 2: [5,4], [4,2], [2,4].
Continuous subarray of size 3: [4,2,4].
Thereare no subarrys of size 4.
Total continuous subarrays = 4 + 3 + 1 = 8.
It can be shown that there are no more continuous subarrays.

Example 2:
Input: nums = [1,2,3]
Output: 6
Explanation:
Continuous subarray of size 1: [1], [2], [3].
Continuous subarray of size 2: [1,2], [2,3].
Continuous subarray of size 3: [1,2,3].
Total continuous subarrays = 3 + 2 + 1 = 6.


0-인덱스 기반의 정수 배열 nums가 주어집니다. nums의 부분 배열이 '연속적'이라고 불리려면 다음 조건을 만족해야 합니다:
부분 배열의 인덱스를 i, i+1, ..., j라고 할 때, i ≤ i1, i2 ≤ j 범위에 있는 모든 인덱스 쌍에 대해서, 0 ≤ |nums[i1] - nums[i2]| ≤ 2를 만족해야 합니다.
연속적인 부분 배열의 총 개수를 반환하세요.
여기서 부분 배열은 배열 내의 연속된 비어있지 않은 요소들의 시퀀스를 의미합니다.
(부연설명: 즉, 부분 배열 내의 어떤 두 수를 골라도 그 차이의 절대값이 2 이하여야 '연속적'이라고 판단합니다)

Constraints:
1 <= nums.length <= 10**5
1 <= nums[i] <= 10**9
 */
class Solution {
public:
    long long continuousSubarrays(vector<int>& nums) {
        const int n=nums.size();
        long long cnt=0;
        multiset<int> hasX;
        for(int l=0, r=0; r<n; r++){
            hasX.insert(nums[r]);
            while(l<r && *prev(hasX.end())-*hasX.begin()>2){
                auto it=hasX.find(nums[l]);
                hasX.erase(it);
                l++;
            }
            cnt+=r-l+1LL;
        }
        return cnt;
    }
    #define ll long long
    long long continuousSubarrays_1(vector<int>& nums) {
        ll cnt = 0;
        int l = 0, r = 0;
        priority_queue<pair<int, int>> pq1;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq2;

        while (r < nums.size()) {
            pq1.push({nums[r], r});
            pq2.push({nums[r], r});

            while (!pq1.empty() && !pq2.empty() && (pq1.top().first - pq2.top().first) > 2) {
                l++;
                while (!pq1.empty() && pq1.top().second < l) pq1.pop();
                while (!pq2.empty() && pq2.top().second < l) pq2.pop();
            }

            cnt += (r - l + 1);
            r++;
        }
        return cnt;
    }
    long long continuousSubarrays_my_answer(vector<int>& nums) {
        long long answer = 0;
        size_t nlen = nums.size();
        size_t left = 0;
        size_t right = 0;
        int val = nums[left];
        int minval = val - 2;
        int maxval = val + 2;
        while (true) {
            // 못찾았을 때
            if (right == nlen || (nums[right] < minval || nums[right] > maxval)) {
                // answer에 count 증가
                answer += right-left;
                // left 1 증가 시키고 set을 이후 left값을 기준으로 초기화
                left++;
                if (left >= nlen) {
                    break;
                }
                if (right <= left) {
                    right = left + 1;
                    val = nums[left];
                    minval = val - 2;
                    maxval = val + 2;
                    continue;
                }
                if (val == nums[left]) {
                    continue;
                }
                val = nums[left];
                minval = val - 2;
                maxval = val + 2;

                for (int i = left + 1; i < right; i++) {
                    int diff = nums[i] - val;
                    if (diff == 0) {
                        continue;
                    }
                    if (diff == -1) {
                        maxval = val + 1;
                    } else if (diff == 1) {
                        minval = val - 1;
                    }
                }
                continue;
            }
            // 찾았을 때, (nums[right] 범위에 맞지 않는 range 제거)
            if (val != nums[right]) {
                int diff = nums[right] - val;
                if (diff == -2) {
                    maxval = val;
                } else if (diff == -1) {
                    maxval = val + 1;
                } else if (diff == 1) {
                    minval = val - 1;
                } else if (diff == 2) {
                    minval = val;
                }
            }
            right++;
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
    vector<int> nums = {5,4,2,4};
	EXPECT_EQ(this->s.continuousSubarrays(nums), 8);
}

TEST_F(CLASS_NAME, __LINE__)
{
    vector<int> nums = {1,2,3};
	EXPECT_EQ(this->s.continuousSubarrays(nums), 6);
}

TEST_F(CLASS_NAME, __LINE__)
{
    vector<int> nums = {5,8,11,14};
	EXPECT_EQ(this->s.continuousSubarrays(nums), 4);
}

TEST_F(CLASS_NAME, __LINE__)
{
    vector<int> nums = {5,4,5,6};
	EXPECT_EQ(this->s.continuousSubarrays(nums), 10);
}

TEST_F(CLASS_NAME, __LINE__)
{
    vector<int> nums = {5,4,5,6,10,9,11,10};
	EXPECT_EQ(this->s.continuousSubarrays(nums), 20);
}

TEST_F(CLASS_NAME, __LINE__)
{
    vector<int> nums = {5,4,5,6,8,9};
	EXPECT_EQ(this->s.continuousSubarrays(nums), 14);
}

TEST_F(CLASS_NAME, __LINE__)
{
    vector<int> nums = {5,6,7,6,6,5,4,5,5,4};
	EXPECT_EQ(this->s.continuousSubarrays(nums), 43);
}

TEST_F(CLASS_NAME, __LINE__)
{
    vector<int> nums = {4,5,6,4,6,3,2};
	EXPECT_EQ(this->s.continuousSubarrays(nums), 18);
}





int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}