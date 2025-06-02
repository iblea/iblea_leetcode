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