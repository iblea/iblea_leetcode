class Solution {
public:
    bool isArraySpecial(vector<int>& nums) {
        int size = nums.size();
        if (size == 1) return true;

        int ago = nums[0] % 2;
        for (int i = 1; i < size; i++) {
            if (nums[i] % 2 == ago) {
                return false;
            }
            ago = nums[i] % 2;
        }
        return true;
    }
};