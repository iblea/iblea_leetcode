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



/* https://leetcode.com/problems/solving-questions-with-brainpower/?envType=daily-question&envId=2025-04-01
 * @lc app=leetcode id=2140 lang=cpp
 * [2140] Solving Questions With Brainpower

You are given a 0-indexed 2D integer array questions where questions[i] = [pointsi, brainpoweri].
The array describes the questions of an exam, where you have to process the questions in order (i.e., starting from question 0) and make a decision whether to solve or skip each question. Solving question i will earn you pointsi points but you will be unable to solve each of the next brainpoweri questions. If you skip question i, you get to make the decision on the next question.
For example, given questions = [[3, 2], [4, 3], [4, 4], [2, 5]]:
If question 0 is solved, you will earn 3 points but you will be unable to solve questions 1 and 2.
If instead, question 0 is skipped and question 1 is solved, you will earn 4 points but you will be unable to solve questions 2 and 3.
Return the maximum points you can earn for the exam.

0-인덱스 2D 정수 배열 questions가 주어지며, questions[i] = [pointsi, brainpoweri]입니다.
이 배열은 시험의 문제들을 설명하며, 순서대로(즉, 0번 문제부터 시작) 문제를 처리하고 각 문제를 풀지 건너뛸지 결정해야 합니다. i번 문제를 풀면 pointsi 점수를 얻지만, 다음 brainpoweri개의 문제를 풀 수 없게 됩니다. i번 문제를 건너뛰면 다음 문제에 대해 결정할 수 있습니다.
예를 들어, questions = [[3, 2], [4, 3], [4, 4], [2, 5]]가 주어진 경우:
0번 문제를 풀면 3점을 얻지만 1번과 2번 문제를 풀 수 없게 됩니다.
대신 0번 문제를 건너뛰고 1번 문제를 풀면 4점을 얻지만 2번과 3번 문제를 풀 수 없게 됩니다.
시험에서 얻을 수 있는 최대 점수를 반환하세요.

Constraints:
1 <= questions.length <= 10**5
questions[i].length == 2
1 <= pointsi, brainpoweri <= 10**5

 */

// @lc code=start
class Solution {
public:
    long long mostPoints(vector<vector<int>>& questions) {
        int n = questions.size();
        vector<long long> dp(n, 0);
        long long max_score = 0;
        for (int i = n - 1; i >= 0; i--) {
            int points = questions[i][0];
            int skip = questions[i][1];
            int skip_next_idx = i + skip + 1;
            if (skip_next_idx >= n) {
                if (max_score < points) {
                    max_score = points;
                }
                dp[i] = max_score;
            } else {
                if (max_score < points + dp[skip_next_idx]) {
                    max_score = points + dp[skip_next_idx];
                }
                dp[i] = max_score;
            }
        }
        // for (int i = 0; i < n; i++) {
        //     cout << dp[i] << " ";
        // }
        // cout << endl;
        // cout << "max_score: " << max_score << endl;
        return dp[0];
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
    // Input: questions = [[3,2],[4,3],[4,4],[2,5]]
    // Output: 5
    // Explanation: The maximum points can be earned by solving questions 0 and 3.
    // - Solve question 0: Earn 3 points, will be unable to solve the next 2 questions
    // - Unable to solve questions 1 and 2
    // - Solve question 3: Earn 2 points
    // Total points earned: 3 + 2 = 5. There is no other way to earn 5 or more points.

    vector<vector<int>> questions = {{3,2},{4,3},{4,4},{2,5}};
	EXPECT_EQ(this->s.mostPoints(questions), 5);
}

TEST_F(CLASS_NAME, __LINE__)
{
    // Example 2:
    // Input: questions = [[1,1],[2,2],[3,3],[4,4],[5,5]]
    // Output: 7
    // Explanation: The maximum points can be earned by solving questions 1 and 4.
    // - Skip question 0
    // - Solve question 1: Earn 2 points, will be unable to solve the next 2 questions
    // - Unable to solve questions 2 and 3
    // - Solve question 4: Earn 5 points
    // Total points earned: 2 + 5 = 7. There is no other way to earn 7 or more points.

    vector<vector<int>> questions = {{1,1},{2,2},{3,3},{4,4},{5,5}};
    EXPECT_EQ(this->s.mostPoints(questions), 7);
}

TEST_F(CLASS_NAME, __LINE__)
{
    vector<vector<int>> questions = {{21,5},{92,3},{74,2},{39,4},{58,2},{5,5},{49,4},{65,3}};
    EXPECT_EQ(this->s.mostPoints(questions), 157);
}

TEST_F(CLASS_NAME, __LINE__)
{
    vector<vector<int>> questions = {{10, 1}, {10, 1}, {10, 1}, {10, 1}, {10, 1}, {10, 1}};
    EXPECT_EQ(this->s.mostPoints(questions), 30);
}



int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
