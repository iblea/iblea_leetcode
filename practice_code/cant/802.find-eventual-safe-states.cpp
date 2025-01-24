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



/* https://leetcode.com/problems/find-eventual-safe-states/description/?envType=daily-question&envId=2025-01-24
 * @lc app=leetcode id=802 lang=cpp
 * [802] Find Eventual Safe States

There is a directed graph of n nodes with each node labeled from 0 to n - 1. The graph is represented by a 0-indexed 2D integer array graph where graph[i] is an integer array of nodes adjacent to node i, meaning there is an edge from node i to each node in graph[i].
A node is a terminal node if there are no outgoing edges. A node is a safe node if every possible path starting from that node leads to a terminal node (or another safe node).
Return an array containing all the safe nodes of the graph. The answer should be sorted in ascending order.

0부터 n-1까지 레이블이 지정된 n개의 노드로 구성된 방향 그래프가 있습니다. 그래프는 0-인덱스 2D 정수 배열 graph로 표현되며, graph[i]는 노드 i에 인접한 노드들의 정수 배열입니다. 이는 노드 i에서 graph[i]의 각 노드로 가는 간선이 있음을 의미합니다.
터미널 노드는 나가는 간선이 없는 노드입니다. 안전 노드는 해당 노드에서 시작하는 모든 가능한 경로가 터미널 노드(또는 다른 안전 노드)로 이어지는 노드입니다.
그래프의 모든 안전 노드를 포함하는 배열을 반환하세요. 답은 오름차순으로 정렬되어야 합니다.


Constraints:
- n == graph.length
- 1 <= n <= 10**4
- 0 <= graph[i].length <= n
- 0 <= graph[i][j] <= n - 1
- graph[i] is sorted in a strictly increasing order.
- The graph may contain self-loops.
- The number of edges in the graph will be in the range [1, 4 * 10**4].
 */

// @lc code=start
class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<bool> is_safe(n, false);
        vector<vector<int>> targets(n, vector<int>());
        vector<int> outdegree(n, 0);
        queue<int> q;

        for (int i = 0; i < n; i++) {
            outdegree[i] = graph[i].size();
            if (outdegree[i] == 0) {
                is_safe[i] = true;
                q.push(i);
            }

            // 역방향 그래프 생성
            for (int next: graph[i]) {
                targets[next].push_back(i);
            }
        }

        while (!q.empty()) {
            int node = q.front();
            q.pop();

            for (int prev: targets[node]) {
                outdegree[prev]--;
                if (outdegree[prev] == 0) {
                    is_safe[prev] = true;
                    q.push(prev);
                }
            }
        }

        vector<int> result;
        for (int i = 0; i < n; i++) {
            if (is_safe[i]) {
                result.push_back(i);
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
    // Input: graph = [[1,2],[2,3],[5],[0],[5],[],[]]
    // Output: [2,4,5,6]
    // Explanation: The given graph is shown above.
    // Nodes 5 and 6 are terminal nodes as there are no outgoing edges from either of them.
    // Every path starting at nodes 2, 4, 5, and 6 all lead to either node 5 or 6.
    // 설명: 위에 주어진 그래프가 표시되어 있습니다.
    // 노드 5와 6은 어떤 나가는 간선도 없기 때문에 터미널 노드입니다.
    // 노드 2, 4, 5, 6에서 시작하는 모든 경로는 노드 5 또는 6으로 이어집니다.
    vector<vector<int>> graph = {{1,2},{2,3},{5},{0},{5},{},{}};
    vector<int> expected = {2,4,5,6};
    EXPECT_EQ(this->s.eventualSafeNodes(graph), expected);
}
TEST_F(CLASS_NAME, __LINE__)
{
    // Example 2:
    // Input: graph = [[1,2,3,4],[1,2],[3,4],[0,4],[]]
    // Output: [4]
    // Explanation:
    // Only node 4 is a terminal node, and every path starting at node 4 leads to node 4.
    vector<vector<int>> graph = {{1,2,3,4},{1,2},{3,4},{0,4},{}};
    vector<int> expected = {4};
    EXPECT_EQ(this->s.eventualSafeNodes(graph), expected);
}



int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}