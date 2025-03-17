#define MAX_NUM 501
class Solution {
public:
    bool divideArray(vector<int>& nums) {
        int arr[MAX_NUM] = {0};
        int count = 0;
        int n = nums.size();

        for (int i = 0; i < n; i++) {
            if (arr[nums[i]] == 0) {
                arr[nums[i]]++;
                count++;
            } else {
                arr[nums[i]]--;
                count--;
            }

        }
        return count == 0;
    }
};