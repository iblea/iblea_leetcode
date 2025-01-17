#include <gtest/gtest.h>
#include <iostream>
#include <iomanip>
#include <algorithm>
#include <vector>
#include <string>
#include <map>

using namespace std;



/* https://leetcode.com/problems/neighboring-bitwise-xor/description/?envType=daily-question&envId=2025-01-17
 * @lc app=leetcode id=2683 lang=cpp
 *
 * [2683] Neighboring Bitwise XOR

A 0-indexed array derived with length n is derived by computing the bitwise XOR of adjacent values in a binary array original of length n.
Specifically, for each index i in the range [0, n - 1]:
- If i = n - 1, then derived[i] = original[i] XOR original[0].
- Otherwise, derived[i] = original[i] XOR original[i + 1].
Given an array derived, your task is to determine whether there exists a valid binary array original that could have formed derived.
Return true if such an array exists or false otherwise.
- A binary array is an array containing only 0's and 1's

길이가 n인 0-인덱스 배열 derived는 길이가 n인 이진 배열 original의 인접한 값들의 비트 XOR 연산으로 계산됩니다.
구체적으로, [0, n - 1] 범위의 각 인덱스 i에 대해:
- i = n - 1인 경우, derived[i] = original[i] XOR original[0]입니다.
- 그 외의 경우, derived[i] = original[i] XOR original[i + 1]입니다.
배열 derived가 주어졌을 때, derived를 형성할 수 있는 유효한 이진 배열 original이 존재하는지 판단하는 것이 과제입니다.
그러한 배열이 존재하면 true를, 그렇지 않으면 false를 반환하세요.
- 이진 배열은 0과 1로만 이루어진 배열입니다

Constraints:
- n == derived.length
- 1 <= n <= 10**5
- The values in derived are either 0's or 1's
 */

// @lc code=start
class Solution {
public:
    bool doesValidArrayExist(vector<int>& derived) {
        int result = 0;
        for (int n : derived) {
            result ^= n;
        }
        return result == 0;
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
    vector<int> derived = {1,1,0};
    EXPECT_EQ(this->s.doesValidArrayExist(derived), true);
}
TEST_F(CLASS_NAME, __LINE__)
{
    vector<int> derived = {1,1};
    EXPECT_EQ(this->s.doesValidArrayExist(derived), true);
}
TEST_F(CLASS_NAME, __LINE__)
{
    vector<int> derived = {1,0};
    EXPECT_EQ(this->s.doesValidArrayExist(derived), false);
}



int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}