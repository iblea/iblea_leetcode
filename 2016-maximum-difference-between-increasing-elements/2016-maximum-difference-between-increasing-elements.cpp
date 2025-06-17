class Solution {
public:
    int maximumDifference(vector<int>& nums) {
        int n = nums.size();
        int result = 0;
        int min_val = INT_MAX, max_val = 0;
        int min_idx = -1, max_idx = -1;

        for (int i = 0; i < n; i++) {
            if (nums[i] < min_val) {
                min_val = nums[i];
                min_idx = i;
                if (max_idx < min_idx) {
                    max_val = 0;
                    max_idx = -1;
                }
            }

            if (nums[i] > max_val) {
                max_val = nums[i];
                max_idx = i;
            }
            result = max(result, max_val - min_val);
        }
        return result == 0 ? -1 : result;
    }
};