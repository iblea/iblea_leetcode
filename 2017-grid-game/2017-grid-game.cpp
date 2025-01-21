class Solution {
public:
    long long gridGame(vector<vector<int>>& grid) {
        int n = grid[0].size();
        vector<long long> top_sum(n + 1, 0);
        vector<long long> bottom_sum(n + 1, 0);
        for (int i = 0; i < n; i++) {
            top_sum[i + 1] = grid[0][i] + top_sum[i];
            bottom_sum[i + 1] = grid[1][i] + bottom_sum[i];
        }

        long long answer = LLONG_MAX;
        for (int i = 0; i < n; i++) {
            answer = min(answer, max(top_sum[n] - top_sum[i + 1], bottom_sum[i]));
        }
        return answer;
    }
};