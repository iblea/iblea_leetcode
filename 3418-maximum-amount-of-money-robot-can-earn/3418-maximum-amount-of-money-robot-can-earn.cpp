class Solution {
public:
    int maximumAmount(vector<vector<int>>& coins) {
        const int NEG_INF = -1e9; // INF_MIN 안주는 이유, INF_MIN - 값 하면 언더플로우로 터짐.
        int ylen = coins.size();
        int xlen = coins[0].size();
        vector<vector<array<int, 3>>> dp(ylen, vector<array<int, 3>>(xlen, {NEG_INF, NEG_INF, NEG_INF}));

        dp[0][0][0] = coins[0][0];
        dp[0][0][1] = coins[0][0] < 0 ? 0 : NEG_INF;
        for (int i = 1; i < ylen; i++) {
            dp[i][0][0] = dp[i-1][0][0] + coins[i][0];
            if (coins[i][0] < 0) {
                int beaten, neutralize;

                // 2번 무력화부터
                beaten = dp[i-1][0][2] + coins[i][0];
                neutralize = dp[i-1][0][1];
                dp[i][0][2] = max(beaten, neutralize);
                // 1번 무력화 구함
                beaten = dp[i-1][0][1] + coins[i][0];
                neutralize = dp[i-1][0][0];
                dp[i][0][1] = max(beaten, neutralize);
            } else {
                dp[i][0][1] = dp[i-1][0][1] + coins[i][0];
                dp[i][0][2] = dp[i-1][0][2] + coins[i][0];
            }
        }
        for (int i = 1; i < xlen; i++) {
            dp[0][i][0] = dp[0][i-1][0] + coins[0][i];
            if (coins[0][i] < 0) {
                int beaten, neutralize;
                
                // 2번 무력화부터
                beaten = dp[0][i-1][2] + coins[0][i];
                neutralize = dp[0][i-1][1];
                dp[0][i][2] = max(beaten, neutralize);
                // 1번 무력화 구함
                beaten = dp[0][i-1][1] + coins[0][i];
                neutralize = dp[0][i-1][0];
                dp[0][i][1] = max(beaten, neutralize);
            } else {
                dp[0][i][1] = dp[0][i-1][1] + coins[0][i];
                dp[0][i][2] = dp[0][i-1][2] + coins[0][i];
            }
        }
        int cur_coin;
        int max_2;
        int max_1;
        for (int i = 1; i < ylen; i++) {
            for (int j = 1; j < xlen; j++) {
                cur_coin = coins[i][j];
                dp[i][j][0] = max(dp[i-1][j][0], dp[i][j-1][0]) + cur_coin;
                if (coins[i][j] < 0) {
                    // 2번 무력화부터
                    max_2 = max(dp[i-1][j][2], dp[i][j-1][2]) + cur_coin;
                    max_1 = max(dp[i-1][j][1], dp[i][j-1][1]);
                    dp[i][j][2] = max(max_2, max_1);
                    // 1번 무력화 구함
                    max_2 = max(dp[i-1][j][1], dp[i][j-1][1]) + cur_coin;
                    max_1 = max(dp[i-1][j][0], dp[i][j-1][0]);
                    dp[i][j][1] = max(max_2, max_1);
                } else {
                    dp[i][j][1] = max(dp[i-1][j][1], dp[i][j-1][1]) + cur_coin;
                    dp[i][j][2] = max(dp[i-1][j][2], dp[i][j-1][2]) + cur_coin;
                }
            }
        }

        return max(dp[ylen-1][xlen-1][0], max(dp[ylen-1][xlen-1][1], dp[ylen-1][xlen-1][2]));
    }
};