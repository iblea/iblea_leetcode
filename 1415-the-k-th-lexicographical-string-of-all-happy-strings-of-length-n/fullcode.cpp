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



/* https://leetcode.com/problems/the-k-th-lexicographical-string-of-all-happy-strings-of-length-n/?envType=daily-question&envId=2025-02-19
 * @lc app=leetcode id=1415 lang=cpp
 * [1415] The k-th Lexicographical String of All Happy Strings of Length n

A happy string is a string that:
consists only of letters of the set ['a', 'b', 'c'].
s[i] != s[i + 1] for all values of i from 1 to s.length - 1 (string is 1-indexed).
For example, strings "abc", "ac", "b" and "abcbabcbcb" are all happy strings and strings "aa", "baa" and "ababbc" are not happy strings.
Given two integers n and k, consider a list of all happy strings of length n sorted in lexicographical order.
Return the kth string of this list or return an empty string if there are less than k happy strings of length n.

해피 문자열은 다음과 같은 문자열입니다:
문자 집합 ['a', 'b', 'c']의 문자들로만 구성됩니다.
s[i] != s[i + 1]이 i=1부터 s.length - 1까지의 모든 값에 대해 성립합니다 (문자열은 1부터 인덱싱됨).
예를 들어, "abc", "ac", "b", "abcbabcbcb"는 모두 해피 문자열이고 "aa", "baa", "ababbc"는 해피 문자열이 아닙니다.
두 정수 n과 k가 주어졌을 때, 길이가 n인 모든 해피 문자열을 사전순으로 정렬한 리스트를 고려합니다.
이 리스트의 k번째 문자열을 반환하거나, 길이가 n인 해피 문자열이 k개보다 적을 경우 빈 문자열을 반환합니다.


Constraints:
1 <= n <= 10
1 <= k <= 100

 */

// @lc code=start
class Solution {
public:
    string getHappyString(int n, int k) {

        // 총 문자열 개수가 k개보다 적을 경우 빈 문자열 반환
        // k는 3*2^(n-1) 보다 클 수 없다.
        if (k > 3 * (1 << (n - 1))) {
            return "";
        }

        // 1
        // a b c
        // 2
        // ab ac ba bc ca cb
        // 3
        // aba abc aca acb bab bac bca bcb cab cac cba cbc
        // 4
        // abab abac abca abcb acab acac acba acbc ... 24개

        // 즉, n이 1개 늘어날 때 마다 2배씩 증가한다.
        // 즉, 3*2^(n-1) 개의 문자열이 생성된다.


        // n=3, k=5 -> bab(5), ba(3), b(2)
        // n=3, k=6 -> bac(6), ba(3), b(2)
        // n=3, k=9 -> cab(9), ca(5), c(3)
        // n=4, k=7 -> acba(7) acb(4), ac(2), a(1)

        int divide_count = n;
        stack<int> st;
        string result = "";
        int group = (k - 1) / (1 << (n - 1));
        result += ('a' + group);
        k = k - group * (1 << (n - 1));
        int curr = k;
        while(divide_count > 1) {
            if (curr == 1) {
                // std::cout << "tmp: " << 1 << std::endl;
                st.push(1);
                divide_count--;
                continue;
            }
            int tmp = curr % 2;
            st.push(tmp);
            // std::cout << "tmp: " << tmp << std::endl;
            if (tmp == 0) {
                curr /= 2;
            } else {
                curr = (curr / 2) + 1;
            }
            divide_count--;
        }
        while(!st.empty()) {
            int tmp = st.top();
            st.pop();
            if (tmp == 1) {
                if (result.back() == 'a') {
                    result += 'b';
                } else {
                    result += 'a';
                }
            } else {
                if (result.back() == 'c') {
                    result += 'b';
                } else {
                    result += 'c';
                }
            }
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
    // Input: n = 1, k = 3
    // Output: "c"
    // Explanation: The list ["a", "b", "c"] contains all happy strings of length 1. The third string is "c".

	EXPECT_EQ(this->s.getHappyString(1, 3), "c");
}

TEST_F(CLASS_NAME, __LINE__)
{
    // Example 2:
    // Input: n = 1, k = 4
    // Output: ""
    // Explanation: There are only 3 happy strings of length 1.

	EXPECT_EQ(this->s.getHappyString(1, 4), "");
}

TEST_F(CLASS_NAME, __LINE__)
{
    // Example 3:
    // Input: n = 3, k = 9
    // Output: "cab"
    // Explanation: There are 12 different happy string of length 3 ["aba", "abc", "aca", "acb", "bab", "bac", "bca", "bcb", "cab", "cac", "cba", "cbc"]. You will find the 9th string = "cab"

	EXPECT_EQ(this->s.getHappyString(3, 9), "cab");
}

TEST_F(CLASS_NAME, __LINE__)
{
    // 100 -> 50(0) -> 25(0) -> 13(1) -> 7(1) -> 4(0) -> 2(0) -> 1(0)
	EXPECT_EQ(this->s.getHappyString(10, 100), "abacbabacb");
}




int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
