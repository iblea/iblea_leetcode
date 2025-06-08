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



/* https://leetcode.com/problems/lexicographical-numbers
 * @lc app=leetcode id=386 lang=cpp
 * [386] Lexicographical Numbers

Given an integer n, return all the numbers in the range [1, n] sorted in lexicographical order.
You must write an algorithm that runs in O(n) time and uses O(1) extra space.

정수 n이 주어졌을 때, [1, n] 범위의 모든 숫자를 사전식 순서로 정렬하여 반환하세요.
O(n) 시간에 실행되고 O(1) 추가 공간을 사용하는 알고리즘을 작성해야 합니다.

Constraints:
1 <= n <= (5 * 10**4)
 */

// @lc code=start
class Solution {
public:
    vector<int> lexicalOrder(int n) {
        vector<int> result(n);
        int current = 1;

        for (int i = 0; i < n; i++) {
            result[i] = current;
            // 1, 10, 100, 1000, 1001, 1002 ... 1009, 101, 1010, 1011 ...
            if (current * 10 <= n) {
                current *= 10;
                continue;
            }
            // n = 13, { 1, 10, 11, 12, 13, 14? , 2, 3 ... }
            while (current % 10 == 9 || current >= n) {
                current /= 10;
            }
            current++;
        }
        return result;
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
    // Input: n = 13
    // Output: [1,10,11,12,13,2,3,4,5,6,7,8,9]

    vector<int> expected = {1,10,11,12,13,2,3,4,5,6,7,8,9};
	EXPECT_EQ(this->s.lexicalOrder(13), expected);
}

TEST_F(CLASS_NAME, __LINE__)
{
    // Example 2:
    // Input: n = 2
    // Output: [1,2]

    vector<int> expected = {1,2};
	EXPECT_EQ(this->s.lexicalOrder(2), expected);
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
