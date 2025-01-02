class Solution {
public:
    int maxScore(string s) {
        int max_score = 0;
        int zero_count = 0;
        int one_count = 0;
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == '1') {
                one_count++;
            }
        }

        int n = s.length() - 1;
        for (int l = 0; l < n; l++) {
            if (s[l] == '0') {
                zero_count++;
            } else {
                one_count--;
            }

            max_score = max(max_score, zero_count + one_count);
        }
        return max_score;
    }
};

