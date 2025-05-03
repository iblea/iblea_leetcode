class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        // 음수 * 음수
        // 양수 * 양수

        int n = nums.size();
        int first = n - 2;
        int second = n - 1;
        long long max_value = 0;
        long long minus;
        long long value;

        for (int i = 0; i < first; i++) {
            for (int j = i + 1; j < second; j++) {
                minus = nums[i] - nums[j];
                for (int k = j + 1; k < n; k++) {
                    value = minus * nums[k];
                    max_value = max(max_value, value);
                }
            }
        }

        return max_value;
    }
};