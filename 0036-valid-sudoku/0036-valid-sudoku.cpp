class Solution {
private:
    static constexpr array<pair<int, int>, 9> three_by_three_box = {{
        {0, 0}, {0, 1}, {0, 2},
        {1, 0}, {1, 1}, {1, 2},
        {2, 0}, {2, 1}, {2, 2}
    }};
public:
    Solution() { }
    bool isValidSudoku(vector<vector<char>>& board) {

        // check row
        for (int i = 0; i < 9; i++) {
            set<int> s;
            for (int j = 0; j < 9; j++) {
                if (board[i][j] == '.') {
                    continue;
                }
                if (s.find(board[i][j]) != s.end()) {
                    return false;
                }
                s.insert(board[i][j]);
            }
        }

        for (int j = 0; j < 9; j++) {
            set<int> s;
            for (int i = 0; i < 9; i++) {
                if (board[i][j] == '.') {
                    continue;
                }
                if (s.find(board[i][j]) != s.end()) {
                    return false;
                }
                s.insert(board[i][j]);
            }
        }

        for (int row = 0; row < 9; row += 3) {

            for (int col = 0; col < 9; col += 3) {
                set<int> s;
                for (pair<int, int> pos : this->three_by_three_box) {
                    if (board[row + pos.first][col + pos.second] == '.') {
                        continue;
                    }
                    if (s.find(board[row + pos.first][col + pos.second]) != s.end()) {
                        return false;
                    }
                    s.insert(board[row + pos.first][col + pos.second]);
                }
            }
        }
        return true;
    }
};