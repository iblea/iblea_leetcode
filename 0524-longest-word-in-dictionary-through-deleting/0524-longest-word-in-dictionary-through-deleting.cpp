class Solution {
public:
    string findLongestWord(string s, vector<string>& dictionary) {

        string answer = "";
        for (string word: dictionary) {
            if (word.size() > s.size()) {
                continue;
            }
            int i = 0;
            for (char c : s) {
                if (i < word.size() && c == word[i]) {
                    i++;
                }
            }

            if (i == word.size()) {
                if (answer.size() < word.size()) {
                    answer = word;
                } else if (answer.size() == word.size() && answer > word) {
                    answer = word;
                }
            }
        }

        return answer;
    }
};
