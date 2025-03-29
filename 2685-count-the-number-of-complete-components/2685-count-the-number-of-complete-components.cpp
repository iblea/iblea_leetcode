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