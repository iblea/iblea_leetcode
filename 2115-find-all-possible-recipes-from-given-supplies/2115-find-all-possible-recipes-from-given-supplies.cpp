class Solution {
public:
    vector<string> findAllRecipes(vector<string>& recipes, vector<vector<string>>& ingredients, vector<string>& supplies) {
        // 레시피를 만들기 위해 필요한 재료 개수를 저장
        unordered_map<string, int> inDegree;
        // 각 재료가 어떤 레시피의 재료로 사용되는지 저장
        unordered_map<string, vector<string>> graph;
        // 결과를 저장할 set (중복 방지)
        unordered_set<string> result;

        // 초기 진입 차수 설정
        for (int i = 0; i < recipes.size(); i++) {
            inDegree[recipes[i]] = ingredients[i].size();
            for (const string& ingredient : ingredients[i]) {
                graph[ingredient].push_back(recipes[i]);
            }
        }

        // 초기 재료들을 큐에 추가
        queue<string> q;
        for (const string& supply : supplies) {
            q.push(supply);
        }

        // BFS로 위상 정렬 수행
        while (!q.empty()) {
            string current = q.front();
            q.pop();

            // 현재 재료로 만들 수 있는 레시피들 확인
            for (const string& recipe : graph[current]) {
                inDegree[recipe]--;
                if (inDegree[recipe] == 0) {
                    result.insert(recipe);
                    q.push(recipe);
                }
            }
        }

        // 결과를 vector로 변환하여 반환
        return vector<string>(result.begin(), result.end());
    }
};