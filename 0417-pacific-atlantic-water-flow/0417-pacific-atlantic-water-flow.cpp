class Solution {
private:
    vector<vector<int>> directions = {{1,0}, {-1,0}, {0, 1}, {0,-1}};

    void bfs(queue<pair<int, int>>& q, vector<vector<int>>& heights, vector<vector<bool>>& reachable) {
        vector<vector<bool>> visited(heights.size(), vector<bool>(heights[0].size(), false));
        int m = heights.size();
        int n = heights[0].size();

        while (!q.empty()) {
            auto [x, y] = q.front();
            q.pop();
            if (visited[x][y]) continue;
            visited[x][y] = true;

            for (const auto& dir : directions) {
                int newX = x + dir[0];
                int newY = y + dir[1];

                if (newX >= 0 && newX < m && newY >= 0 && newY < n &&
                    !reachable[newX][newY] && heights[newX][newY] >= heights[x][y]) {
                    reachable[newX][newY] = true;
                    q.push({newX, newY});
                }
            }
        }
    }

public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int x = heights[0].size();
        int y = heights.size();

        vector<vector<bool>> pacific_reachable(y, vector<bool>(x, false));
        vector<vector<bool>> atlantic_reachable(y, vector<bool>(x, false));
        vector<vector<int>> result;

        queue<pair<int, int>> pacific_queue;
        queue<pair<int, int>> atlantic_queue;

        for (int i = 0; i < y; ++i) {
            pacific_queue.push({i, 0});
            atlantic_queue.push({i, x - 1});
            pacific_reachable[i][0] = true;
            atlantic_reachable[i][x - 1] = true;
        }

        for (int j = 0; j < x; ++j) {
            pacific_queue.push({0, j});
            atlantic_queue.push({y - 1, j});
            pacific_reachable[0][j] = true;
            atlantic_reachable[y - 1][j] = true;
        }

        bfs(pacific_queue, heights, pacific_reachable);
        bfs(atlantic_queue, heights, atlantic_reachable);

        for (int i = 0; i < y; ++i) {
            for (int j = 0; j < x; ++j) {
                if (pacific_reachable[i][j] && atlantic_reachable[i][j]) {
                    result.push_back({i, j});
                }
            }
        }

        return result;
    }
};