class Solution {
private:
    vector<pair<int, int>> directions = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    int xlen;
    int ylen;

    int dfs(vector<vector<int>>* grid, vector<vector<bool>>* visited, int x, int y) {
        int dx, dy;
        queue<pair<int, int>> q;
        q.push({x, y});
        (*visited)[y][x] = true;
        int fish = 0;
        while (!q.empty()) {
            auto [nx, ny] = q.front();
            q.pop();
            fish += (*grid)[ny][nx];
            for (auto& dir : directions) {
                dx = nx + dir.first;
                dy = ny + dir.second;
                if (dx < 0 || dx >= this->xlen || dy < 0 || dy >= this->ylen) {
                    continue;
                }
                if ((*visited)[dy][dx]) {
                    continue;
                }
                if ((*grid)[dy][dx] == 0) {
                    continue;
                }
                q.push({dx, dy});
                (*visited)[dy][dx] = true;
            }
        }
        return fish;
    }
public:
    int findMaxFish(vector<vector<int>>& grid) {
        this->xlen = grid[0].size();
        this->ylen = grid.size();
        int maxFish = 0;

        vector<vector<bool>> visited(ylen, vector<bool>(xlen, false));
        for (int y = 0; y < ylen; y++) {
            for (int x = 0; x < xlen; x++) {
                if (grid[y][x] == 0 || visited[y][x]) {
                    continue;
                }
                maxFish = max(maxFish, dfs(&grid, &visited, x, y));
            }
        }


        return maxFish;
    }
};