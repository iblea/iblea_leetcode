class Solution {
public:
    bool check(vector<int>& nums) {

        int max_num = 0;
        int n = nums.size();
        for (int i = 1; i < n; i++) {
            if (max_num > 0 && nums[i] > max_num) {
                return false;
            }
            if (nums[i] >= nums[i-1]) {
                continue;
            }

            if (max_num <= 0) {
                max_num = nums[i-1];
                continue;
            }
            return false;
        }
        if (max_num <= 0) {
            if (nums[n-1] < nums[0]) {
                return false;
            }
        } else {
            if (nums[n-1] > nums[0]) {
                return false;
            }
        }
        return true;
    }
};