class Solution {
public:
    int minTimeToReach(vector<vector<int>>& moveTime) {

        const int n = moveTime.size();
        const int m = moveTime[0].size();
        const int goal_n = n - 1;
        const int goal_m = m - 1;

        vector<pair<int, int>> directions = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

        priority_queue<array<int, 3>, vector<array<int, 3>>, greater<array<int, 3>>> pq;
        vector<vector<bool>> visited(n, vector<bool>(m, false));

        pq.push({0, 0, 0});
        while (!pq.empty()) {
            auto [time, x, y] = pq.top();
            pq.pop();
            if (x == goal_n && y == goal_m) {
                return time;
            }

            if (visited[x][y]) {
                continue;
            }

            visited[x][y] = true;
            for (auto [dx, dy] : directions) {
                int nx = x + dx;
                int ny = y + dy;
                if (nx < 0 || nx >= n || ny < 0 || ny >= m) {
                    continue;
                }
                if (visited[nx][ny]) {
                    continue;
                }
                pq.push({max(time + 1, moveTime[nx][ny] + 1), nx, ny});
            }
        }
        return -1;
    }
};