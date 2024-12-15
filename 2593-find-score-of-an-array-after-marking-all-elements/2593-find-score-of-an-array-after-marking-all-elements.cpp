class Solution {
public:
    long long findScore(vector<int>& nums) {

        vector<tuple<int, int>> pos;
        for (size_t i = 0; i < nums.size(); i++) {
            // value, index
            tuple<int, int> t = make_tuple(nums[i], i);
            pos.push_back(t);
        }

        // 첫 번째값을 기준으로 정렬
        vector<bool> visited(nums.size(), false);
        sort(pos.begin(), pos.end(), [](tuple<int, int> a, tuple<int, int> b) {
            if (get<0>(a) == get<0>(b)) {
                return get<1>(a) < get<1>(b);
            }
            return get<0>(a) < get<0>(b);
        });

        long long answer = 0;
        for (size_t i = 0; i < pos.size(); i++) {
            int value = get<0>(pos[i]);
            int index = get<1>(pos[i]);
            if (visited[index]) {
                continue;
            }

            visited[index] = true;
            int left = index - 1;
            int right = index + 1;
            if (left >= 0 && !visited[left]) {
                visited[left] = true;
            }
            if (right < nums.size() && !visited[right]) {
                visited[right] = true;
            }
            answer += value;
        }
        return answer;
    }
};

