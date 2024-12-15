#include <gtest/gtest.h>
#include <iostream>
#include <iomanip>
#include <algorithm>
#include <vector>
#include <string>
#include <map>

using namespace std;


/*

https://leetcode.com/problems/find-score-of-an-array-after-marking-all-elements/description/?envType=daily-question&envId=2024-12-13

You are given an array nums consisting of positive integers.
Starting with score = 0, apply the following algorithm:
Choose the smallest integer of the array that is not marked. If there is a tie, choose the one with the smallest index.
Add the value of the chosen integer to score.
Mark the chosen element and its two adjacent elements if they exist.
Repeat until all the array elements are marked.
Return the score you get after applying the above algorithm.

Example 1:
Input: nums = [2,1,3,4,5,2]
Output: 7
Explanation: We mark the elements as follows:
- 1 is the smallest unmarked element, so we mark it and its two adjacent elements: [2,1,3,4,5,2].
- 2 is the smallest unmarked element, so we mark it and its left adjacent element: [2,1,3,4,5,2].
- 4 is the only remaining unmarked element, so we mark it: [2,1,3,4,5,2].
Our score is 1 + 2 + 4 = 7.

Example 2:
Input: nums = [2,3,5,1,3,2]
Output: 5
Explanation: We mark the elements as follows:
- 1 is the smallest unmarked element, so we mark it and its two adjacent elements: [2,3,5,1,3,2].
- 2 is the smallest unmarked element, since there are two of them, we choose the left-most one, so we mark the one at index 0 and its right adjacent element: [2,3,5,1,3,2].
- 2 is the only remaining unmarked element, so we mark it: [2,3,5,1,3,2].
Our score is 1 + 2 + 2 = 5.

양의 정수로 구성된 배열 nums가 주어집니다. score = 0으로 시작하여 다음 알고리즘을 적용합니다:

- 표시되지 않은 배열의 가장 작은 정수를 선택합니다. 동점인 경우 가장 작은 인덱스를 가진 것을 선택합니다.
- 선택한 정수의 값을 score에 더합니다.
- 선택한 요소와 그 양쪽에 인접한 요소(존재하는 경우)를 표시합니다.
- 배열의 모든 요소가 표시될 때까지 반복합니다.
위의 알고리즘을 적용한 후 얻은 score를 반환합니다.

예제 1: 입력: nums = [2,1,3,4,5,2] 출력: 7 설명: 다음과 같이 요소를 표시합니다:
- 1이 표시되지 않은 가장 작은 요소이므로 이것과 인접한 두 요소를 표시합니다: [2,1,3,4,5,2].
- 2가 표시되지 않은 가장 작은 요소이므로 이것과 왼쪽 인접 요소를 표시합니다: [2,1,3,4,5,2].
- 4가 남은 유일한 표시되지 않은 요소이므로 이것을 표시합니다: [2,1,3,4,5,2]. 우리의 점수는 1 + 2 + 4 = 7입니다.

예제 2: 입력: nums = [2,3,5,1,3,2] 출력: 5 설명: 다음과 같이 요소를 표시합니다:
1이 표시되지 않은 가장 작은 요소이므로 이것과 인접한 두 요소를 표시합니다: [2,3,5,1,3,2].
2가 표시되지 않은 가장 작은 요소이며, 두 개가 있으므로 가장 왼쪽에 있는 것을 선택합니다. 따라서 인덱스 0의 요소와 그 오른쪽 인접 요소를 표시합니다: [2,3,5,1,3,2].
2가 남은 유일한 표시되지 않은 요소이므로 이것을 표시합니다: [2,3,5,1,3,2]. 우리의 점수는 1 + 2 + 2 = 5입니다.







Constraints:
1 <= nums.length <= 10**5
1 <= nums[i] <= 10**6
 */
class Solution {
public:
    long long findScore(vector<int>& nums) {

        vector<tuple<int, int>> pos;
        for (size_t i = 0; i < nums.size(); i++) {
            // value, index
            tuple<int, int> t = make_tuple(nums[i], i);
            pos.push_back(t);
        }

        // 첫 번째값을 기준으로 정렬
        vector<bool> visited(nums.size(), false);
        sort(pos.begin(), pos.end(), [](tuple<int, int> a, tuple<int, int> b) {
            if (get<0>(a) == get<0>(b)) {
                return get<1>(a) < get<1>(b);
            }
            return get<0>(a) < get<0>(b);
        });

        long long answer = 0;
        for (size_t i = 0; i < pos.size(); i++) {
            int value = get<0>(pos[i]);
            int index = get<1>(pos[i]);
            if (visited[index]) {
                continue;
            }

            visited[index] = true;
            int left = index - 1;
            int right = index + 1;
            if (left >= 0 && !visited[left]) {
                visited[left] = true;
            }
            if (right < nums.size() && !visited[right]) {
                visited[right] = true;
            }
            answer += value;
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
    vector<int> pushed = {2,1,3,4,5,2};
	EXPECT_EQ(this->s.findScore(pushed) , 7);
}

TEST_F(CLASS_NAME, __LINE__)
{
    vector<int> pushed = {2,3,5,1,3,2};
	EXPECT_EQ(this->s.findScore(pushed) , 5);
}


int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}