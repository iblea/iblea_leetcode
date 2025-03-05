class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int result = nums[0];
        int maxval = nums[0];
        int minval = nums[0];

        int curr;
        int cur_max;
        int cur_min;

        for (int i = 1; i < nums.size(); i++) {
            curr = nums[i];
            cur_max = max({curr, maxval * curr, minval * curr});
            cur_min = min({curr, maxval * curr, minval * curr});
            maxval = cur_max;
            minval = cur_min;
            // std::cout << curr << " maxval: " << maxval << ", minval: " << minval << std::endl;

            result = max(result, maxval);
        }

        return result;
    }
};