class Solution {
public:

    string convert(string s, int numRows) {

        if (numRows == 1) return s;

        int n = s.size();
        int cycle = 2 * numRows - 2;
        string result;

        for (int i = 0; i < numRows; i++) {
            int sub_cycle = cycle - (i * 2);
            for (int j = 0; j + i < n; j += cycle) {
                result += s[j + i];
                // 첫 번째와마지막 행이 아니면 추가해야 함.
                if (i != 0 && i != numRows - 1) {
                    if (j + i + sub_cycle < n) {
                        result += s[j + i + sub_cycle];
                    }
                }
            }
        }
        return result;
    }
    string convert_answer(string s, int numRows) {
        if (numRows == 1) return s;

        int n = s.size();
        int cycle = 2 * numRows - 2;
        string result;

        for (int i = 0; i < numRows; i++) {
            for (int j = 0; j + i < n; j += cycle) {
                result += s[j + i];
                if (i != 0 && i != numRows - 1 && j + cycle - i < n) {
                    result += s[j + cycle - i];
                }
            }
        }
        return result;
    }
};
