class Solution {
public:
    bool canBeValid(string s, string locked) {
        cout << "s: " << s << endl;
        size_t slen = s.size();
        if (slen % 2 == 1) return false;

        int open_count = 0;
        int close_count = 0;

        int total_count = 0;
        for (int i = 0; i < slen; i++) {
            if (locked[i] == '1') {
                if (s[i] == ')') close_count++;
            }
            total_count = i + 1;
            if (total_count - close_count < close_count) {
                return false;
            }
        }
        for (int i = slen - 1; i >= 0; i--) {
            if (locked[i] == '1') {
                if (s[i] == '(') open_count++;
            }
            total_count = slen - i;
            if (total_count - open_count < open_count) {
                return false;
            }
        }

        return true;
    }
};