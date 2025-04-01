class Solution {
public:
    long long mostPoints(vector<vector<int>>& questions) {
        int n = questions.size();
        vector<long long> dp(n, 0);
        long long max_score = 0;
        for (int i = n - 1; i >= 0; i--) {
            int points = questions[i][0];
            int skip = questions[i][1];
            int skip_next_idx = i + skip + 1;
            if (skip_next_idx >= n) {
                if (max_score < points) {
                    max_score = points;
                }
                dp[i] = max_score;
            } else {
                if (max_score < points + dp[skip_next_idx]) {
                    max_score = points + dp[skip_next_idx];
                }
                dp[i] = max_score;
            }
        }
        // for (int i = 0; i < n; i++) {
        //     cout << dp[i] << " ";
        // }
        // cout << endl;
        // cout << "max_score: " << max_score << endl;
        return dp[0];
    }
};