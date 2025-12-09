class Solution {
public:
    int specialTriplets_o_square_2(vector<int>& nums) {

        int for_check = nums.size() - 1;
        int result = 0;

        for (int i = 1; i < for_check; i++) {
            int find_val = nums[i] * 2;
            int left_count = 0;
            int right_count = 0;
            for (int left = 0; left < i; left++) {
                if (nums[left] == find_val) {
                    left_count++;
                }
            }
            for (int right = i + 1; right <= for_check; right++) {
                if (nums[right] == find_val) {
                    right_count++;
                }
            }
            long long count = (long long)left_count * (long long)right_count;
            result = (result + (int)(count % 1000000007)) % 1000000007;
        }
        return result;
    }

    int specialTriplets(vector<int>& nums) {
        const int MOD = 1e9 + 7;

        unordered_map<int, int> left_count, right_count;
        for (int num : nums) {
            right_count[num]++;
        }

        long long result = 0;
        for (int i = 0; i < nums.size(); i++) {
            int val = nums[i];
            int target = val * 2;
            right_count[val]--;
            long long count = (long long)left_count[target] * (long long)right_count[target];
            result = (result + count) % MOD;
            left_count[val]++;
        }

        return (int)(result);
    }
};