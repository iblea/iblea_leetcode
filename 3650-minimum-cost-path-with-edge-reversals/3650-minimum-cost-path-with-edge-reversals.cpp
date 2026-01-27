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