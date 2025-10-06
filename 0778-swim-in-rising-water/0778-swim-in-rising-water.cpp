class Solution {
private:
    pair<int, int> directions[4] = {{0,1}, {0,-1}, {1,0}, {-1,0}};
public:
    int swimInWater(vector<vector<int>>& grid) {
        int x = grid[0].size();
        int y = grid.size();
        const int targetX = x - 1;
        const int targetY = y - 1;
        priority_queue<array<int, 3>, vector<array<int, 3>>, greater<>> minHeap; // {height, x, y}
        vector<vector<bool>> visited(grid.size(), vector<bool>(grid.size(), false));
        minHeap.push({grid[0][0], 0, 0});
        visited[0][0] = true;
        int ans = 0;

        while (!minHeap.empty()) {
            auto [height, curX, curY] = minHeap.top();
            minHeap.pop();
            ans = max(ans, height);
            if (curX == targetX && curY == targetY) break;

            for (auto& dir : directions) {
                int nextX = curX + dir.first;
                int nextY = curY + dir.second;
                if (nextX < 0 || nextX >= x || nextY < 0 || nextY >= y) continue;
                if (visited[nextY][nextX]) continue;
                visited[nextY][nextX] = true;
                minHeap.push({grid[nextY][nextX], nextX, nextY});
            }
        }

        return ans;
    }
};