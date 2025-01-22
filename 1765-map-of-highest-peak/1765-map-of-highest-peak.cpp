class Solution {
private:
    int ylen;
    int xlen;

    bool is_valid(int x, int y) {
        if (x < 0 || x >= this->xlen || y < 0 || y >= this->ylen) {
            return false;
        }
        return true;
    }

public:
    vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {
        this->ylen = isWater.size();
        this->xlen = isWater[0].size();

        vector<vector<int>> height(this->ylen, vector<int>(this->xlen, 1));
        vector<vector<bool>> visited(this->ylen, vector<bool>(this->xlen, 0));
        vector<pair<int, int>> directions = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        priority_queue<array<int, 3>, vector<array<int, 3>>, greater<array<int, 3>>> pq;

        int nx, ny ;
        for (int y = 0; y < this->ylen; y++) {
            for (int x = 0; x < this->xlen; x++) {
                if (isWater[y][x] == 0) {
                    continue;
                }
                height[y][x] = 0;
                visited[y][x] = true;
                for (auto& dir : directions) {
                    nx = x + dir.first;
                    ny = y + dir.second;
                    if (this->is_valid(nx, ny) && visited[ny][nx] == false) {
                        pq.push({height[y][x] + 1, nx, ny});
                    }
                }
            }
        }

        int max_height;
        while (!pq.empty()) {
            auto [h, x, y] = pq.top();
            pq.pop();
            if (! this->is_valid(x, y)) {
                continue;
            }
            if (visited[y][x]) {
                continue;
            }
            visited[y][x] = true;
            height[y][x] = h;
            for (auto& dir : directions) {
                nx = x + dir.first;
                ny = y + dir.second;
                if (this->is_valid(nx, ny)) {
                    if (visited[ny][nx] == false) {
                        pq.push({height[y][x] + 1, nx, ny});
                    }
                }
            }
        }
        return height;
    }
};