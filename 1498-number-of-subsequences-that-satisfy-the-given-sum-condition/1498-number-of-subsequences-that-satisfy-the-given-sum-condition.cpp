class Solution {
private:
    static const int MOD = 1000000007;
public:
    int numSubseq(vector<int>& nums, int target) {
        const int n = nums.size();
        const int last_idx = n - 1;
        sort(nums.begin(), nums.end());

        int left = 0, right = last_idx, result = 0;
        vector<long long> pow_array(n);
        pow_array[0] = 1;
        for (int i = 1; i < n; i++) {
            pow_array[i] = (pow_array[i - 1] * 2) % MOD;
        }
        while (left <= right) {
            if (nums[left] + nums[right] <= target) {
                result = (result + pow_array[right - left]) % MOD;
                left++;
            } else {
                right--;
            }
        }

        return result;
    }
};