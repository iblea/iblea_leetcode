class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;

        int m = n - 2;
        for (int i = 0; i < m; i++) {
            if (nums[i] == 0) {
                nums[i] = 1;
                nums[i+1] = !(nums[i+1]);
                nums[i+2] = !(nums[i+2]);
                ans++;
            }
        }
        if (nums[n-1] != 1 || nums[n-2] != 1) {
            return -1;
        }
        return ans;
    }
};