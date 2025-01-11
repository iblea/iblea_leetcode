class Solution {
public:
    string shiftingLetters(string s, vector<vector<int>>& shifts) {
        size_t slen = s.size();
        vector<int> shift_index(slen + 1, 0);

        int start, end, direction;
        for (vector<int>& shift : shifts) {
            start = shift[0];
            end = shift[1];
            direction = shift[2];
            if (direction == 1) {
                shift_index[start]++;
                shift_index[end+1]--;
            } else {
                shift_index[start]--;
                shift_index[end+1]++;
            }
        }

        vector<int> shift_count(slen, 0);
        int shift = 0;
        for (int i = 0; i < slen; i++) {
            shift += shift_index[i];
            shift_count[i] = shift;
        }

        string result = s;
        for (int i = 0; i < slen; i++) {
            shift = (s[i] - 'a' + shift_count[i]) % 26;
            if (shift < 0) {
                shift += 26;
            }
            result[i] = shift + 'a';
        }
        return result;
    }
};