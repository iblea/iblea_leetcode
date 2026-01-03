class Solution {
public:
    vector<int> parent, rank_;

    int find(int x) {
        if (parent[x] != x) {
            parent[x] = find(parent[x]);
        }
        return parent[x];
    }

    void unite(int x, int y) {
        int px = find(x), py = find(y);
        if (px == py) return;
        if (rank_[px] < rank_[py]) swap(px, py);
        parent[py] = px;
        if (rank_[px] == rank_[py]) rank_[px]++;
    }

    int latestDayToCross(int row, int col, vector<vector<int>>& cells) {
        // 맨 마지막 날부터 역순으로 진행하면서 union-find를 이용해 땅 셀만 밟고 맨 위에서 맨 아래까지 걸어갈 수 있는지 구한다.
        // 즉, union-find를 이용해 마지막 행과 첫 번째 행이 union으로 연결되는 시점이 곧 땅 셀만 밟고 맨 위에서 맨 아래까지 걸어갈 수 있는 마지막 날이라고 판단할 수 있다.

        int n = row * col;
        int top = n;        // 가상 노드: 첫 번째 행과 연결
        int bottom = n + 1; // 가상 노드: 마지막 행과 연결

        parent.resize(n + 2);
        rank_.resize(n + 2, 0);
        for (int i = 0; i < n + 2; i++) parent[i] = i;

        vector<vector<int>> grid(row, vector<int>(col, 1)); // 모든 셀이 물(1)
        int dirs[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

        // 역순으로 물을 빼면서 연결 확인
        for (int day = n - 1; day >= 0; day--) {
            int r = cells[day][0] - 1; // 0-indexed로 변환
            int c = cells[day][1] - 1;
            grid[r][c] = 0; // 땅으로 복원

            int idx = r * col + c;

            // 첫 번째 행이면 top과 연결
            if (r == 0) unite(idx, top);
            // 마지막 행이면 bottom과 연결
            if (r == row - 1) unite(idx, bottom);

            // 인접한 땅 셀과 연결
            for (auto& d : dirs) {
                int nr = r + d[0], nc = c + d[1];
                if (nr >= 0 && nr < row && nc >= 0 && nc < col && grid[nr][nc] == 0) {
                    unite(idx, nr * col + nc);
                }
            }

            // top과 bottom이 연결되면 이 날이 답
            if (find(top) == find(bottom)) {
                return day;
            }
        }

        return 0;
    }
};