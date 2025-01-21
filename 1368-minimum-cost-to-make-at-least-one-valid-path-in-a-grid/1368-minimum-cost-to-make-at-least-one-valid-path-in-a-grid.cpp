class Solution {

    int ylen = 0;
    int xlen = 0;
    vector<vector<int>> cost;
    vector<pair<int, int>> move_pos = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    priority_queue<array<int, 3>, vector<array<int, 3>>, greater<array<int, 3>>> pq;
    pair<int, int> move(int direction) {
        // x, y
        switch(direction) {
            case 1: return {1, 0};
            case 2: return {-1, 0};
            case 3: return {0, 1};
            case 4: return {0, -1};
        }
        return {0, 0};
    };

    bool is_valid(int x, int y) {
        if (x < 0 || x >= xlen || y < 0 || y >= ylen) {
            return false;
        }
        return true;
    };

    void move_zerocost(vector<vector<int>> &grid, int x, int y, int c) {
        int nx, ny;
        while(is_valid(x, y)) {
            if (this->cost[y][x] <= c) {
                // 무한루프 방지를 위해 이미 방문한 셀을 참조하는 경우 종료한다.
                break;
            }
            this->cost[y][x] = c;
            pair<int, int> move_dir = move(grid[y][x]);
            for (auto dir : this->move_pos) {
                nx = x + dir.first;
                ny = y + dir.second;
                this->pq.push({c + 1, nx, ny});
            }
            x += move_dir.first;
            y += move_dir.second;
        }
    };

public:
    int minCost(vector<vector<int>>& grid) {
        this->ylen = grid.size();
        this->xlen = grid[0].size();

        this->cost = vector<vector<int>>(ylen, vector<int>(xlen, INT_MAX));
        this->pq = priority_queue<array<int, 3>, vector<array<int, 3>>, greater<array<int, 3>>>();
        pq.push({0, 0, 0});

        // 0 이동 가능한 셀을 찾아서 4방향으로 이동(이동이 가능한 경우이거나, 이동한 이후 cost[y][x]가 최소인 경우)하는 큐를 만들어서 큐에 넣는다.
        // 큐에서 빼낸 셀의 좌표를 기준으로 0 이동이 가능한 셀을 찾아 4방향으로 이동(이동이 가능한 경우이거나, 이동한 이후 cost[y][x]가 최소인 경우)하는 큐를 만들어서 큐에 넣는다.
        // 이하 반복...
        while (!pq.empty()) {
            auto [c, x, y] = pq.top();
            pq.pop();
            move_zerocost(grid, x, y, c);
        }
        return this->cost[this->ylen - 1][this->xlen - 1];
    }
};
