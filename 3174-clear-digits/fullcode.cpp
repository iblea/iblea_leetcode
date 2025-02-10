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

using namespace std;


/* https://leetcode.com/problems/clear-digits/?envType=daily-question&envId=2025-02-10
 * @lc app=leetcode id=3174 lang=cpp
 * [3174] Clear Digits

You are given a string s.
Your task is to remove all digits by doing this operation repeatedly:
Delete the first digit and the closest non-digit character to its left.
Return the resulting string after removing all digits.

문자열 s가 주어집니다.
다음 작업을 반복하여 모든 숫자를 제거하는 것이 당신의 임무입니다:
첫 번째 숫자와 그 숫자의 왼쪽에서 가장 가까운 숫자가 아닌 문자를 삭제합니다.
모든 숫자를 제거한 후의 결과 문자열을 반환하세요.

Constraints:
1 <= s.length <= 100
s consists only of lowercase English letters and digits.
The input is generated such that it is possible to delete all digits.
s는 영어 소문자와 숫자로만 구성됩니다.
입력은 모든 숫자를 삭제할 수 있도록 생성됩니다.
 */

// @lc code=start
class Solution {
public:
    string clearDigits(string s) {

        vector<int> strv;
        vector<int> numv;

        for (int i = 0; i < s.length(); i++) {
            if (isdigit(s[i])) {
                numv.push_back(i);
            } else {
                strv.push_back(i);
            }
        }

        for (int i = 0; i < numv.size(); i++) {
            int num = numv[i];
            s[num] = '?';
            // upper_bound는 같거나 큰 값을 찾는다. 따라서 찾은 값의 이전 값을 찾아 삭제한다.
            auto it = upper_bound(strv.begin(), strv.end(), num);
            if (it != strv.begin()) {
                --it;
                s[*(it)] = '?';
                strv.erase(it);
            }
        }
        s.erase(remove(s.begin(), s.end(), '?'), s.end());
        return s;
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
	// Input: s = "abc"
	// Output: "abc"
	// Explanation:
	// There is no digit in the string.

	EXPECT_EQ(this->s.clearDigits("abc"), "abc");
}

TEST_F(CLASS_NAME, __LINE__)
{
	// Example 2:
	// Input: s = "cb34"
	// Output: ""
	// Explanation:
	// First, we apply the operation on s[2], and s becomes "c4".
	// Then we apply the operation on s[1], and s becomes "".

	EXPECT_EQ(this->s.clearDigits("cb34"), "");
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}