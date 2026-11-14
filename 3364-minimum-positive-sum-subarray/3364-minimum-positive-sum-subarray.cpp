class Solution {
public:
    int minimumSumSubarray(vector<int>& nums, int l, int r) {
        int min_val = -1;

        for (int i = 0; i < nums.size(); i++) {
            int sum = 0;
            for (int j = i; j < nums.size(); j++) {
                sum += nums[j];
                if (j - i + 1 >= l && j - i + 1 <= r && sum > 0) {
                    if (min_val == -1 || sum < min_val) {
                        min_val = sum;
                    }
                }
            }
        }
        return min_val;
    }
};