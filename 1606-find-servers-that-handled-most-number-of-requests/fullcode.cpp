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


/* https://leetcode.com/problems/find-servers-that-handled-most-number-of-requests/
1606 | Hard | Find Servers That Handled Most Number of Requests

You have k servers numbered from 0 to k-1 that are being used to handle multiple requests simultaneously. Each server has infinite computational capacity but cannot handle more than one request at a time. The requests are assigned to servers according to a specific algorithm:
	* The i^th (0-indexed) request arrives.
	* If all servers are busy, the request is dropped (not handled at all).
	* If the (i % k)^th server is available, assign the request to that server.
	* Otherwise, assign the request to the next available server (wrapping around the list of servers and starting from 0 if necessary). For example, if the i^th server is busy, try to assign the request to the (i+1)^th server, then the (i+2)^th server, and so on.
You are given a strictly increasing array arrival of positive integers, where arrival[i] represents the arrival time of the i^th request, and another array load, where load[i] represents the load of the i^th request (the time it takes to complete). Your goal is to find the busiest server(s). A server is considered busiest if it handled the most number of requests successfully among all the servers.
Return a list containing the IDs (0-indexed) of the busiest server(s). You may return the IDs in any order.

󰛨 Example 1:
[img](https://assets.leetcode.com/uploads/2020/09/08/load-1.png)
	Input: k = 3, arrival = [1,2,3,4,5], load = [5,2,3,3,3] 
	Output: [1] 
	Explanation: 
	All of the servers start out available.
	The first 3 requests are handled by the first 3 servers in order.
	Request 3 comes in. Server 0 is busy, so it's assigned to the next available server, which is 1.
	Request 4 comes in. It cannot be handled since all servers are busy, so it is dropped.
	Servers 0 and 2 handled one request each, while server 1 handled two requests. Hence server 1 is the busiest server.

󰛨 Example 2:
	Input: k = 3, arrival = [1,2,3,4], load = [1,2,1,2]
	Output: [0]
	Explanation: 
	The first 3 requests are handled by first 3 servers.
	Request 3 comes in. It is handled by server 0 since the server is available.
	Server 0 handled two requests, while servers 1 and 2 handled one request each. Hence server 0 is the busiest server.

󰛨 Example 3:
	Input: k = 3, arrival = [1,2,3], load = [10,12,11]
	Output: [0,1,2]
	Explanation: Each server handles a single request, so they are all considered the busiest.

 Constraints:
	* 1 <= k <= 10^5
	* 1 <= arrival.length, load.length <= 10^5
	* arrival.length == load.length
	* 1 <= arrival[i], load[i] <= 10^9
	* arrival is strictly increasing.


0부터 k-1까지 번호가 매겨진 k개의 서버가 있으며, 이 서버들은 여러 요청을 동시에 처리하는 데 사용됩니다. 각 서버는 연산 능력이 무한하지만, 한 번에 두 개 이상의 요청을 처리할 수는 없습니다. 요청은 다음과 같은 특정 알고리즘에 따라 서버에 할당됩니다:
	* i번째(인덱스가 0부터 시작하는) 요청이 도착합니다.
	* 모든 서버가 사용 중이면, 해당 요청은 버려집니다(전혀 처리되지 않음).
	* (i % k)번째 서버가 사용 가능하면, 요청을 해당 서버에 할당합니다.
	* 그렇지 않으면, 요청을 다음으로 사용 가능한 서버에 할당합니다(필요한 경우 서버 목록의 끝에서 처음으로 돌아가 0번부터 다시 탐색합니다). 예를 들어, i번째 서버가 사용 중이면 (i+1)번째 서버에 요청 할당을 시도하고, 그다음에는 (i+2)번째 서버에 시도하는 식으로 진행합니다.
엄격하게 증가하는 양의 정수 배열 arrival이 주어지며, arrival[i]는 i번째 요청의 도착 시간을 나타냅니다. 또 다른 배열 load도 주어지며, load[i]는 i번째 요청의 부하(완료하는 데 걸리는 시간)를 나타냅니다. 목표는 가장 바쁜 서버(들)를 찾는 것입니다. 모든 서버 중에서 가장 많은 요청을 성공적으로 처리한 서버를 가장 바쁜 서버로 간주합니다.
가장 바쁜 서버(들)의 ID(인덱스가 0부터 시작하는)를 담은 리스트를 반환하십시오. ID는 어떤 순서로 반환해도 됩니다.

󰛨 예제 1:
[img](https://assets.leetcode.com/uploads/2020/09/08/load-1.png)
	입력: k = 3, arrival = [1,2,3,4,5], load = [5,2,3,3,3]
	출력: [1]
	설명:
	모든 서버는 사용 가능한 상태로 시작합니다.
	처음 3개의 요청은 처음 3개의 서버가 순서대로 처리합니다.
	요청 3이 들어옵니다. 서버 0이 사용 중이므로, 다음으로 사용 가능한 서버인 1에 할당됩니다.
	요청 4가 들어옵니다. 모든 서버가 사용 중이어서 처리할 수 없으므로 버려집니다.
	서버 0과 2는 각각 하나의 요청을 처리했고, 서버 1은 두 개의 요청을 처리했습니다. 따라서 서버 1이 가장 바쁜 서버입니다.

󰛨 예제 2:
	입력: k = 3, arrival = [1,2,3,4], load = [1,2,1,2]
	출력: [0]
	설명:
	처음 3개의 요청은 처음 3개의 서버가 처리합니다.
	요청 3이 들어옵니다. 서버 0이 사용 가능하므로 서버 0이 처리합니다.
	서버 0은 두 개의 요청을 처리했고, 서버 1과 2는 각각 하나의 요청을 처리했습니다. 따라서 서버 0이 가장 바쁜 서버입니다.

󰛨 예제 3:
	입력: k = 3, arrival = [1,2,3], load = [10,12,11]
	출력: [0,1,2]
	설명: 각 서버가 하나의 요청만 처리하므로, 모든 서버가 가장 바쁜 서버로 간주됩니다.

 제약 조건:
	* 1 <= k <= 10^5
	* 1 <= arrival.length, load.length <= 10^5
	* arrival.length == load.length
	* 1 <= arrival[i], load[i] <= 10^9
	* arrival은 엄격하게 증가합니다.

 */

