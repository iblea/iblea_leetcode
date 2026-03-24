class Solution {
private:
    static constexpr int MOD = 12345;
public:
    vector<vector<int>> constructProductMatrix(vector<vector<int>>& grid) {

        // 2차원 배열을 1차원 배열로 변환
        vector<int> arr;
        int y = grid.size();
        int x = grid[0].size();
        for (int i = 0; i < y; ++i) {
            for (int j = 0; j < x; ++j) {
                arr.push_back(grid[i][j]);
            }
        }
        size_t n = arr.size();

        vector<int> prefix(n, 1);
        vector<int> suffix(n, 1);
        for (size_t i = 1; i < n; ++i) {
            prefix[i] = (long long)prefix[i - 1] * arr[i - 1] % MOD;
            suffix[n-i-1] = (long long)suffix[n-i] * arr[n-i] % MOD;
        }

        vector<vector<int>> result(y, vector<int>(x, 0));
        for (int i = 0; i < y; ++i) {
            for (int j = 0; j < x; ++j) {
                result[i][j] = (prefix[i * x + j] * suffix[i * x + j]) % MOD;
            }
        }
        return result;
    }
};
