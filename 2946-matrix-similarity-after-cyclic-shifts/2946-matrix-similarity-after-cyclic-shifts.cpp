class Solution {
public:
    bool areSimilar(vector<vector<int>>& mat, int k) {
        int m = mat.size();
        int n = mat[0].size();
        int modk = k%n;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (i % 2 == 0) {
                    // 왼쪽 순환 이동 공식은 (j+k)%n
                    if (mat[i][j] != mat[i][(j+modk)%n]) {
                        return false;
                    }
                } else {
                    // 오른쪽 순환 이동 공식은 (j+n-k)%n
                    if (mat[i][j] != mat[i][(j+n-modk)%n]) {
                        return false;
                    }
                }
            }
        }
        return true;
    }
};