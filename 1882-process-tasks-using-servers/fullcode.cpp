#include <gtest/gtest.h>
#include <iostream>
#include <iomanip>
#include <algorithm>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <queue>
#include <array>
#include <any>

using namespace std;


/* https://leetcode.com/problems/process-tasks-using-servers/
1882 | Medium |  Process Tasks Using Servers

You are given two 0-indexed integer arrays servers and tasks of lengths n and m respectively. servers[i] is the weight of the i^th server, and tasks[j] is the time needed to process the j^th task in seconds.
Tasks are assigned to the servers using a task queue. Initially, all servers are free, and the queue is empty.
At second j, the j^th task is inserted into the queue (starting with the 0^th task being inserted at second 0). As long as there are free servers and the queue is not empty, the task in the front of the queue will be assigned to a free server with the smallest weight, and in case of a tie, it is assigned to a free server with the smallest index.
If there are no free servers and the queue is not empty, we wait until a server becomes free and immediately assign the next task. If multiple servers become free at the same time, then multiple tasks from the queue will be assigned in order of insertion following the weight and index priorities above.
A server that is assigned task j at second t will be free again at second t + tasks[j].
Build an array ans of length m, where ans[j] is the index of the server the j^th task will be assigned to.
Return the array ans.

󰛨 Example 1:
	Input: servers = [3,3,2], tasks = [1,2,3,2,1,2]
	Output: [2,2,0,2,1,2]
	Explanation: Events in chronological order go as follows:
	- At second 0, task 0 is added and processed using server 2 until second 1.
	- At second 1, server 2 becomes free. Task 1 is added and processed using server 2 until second 3.
	- At second 2, task 2 is added and processed using server 0 until second 5.
	- At second 3, server 2 becomes free. Task 3 is added and processed using server 2 until second 5.
	- At second 4, task 4 is added and processed using server 1 until second 5.
	- At second 5, all servers become free. Task 5 is added and processed using server 2 until second 7.

󰛨 Example 2:
	Input: servers = [5,1,4,3,2], tasks = [2,1,2,4,5,2,1]
	Output: [1,4,1,4,1,3,2]
	Explanation: Events in chronological order go as follows: 
	- At second 0, task 0 is added and processed using server 1 until second 2.
	- At second 1, task 1 is added and processed using server 4 until second 2.
	- At second 2, servers 1 and 4 become free. Task 2 is added and processed using server 1 until second 4. 
	- At second 3, task 3 is added and processed using server 4 until second 7.
	- At second 4, server 1 becomes free. Task 4 is added and processed using server 1 until second 9. 
	- At second 5, task 5 is added and processed using server 3 until second 7.
	- At second 6, task 6 is added and processed using server 2 until second 7.

 Constraints:
	* servers.length == n
	* tasks.length == m
	* 1 <= n, m <= 2 * 10^5
	* 1 <= servers[i], tasks[j] <= 2 * 10^5

길이가 각각 n과 m이고 인덱스가 0부터 시작하는 정수 배열 servers와 tasks가 주어집니다. servers[i]는 i번째 서버의 가중치이고, tasks[j]는 j번째 작업을 처리하는 데 필요한 시간(초)입니다.
작업은 작업 큐를 통해 서버에 할당됩니다. 처음에는 모든 서버가 유휴 상태이고 큐는 비어 있습니다.
j초에 j번째 작업이 큐에 삽입됩니다(0번째 작업이 0초에 삽입되는 것부터 시작합니다). 유휴 서버가 있고 큐가 비어 있지 않은 동안에는 큐의 맨 앞에 있는 작업이 가중치가 가장 작은 유휴 서버에 할당되며, 가중치가 같으면 인덱스가 가장 작은 유휴 서버에 할당됩니다.
유휴 서버가 없고 큐가 비어 있지 않으면 서버가 유휴 상태가 될 때까지 기다린 뒤 즉시 다음 작업을 할당합니다. 여러 서버가 동시에 유휴 상태가 되면 큐에 있는 여러 작업이 위의 가중치 및 인덱스 우선순위에 따라 삽입된 순서대로 할당됩니다.
t초에 작업 j를 할당받은 서버는 t + tasks[j]초에 다시 유휴 상태가 됩니다.
길이가 m인 배열 ans를 만드십시오. 여기서 ans[j]는 j번째 작업이 할당될 서버의 인덱스입니다.
배열 ans를 반환하십시오.

󰛨 예제 1:
	입력: servers = [3,3,2], tasks = [1,2,3,2,1,2]
	출력: [2,2,0,2,1,2]
	설명: 시간 순서대로 발생하는 이벤트는 다음과 같습니다:
	- 0초에 작업 0이 추가되어 서버 2에서 1초까지 처리됩니다.
	- 1초에 서버 2가 유휴 상태가 됩니다. 작업 1이 추가되어 서버 2에서 3초까지 처리됩니다.
	- 2초에 작업 2가 추가되어 서버 0에서 5초까지 처리됩니다.
	- 3초에 서버 2가 유휴 상태가 됩니다. 작업 3이 추가되어 서버 2에서 5초까지 처리됩니다.
	- 4초에 작업 4가 추가되어 서버 1에서 5초까지 처리됩니다.
	- 5초에 모든 서버가 유휴 상태가 됩니다. 작업 5가 추가되어 서버 2에서 7초까지 처리됩니다.

󰛨 예제 2:
	입력: servers = [5,1,4,3,2], tasks = [2,1,2,4,5,2,1]
	출력: [1,4,1,4,1,3,2]
	설명: 시간 순서대로 발생하는 이벤트는 다음과 같습니다:
	- 0초에 작업 0이 추가되어 서버 1에서 2초까지 처리됩니다.
	- 1초에 작업 1이 추가되어 서버 4에서 2초까지 처리됩니다.
	- 2초에 서버 1과 서버 4가 유휴 상태가 됩니다. 작업 2가 추가되어 서버 1에서 4초까지 처리됩니다.
	- 3초에 작업 3이 추가되어 서버 4에서 7초까지 처리됩니다.
	- 4초에 서버 1이 유휴 상태가 됩니다. 작업 4가 추가되어 서버 1에서 9초까지 처리됩니다.
	- 5초에 작업 5가 추가되어 서버 3에서 7초까지 처리됩니다.
	- 6초에 작업 6이 추가되어 서버 2에서 7초까지 처리됩니다.

 제약 조건:
	* servers.length == n
	* tasks.length == m
	* 1 <= n, m <= 2 * 10^5
	* 1 <= servers[i], tasks[j] <= 2 * 10^5

 */

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
// @leet end


