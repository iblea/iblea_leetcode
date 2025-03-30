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



/* https://leetcode.com/problems/partition-labels/?envType=daily-question&envId=2025-03-30
 * @lc app=leetcode id=763 lang=cpp
 * [763] Partition Labels

You are given a string s. We want to partition the string into as many parts as possible so that each letter appears in at most one part. For example, the string "ababcc" can be partitioned into ["abab", "cc"], but partitions such as ["aba", "bcc"] or ["ab", "ab", "cc"] are invalid.
Note that the partition is done so that after concatenating all the parts in order, the resultant string should be s.
Return a list of integers representing the size of these parts.

문자열 s가 주어집니다. 각 문자가 최대 하나의 파트에만 나타나도록 문자열을 가능한 많은 파트로 분할하려고 합니다. 예를 들어, 문자열 "ababcc"는 ["abab", "cc"]로 분할할 수 있지만, ["aba", "bcc"]나 ["ab", "ab", "cc"]와 같은 분할은 유효하지 않습니다.
분할은 모든 파트를 순서대로 연결했을 때 결과 문자열이 s가 되도록 수행됩니다.
이러한 파트들의 크기를 나타내는 정수 리스트를 반환하세요.

Constraints:
1 <= s.length <= 500
s consists of lowercase English letters.
 */

// @lc code=start
class Solution {
public:
    vector<int> partitionLabels(string s) {
        int n = s.length();
        vector<int> result;
        map<char, int> last_index;
        for (int i = 0; i < n; i++) {
            last_index[s[i]] = i;
        }

        int count = 0;
        int max_index = 0;
        for (int i = 0; i < n; i++) {
            max_index = max(max_index, last_index[s[i]]);
            count++;
            if (max_index == i) {
                result.push_back(count);
                count = 0;
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
    // Input: s = "ababcbacadefegdehijhklij"
    // Output: [9,7,8]
    // Explanation:
    // The partition is "ababcbaca", "defegde", "hijhklij".
    // This is a partition so that each letter appears in at most one part.
    // A partition like "ababcbacadefegde", "hijhklij" is incorrect, because it splits s into less parts.

    vector<int> expected = {9,7,8};
	EXPECT_EQ(this->s.partitionLabels("ababcbacadefegdehijhklij"), expected);
}

TEST_F(CLASS_NAME, __LINE__)
{
    // Example 2:
    // Input: s = "eccbbbbdec"
    // Output: [10]

    vector<int> expected = {10};
	EXPECT_EQ(this->s.partitionLabels("eccbbbbdec"), expected);
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
