class Solution {
public:
    long long countBadPairs(vector<int>& nums) {
        // 2->1
        // 3->3
        // 4->6  4*3/2
        // 5->10 5*4/2
        // 6->15 6*5/2
        int nlen = nums.size();
        long long total_nums = (long long)nlen * (nlen - 1) / 2;
        unordered_map<long long, int> diff_map;
        long long good_pairs = 0;
        // j - i == nums[j] - nums[i]
        // nums[j] - j == nums[i] - i
        // -> nums[i] - i 가 같은 값이면 좋은 쌍임.
        // 따라서 전체 쌍에서 좋은 쌍을 빼서 나쁜 쌍을 구하면 된다.
        for (int i = 0; i < nlen; i++) {
            long long diff = nums[i] - i;
            if (diff_map.find(diff) != diff_map.end()) {
                good_pairs += diff_map[diff];
                diff_map[diff]++;
            } else {
                diff_map[diff] = 1;
            }
        }

        return total_nums - good_pairs;
    }
};