#define CLASS_NAME gtest_template

class CLASS_NAME: public ::testing::Test {
private:
    clock_t t0;
    clock_t t1;
public:
    Solution s;
protected:
    CLASS_NAME() { this->s = Solution(); }
    ~CLASS_NAME() override { }

    void SetUp() override { set_start_time(); }
    void TearDown() override { set_end_time(); get_duration_time(); }

    void set_start_time() {
        this->t0 = clock(); // or gettimeofday or whatever
    }
    void set_end_time() {
        this->t1 = clock(); // or gettimeofday or whatever
    }

    // 시간 관련 체크
    void get_duration_time() {
        double elapsedSec = (double)(this->t1 - this->t0) / (double)1000000;
        double elapsedMS = (double)(this->t1 - this->t0) / (double)1000;

        cout << setprecision(3) << fixed << endl << "Duration of Times : ";
        cout << elapsedMS << "ms, " << elapsedSec << "sec" << endl << endl;
    }
};

TEST_F(CLASS_NAME, __LINE__)
{
    vector<int> servers = {3,3,2};
    vector<int> tasks = {1,2,3,2,1,2};
    vector<int> expected = {2,2,0,2,1,2};
    EXPECT_EQ(this->s.assignTasks(servers, tasks), expected);
}

TEST_F(CLASS_NAME, __LINE__)
{
    vector<int> servers = {5,1,4,3,2};
    vector<int> tasks = {2,1,2,4,5,2,1};
    vector<int> expected = {1,4,1,4,1,3,2};
    EXPECT_EQ(this->s.assignTasks(servers, tasks), expected);
}


int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
