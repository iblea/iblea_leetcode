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



/* https://leetcode.com/problems/minimum-cost-path-with-edge-reversals
 * @lc app=leetcode id=3650 lang=cpp
 * [3650] Minimum Cost Path with Edge Reversals

You are given a directed, weighted graph with n nodes labeled from 0 to n - 1, and an array edges where edges[i] = [ui, vi, wi] represents a directed edge from node ui to node vi with cost wi.
Each node ui has a switch that can be used at most once: when you arrive at ui and have not yet used its switch, you may activate it on one of its incoming edges vi → ui reverse that edge to ui → vi and immediately traverse it.
The reversal is only valid for that single move, and using a reversed edge costs 2 * wi.
Return the minimum total cost to travel from node 0 to node n - 1. If it is not possible, return -1.

0부터 n - 1까지 레이블이 붙은 n개의 노드를 가진 방향성 가중치 그래프와, edges[i] = [ui, vi, wi]가 노드 ui에서 노드 vi로 향하는 비용 wi의 방향 간선을 나타내는 배열 edges가 주어집니다.
각 노드 ui에는 최대 한 번 사용할 수 있는 스위치가 있습니다: ui에 도착했을 때 아직 해당 스위치를 사용하지 않았다면, 들어오는 간선 vi → ui 중 하나에서 스위치를 활성화하여 해당 간선을 ui → vi로 뒤집고 즉시 이동할 수 있습니다.
간선 뒤집기는 해당 단일 이동에만 유효하며, 뒤집힌 간선을 사용하는 비용은 2 * wi입니다.
노드 0에서 노드 n - 1까지 이동하는 최소 총 비용을 반환하세요. 불가능한 경우 -1을 반환하세요.

Constraints:
2 <= n <= 5 * 10^4
1 <= edges.length <= 10^5
edges[i] = [ui, vi, wi]
0 <= ui, vi <= n - 1
1 <= wi <= 1000
 */
// @lc code=start
class Solution {
public:
    int minCost(int n, vector<vector<int>>& edges) {
        vector<vector<pair<int,int>>> fline(n);  // 정방향: u -> v
        vector<vector<pair<int,int>>> rline(n);  // u로 들어오는 간선들

        for (const auto& e : edges) {
            int u = e[0];
            int v = e[1];
            int w = e[2];

            fline[u].emplace_back(v, w);
            rline[v].emplace_back(u, w * 2);
        }


        vector<long long> dist(n, LLONG_MAX);
        dist[0] = 0;

        priority_queue<
            pair<long long, int>,
            vector<pair<long long, int>>,
            greater<pair<long long, int>>
        > pq;
        pq.push({0, 0}); // {cost, node}

        while (!pq.empty()) {
            auto [d, u] = pq.top();
            pq.pop();
            if (u == n - 1) {
                return d;
            }
            if (d > dist[u]) {
                continue;
            }
            for (const auto & [v, w]: fline[u]) {
                if (dist[v] > dist[u] + w) {
                    dist[v] = dist[u] + w;
                    pq.push({dist[v], v});
                }
            }
            for (const auto & [v, w]: rline[u]) {
                if (dist[v] > dist[u] + w) {
                    dist[v] = dist[u] + w;
                    pq.push({dist[v], v});
                }
            }
        }
        return -1;
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
    // Input: n = 4, edges = [[0,1,3],[3,1,1],[2,3,4],[0,2,2]]
    // Output: 5
    // Explanation:
    // Use the path 0 → 1 (cost 3).
    // At node 1 reverse the original edge 3 → 1 into 1 → 3 and traverse it at cost 2 * 1 = 2.
    // 노드 1에서 원래 간선 3 → 1을 1 → 3으로 역전시키고, 비용 2 * 1 = 2로 이동합니다.
    // Total cost is 3 + 2 = 5.

    vector<vector<int>> edges = {
        {0,1,3},
        {3,1,1},
        {2,3,4},
        {0,2,2}
    };
    EXPECT_EQ(this->s.minCost(4, edges), 5);
}

TEST_F(CLASS_NAME, __LINE__)
{
    // Example 2:
    // Input: n = 4, edges = [[0,2,1],[2,1,1],[1,3,1],[2,3,3]]
    // Output: 3
    // Explanation:
    // No reversal is needed. Take the path 0 → 2 (cost 1), then 2 → 1 (cost 1), then 1 → 3 (cost 1).
    // Total cost is 1 + 1 + 1 = 3.

    vector<vector<int>> edges = {
        {0,2,1},
        {2,1,1},
        {1,3,1},
        {2,3,3}
    };
    EXPECT_EQ(this->s.minCost(4, edges), 3);
}

TEST_F(CLASS_NAME, __LINE__)
{
    vector<vector<int>> edges = {{2,0,12},{1,0,5},{0,1,15}};
    EXPECT_EQ(this->s.minCost(3, edges),24);
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
