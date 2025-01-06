#include <gtest/gtest.h>
#include <iostream>
#include <iomanip>
#include <algorithm>
#include <vector>
#include <string>
#include <map>

using namespace std;


/*
https://leetcode.com/problems/minimum-number-of-operations-to-move-all-balls-to-each-box/description/?envType=daily-question&envId=2025-01-06
 * @lc app=leetcode id=1769 lang=cpp
 *
 * [1769] Minimum Number of Operations to Move All Balls to Each Box
 // Start of Selection
You have n boxes. You are given a binary string boxes of length n, where boxes[i] is '0' if the ith box is empty, and '1' if it contains one ball.
In one operation, you can move one ball from a box to an adjacent box. Box i is adjacent to box j if abs(i - j) == 1. Note that after doing so, there may be more than one ball in some boxes.
Return an array answer of size n, where answer[i] is the minimum number of operations needed to move all the balls to the ith box.
Each answer[i] is calculated considering the initial state of the boxes.

상자 n개가 있습니다. 길이가 n인 이진 문자열 boxes가 주어지며, boxes[i]가 '0'이면 i번째 상자가 비어 있는 것이고, '1'이면 하나의 공이 들어 있는 것입니다.
한 번의 작업에서, 하나의 공을 상자에서 인접한 상자로 옮길 수 있습니다. 상자 i는 abs(i - j) == 1일 때 상자 j와 인접합니다. 이 작업 후에는 일부 상자에 여러 개의 공이 있을 수 있습니다.
크기가 n인 배열 answer를 반환하며, answer[i]는 모든 공을 i번째 상자로 옮기는 데 필요한 최소 작업 수입니다.
각 answer[i]는 상자의 초기 상태를 고려하여 계산됩니다.

Input: boxes = "110"
Output: [1,1,3]
Explanation: The answer for each box is as follows:
1) First box: you will have to move one ball from the second box to the first box in one operation.
2) Second box: you will have to move one ball from the first box to the second box in one operation.
3) Third box: you will have to move one ball from the first box to the third box in two operations, and move one ball from the second box to the third box in one operation.

설명: 각 상자에 대한 답은 다음과 같습니다:
1) 첫 번째 상자: 두 번째 상자에서 첫 번째 상자로 하나의 공을 한 번의 작업으로 옮겨야 합니다.
2) 두 번째 상자: 첫 번째 상자에서 두 번째 상자로 하나의 공을 한 번의 작업으로 옮겨야 합니다.
3) 세 번째 상자: 첫 번째 상자에서 세 번째 상자로 하나의 공을 두 번의 작업으로 옮기고, 두 번째 상자에서 세 번째 상자로 하나의 공을 한 번의 작업으로 옮겨야 합니다.

Input: boxes = "001011"
Output: [11,8,5,4,3,4]

Constraints:
n == boxes.length
1 <= n <= 2000
boxes[i] is either '0' or '1'.
 */

// @lc code=start
class Solution {
public:

    vector<int> minOperations(string boxes) {
        vector<int> answer;
        for (int i = 0; i < boxes.size(); i++) {
            int sum = 0;
            for (int j = 0; j < boxes.size(); j++) {
                if (boxes[j] == '0') {
                    continue;
                }
                sum += abs(j - i);
            }
            answer.push_back(sum);
        }
        return answer;
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
    vector<int> answer = {1,1,3};
	EXPECT_EQ(this->s.minOperations("110"), answer);
}

TEST_F(CLASS_NAME, __LINE__)
{
    vector<int> answer = {11,8,5,4,3,4};
	EXPECT_EQ(this->s.minOperations("001011"), answer);
}


int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}