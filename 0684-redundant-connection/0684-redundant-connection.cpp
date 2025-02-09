class Solution {
    vector<int> parent;

    int find_parent(int x) {

        // 반복문
        int result, top;
        stack<int> st;
        st.push(x);
        while (true) {
            top = st.top();
            if (this->parent[top] == top) {
                result = top;
                break;
            }
            st.push(this->parent[top]);
        }
        while (!st.empty()) {
            top = st.top();
            this->parent[top] = result;
            st.pop();
        }
        return result;

        // 재귀
        // if (this->parent[x] != x) {
        //     this->parent[x] = this->find_parent(this->parent[x]);
        // }
        // return this->parent[x];
    }

    bool union_set(int x, int y) {
        int xroot = this->find_parent(x);
        int yroot = this->find_parent(y);

        if (xroot == yroot) {
            return false;
        }

        this->parent[xroot] = yroot;
        return true;
    }
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {

        int nlen = edges.size();
        this->parent = vector<int>(nlen + 1, 0);
        // 자기 자신을 부모로 설정 (union-find 알고리즘의 부모 초기화)
        for (int i = 0; i < nlen; i++) {
            this->parent[i] = i;
        }

        for (const auto& edge : edges) {
            if (!this->union_set(edge[0], edge[1])) {
                return edge;
            }
        }
        return {};
    }
};