class Solution {
public:
    int findLHS(vector<int>& nums) {
        int max_length = 0;
        map<int, int> num_map;

        for (int num : nums) {
            num_map[num]++;
        }

        int cur_num;
        for (auto it = num_map.begin(); it != num_map.end(); it++) {
            cur_num = it->first;
            if (num_map.find(cur_num + 1) != num_map.end()) {
                max_length = max(max_length, it->second + num_map[cur_num + 1]);
            }
        }
        return max_length;
    }
};