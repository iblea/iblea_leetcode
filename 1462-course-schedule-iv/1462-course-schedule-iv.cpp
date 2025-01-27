class Solution {
public:
    // DFS
    vector<bool> checkIfPrerequisite(int numCourses, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
        vector<set<int>> graph(numCourses, set<int>());

        for (const auto& prerequisite : prerequisites) {
            graph[prerequisite[0]].insert(prerequisite[1]);
        }

        set<int> *next;
        for (int i = 0; i < numCourses; ++i) {
            stack<int> s = stack<int>();
            for (int j : graph[i]) {
                s.push(j);
            }
            while(! s.empty()) {
                next = &graph[s.top()];
                s.pop();
                for (int j : *next) {
                    if (graph[i].count(j)) {
                        continue;
                    }
                    graph[i].insert(j);
                    s.push(j);
                }
            }
        }

        vector<bool> answer(queries.size(), false);
        for (int i = 0; i < queries.size(); ++i) {
            int u = queries[i][0];
            int v = queries[i][1];
            if (graph[u].count(v)) {
                answer[i] = true;
            }
        }
        return answer;
    }

    // Floyd-Warshall
    vector<bool> checkIfPrerequisite_Floyd_Warshall(int numCourses, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
        // Floyd-Warshall 알고리즘을 위한 인접 행렬 초기화
        vector<vector<bool>> reachable(numCourses, vector<bool>(numCourses, false));

        // 직접적인 선수 과목 관계 설정
        for (const auto& p : prerequisites) {
            reachable[p[0]][p[1]] = true;
        }

        // Floyd-Warshall 알고리즘
        for (int k = 0; k < numCourses; k++) {
            for (int i = 0; i < numCourses; i++) {
                for (int j = 0; j < numCourses; j++) {
                    reachable[i][j] = reachable[i][j] || (reachable[i][k] && reachable[k][j]);
                }
            }
        }

        // 쿼리에 대한 답변 생성
        vector<bool> answer;
        for (const auto& q : queries) {
            answer.push_back(reachable[q[0]][q[1]]);
        }

        return answer;
    }
};