class Solution {
public:
    vector<int> getFinalState(vector<int>& nums, int k, int multiplier) {

        // nums 배열을복사
        vector<int> result = nums;
        // 우선순위 큐를 사용해 value와 해당 index를 저장한다.
        // 우선순위 큐는 첫 번째 인덱스의 값이 작은 순서대로 정렬된다.
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

        for (int i = 0; i < nums.size(); i++) {
            pq.push({nums[i], i});
        }

        // int min_val;
        for (int i = 0; i < k; i++) {
            auto [value, index] = pq.top();
            // min_val = value;
            pq.pop();
            // 최소값을 찾아 곱한 뒤 다시 우선순위 큐에 넣는다.
            // 이후 이를 배열에도 반영한다.
            pq.push({value * multiplier, index});
            result[index] = value * multiplier;

            #if 0
            // 우선순위 큐에 있는 최소값이 같은 경우 반복적으로 처리한다.
            while (!pq.empty() && pq.top().first == min_val) {
                auto [value, index] = pq.top();
                std::cout << pq.top().first << ", " << pq.top().second << std::endl;
                pq.pop();
                result[index] = value * multiplier;
                pq.push({value * multiplier, index});
            }
            #endif
        }
        return result;
    }
};

