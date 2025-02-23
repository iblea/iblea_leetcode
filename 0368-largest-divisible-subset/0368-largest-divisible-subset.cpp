class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, 1);
        vector<int> prev(n, -1);
        vector<int> result;

        int max_len = 0;
        int max_index = 0;
        sort(nums.begin(), nums.end());

        for (int i = 1; i < n; i++) {
            for (int j = 0; j < i; j++) {
                if (nums[i] % nums[j] == 0 && dp[i] < dp[j] + 1) {
                    dp[i] = dp[j] + 1;
                    prev[i] = j;
                }
            }
            if (max_len < dp[i]) {
                max_len = dp[i];
                max_index = i;
            }
        }

        while (max_index != -1) {
            result.push_back(nums[max_index]);
            max_index = prev[max_index];
        }
        reverse(result.begin(), result.end());
        return result;
    };
};