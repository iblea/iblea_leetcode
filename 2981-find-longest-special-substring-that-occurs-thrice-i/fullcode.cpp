#include <gtest/gtest.h>
#include <iostream>
#include <iomanip>
#include <algorithm>
#include <vector>
#include <string>
#include <map>

using namespace std;


/*
https://leetcode.com/problems/find-longest-special-substring-that-occurs-thrice-i

소문자 영어 문자들로 구성된 문자열 s가 주어집니다. 특별 문자열(special string)은 단 하나의 문자로만 이루어진 문자열을 의미합니다. 예를 들어, "abc"는 특별 문자열이 아니지만, "ddd", "zz", "f"는 특별 문자열입니다.

주어진 문자열 s에서 최소 3번 이상 등장하는 가장 긴 특별 부분 문자열의 길이를 찾아 반환해야 합니다.
만약 3번 이상 등장하는 특별 부분 문자열이 없다면 -1을 반환합니다.
여기서 부분 문자열(substring)은 문자열 내에서 연속된 문자들의 시퀀스를 의미합니다.

예시:

s = "aaa" -> 결과: 1 (문자 'a'가 3번 등장)
s = "aaaa" -> 결과: 2 ('aa'가 3번 등장)
s = "abcd" -> 결과: -1 (3번 이상 등장하는 특별 부분 문자열이 없음)

Constraints:
3 <= s.length <= 50
s consists of only lowercase English letters.
 */

class Solution {
public:
    int maximumLength(string s) {
        int n = s.size();
        int ago_answer = 0;
        int answer = 0;
        int end = 0;
        while (true) {
            for (int start = 0; start < n - end; start++) {
                string sub = "";
                char start_c = s[start];
                sub += start_c;
                int i_end = start + end + 1;
                for (int i = start + 1; i < i_end; i++) {
                    if (start_c != s[i]) {
                        sub = "";
                        break;
                    }
                    sub += s[i];
                }
                if (sub == "") {
                    continue;
                }
                int cnt = 0;
                for (int i = 0; i < n - end; i++) {
                    if (sub != s.substr(i, end + 1)) {
                        continue;
                    }

                    cnt++;
                    if (cnt >= 3) {
                        answer = end + 1;
                        break;
                    }
                }
                // 3번 이상 등장하는 특별 부분 문자열을 찾았다면 종료함.
                // 더 찾을 필요가 없음.
                if (ago_answer != answer) {
                    break;
                }
            }
            if (ago_answer == answer) {
                break;
            }
            ago_answer = answer;
            end++;
        }
        if (answer == 0) {
            return -1;
        }
        return answer;
    }

    int maximumLength1(string s) {
        int n = s.size(), max_len = -1;

        for (int len = 1; len <= n; ++len) {
            unordered_map<string, int> freq;

            for (int i = 0; i <= n - len; ++i) {
                string sub = s.substr(i, len);

                bool is_special = true;
                for (int j = 1; j < len; ++j) {
                    if (sub[j] != sub[0]) {
                        is_special = false;
                        break;
                    }
                }

                if (is_special) {
                    freq[sub]++;
                    if (freq[sub] >= 3)
                        max_len = max(max_len, len);
                }
            }
        }

        return max_len;
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
	EXPECT_EQ(this->s.maximumLength("aaa"), 1);
}

TEST_F(CLASS_NAME, __LINE__)
{
	EXPECT_EQ(this->s.maximumLength("aaaa"), 2);
}

TEST_F(CLASS_NAME, __LINE__)
{
	EXPECT_EQ(this->s.maximumLength("abcdef"), -1);
}

TEST_F(CLASS_NAME, __LINE__)
{
	EXPECT_EQ(this->s.maximumLength("abcaba"), 1);
}

TEST_F(CLASS_NAME, __LINE__)
{
	EXPECT_EQ(this->s.maximumLength("abababa"), 1);
}

TEST_F(CLASS_NAME, __LINE__)
{
	EXPECT_EQ(this->s.maximumLength("abcabcabc"), 1);
}

TEST_F(CLASS_NAME, __LINE__)
{
	EXPECT_EQ(this->s.maximumLength("aaaaaa"), 4);
}

TEST_F(CLASS_NAME, __LINE__)
{
	EXPECT_EQ(this->s.maximumLength("abaaaaaabaa"), 4);
}

TEST_F(CLASS_NAME, __LINE__)
{
	EXPECT_EQ(this->s.maximumLength("abaabaabaaa"), 2);
}

TEST_F(CLASS_NAME, __LINE__)
{
	EXPECT_EQ(this->s.maximumLength("cccacccc"), 3);
}

TEST_F(CLASS_NAME, __LINE__)
{
	EXPECT_EQ(this->s.maximumLength("cccerrrecdcdccedecdccccdd"), 3);
    // cccerrrecdcdccedecdccccddeeeddcdcddedccdceeedccecde
}

TEST_F(CLASS_NAME, __LINE__)
{
	EXPECT_EQ(this->s.maximumLength("cccerrrecdcdccedecdccccddeeeddcdcddedccdceeedccecde"), 3);
}





int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}