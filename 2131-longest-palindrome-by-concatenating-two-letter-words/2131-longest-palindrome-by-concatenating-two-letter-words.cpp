class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        map<string, int> word_count;
        int only_onepair = 0;

        for (auto &word : words) {
            if (word_count.find(word) == word_count.end()) {
                word_count[word] = 1;
            } else {
                word_count[word]++;
            }
        }

        int count = 0;
        // word_count의 키를 순회한다.
        for (auto &word : word_count) {
            if (word.first[0] == word.first[1]) {
                if (only_onepair == 0 && word.second % 2 != 0) {
                    only_onepair = 1;
                }
                count += (word.second / 2) * 2;
                continue;
            } else {
                if (word.second == 0) {
                    continue;
                }
                string reverse_key = string(1, word.first[1]) + string(1, word.first[0]);
                if (word_count.find(reverse_key) == word_count.end()) {
                    // 반대 키를 못찾으면 스킵
                    continue;
                }
                int min_count = min(word.second, word_count[reverse_key]);
                count += (min_count * 2);
                word_count[word.first] = 0;
                word_count[reverse_key] = 0;
            }
        }

        return (count * 2) + (only_onepair * 2);
    }
};