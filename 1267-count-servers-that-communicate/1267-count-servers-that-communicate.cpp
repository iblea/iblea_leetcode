class Solution {
public:
    int countServers(vector<vector<int>>& grid) {

        int count = 0;
        int ylen = grid.size();
        int xlen = grid[0].size();

        vector<int> x_can_communicate(xlen, 0);
        vector<int> y_can_communicate(ylen, 0);
        vector<pair<int, int>> server_pos;

        for (int y = 0; y < ylen; y++) {
            for (int x = 0; x < xlen; x++) {
                if (grid[y][x] == 1) {
                    server_pos.push_back({x, y});
                    x_can_communicate[x]++;
                    y_can_communicate[y]++;
                }
            }
        }

        for (auto [x, y] : server_pos) {
            if (x_can_communicate[x] > 1 || y_can_communicate[y] > 1) {
                count++;
            }
        }
        return count;
    }
};