#include <gtest/gtest.h>
#include <iostream>
#include <iomanip>
#include <algorithm>
#include <vector>
#include <string>
#include <map>

using namespace std;


/*
https://leetcode.com/problems/zigzag-conversion/description/

numRows = 2
ACE
BDF

numRows = 3, cycle=4 ABCDEFGHIJK -> AEIBDFHJCGK
A E I
BDFHJ
C G K

numRows = 4, cycle=6 ABCDEFGHIJKLMNOP -> AGMBFHLNCEIKDJOP
A  G  M
B FH LN
CE IK O
D  J  P

A   I   Q
B  HJ  PR
C G K O S
DF  LN  T
E   M   U

 */

class Solution {
public:

    string convert(string s, int numRows) {

        if (numRows == 1) return s;

        int n = s.size();
        int cycle = 2 * numRows - 2;
        string result;

        for (int i = 0; i < numRows; i++) {
            int sub_cycle = cycle - (i * 2);
            for (int j = 0; j + i < n; j += cycle) {
                result += s[j + i];
                // 첫 번째와마지막 행이 아니면 추가해야 함.
                if (i != 0 && i != numRows - 1) {
                    if (j + i + sub_cycle < n) {
                        result += s[j + i + sub_cycle];
                    }
                }
            }
        }
        return result;
    }
    string convert_answer(string s, int numRows) {
        if (numRows == 1) return s;

        int n = s.size();
        int cycle = 2 * numRows - 2;
        string result;

        for (int i = 0; i < numRows; i++) {
            for (int j = 0; j + i < n; j += cycle) {
                result += s[j + i];
                if (i != 0 && i != numRows - 1 && j + cycle - i < n) {
                    result += s[j + cycle - i];
                }
            }
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
	EXPECT_EQ(this->s.convert("PAYPALISHIRING", 3), "PAHNAPLSIIGYIR");
}

TEST_F(CLASS_NAME, __LINE__)
{
	EXPECT_EQ(this->s.convert("PAYPALISHIRING", 4), "PINALSIGYAHRPI");
}

TEST_F(CLASS_NAME, __LINE__)
{
	EXPECT_EQ(this->s.convert("A", 1), "A");
}

TEST_F(CLASS_NAME, __LINE__)
{
	EXPECT_EQ(this->s.convert("ABCDEF", 2), "ACEBDF");
}

TEST_F(CLASS_NAME, __LINE__)
{
	EXPECT_EQ(this->s.convert("ABCDEFGHIJK", 3), "AEIBDFHJCGK");
}




int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}