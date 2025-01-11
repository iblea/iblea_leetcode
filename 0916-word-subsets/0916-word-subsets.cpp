class Solution {
    vector<char> get_char_count(const string& str) {
        vector<char> count(26, 0);
        for (char c : str) {
            count[c - 'a']++;
        }
        return count;
    }

    bool is_subset(const vector<char>& big, const vector<char>& small) {
        for (int i = 0; i < 26; i++) {
            if (big[i] >= small[i]) {
                continue;
            }
            return false;
        }
        return true;
    }

public:
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
        vector<string> answer;
        sort(words2.begin(), words2.end(), [](const string& a, const string& b) {
            return a.length() > b.length();
        });
        map<string, vector<char>> words2_map;
        for (string str : words2) {
            vector<char> count = this->get_char_count(str);
            bool is_subset = false;
            for (const auto& p : words2_map) {
                if (this->is_subset(p.second, count)) {
                    is_subset = true;
                    break;
                }
            }
            if (!is_subset) {
                words2_map[str] = count;
            }
        }

        for (string str : words1) {
            bool subset = true;
            vector<char> str_count = this->get_char_count(str);
            for (const auto& p : words2_map) {
                if (!this->is_subset(str_count, p.second)) {
                    subset = false;
                    break;
                }
            }
            if (subset) {
                answer.push_back(str);
            }
        }
        return answer;
    }
};