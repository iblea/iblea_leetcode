class Solution {
public:
    string clearStars(string s) {
        vector<char> result;
        vector<int> alphabet_count(26, 0);
        int removal_index = -1;
        for (char c : s) {
            if (c == '*') {
                for (int i = 0; i < 26; i++) {
                    if (alphabet_count[i] > 0) {
                        alphabet_count[i]--;
                        removal_index = i + 'a';
                        break;
                    }
                }
                for (int i = result.size() - 1; i >= 0; i--) {
                    if (result[i] == removal_index) {
                        result.erase(result.begin() + i);
                        break;
                    }
                }
                continue;
            }
            result.push_back(c);
            alphabet_count[c - 'a']++;
        }
        return string(result.begin(), result.end());
    }
};