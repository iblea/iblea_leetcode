class Solution {
public:
    int countPalindromicSubsequence(string s) {
        int alphabets[26] = {0,};
        int first_index[26] = {-1,};
        int last_index[26] = {-1,};
        size_t slen = s.size();
        char c;
        for (int i = 0; i < slen; i++) {
            c = s[i];
            alphabets[c - 'a']++;
            if (alphabets[c - 'a'] == 1) {
                first_index[c - 'a'] = i;
            }
            last_index[c - 'a'] = i;
        }

        int first_idx;
        int last_idx;
        int answer = 0;
        for (int i = 0; i < 26; i++) {
            if (alphabets[i] < 2) {
                continue;
            }
            first_idx = first_index[i];
            last_idx = last_index[i];
            bool visited[26] = {false,};
            for (int j = first_idx + 1; j < last_idx; j++) {
                if (visited[s[j] - 'a']) {
                    continue;
                }
                visited[s[j] - 'a'] = true;
                answer++;
            }
        }
        return answer;
    }
};