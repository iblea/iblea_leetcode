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