// @leet start
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
    int k = 3;
    vector<int> arrival = {1,2,3,4,5};
    vector<int> load = {5,2,3,3,3};
    vector<int> expected = {1};
    EXPECT_EQ(this->s.busiestServers(k, arrival, load), expected);
}

TEST_F(CLASS_NAME, __LINE__)
{
    int k = 3;
    vector<int> arrival = {1,2,3,4};
    vector<int> load = {1,2,1,2};
    vector<int> expected = {0};
    EXPECT_EQ(this->s.busiestServers(k, arrival, load), expected);
}

TEST_F(CLASS_NAME, __LINE__)
{
    int k = 3;
    vector<int> arrival = {1,2,3};
    vector<int> load = {10,12,11};
    vector<int> expected = {0,1,2};
    EXPECT_EQ(this->s.busiestServers(k, arrival, load), expected);
}

TEST_F(CLASS_NAME, __LINE__)
{
    int k = 2;
    vector<int> arrival = {1,2,100};
    vector<int> load = {200,3,2};
    vector<int> expected = {1};
    EXPECT_EQ(this->s.busiestServers(k, arrival, load), expected);
}

TEST_F(CLASS_NAME, __LINE__)
{
    int k = 2;
    vector<int> arrival = {1,80,100};
    vector<int> load = {200,50,2};
    vector<int> expected = {0,1};
    EXPECT_EQ(this->s.busiestServers(k, arrival, load), expected);
}



int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
