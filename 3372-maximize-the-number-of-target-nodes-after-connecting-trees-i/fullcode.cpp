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


/* https://leetcode.com/problems/maximize-the-number-of-target-nodes-after-connecting-trees-i/?envType=daily-question&envId=2025-05-28
 * @lc app=leetcode id=3372 lang=cpp
 * [3372] Maximize the Number of Target Nodes After Connecting Trees I

There exist two undirected trees with n and m nodes, with distinct labels in ranges [0, n - 1] and [0, m - 1], respectively.
You are given two 2D integer arrays edges1 and edges2 of lengths n - 1 and m - 1, respectively, where edges1[i] = [ai, bi] indicates that there is an edge between nodes ai and bi in the first tree and edges2[i] = [ui, vi] indicates that there is an edge between nodes ui and vi in the second tree. You are also given an integer k.
Node u is target to node v if the number of edges on the path from u to v is less than or equal to k. Note that a node is always target to itself.
Return an array of n integers answer, where answer[i] is the maximum possible number of nodes target to node i of the first tree if you have to connect one node from the first tree to another node in the second tree.
Note that queries are independent from each other. That is, for every query you will remove the added edge before proceeding to the next query.

n개와 m개의 노드를 가진 두 개의 무방향 트리가 존재하며, 각각 [0, n - 1]과 [0, m - 1] 범위의 서로 다른 라벨을 가집니다.
길이가 n - 1과 m - 1인 두 개의 2D 정수 배열 edges1과 edges2가 주어지며, edges1[i] = [ai, bi]는 첫 번째 트리에서 노드 ai와 bi 사이에 간선이 있음을 나타내고, edges2[i] = [ui, vi]는 두 번째 트리에서 노드 ui와 vi 사이에 간선이 있음을 나타냅니다. 또한 정수 k가 주어집니다.
노드 u에서 노드 v까지의 경로상 간선의 수가 k 이하일 때, 노드 u는 노드 v의 타겟입니다. 노드는 항상 자기 자신의 타겟임에 주의하세요.
첫 번째 트리의 한 노드를 두 번째 트리의 다른 노드에 연결해야 할 때, 첫 번째 트리의 노드 i의 타겟이 될 수 있는 노드의 최대 개수인 answer[i]를 포함하는 길이 n의 정수 배열을 반환하세요.
쿼리들은 서로 독립적임에 주의하세요. 즉, 모든 쿼리에 대해 다음 쿼리로 진행하기 전에 추가된 간선을 제거합니다.



Constraints:
2 <= n, m <= 1000
edges1.length == n - 1
edges2.length == m - 1
edges1[i].length == edges2[i].length == 2
edges1[i] = [ai, bi]
0 <= ai, bi < n
edges2[i] = [ui, vi]
0 <= ui, vi < m
The input is generated such that edges1 and edges2 represent valid trees.
0 <= k <= 1000


 */

// @lc code=start
class Solution {

private:

    int dfs(map<int, vector<int>> &graph, int max_depth, int curr, int prev = -1, int level=0) {
        if (level > max_depth) {
            return 0;
        }
        int node_count = 0;
        vector<int> &nodes = graph[curr];

        for (int next : nodes) {
            if (next == prev || next == curr) {
                continue;
            }
            node_count += this->dfs(graph, max_depth, next, curr, level + 1);
        }

        return node_count + 1;
    }

public:
    vector<int> maxTargetNodes(vector<vector<int>>& edges1, vector<vector<int>>& edges2, int k) {

        map<int, vector<int>> graph1;
        map<int, vector<int>> graph2;

        for (auto& edge : edges1) {
            graph1[edge[0]].push_back(edge[1]);
            graph1[edge[1]].push_back(edge[0]);
        }

        for (auto& edge : edges2) {
            graph2[edge[0]].push_back(edge[1]);
            graph2[edge[1]].push_back(edge[0]);
        }

        int max_depth = 0;
        for (pair<int, vector<int>> p : graph2) {
            int node_count = this->dfs(graph2, k - 1, p.first);
            max_depth = max(max_depth, node_count);
        }

        vector<int> answer(edges1.size() + 1, 0);
        for (int i = 0; i < edges1.size() + 1; i++) {
            answer[i] = this->dfs(graph1, k, i) + max_depth;
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
    // Example 1:
    // Input: edges1 = [[0,1],[0,2],[2,3],[2,4]], edges2 = [[0,1],[0,2],[0,3],[2,7],[1,4],[4,5],[4,6]], k = 2
    // Output: [9,7,9,8,8]
    // Explanation:
    // For i = 0, connect node 0 from the first tree to node 0 from the second tree.
    // For i = 1, connect node 1 from the first tree to node 0 from the second tree.
    // For i = 2, connect node 2 from the first tree to node 4 from the second tree.
    // For i = 3, connect node 3 from the first tree to node 4 from the second tree.
    // For i = 4, connect node 4 from the first tree to node 4 from the second tree.

    vector<vector<int>> edges1 = {{0,1},{0,2},{2,3},{2,4}};
    vector<vector<int>> edges2 = {{0,1},{0,2},{0,3},{2,7},{1,4},{4,5},{4,6}};
    int k = 2;
    vector<int> expected = {9,7,9,8,8};

	EXPECT_EQ(this->s.maxTargetNodes(edges1, edges2, k), expected);
}

TEST_F(CLASS_NAME, __LINE__)
{
    // Example 2:
    // Input: edges1 = [[0,1],[0,2],[0,3],[0,4]], edges2 = [[0,1],[1,2],[2,3]], k = 1
    // Output: [6,3,3,3,3]
    // Explanation:
    // For every i, connect node i of the first tree with any node of the second tree.

    vector<vector<int>> edges1 = {{0,1},{0,2},{0,3},{0,4}};
    vector<vector<int>> edges2 = {{0,1},{1,2},{2,3}};
    int k = 1;
    vector<int> expected = {6,3,3,3,3};

    EXPECT_EQ(this->s.maxTargetNodes(edges1, edges2, k), expected);
}


int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
