class Solution {
public:
    int jump(vector<int>& nums) {
        if (nums.size() == 1) return 0;
        if (nums.size() == 2) return 1;

        int target = nums.size() - 1;
        vector<int> memo(nums.size() - 1, 2147483647);
        for (int curr = nums.size() - 2; curr >= 0; curr--) {
            if (nums[curr] == 0) {
                continue;
            }
            for (int i = 1; i <= nums[curr]; i++) {
                if (curr + i >= target) {
                    memo[curr] = 0;
                    for (int j = curr + 1; j < memo.size(); j++) {
                        memo[j] = 1;
                    }
                    break;
                }
                memo[curr] = min(memo[curr], memo[curr + i]);
            }
            if (memo[curr] == 2147483647) {
                continue;
            }
            memo[curr]++;
        }
        // if (memo[0] == 2147483647) return -1;
        return memo[0];
    }
};
