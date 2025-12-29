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
#include <unordered_set>

using namespace std;



/* https://leetcode.com/problems/pyramid-transition-matrix?envType=daily-question&envId=2025-12-29
 * @lc app=leetcode id=756 lang=cpp
 * [756] Pyramid Transition Matrix

You are stacking blocks to form a pyramid. Each block has a color, which is represented by a single letter. Each row of blocks contains one less block than the row beneath it and is centered on top.
To make the pyramid aesthetically pleasing, there are only specific triangular patterns that are allowed. A triangular pattern consists of a single block stacked on top of two blocks. The patterns are given as a list of three-letter strings allowed, where the first two characters of a pattern represent the left and right bottom blocks respectively, and the third character is the top block.
For example, "ABC" represents a triangular pattern with a 'C' block stacked on top of an 'A' (left) and 'B' (right) block. Note that this is different from "BAC" where 'B' is on the left bottom and 'A' is on the right bottom.
You start with a bottom row of blocks bottom, given as a single string, that you must use as the base of the pyramid.
Given bottom and allowed, return true if you can build the pyramid all the way to the top such that every triangular pattern in the pyramid is in allowed, or false otherwise.

블록을 쌓아 피라미드를 만들고 있습니다. 각 블록에는 단일 문자로 표현되는 색상이 있습니다. 각 행의 블록은 아래 행보다 하나 적은 블록을 포함하며 위에 중앙 정렬됩니다.
피라미드를 미학적으로 보기 좋게 만들기 위해, 허용되는 특정 삼각형 패턴만 있습니다. 삼각형 패턴은 두 블록 위에 쌓인 단일 블록으로 구성됩니다. 패턴은 세 글자 문자열 목록 allowed로 주어지며, 패턴의 처음 두 문자는 각각 왼쪽과 오른쪽 하단 블록을 나타내고, 세 번째 문자는 상단 블록입니다.
예를 들어, "ABC"는 'A'(왼쪽)와 'B'(오른쪽) 블록 위에 'C' 블록이 쌓인 삼각형 패턴을 나타냅니다. 이것은 'B'가 왼쪽 하단에 있고 'A'가 오른쪽 하단에 있는 "BAC"와는 다릅니다.
피라미드의 밑줄로 사용해야 하는 단일 문자열로 주어진 하단 행 블록 bottom으로 시작합니다.
bottom과 allowed가 주어졌을 때, 피라미드의 모든 삼각형 패턴이 allowed에 있도록 피라미드를 맨 위까지 만들 수 있으면 true를 반환하고, 그렇지 않으면 false를 반환합니다.

Constraints:
2 <= bottom.length <= 6
0 <= allowed.length <= 216
allowed[i].length == 3
The letters in all input strings are from the set {'A', 'B', 'C', 'D', 'E', 'F'}.
All the values of allowed are unique.
 */
// @lc code=start
class Solution {
public:
    map<string, vector<char>> tops;  // "AB" → ['C', 'D']
    unordered_set<string> failed;    // 메모이제이션: 실패한 층 기록

    bool pyramidTransition(string bottom, vector<string>& allowed) {
        // allowed: list->map 형태로 변환해서 탐색 시간 단축
        for (const string& s : allowed) {
            string key = s.substr(0, 2);
            tops[key].push_back(s[2]);
        }

        return solve(bottom);
    }

    bool solve(string& cur) {
        if (cur.size() == 1) return true;

        // 이미 실패한 층이면 바로 false
        if (failed.count(cur)) return false;

        string next = "";
        if (buildNext(cur, next, 0)) return true;

        // 실패 기록
        failed.insert(cur);
        return false;
    }

    bool buildNext(string& cur, string& next, int pos) {
        // 한 층 완성 -> 그 층으로 다시 solve
        if (pos == cur.size() - 1) {
            return solve(next);
        }

        string key = cur.substr(pos, 2);
        if (tops.find(key) == tops.end()) return false;

        for (char c : tops[key]) {
            next.push_back(c);
            if (buildNext(cur, next, pos + 1)) return true;
            next.pop_back();  // backtrack
        }

        return false;
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
    // Input: bottom = "BCD", allowed = ["BCC","CDE","CEA","FFF"]
    // Output: true
    // Explanation: The allowed triangular patterns are shown on the right.
    // Starting from the bottom (level 3), we can build "CE" on level 2 and then build "A" on level 1.
    // There are three triangular patterns in the pyramid, which are "BCC", "CDE", and "CEA". All are allowed.
    // 설명: 허용된 삼각형 패턴은 오른쪽에 표시되어 있습니다.
    // 맨 아래(레벨 3)에서 시작하여, 레벨 2에서 "CE"를 만들고, 그 다음 레벨 1에서 "A"를 만들 수 있습니다.
    // 피라미드에는 세 개의 삼각형 패턴이 있으며, "BCC", "CDE", "CEA"입니다. 모두 허용됩니다.

    string bottom = "BCD";
    vector<string> allowed = {"BCC","CDE","CEA","FFF"};
    EXPECT_EQ(this->s.pyramidTransition(bottom, allowed), true);
}

TEST_F(CLASS_NAME, __LINE__)
{
    // Example 2:
    // Input: bottom = "AAAA", allowed = ["AAB","AAC","BCD","BBE","DEF"]
    // Output: false
    // Explanation: The allowed triangular patterns are shown on the right.
    // Starting from the bottom (level 4), there are multiple ways to build level 3, but trying all the possibilites, you will get always stuck before building level 1.
    // 설명: 허용된 삼각형 패턴들이 오른쪽에 표시되어 있습니다.
    // 맨 아래(레벨 4)에서 시작하여 레벨 3을 만드는 방법은 여러 가지가 있지만, 모든 가능성을 시도해 보면 레벨 1을 만들기 전에 항상 막히게 됩니다.

    string bottom = "AAAA";
    vector<string> allowed = { "AAB","AAC","BCD","BBE","DEF" };
    EXPECT_EQ(this->s.pyramidTransition(bottom, allowed), false);
}

TEST_F(CLASS_NAME, __LINE__)
{
    string bottom = "BCDDA";
    vector<string> allowed = { "DBD","BCC","CDD","DAD","DDA","AAC","CCA","BCD" };
	bool res = this->s.pyramidTransition(bottom, allowed);
    EXPECT_EQ(res, false);
}


int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
