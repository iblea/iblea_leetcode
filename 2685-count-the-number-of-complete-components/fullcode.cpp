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



/* https://leetcode.com/problems/count-the-number-of-complete-components/?envType=daily-question&envId=2025-03-22
 * @lc app=leetcode id=2685 lang=cpp
 * [2685] Count the Number of Complete Components

You are given an integer n. There is an undirected graph with n vertices, numbered from 0 to n - 1. You are given a 2D integer array edges where edges[i] = [ai, bi] denotes that there exists an undirected edge connecting vertices ai and bi.
Return the number of complete connected components of the graph.
A connected component is a subgraph of a graph in which there exists a path between any two vertices, and no vertex of the subgraph shares an edge with a vertex outside of the subgraph.
A connected component is said to be complete if there exists an edge between every pair of its vertices.

정수 n이 주어집니다. n개의 정점을 가진 무방향 그래프가 있으며, 정점은 0부터 n - 1까지 번호가 매겨져 있습니다. 2D 정수 배열 edges가 주어지는데, edges[i] = [ai, bi]는 정점 ai와 bi를 연결하는 무방향 간선이 존재함을 나타냅니다.
그래프의 완전 연결 컴포넌트의 수를 반환하세요.
연결 컴포넌트는 그래프의 부분 그래프로, 모든 두 정점 사이에 경로가 존재하며, 부분 그래프의 어떤 정점도 부분 그래프 외부의 정점과 간선을 공유하지 않습니다.
연결 컴포넌트가 완전하다는 것은 모든 정점 쌍 사이에 간선이 존재한다는 것을 의미합니다.

Constraints:
1 <= n <= 50
0 <= edges.length <= n * (n - 1) / 2
edges[i].length == 2
0 <= ai, bi <= n - 1
ai != bi
There are no repeated edges.
 */

// @lc code=start
class Solution {
private:
    vector<pair<int, int>> visited;

    int find(vector<int>& union_find, int x) {
        if (union_find[x] != x) {
            union_find[x] = find(union_find, union_find[x]);
        }
        return union_find[x];
    }
    void union_merge(vector<int>& union_find, int x, int y) {
        int root_x = find(union_find, x);
        int root_y = find(union_find, y);
        if (root_x != root_y) {
            union_find[root_x] = root_y;
            visited[root_y].first += visited[root_x].first + 1;
            visited[root_y].second += visited[root_x].second;
        } else {
            visited[root_y].first += 1;
        }
    }
public:
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        this->visited = vector<pair<int, int>>(n);

        vector<int> union_find(n);
        for (int i = 0; i < n; i++) {
            union_find[i] = i;
        }

        for (int i = 0; i < n; i++) {
            // first -> 간선 수, second -> 정점 수
            this->visited[i].first = 0;
            this->visited[i].second = 1;
            // (union_find[i] == i) && (((second * (second - 1)) / 2) == first)
        }

        for (auto edge : edges) {
            this->union_merge(union_find, edge[0], edge[1]);
        }

        int answer = 0;
        for (int i = 0; i < n; i++) {
            if (union_find[i] != i) {
                continue;
            }
            if (((this->visited[i].second * (this->visited[i].second - 1)) / 2) == this->visited[i].first) {
                answer++;
            }
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
    // Input: n = 6, edges = [[0,1],[0,2],[1,2],[3,4]]
    // Output: 3
    // Explanation: From the picture above, one can see that all of the components of this graph are complete.

    int n = 6;
    vector<vector<int>> edges = {{0,1},{0,2},{1,2},{3,4}};
	EXPECT_EQ(this->s.countCompleteComponents(n, edges), 3);
}

TEST_F(CLASS_NAME, __LINE__)
{
    // Example 2:
    // Input: n = 6, edges = [[0,1],[0,2],[1,2],[3,4],[3,5]]
    // Output: 1
    // Explanation: The component containing vertices 0, 1, and 2 is complete since there is an edge between every pair of two vertices. On the other hand, the component containing vertices 3, 4, and 5 is not complete since there is no edge between vertices 4 and 5. Thus, the number of complete components in this graph is 1.

    int n = 6;
    vector<vector<int>> edges = {{0,1},{0,2},{1,2},{3,4},{3,5}};
	EXPECT_EQ(this->s.countCompleteComponents(n, edges), 1);
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
