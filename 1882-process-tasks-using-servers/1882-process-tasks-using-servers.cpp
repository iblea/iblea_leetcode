class Solution {
    using P = pair<long long, int>; // {weight / end_time, server_index}
    vector<int> *servers;
    priority_queue<P, vector<P>, greater<P>> free; // 유휴 서버
    priority_queue<P, vector<P>, greater<P>> busy; // 작업중인 서버

    void move_busy_to_free(long long t) {
        if ((this->busy).empty()) return;

        while (!(this->busy).empty()) {
            auto [end_time, server_index] = (this->busy).top();
            if (end_time > t) break;

            (this->busy).pop();
            (this->free).push({(*(this->servers))[server_index], server_index});
        }
    }

public:
    vector<int> assignTasks(vector<int>& servers, vector<int>& tasks) {
        this->servers = &servers;

        vector<int> ans(tasks.size(), -1);

        // 큐에 데이터를 집어넣을 때, 우선 먼저 시간. 작업이 종료되는 시간이 먼저
        // 작업 시간이 같다면, 가중치가 높은 서버가 먼저.
        // 즉 우선순위 큐를 활용한다.

        // 그러면 각 정렬 기준을 2개로 잡고 가야한다는거임?
        /*
        0. 유휴 서버에 큐에는 가중치,인덱스 기반으로 현재 동작하지 않는 서버를 free큐에 모두 집어넣는다.
          - 즉, 최초에는 가중치 기반으로 유휴 서버에 모두 집어넣는다.

        1. t 시간에 끝나는 서버를 모두 busy 큐에서 빼서 free 큐에 넣는다.

        2. tasks[j] 를 가중치/인덱스 기반으로 free 큐에서 빼서 busy 큐에 넣는다.
          - busy 큐에 들어간 서버는 작업이 끝나는 시간(end_time)과 서버 인덱스를 기준으로 정렬한다.
          - free 큐에 데이터가 없을 경우, t를 busy의 top으로 이동시키고 1번을 우선 재반복해야 한다.
        3. 카운트를 재계산한다.
          - j를 1 증가시킨다.
          - t = max(t,j) 로 업데이트한다.
        */


        long long t = 0;
        for (size_t i = 0; i < servers.size(); i++) {
            this->free.push({servers[i], i});
        }

        for (size_t j = 0; j < tasks.size(); j++) {
            t = max(t, (long long)j);
            this->move_busy_to_free(t);
            if (this->free.empty()) {
                t = (this->busy).top().first;
                this->move_busy_to_free(t);
            }
            auto [weight, server_index] = (this->free).top();
            (this->free).pop();
            ans[j] = server_index;
            (this->busy).push({t + tasks[j], server_index});
        }

        return ans;
    }
};