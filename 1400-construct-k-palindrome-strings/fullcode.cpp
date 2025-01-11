#include <gtest/gtest.h>
#include <iostream>
#include <iomanip>
#include <algorithm>
#include <vector>
#include <string>
#include <map>

using namespace std;


/*
https://leetcode.com/problems/construct-k-palindrome-strings/description/?envType=daily-question&envId=2025-01-11
 * @lc app=leetcode id=1400 lang=cpp
 *
 * [1400] Construct K Palindrome Strings
Given a string s and an integer k, return true if you can use all the characters in s to construct k palindrome strings or false otherwise.
문자열 s와 정수 k가 주어지면, s의 모든 문자를 사용하여 k개의 회문 문자열을 구성할 수 있으면 true를 반환하고, 그렇지 않으면 false를 반환합니다.
 */
// @lc code=start
class Solution {
public:
    bool canConstruct(string s, int k) {
        if (s.length() < k) return false;
        int alphabet[26] = {0,};

        for (char c : s) {
            alphabet[c - 'a']++;
        }
        int odd_count = 0;
        for (int i = 0; i < 26; i++) {
            if (alphabet[i] % 2 == 1) odd_count++;
        }
        // 1, 즉 홀수 개가 몇 개가 있는지가 중요하다.
        // 홀수 개가 k와 같거나 작을 경우 회문을 만들 수 있고,
        // 홀수 개가 k보다 많을 경우 회문을 만들 수 없다.
        return odd_count <= k;
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
	EXPECT_EQ(this->s.canConstruct("annabelle", 2), true);
}

TEST_F(CLASS_NAME, __LINE__)
{
	EXPECT_EQ(this->s.canConstruct("leetcode", 3), false);
}

TEST_F(CLASS_NAME, __LINE__)
{
	EXPECT_EQ(this->s.canConstruct("true", 4), true);
}



int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}