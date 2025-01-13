class Solution {
public:
    bool canJump(vector<int>& nums) {
        if (nums.size() == 1) return true;
        if (nums[0] == 0) return false;
        if (nums.size() == 2) return true;
        int jump_max = nums.size() - 1;
        vector<bool> dp(jump_max, false);

        for (int i = jump_max - 1; i >= 0; i--) {
            for (int j = 1; j <= nums[i]; j++) {
                if (i + j >= jump_max) {
                    dp[i] = true;
                    break;
                }
                if (dp[i + j]) {
                    dp[i] = true;
                    break;
                }
            }
        }
        return dp[0];
    }
};