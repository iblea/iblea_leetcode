class Solution {
public:
    int numTilings(int n) {

        const int MOD = 1000000007;

        if (n <= 2) {
            return n;
        }
        vector<array<long long, 3>>dp(n + 1, {0, 0, 0});

        dp[1][0] = 1; // | 모양
        dp[1][1] = 0; // 만들 수 없음
        dp[1][2] = 0; // 만들 수 없음

        dp[2][0] = 2; // || = 모양
        dp[2][1] = 1; // ㄴ 모양
        dp[2][2] = 1; // ㄱ 모양

        for (int i = 3; i < n; i++) {
            dp[i][0] = (dp[i-1][0] + dp[i-2][0] + dp[i-1][1] + dp[i-1][2]) % MOD;
            dp[i][1] = (dp[i-2][0] + dp[i-1][2]) % MOD;
            dp[i][2] = (dp[i-2][0] + dp[i-1][1]) % MOD;
        }

        return (dp[n-1][0] + dp[n-2][0] + dp[n-1][1] + dp[n-1][2]) % MOD;
    }
};