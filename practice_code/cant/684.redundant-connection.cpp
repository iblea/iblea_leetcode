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



/* https://leetcode.com/problems/redundant-connection/?envType=daily-question&envId=2025-01-29
 * @lc app=leetcode id=684 lang=cpp
 * [684] Redundant Connection

In this problem, a tree is an undirected graph that is connected and has no cycles.
You are given a graph that started as a tree with n nodes labeled from 1 to n, with one additional edge added. The added edge has two different vertices chosen from 1 to n, and was not an edge that already existed. The graph is represented as an array edges of length n where edges[i] = [ai, bi] indicates that there is an edge between nodes ai and bi in the graph.
Return an edge that can be removed so that the resulting graph is a tree of n nodes. If there are multiple answers, return the answer that occurs last in the input.

이 문제에서 트리는 연결되어 있고 사이클이 없는 무방향 그래프입니다.
1부터 n까지 레이블이 지정된 n개의 노드로 구성된 트리에서 시작하여 하나의 간선이 추가된 그래프가 주어집니다. 추가된 간선은 1부터 n 사이에서 선택된 서로 다른 두 정점을 가지며, 이미 존재하는 간선이 아닙니다. 그래프는 길이가 n인 edges 배열로 표현되며, edges[i] = [ai, bi]는 그래프에서 노드 ai와 bi 사이에 간선이 있음을 나타냅니다.
제거했을 때 n개의 노드로 구성된 트리가 되는 간선을 반환하세요. 답이 여러 개인 경우 입력에서 마지막으로 등장하는 답을 반환하세요.


Constraints:
n == edges.length
3 <= n <= 1000
edges[i].length == 2
1 <= ai < bi <= edges.length
ai != bi
There are no repeated edges.
The given graph is connected.
 */

// @lc code=start
class Solution {
    vector<int> parent;

    int find_parent(int x) {

        // 반복문
        int result, top;
        stack<int> st;
        st.push(x);
        while (true) {
            top = st.top();
            if (this->parent[top] == top) {
                result = top;
                break;
            }
            st.push(this->parent[top]);
        }
        while (!st.empty()) {
            top = st.top();
            this->parent[top] = result;
            st.pop();
        }
        return result;

        // 재귀
        // if (this->parent[x] != x) {
        //     this->parent[x] = this->find_parent(this->parent[x]);
        // }
        // return this->parent[x];
    }

    bool union_set(int x, int y) {
        int xroot = this->find_parent(x);
        int yroot = this->find_parent(y);

        if (xroot == yroot) {
            return false;
        }

        this->parent[xroot] = yroot;
        return true;
    }
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {

        int nlen = edges.size();
        this->parent = vector<int>(nlen + 1, 0);
        // 자기 자신을 부모로 설정 (union-find 알고리즘의 부모 초기화)
        for (int i = 0; i < nlen; i++) {
            this->parent[i] = i;
        }

        for (const auto& edge : edges) {
            if (!this->union_set(edge[0], edge[1])) {
                return edge;
            }
        }
        return {};
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
    // Input: edges = [[1,2],[1,3],[2,3]]
    // Output: [2,3]
    vector<vector<int>> edges = {{1,2},{1,3},{2,3}};
    vector<int> result = {2,3};
	EXPECT_EQ(this->s.findRedundantConnection(edges), result);
}

TEST_F(CLASS_NAME, __LINE__)
{
    // Example 2:
    // Input: edges = [[1,2],[2,3],[3,4],[1,4],[1,5]]
    // Output: [1,4]
    vector<vector<int>> edges = {{1,2},{2,3},{3,4},{1,4},{1,5}};
    vector<int> result = {1,4};
	EXPECT_EQ(this->s.findRedundantConnection(edges), result);
}

TEST_F(CLASS_NAME, __LINE__)
{
    // Example 2:
    // Input: edges = [[3,4],[1,2],[2,4],[3,5],[2,5]]
    // Output: [2,5]
    vector<vector<int>> edges = {{3,4},{1,2},{2,4},{3,5},{2,5}};
    vector<int> result = {2,5};
	EXPECT_EQ(this->s.findRedundantConnection(edges), result);
    // 1>2>4>3>5
}





int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}