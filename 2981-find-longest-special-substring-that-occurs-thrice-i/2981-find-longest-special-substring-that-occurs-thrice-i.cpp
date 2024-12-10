class Solution {
public:
    int maximumLength1(string s) {
        int n = s.size();
        int ago_answer = 0;
        int answer = 0;
        int end = 0;
        while (true) {
            for (int start = 0; start < n - end; start++) {
                string sub = s.substr(start, end + 1);
                int cnt = 0;
                for (int i = 0; i < n - end; i++) {
                    if (sub != s.substr(i, end + 1)) {
                        continue;
                    }

                    cnt++;
                    if (cnt >= 3) {
                        answer = end + 1;
                        break;
                    }
                }
                // 3번 이상 등장하는 특별 부분 문자열을 찾았다면 종료함.
                // 더 찾을 필요가 없음.
                if (ago_answer != answer) {
                    break;
                }
            }
            if (ago_answer == answer) {
                break;
            }
            ago_answer = answer;
            end++;
        }
        if (answer == 0) {
            return -1;
        }
        return answer;
    }

    int maximumLength(string s) {
        int n = s.size(), max_len = -1;

        for (int len = 1; len <= n; ++len) {
            unordered_map<string, int> freq;

            for (int i = 0; i <= n - len; ++i) {
                string sub = s.substr(i, len);

                bool is_special = true;
                for (int j = 1; j < len; ++j) {
                    if (sub[j] != sub[0]) {
                        is_special = false;
                        break;
                    }
                }

                if (is_special) {
                    freq[sub]++;
                    if (freq[sub] >= 3)
                        max_len = max(max_len, len);
                }
            }
        }

        return max_len;
    }
};

