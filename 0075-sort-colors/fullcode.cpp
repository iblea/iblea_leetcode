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


/*
 * @lc app=leetcode id=75 lang=cpp
 * [75] 색깔 정렬

n개의 빨간색, 흰색, 파란색으로 칠해진 객체가 들어있는 배열 nums가 주어졌을 때, 같은 색깔의 객체들이 인접하도록 제자리에서 정렬해줘. 색깔의 순서는 빨간색, 흰색, 파란색 순서야.
빨간색, 흰색, 파란색을 각각 정수 0, 1, 2로 표현할 거야.
라이브러리의 sort 함수를 사용하지 않고 이 문제를 풀어야 해.


예시 1:
입력: nums = [2,0,2,1,1,0]
출력: [0,0,1,1,2,2]
예시 2:
입력: nums = [2,0,1]
출력: [0,1,2]


제약 조건:
n == nums.length
1 <= n <= 300
nums[i]는 0, 1, 2 중 하나야.

추가 문제: 상수 크기의 추가 공간만 사용해서 한 번만 배열을 순회하는 알고리즘을 생각해볼 수 있을까?
 */

// @lc code=start

#define RED_COLOR 0
#define WHITE_COLOR 1
#define BLUE_COLOR 2

class Solution {
public:
    void sortColors(vector<int>& nums) {
        vector<int> colorCount(3, 0);

        for (int i = 0; i < nums.size(); i++) {
            colorCount[nums[i]]++;
        }
        for (int i = 0; i < nums.size(); i++) {
            if (i < colorCount[RED_COLOR]) {
                nums[i] = RED_COLOR;
            } else if (i < colorCount[RED_COLOR] + colorCount[WHITE_COLOR]) {
                nums[i] = WHITE_COLOR;
            } else {
                nums[i] = BLUE_COLOR;
            }
        }
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
    vector<int> nums = {2, 0, 2, 1, 1, 0};
    s.sortColors(nums);
    EXPECT_EQ(nums[0], 0);
    EXPECT_EQ(nums[1], 0);
    EXPECT_EQ(nums[2], 1);
    EXPECT_EQ(nums[3], 1);
    EXPECT_EQ(nums[4], 2);
    EXPECT_EQ(nums[5], 2);

    nums = {2, 0, 1};
    s.sortColors(nums);
    EXPECT_EQ(nums[0], 0);
    EXPECT_EQ(nums[1], 1);
    EXPECT_EQ(nums[2], 2);
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
