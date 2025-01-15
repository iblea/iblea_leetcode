#include <gtest/gtest.h>
#include <iostream>
#include <iomanip>
#include <algorithm>
#include <vector>
#include <string>
#include <map>

using namespace std;



/*
https://leetcode.com/problems/minimize-xor/description/?envType=daily-question&envId=2025-01-15
 * @lc app=leetcode id=2429 lang=cpp
 * [2429] Minimize XOR

Given two positive integers num1 and num2, find the positive integer x such that:
- x has the same number of set bits as num2, and
- The value x XOR num1 is minimal.
Note that XOR is the bitwise XOR operation.
Return the integer x. The test cases are generated such that x is uniquely determined.
The number of set bits of an integer is the number of 1's in its binary representation.

두 개의 양의 정수 num1과 num2가 주어졌을 때, 다음 조건을 만족하는 양의 정수 x를 찾으시오:
- x는 num2와 동일한 수의 설정된 비트를 가지고 있어야 합니다.
- x XOR num1의 값이 최소가 되어야 합니다.
XOR은 비트 단위의 XOR 연산임을 유의하십시오.
정수 x를 반환하십시오. 테스트 케이스는 x가 고유하게 결정되도록 생성됩니다.
정수의 설정된 비트 수는 이진 표현에서 1의 수입니다.

XOR 0 0 -> 0, 0 1 -> 1, 1 0 -> 1, 1 1 -> 0

Example 1:
Input: num1 = 3, num2 = 5
Output: 3
Explanation:
The binary representations of num1 and num2 are 0011 and 0101, respectively.
The integer 3 has the same number of set bits as num2, and the value 3 XOR 3 = 0 is minimal.
// 0011
// 0101

Example 2:
Input: num1 = 1, num2 = 12
Output: 3
Explanation:
The binary representations of num1 and num2 are 0001 and 1100, respectively.
The integer 3 has the same number of set bits as num2, and the value 3 XOR 1 = 2 is minimal.
// 0001
// 1100

Constraints:
1 <= num1, num2 <= 10**9
 */

// @lc code=start
class Solution {
public:

    string toBinary(int num) {
        string binary = "";
        while (num > 0) {
            binary = (num % 2 == 0 ? "0" : "1") + binary;
            num >>= 1;
        }
        return binary;
    }

    int minimizeXor(int num1, int num2) {
        string num1_binary = toBinary(num1);
        string num2_binary = toBinary(num2);

        int bitcount = 0;
        for (int i = 0; i < num2_binary.size(); i++) {
            if (num2_binary[i] == '1') {
                bitcount++;
            }
        }
        string result_str(num1_binary.size(), '0');
        for (int i = 0; i < num1_binary.size(); i++) {
            if (bitcount == 0) {
                break;
            }
            // 이걸 헷갈렸다. num1의 1 비트를 찾아야 한다.
            if (num1_binary[i] == '1') {
                result_str[i] = '1';
                bitcount--;
            }
        }
        std::cout << "CONSOLE | " << "num1_binary : " << num1_binary << endl;
        cout << "CONSOLE | " << "result_str : " << result_str << endl;
        for (int i = result_str.size() - 1; i >= 0; i--) {
            if (bitcount == 0) {
                break;
            }
            if (result_str[i] == '0') {
                result_str[i] = '1';
                bitcount--;
            }
        }
        if (bitcount > 0) {
            result_str = string(bitcount, '1') + result_str;
        }
        return stoi(result_str, nullptr, 2);
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
	EXPECT_EQ(this->s.minimizeXor(3, 5), 3);
}
TEST_F(CLASS_NAME, __LINE__)
{
	EXPECT_EQ(this->s.minimizeXor(1, 12), 3);
}
TEST_F(CLASS_NAME, __LINE__)
{
	EXPECT_EQ(this->s.minimizeXor(15, 31), 31);
}
TEST_F(CLASS_NAME, __LINE__)
{
    // 11001
    // 1001000
    // 11000
	EXPECT_EQ(this->s.minimizeXor(25, 72), 24);
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}