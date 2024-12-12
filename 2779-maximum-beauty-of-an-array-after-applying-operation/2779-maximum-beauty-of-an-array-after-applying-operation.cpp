class Solution {
public:
    int maximumBeauty(vector<int>& nums, int k) {
        vector<int> n(nums);
        sort(n.begin(), n.end());
        int similar = k * 2;
        size_t start = 0;
        size_t end = 1;
        size_t len = n.size();
        int ago_pos = -1;
        int answer = 0;
        // sliding window
        // k = 2 일때, 0부터 4까지, 1부터 5까지, 2부터 6까지 ....
        while (start < len) {
            if (end < len && n[end] <= n[start] + similar) {
                end++;
                continue;
            }
            // 넘으면
            int cnt = end - start;
            answer = max(answer, cnt);
            ago_pos = n[start];
            while (start < len and n[start] == ago_pos) {
                start++;
            }
            if (start >= end) {
                end = start + 1;
            }
        }
        return answer;
    }

    int maximumBeauty_1(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int similar = k * 2;
        int answer = 1;
        int ago_pos = -1;
        for (size_t i = 0; i < nums.size(); i++) {
            int pos = nums[i];
            if (pos == ago_pos) {
                continue;
            }
            int cnt = 1;
            for (size_t j = i + 1; j < nums.size(); j++) {
                if (nums[j] <= pos + similar) {
                    cnt++;
                } else {
                    break;
                }
            }
            if (cnt > answer) {
                answer = cnt;
            }
            ago_pos = pos;;
        }
        return answer;
    }
};

