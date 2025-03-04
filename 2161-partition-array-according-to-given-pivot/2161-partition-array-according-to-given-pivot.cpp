class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        vector<int> result(nums.size());
        int res_size = 0;
        vector<int> tmp(nums.size());
        int tmp_size = 0;

        int same_count = 0;

        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] < pivot) {
                result[res_size++] = nums[i];
            }
            else if (nums[i] == pivot) {
                same_count++;
            }
            else {
                tmp[tmp_size++] = nums[i];
            }
        }

        while (same_count > 0) {
            result[res_size++] = pivot;
            same_count--;
        }

        for (int i = 0; i < tmp_size; i++) {
            result[res_size++] = tmp[i];
        }
        return result;
    }
};