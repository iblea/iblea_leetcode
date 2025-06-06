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


/* https://leetcode.com/problems/lexicographically-smallest-equivalent-string/?envType=daily-question&envId=2025-06-05
 * @lc app=leetcode id=1061 lang=cpp
 * [1061] Lexicographically Smallest Equivalent String

You are given two strings of the same length s1 and s2 and a string baseStr.
We say s1[i] and s2[i] are equivalent characters.

For example, if s1 = "abc" and s2 = "cde", then we have 'a' == 'c', 'b' == 'd', and 'c' == 'e'.
Equivalent characters follow the usual rules of any equivalence relation:

Reflexivity: 'a' == 'a'.
Symmetry: 'a' == 'b' implies 'b' == 'a'.
Transitivity: 'a' == 'b' and 'b' == 'c' implies 'a' == 'c'.
For example, given the equivalency information from s1 = "abc" and s2 = "cde", "acd" and "aab" are equivalent strings of baseStr = "eed", and "aab" is the lexicographically smallest equivalent string of baseStr.

Return the lexicographically smallest equivalent string of baseStr by using the equivalency information from s1 and s2.

같은 길이의 두 문자열 s1과 s2, 그리고 문자열 baseStr이 주어집니다.
s1[i]와 s2[i]는 동등한 문자라고 합니다.

예를 들어, s1 = "abc"이고 s2 = "cde"라면, 'a' == 'c', 'b' == 'd', 'c' == 'e'입니다.
동등한 문자들은 일반적인 동치 관계의 규칙을 따릅니다:

반사성: 'a' == 'a'.
대칭성: 'a' == 'b'이면 'b' == 'a'입니다.
이행성: 'a' == 'b'이고 'b' == 'c'이면 'a' == 'c'입니다.
예를 들어, s1 = "abc"와 s2 = "cde"로부터 주어진 동등성 정보에서, "acd"와 "aab"는 baseStr = "eed"의 동등한 문자열이며, "aab"는 baseStr의 사전순으로 가장 작은 동등한 문자열입니다.

s1과 s2의 동등성 정보를 사용하여 baseStr의 사전순으로 가장 작은 동등한 문자열을 반환하세요.


Constraints:

1 <= s1.length, s2.length, baseStr <= 1000
s1.length == s2.length
s1, s2, and baseStr consist of lowercase English letters.
 */
// @lc code=start
#define ALPHABET_SIZE 26
class Solution {
private:
    int parent[ALPHABET_SIZE];

    int find(int x) {
        if (parent[x] != x) {
            parent[x] = find(parent[x]); // path compression
        }
        return parent[x];
    }

    void unionSet(int x, int y) {
        int rootX = find(x);
        int rootY = find(y);

        if (rootX != rootY) {
            // 더 작은 문자를 root로 만들기
            if (rootX < rootY) {
                parent[rootY] = rootX;
            } else {
                parent[rootX] = rootY;
            }
        }
    }

public:
    // union-find 알고리즘 이용하면 매우 쉽게 풀 수 있는 문제
    string smallestEquivalentString(string s1, string s2, string baseStr) {

        for (int i = 0; i < ALPHABET_SIZE; i++) {
            parent[i] = i;
        }

        for (int i = 0; i < s1.length(); i++) {
            int idx1 = s1[i] - 'a';
            int idx2 = s2[i] - 'a';
            unionSet(idx1, idx2);
        }

        string result = "";
        for (char c : baseStr) {
            int idx = c - 'a';
            int root = find(idx);
            result += (char)('a' + root);
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
    //
    // Input: s1 = "parker", s2 = "morris", baseStr = "parser"
    // Output: "makkek"
    // Explanation: Based on the equivalency information in s1 and s2, we can group their characters as [m,p], [a,o], [k,r,s], [e,i].
    // The characters in each group are equivalent and sorted in lexicographical order.
    // So the answer is "makkek".

    EXPECT_EQ(this->s.smallestEquivalentString("parker", "morris", "parser"), "makkek");
}

TEST_F(CLASS_NAME, __LINE__)
{
    // Example 2:
    //
    // Input: s1 = "hello", s2 = "world", baseStr = "hold"
    // Output: "hdld"
    // Explanation: Based on the equivalency information in s1 and s2, we can group their characters as [h,w], [d,e,o], [l,r].
    // So only the second letter 'o' in baseStr is changed to 'd', the answer is "hdld".

    EXPECT_EQ(this->s.smallestEquivalentString("hello", "world", "hold"), "hdld");
}

TEST_F(CLASS_NAME, __LINE__)
{
    // Example 3:
    //
    // Input: s1 = "leetcode", s2 = "programs", baseStr = "sourcecode"
    // Output: "aauaaaaada"
    // Explanation: We group the equivalent characters in s1 and s2 as [a,o,e,r,s,c], [l,p], [g,t] and [d,m], thus all letters in baseStr except 'u' and 'd' are transformed to 'a', the answer is "aauaaaaada".

    EXPECT_EQ(this->s.smallestEquivalentString("leetcode", "programs", "sourcecode"), "aauaaaaada");
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
