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


/*

https://leetcode.com/problems/count-zero-request-servers/
2747 | Medium |  Count Zero Request Servers

You are given an integer n denoting the total number of servers and a 2D 0-indexed integer array logs, where logs[i] = [server_id, time] denotes that the server with id server_id received a request at time time.

You are also given an integer x and a 0-indexed integer array queries.

Return a 0-indexed integer array arr of length queries.length where arr[i] represents the number of servers that did not receive any requests during the time interval [queries[i] - x, queries[i]].

Note that the time intervals are inclusive.

󰛨 Example 1:
	│ Input: n = 3, logs = [[1,3],[2,6],[1,5]], x = 5, queries = [10,11]
	│ Output: [1,2]
	│ Explanation: 
	│ For queries[0]: The servers with ids 1 and 2 get requests in the duration of [5, 10]. Hence, only server 3 gets zero requests.
	│ For queries[1]: Only the server with id 2 gets a request in duration of [6,11]. Hence, the servers with ids 1 and 3 are the only servers that do not receive any requests during that time period.

󰛨 Example 2:
	│ Input: n = 3, logs = [[2,4],[2,1],[1,2],[3,1]], x = 2, queries = [3,4]
	│ Output: [0,1]
	│ Explanation: 
	│ For queries[0]: All servers get at least one request in the duration of [1, 3].
	│ For queries[1]: Only server with id 3 gets no request in the duration [2,4].

 Constraints:
	* 1 <= n <= 10^5
	* 1 <= logs.length <= 10^5
	* 1 <= queries.length <= 10^5
	* logs[i].length == 2
	* 1 <= logs[i][0] <= n
	* 1 <= logs[i][1] <= 10^6
	* 1 <= x <= 10^5
	* x < queries[i] <= 10^6


https://leetcode.com/problems/count-zero-request-servers/
2747 | Medium |  Count Zero Request Servers (요청을 받지 않은 서버 수 세기)

서버의 총 개수를 나타내는 정수 n과 2차원 0-indexed 정수 배열 logs가 주어집니다. 여기서 logs[i] = [server_id, time]은 id가 server_id인 서버가 시각 time에 요청을 받았음을 의미합니다.

또한 정수 x와 0-indexed 정수 배열 queries가 주어집니다.

길이가 queries.length인 0-indexed 정수 배열 arr을 반환하세요. 여기서 arr[i]는 시간 구간 [queries[i] - x, queries[i]] 동안 요청을 하나도 받지 않은 서버의 수입니다.

시간 구간은 양 끝 값을 포함합니다.

󰛨 예제 1:
	│ 입력: n = 3, logs = [[1,3],[2,6],[1,5]], x = 5, queries = [10,11]
	│ 출력: [1,2]
	│ 설명: 
	│ queries[0]의 경우: id가 1과 2인 서버는 [5, 10] 구간에 요청을 받습니다. 따라서 요청을 하나도 받지 않은 서버는 서버 3뿐입니다.
	│ queries[1]의 경우: [6,11] 구간에 요청을 받은 서버는 id가 2인 서버뿐입니다. 따라서 해당 구간에 요청을 하나도 받지 않은 서버는 id가 1과 3인 서버뿐입니다.

󰛨 예제 2:
	│ 입력: n = 3, logs = [[2,4],[2,1],[1,2],[3,1]], x = 2, queries = [3,4]
	│ 출력: [0,1]
	│ 설명: 
	│ queries[0]의 경우: 모든 서버가 [1, 3] 구간에 요청을 한 번 이상 받습니다.
	│ queries[1]의 경우: [2,4] 구간에 요청을 받지 않은 서버는 id가 3인 서버뿐입니다.

 제약 조건:
	* 1 <= n <= 10^5
	* 1 <= logs.length <= 10^5
	* 1 <= queries.length <= 10^5
	* logs[i].length == 2
	* 1 <= logs[i][0] <= n
	* 1 <= logs[i][1] <= 10^6
	* 1 <= x <= 10^5
	* x < queries[i] <= 10^6
 */

// @leet start
class Solution {
public:
    vector<int> countServers(int n, vector<vector<int>>& logs, int x, vector<int>& queries) {
		vector<int> res = vector<int>(queries.size(), 0);
		sort(logs.begin(), logs.end(), [](const auto &a, const auto &b) {
			return a[1] < b[1];
		});
		vector<pair<int, int>> sq;
		for (size_t i = 0; i < queries.size(); i++) {
			sq.push_back({queries[i], i});
		}
		sort(sq.begin(), sq.end(), [](const auto &a, const auto &b) {
			return a.first < b.first;
		});

		int cnt = 0; 
		vector<int> server_cnt(n + 1, 0);
		size_t l = 0, r = 0;

		/*
		 * t = 5, x = 3 -> 2 ~ 5 초 사이의 서버를 구해야 하는데 중복을 빼야 함.
		 * [1,2], [1,3]
		 * 1 서버에 2초, 3 초 모두 요청이 들어옴.
		 * 이 때, 1 서버는 2초에 요청이 들어왔으므로, 3초에서는 카운트 증가가 안되어야 함.
		 * n개만큼 서버 개수를 만들어서
		 * 카운트를 올리기 전, server_cnt 가 0이면, cnt++ 한다.
		 * 이후, server_cnt[n]++; 한다.
		 * 그러면 2초에서 server_cnt[1] = 0 이라 cnt++ 되어 cnt = 1이 되지만,
		 * 3초에서는 server_cnt[1] = 1 이므로, cnt++되지 않는다.
		 *
		 * 반대로 뺄 때에는 server_cnt[n]--; 한 후, server_cnt[n] == 0 이면, cnt-- 한다.
		 */

		for (const auto &[q, idx] : sq ) {
			while (r < logs.size() && logs[r][1] <= q) {
				int server_id = logs[r][0];
				if (server_cnt[server_id] == 0) {
					cnt++;
				}
				server_cnt[server_id]++;
				r++;
			}
			while (l < logs.size() && logs[l][1] < q - x) {
				int server_id = logs[l][0];
				server_cnt[server_id]--;
				if (server_cnt[server_id] == 0) {
					cnt--;
				}
				l++;
			}
			res[idx] = n - cnt;
		}

		return res;
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
	vector<vector<int>> logs = {{1,3},{2,6},{1,5}};
	vector<int> queries = {10,11};
	int n = 3;
	int x = 5;
	vector<int> expected = {1,2};
    EXPECT_EQ(this->s.countServers(n, logs, x, queries), expected);
}

TEST_F(CLASS_NAME, __LINE__)
{
	vector<vector<int>> logs = {{2,4},{2,1},{1,2},{3,1}};
	vector<int> queries = {3,4};
	int n = 3;
	int x = 2;
	vector<int> expected = {0,1};
    EXPECT_EQ(this->s.countServers(n, logs, x, queries), expected);
}


int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
