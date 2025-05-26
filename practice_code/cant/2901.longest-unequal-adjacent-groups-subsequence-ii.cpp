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


/*
 * @lc app=leetcode id=2901 lang=cpp
 * [2901] Longest Unequal Adjacent Groups Subsequence II

You are given a string array words, and an array groups, both arrays having length n.
The hamming distance between two strings of equal length is the number of positions at which the corresponding characters are different.
You need to select the longest subsequence from an array of indices [0, 1, ..., n - 1], such that for the subsequence denoted as [i0, i1, ..., ik-1] having length k, the following holds:
For adjacent indices in the subsequence, their corresponding groups are unequal, i.e., groups[ij] != groups[ij+1], for each j where 0 < j + 1 < k.
words[ij] and words[ij+1] are equal in length, and the hamming distance between them is 1, where 0 < j + 1 < k, for all indices in the subsequence.
Return a string array containing the words corresponding to the indices (in order) in the selected subsequence. If there are multiple answers, return any of them.
Note: strings in words may be unequal in length.

문자열 배열 words와 정수 배열 groups가 주어집니다. 두 배열의 길이는 n입니다.
동일한 길이의 두 문자열의 해밍 거리란, 각 위치에서 서로 다른 문자의 개수를 의미합니다.
[0, 1, ..., n - 1]의 인덱스 배열에서 가장 긴 부분수열을 선택해야 하며, 선택된 부분수열 [i0, i1, ..., ik-1] (길이 k)에 대해 다음 조건을 만족해야 합니다:
- 부분수열에서 인접한 인덱스의 그룹이 서로 달라야 합니다. 즉, 모든 j (0 < j + 1 < k)에 대해 groups[ij] != groups[ij+1]이어야 합니다.
- words[ij]와 words[ij+1]의 길이가 같고, 해밍 거리가 1이어야 합니다. (모든 인접한 쌍에 대해)
선택된 인덱스에 해당하는 words의 문자열을 순서대로 반환하세요. 답이 여러 개라면 아무거나 반환해도 됩니다.
참고: words의 문자열 길이는 서로 다를 수 있습니다.

Constraints:
- 1 <= n == words.length == groups.length <= 1000
- 1 <= words[i].length <= 10
- 1 <= groups[i] <= n
- words는 서로 다른 문자열로 이루어져 있습니다.
- words[i]는 소문자 영어 알파벳으로만 이루어져 있습니다.
*/

// @lc code=start
class Solution {
private:
    int hammingDistance(const string& a, const string& b) {
        if (a.size() != b.size()) {
            return -1;
        }
        int distance = 0;
        for (int i = 0; i < a.size(); ++i) {
            if (a[i] != b[i]) {
                ++distance;
            }
        }
        return distance;
    }
public:
    vector<string> getWordsInLongestSubsequence(vector<string>& words, vector<int>& groups) {
        int n = words.size();
        vector<int>dp(n, 1);
        vector<int> prev(n, -1);

        // 최장 증가 부분수열 변형
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < i; ++j) {
                // 조건을 만족하는 경우 길이 같고, 그룹 다르고, 해밍 거리 1
                if (groups[i] != groups[j] && hammingDistance(words[i], words[j]) == 1) {
                    if (dp[i] < dp[j] + 1) {
                        dp[i] = dp[j] + 1;
                        prev[i] = j; // 이전 인덱스 저장
                    }
                }
            }
        }

        int end = 0;
        for (int i = 1; i < n; ++i) {
            if (dp[i] > dp[end]) {
                end = i;
            }
        }
        vector<string> result;
        while (end >= 0) {
            result.push_back(words[end]);
            end = prev[end];
        }
        reverse(result.begin(), result.end());
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
    // Input: words = ["bab","dab","cab"], groups = [1,2,2]
    // Output: ["bab","cab"]
    // Explanation: A subsequence that can be selected is [0,2].
    // groups[0] != groups[2]
    // words[0].length == words[2].length, and the hamming distance between them is 1.
    // So, a valid answer is [words[0],words[2]] = ["bab","cab"].
    // Another subsequence that can be selected is [0,1].
    // groups[0] != groups[1]
    // words[0].length == words[1].length, and the hamming distance between them is 1.
    // So, another valid answer is [words[0],words[1]] = ["bab","dab"].
    // It can be shown that the length of the longest subsequence of indices that satisfies the conditions is 2.

    // 설명: 선택할 수 있는 부분수열은 [0,2]입니다.
    // groups[0] != groups[2]
    // words[0].length == words[2].length이고, 두 문자열의 해밍 거리는 1입니다.
    // 따라서, 유효한 답은 [words[0], words[2]] = ["bab", "cab"]입니다.
    // 또 다른 선택 가능한 부분수열은 [0,1]입니다.
    // groups[0] != groups[1]
    // words[0].length == words[1].length이고, 해밍 거리가 1입니다.
    // 따라서, 또 다른 유효한 답은 [words[0], words[1]] = ["bab", "dab"]입니다.
    // 조건을 만족하는 가장 긴 부분수열의 길이는 2임을 알 수 있습니다.


    vector<string> words = {"bab", "dab", "cab"};
    vector<int> groups = {1, 2, 2};
    vector<vector<string>> expects = {{"bab", "cab"}, {"bab", "dab"}};
    bool result = false;

    vector<string> answer = this->s.getWordsInLongestSubsequence(words, groups);
    for (auto& expect : expects) {
        if (answer == expect) {
            result = true;
            break;
        }
    }
	// EXPECT_EQ(this->s.getWordsInLongestSubsequence(words, groups), expected);
    EXPECT_EQ(result, true);
}

TEST_F(CLASS_NAME, __LINE__)
{
    // Example 2:
    // Input: words = ["a","b","c","d"], groups = [1,2,3,4]
    // Output: ["a","b","c","d"]
    // Explanation: We can select the subsequence [0,1,2,3].
    // It satisfies both conditions.
    // Hence, the answer is [words[0],words[1],words[2],words[3]] = ["a","b","c","d"].
    // It has the longest length among all subsequences of indices that satisfy the conditions.
    // Hence, it is the only answer.
    // 설명: 부분수열 [0,1,2,3]을 선택할 수 있습니다.
    // 두 조건을 모두 만족합니다.
    // 따라서 답은 [words[0], words[1], words[2], words[3]] = ["a","b","c","d"]입니다.
    // 조건을 만족하는 부분수열 중 가장 긴 길이를 가집니다.
    // 따라서 유일한 답입니다.

    vector<string> words = {"a", "b", "c", "d"};
    vector<int> groups = {1, 2, 3, 4};
    vector<string> expected = {"a", "b", "c", "d"};
    EXPECT_EQ(this->s.getWordsInLongestSubsequence(words, groups), expected);
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
