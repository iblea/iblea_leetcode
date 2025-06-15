class Solution {
public:
    int maxDiff(int num) {
        string s = to_string(num);
        string y_str = "";
        string x_str = "";
        int x, y;
        int n = s.size();

        int idx = -1;
        for (int i = 0; i < n; i++) {
            if (s[i] == '9') {
                continue;
            }
            idx = i;
            break;
        }
        if (idx >= 0) {
            char changed_num = s[idx];
            for (char c : s) {
                if (c == changed_num) {
                    x_str += '9';
                } else {
                    x_str += c;
                }
            }
            x = stoi(x_str);
        } else {
            x = num;
        }
        idx = -1;

        if (s[0] == '1') {
            for (int i = 1; i < n; i++) {
                if (s[i] == '0' || s[i] == '1') {
                    continue;
                }
                idx = i;
                break;
            }
        } else {
            idx = 0;
        }
        if (idx == 0) {
            char changed_num = s[idx];
            y_str = "1";
            for (int i = 1; i < n; i++) {
                if (s[i] == changed_num) {
                    y_str += '1';
                } else {
                    y_str += s[i];
                }
            }
            y = stoi(y_str);
        } else if (idx >= 1) {
            char changed_num = s[idx];
            for (char c : s) {
                if (c == changed_num) {
                    y_str += '0';
                } else {
                    y_str += c;
                }
            }
            y = stoi(y_str);
        } else {
            y = num;
        }

        return x - y;
    }
};