class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        int n = strs.size();
        int m = strs[0].size();

        // arr[x] 로 끝나는 LIS
        vector<int> dp(m, 1);
        for (int j = 0; j < m; j++) {
            for (int i = 0; i < j; i++) {
                bool LIS = true;

                for (int k = 0; k < n; k++) {
                    if (strs[k][i] > strs[k][j]) {
                        LIS = false;
                        break;
                    }
                }
                if (LIS) {
                    dp[j] = max(dp[j], dp[i] + 1);
                }

            }
        }
        int max_keep = *max_element(dp.begin(), dp.end());
        return m - max_keep;
    }
};