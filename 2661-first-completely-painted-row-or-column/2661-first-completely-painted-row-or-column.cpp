class Solution {
public:
    int firstCompleteIndex(vector<int>& arr, vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();
        int total = m * n;
        vector<pair<int, int>> matpos(total + 1, {0, 0});
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                matpos[mat[i][j]] = {i, j};
            }
        }

        vector<int> rowcnt(m, 0); // rowcnt[i] == n
        vector<int> colcnt(n, 0); // colcnt[i] == m
        pair<int, int> pos;
        int i = 0;
        for (i = 0; i < total; i++) {
            pos = matpos[arr[i]];
            rowcnt[pos.first]++;
            colcnt[pos.second]++;
            if (rowcnt[pos.first] == n || colcnt[pos.second] == m) {
                break;
            }
        }
        return i;
    }
};