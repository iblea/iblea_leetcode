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



/* https://leetcode.com/problems/course-schedule-iv/description/?envType=daily-question&envId=2025-01-27
 * @lc app=leetcode id=1462 lang=cpp
 * [1462] Course Schedule IV

There are a total of numCourses courses you have to take, labeled from 0 to numCourses - 1. You are given an array prerequisites where prerequisites[i] = [ai, bi] indicates that you must take course ai first if you want to take course bi.
For example, the pair [0, 1] indicates that you have to take course 0 before you can take course 1.
Prerequisites can also be indirect. If course a is a prerequisite of course b, and course b is a prerequisite of course c, then course a is a prerequisite of course c.
You are also given an array queries where queries[j] = [uj, vj]. For the jth query, you should answer whether course uj is a prerequisite of course vj or not.
Return a boolean array answer, where answer[j] is the answer to the jth query.

당신이 수강해야 하는 총 numCourses개의 강좌가 있으며, 0부터 numCourses - 1까지 번호가 매겨져 있습니다. prerequisites 배열이 주어지는데, prerequisites[i] = [ai, bi]는 bi 강좌를 수강하기 위해서는 먼저 ai 강좌를 수강해야 함을 나타냅니다.
예를 들어, [0, 1] 쌍은 강좌 1을 수강하기 전에 강좌 0을 수강해야 함을 나타냅니다.
선수 과목은 간접적일 수도 있습니다. 만약 강좌 a가 강좌 b의 선수 과목이고, 강좌 b가 강좌 c의 선수 과목이라면, 강좌 a는 강좌 c의 선수 과목이 됩니다.
또한 queries 배열이 주어지는데, queries[j] = [uj, vj]입니다. j번째 쿼리에 대해, 강좌 uj가 강좌 vj의 선수 과목인지 여부를 답해야 합니다.
boolean 배열 answer를 반환하세요. answer[j]는 j번째 쿼리에 대한 답입니다.

Constraints:
- 2 <= numCourses <= 100
- 0 <= prerequisites.length <= (numCourses * (numCourses - 1) / 2)
- prerequisites[i].length == 2
- 0 <= ai, bi <= numCourses - 1
- ai != bi
- All the pairs [ai, bi] are unique.
- The prerequisites graph has no cycles.
- 1 <= queries.length <= 10**4
- 0 <= ui, vi <= numCourses - 1
- ui != vi
 */

// @lc code=start
class Solution {
public:
    // DFS
    vector<bool> checkIfPrerequisite(int numCourses, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
        vector<set<int>> graph(numCourses, set<int>());

        for (const auto& prerequisite : prerequisites) {
            graph[prerequisite[0]].insert(prerequisite[1]);
        }

        set<int> *next;
        for (int i = 0; i < numCourses; ++i) {
            stack<int> s = stack<int>();
            for (int j : graph[i]) {
                s.push(j);
            }
            while(! s.empty()) {
                next = &graph[s.top()];
                s.pop();
                for (int j : *next) {
                    if (graph[i].count(j)) {
                        continue;
                    }
                    graph[i].insert(j);
                    s.push(j);
                }
            }
        }

        vector<bool> answer(queries.size(), false);
        for (int i = 0; i < queries.size(); ++i) {
            int u = queries[i][0];
            int v = queries[i][1];
            if (graph[u].count(v)) {
                answer[i] = true;
            }
        }
        return answer;
    }

    // Floyd-Warshall
    vector<bool> checkIfPrerequisite_Floyd_Warshall(int numCourses, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
        // Floyd-Warshall 알고리즘을 위한 인접 행렬 초기화
        vector<vector<bool>> reachable(numCourses, vector<bool>(numCourses, false));

        // 직접적인 선수 과목 관계 설정
        for (const auto& p : prerequisites) {
            reachable[p[0]][p[1]] = true;
        }

        // Floyd-Warshall 알고리즘
        for (int k = 0; k < numCourses; k++) {
            for (int i = 0; i < numCourses; i++) {
                for (int j = 0; j < numCourses; j++) {
                    reachable[i][j] = reachable[i][j] || (reachable[i][k] && reachable[k][j]);
                }
            }
        }

        // 쿼리에 대한 답변 생성
        vector<bool> answer;
        for (const auto& q : queries) {
            answer.push_back(reachable[q[0]][q[1]]);
        }

        return answer;
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
    int numCourses = 2;
    vector<vector<int>> prerequisites = {{1, 0}};
    vector<vector<int>> queries = {{0, 1}, {1, 0}};
    vector<bool> expected = {false, true};
    EXPECT_EQ(this->s.checkIfPrerequisite(numCourses, prerequisites, queries), expected);
}
TEST_F(CLASS_NAME, __LINE__)
{
    int numCourses = 2;
    vector<vector<int>> prerequisites = {};
    vector<vector<int>> queries = {{1, 0}, {0, 1}};
    vector<bool> expected = {false, false};
    EXPECT_EQ(this->s.checkIfPrerequisite(numCourses, prerequisites, queries), expected);
}
TEST_F(CLASS_NAME, __LINE__)
{
    int numCourses = 3;
    vector<vector<int>> prerequisites = {{1, 2}, {1, 0}, {2, 0}};
    vector<vector<int>> queries = {{1, 0}, {1, 2}};
    vector<bool> expected = {true, true};
    EXPECT_EQ(this->s.checkIfPrerequisite(numCourses, prerequisites, queries), expected);
}
TEST_F(CLASS_NAME, __LINE__)
{
    int numCourses = 3;
    vector<vector<int>> prerequisites = {{1, 2}, {2, 0}};
    vector<vector<int>> queries = {{1, 0}, {1, 2}};
    vector<bool> expected = {true, true};
    EXPECT_EQ(this->s.checkIfPrerequisite(numCourses, prerequisites, queries), expected);
}



int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}