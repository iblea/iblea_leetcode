class Solution {
public:
    int minZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        long long sums = 0;
        int q = queries.size();

        for (int num : nums) {
            sums += num;
        }
        if (sums <= 0) {
            return 0;
        }

        for (int i = 0; i < q; i++) {
            int l = queries[i][0];
            int r = queries[i][1];
            int val = queries[i][2];
            for (int j = l; j <= r; j++) {
                if (nums[j] <= 0) {
                    continue;
                }
                if (nums[j] - val < 0) {
                    sums -= nums[j];
                    nums[j] = 0;
                } else {
                    sums -= val;
                    nums[j] -= val;
                }
                if (sums <= 0) {
                    return i + 1;
                }
            }
        }
        return -1;
    }
};