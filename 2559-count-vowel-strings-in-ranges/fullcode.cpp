#include <gtest/gtest.h>
#include <iostream>
#include <iomanip>
#include <algorithm>
#include <vector>
#include <string>
#include <map>

using namespace std;


/*
https://leetcode.com/problems/count-vowel-strings-in-ranges/description/?envType=daily-question&envId=2025-01-02
2559. Count Vowel Strings in Ranges

You are given a 0-indexed array of strings words and a 2D array of integers queries.
Each query queries[i] = [li, ri] asks us to find the number of strings present in the range li to ri (both inclusive) of words that start and end with a vowel.
Return an array ans of size queries.length, where ans[i] is the answer to the ith query.
Note that the vowel letters are 'a', 'e', 'i', 'o', and 'u'.

0부터 시작하는 인덱스를 가진 문자열 배열 words와 2차원 정수 배열 queries가 주어집니다.
각 쿼리 queries[i] = [li, ri]는 words 배열의 li부터 ri까지의 범위(둘 다 포함)에서 모음으로 시작하고 모음으로 끝나는 문자열의 개수를 찾도록 요청합니다.
queries.length 크기의 배열 ans를 반환하세요. 여기서 ans[i]는 i번째 쿼리에 대한 답입니다.
참고로 모음은 'a', 'e', 'i', 'o', 'u' 입니다.

Example 1:
Input: words = ["aba","bcb","ece","aa","e"], queries = [[0,2],[1,4],[1,1]]
Output: [2,3,0]
Explanation: The strings starting and ending with a vowel are "aba", "ece", "aa" and "e".
The answer to the query [0,2] is 2 (strings "aba" and "ece").
to query [1,4] is 3 (strings "ece", "aa", "e").
to query [1,1] is 0.
We return [2,3,0].
Example 2:

Input: words = ["a","e","i"], queries = [[0,2],[0,1],[2,2]]
Output: [3,2,1]
Explanation: Every string satisfies the conditions, so we return [3,2,1].

Constraints:
1 <= words.length <= 10**5
1 <= words[i].length <= 40
words[i] consists only of lowercase English letters.
sum(words[i].length) <= 3 * 10**5
1 <= queries.length <= 10**5
0 <= li <= ri < words.length
 */

class Solution {
public:
    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {

        bool alphabet[26] = {false,};
        alphabet['a' - 'a'] = true;
        alphabet['e' - 'a'] = true;
        alphabet['i' - 'a'] = true;
        alphabet['o' - 'a'] = true;
        alphabet['u' - 'a'] = true;

        vector<int> prefix_sum(words.size() + 1, 0);
        prefix_sum[0] = alphabet[words[0][0] - 'a'] && alphabet[words[0][words[0].length() - 1] - 'a'];
        for (int i = 1; i < words.size(); i++) {
            prefix_sum[i] = prefix_sum[i - 1];
            prefix_sum[i] += (alphabet[words[i][0] - 'a'] && alphabet[words[i][words[i].length() - 1] - 'a']);
        }

        vector<int> answer(queries.size(), 0);

        for (int i = 0; i < queries.size(); i++) {
            int li = queries[i][0];
            int ri = queries[i][1];
            if (li == 0) {
                answer[i] = prefix_sum[ri];
            } else {
                answer[i] = prefix_sum[ri] - prefix_sum[li - 1];
            }
        }
        return answer;
    }

    // 역시 뭔가 time limit exceeded가 나올것 같았는데... 역시나였군.
    vector<int> vowelStrings_time_limit_exceeded(vector<string>& words, vector<vector<int>>& queries) {

        bool alphabet[26] = {false,};
        alphabet['a' - 'a'] = true;
        alphabet['e' - 'a'] = true;
        alphabet['i' - 'a'] = true;
        alphabet['o' - 'a'] = true;
        alphabet['u' - 'a'] = true;

        // stat: 0 - false, 1 - true, -1 - not visited
        vector<int> cache(words.size(), -1);
        vector<int> answer;

        for (vector<int> query : queries) {
            int li = query[0];
            int ri = query[1];
            int count = 0;
            for (int i = li; i <= ri; i++) {
                if (cache[i] == 1) {
                    count++;
                    continue;
                }
                if (cache[i] == 0) {
                    continue;
                }
                cache[i] = alphabet[words[i][0] - 'a'] && alphabet[words[i][words[i].length() - 1] - 'a'];
                count += cache[i];
            }
            answer.push_back(count);
        }
        return answer;
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
    vector<string> words = {"aba","bcb","ece","aa","e"};
    vector<vector<int>> queries = {{0,2},{1,4},{1,1}};
    vector<int> result = s.vowelStrings(words, queries);
    vector<int> expected = {2,3,0};
    EXPECT_EQ(result, expected);
}

TEST_F(CLASS_NAME, __LINE__)
{
    vector<string> words = {"a","e","i"};
    vector<vector<int>> queries = {{0,2},{0,1},{2,2}};
    vector<int> result = s.vowelStrings(words, queries);
    vector<int> expected = {3,2,1};
    EXPECT_EQ(result, expected);
}



int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}