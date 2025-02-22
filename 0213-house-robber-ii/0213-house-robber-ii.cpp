class Solution {
private:
    int dp(vector<int>& nums, int start, int end) {
        int n = end - start;

        vector<int> tmp(n, 0);
        tmp[0] = nums[start];
        tmp[1] = max(nums[start], nums[start + 1]);

        for (int i = 2; i < n; i++) {
            tmp[i] = max(tmp[i-1], tmp[i-2] + nums[i + start]);
        }
        return tmp[n-1];
    }
public:
    int rob(vector<int>& nums) {
        if (nums.size() == 1) return nums[0];
        if (nums.size() == 2) return max(nums[0], nums[1]);

        int n = nums.size();

        // 첫 번째 집을 털 경우, 마지막 집을 털 수 없고, 마지막 집을 털 경우, 첫 번째 집을 털 수 없는 점을 이용하여 두 가지 경우로 나누어 계산
        // 첫 번째 집부터 마지막 - 1 번째 집까지
        int result1 = dp(nums, 0, n - 1);
        // 두 번째 집부터 마지막 집까지
        int result2 = dp(nums, 1, n);

        return max(result1, result2);
    }
};