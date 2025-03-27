class Solution {
public:
    int minimumIndex(vector<int>& nums) {
        int n = nums.size();
        int dominant = 0;
        int dominant_count = 0;
        // counter로 nums 요소의 개수를 세고, 지배적 요소를 찾는다.
        unordered_map<int, int> counter;
        for (int num : nums) {
            counter[num]++;
        }
        for (auto [num, count] : counter) {
            if (count > n / 2) {
                if (dominant > 0) {
                    return -1;
                }
                dominant = num;
                dominant_count = count;
            }
        }
        if (dominant <= 0) {
            return -1;
        }

        int left = 0;
        int right = dominant_count;
        int m = n - 1;
        for (int i = 0; i < m; i++) {
            if (nums[i] == dominant) {
                left++;
                right--;
            }
            if ((left * 2 > i + 1) && (right * 2 > m - i)) {
                return i;
            }
        }

        return -1;
    }
};