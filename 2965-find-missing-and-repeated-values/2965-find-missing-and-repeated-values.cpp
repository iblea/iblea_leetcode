class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        int a = 0, b = 0;

        set<int> s = {};
        int n = grid.size();
        int value = 0;
        generate_n(inserter(s, s.begin()), n * n, [&value]() { value++; return value; });

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (s.erase(grid[i][j]) == 0) {
                    a = grid[i][j];
                }
            }
        }

        b = *s.begin();
        return vector<int>{a, b};
    }
};