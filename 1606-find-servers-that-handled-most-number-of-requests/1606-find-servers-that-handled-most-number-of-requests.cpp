class Solution {
public:
    vector<int> busiestServers(int k, vector<int>& arrival, vector<int>& load) {
        vector<int> result;

        using P = pair<int, int>; // end_time, server_id
        priority_queue<P, vector<P>, greater<P>> busy; // end_time, server_id
        set<int> free; // server_id

        // 초기 놀고잇는 서버 다 쳐넣어
        for (int i = 0; i < k; i++) {
            free.insert(i);
        }
        vector<int> count(k, 0);
        int max_count = 0;

        for (size_t i = 0; i < arrival.size(); i++) {
            // busy에서 끝난 서버들 free로 이동
            while (!busy.empty() && busy.top().first <= arrival[i]) {
                free.insert(busy.top().second);
                busy.pop();
            }
            
            // free.length == 0 이면, 모든 서버가 바쁘므로, 요청을 버린다.
            if (free.empty()) {
                continue;
            }

            // i % k 부터 시작해서, free에 있는 서버를 찾는다.
            auto it = free.lower_bound(i % k);
            if (it == free.end()) {
                // i % k 이후에 free에 있는 서버가 없으면, 0부터 시작해서 free에 있는 서버를 찾는다.
                // i%k 보다 큰 값 중에 없으면, 0부터 돌아가서 찾아야 하는데, 이 경우 .begin() 이 가장 작은 값이므로, .begin()을 사용한다.
                it = free.begin();
            }
            int server_id = *it;
            free.erase(it);
            count[server_id]++;
            max_count = max(max_count, count[server_id]);
            busy.push({arrival[i] + load[i], server_id});
        }

        for (int i = 0; i < k; i++) {
            if (count[i] == max_count) {
                result.push_back(i);
            }
        }
        return result;
    }
};