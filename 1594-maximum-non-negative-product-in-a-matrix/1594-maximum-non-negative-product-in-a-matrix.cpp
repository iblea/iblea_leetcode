class Solution {
private:
    static constexpr int MOD = 1e9 + 7;
public:
    int maxProductPath(vector<vector<int>>& grid) {
        int y = grid.size();
        int x = grid[0].size();
        vector<vector<long long>> dp_max(y, vector<long long>(x, 0));
        vector<vector<long long>> dp_min(y, vector<long long>(x, 0));

        // 초기 값 설정
        dp_max[0][0] = grid[0][0];
        dp_min[0][0] = grid[0][0];
        for (int i = 1; i < y; ++i) {
            dp_max[i][0] = dp_max[i-1][0] * grid[i][0];
            dp_min[i][0] = dp_min[i-1][0] * grid[i][0];
        }
        for (int j = 1; j < x; ++j) {
            dp_max[0][j] = dp_max[0][j-1] * grid[0][j];
            dp_min[0][j] = dp_min[0][j-1] * grid[0][j];
        }

        // dp 시작
        for (int i = 1; i < y; ++i) {
            for (int j = 1; j < x; ++j) {
                long long maxup = dp_max[i-1][j] * grid[i][j];
                long long maxleft = dp_max[i][j-1] * grid[i][j];
                long long minup = dp_min[i-1][j] * grid[i][j];
                long long minleft = dp_min[i][j-1] * grid[i][j];
                dp_max[i][j] = max({maxup, maxleft, minup, minleft});
                dp_min[i][j] = min({maxup, maxleft, minup, minleft});
            }
        }

        long long result = dp_max[y-1][x-1];
        if (result < 0) {
            return -1;
        }
        return result % MOD;
    }
};
