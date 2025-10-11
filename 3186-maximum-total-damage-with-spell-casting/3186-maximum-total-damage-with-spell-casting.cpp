class Solution {
public:
    long long maximumTotalDamage(vector<int>& power) {
        vector<long long> dp;
        sort(power.begin(), power.end());
        dp.push_back(power[0]);
        for (int i = 1; i < power.size(); i++) {
            if (power[i] == power[i-1]) {
                dp.push_back(dp.back() + power[i]);
                continue;
            }
            bool found = false;
            for (int j = i - 1; j >= 0; j--) {
                if (abs(power[i] - power[j]) > 2) {
                    dp.push_back(max(dp.back(), dp[j] + power[i]));
                    found = true;
                    break;
                }
            }
            if (!found) {
                dp.push_back(max(dp.back(), (long long)power[i]));
            }
        }

        return dp.back();
    }
};