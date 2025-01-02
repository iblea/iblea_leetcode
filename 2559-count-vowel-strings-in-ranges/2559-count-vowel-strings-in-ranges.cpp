class Solution {
public:
    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {

        bool alphabet[26] = {false,};
        alphabet['a' - 'a'] = true;
        alphabet['e' - 'a'] = true;
        alphabet['i' - 'a'] = true;
        alphabet['o' - 'a'] = true;
        alphabet['u' - 'a'] = true;

        // stat: 0 - false, 1 - true, -1 - not visited
        vector<int> cache(words.size(), -1);
        vector<int> answer;

        for (vector<int> query : queries) {
            int li = query[0];
            int ri = query[1];
            int count = 0;
            for (int i = li; i <= ri; i++) {
                if (cache[i] == 1) {
                    count++;
                    continue;
                }
                if (cache[i] == 0) {
                    continue;
                }
                cache[i] = alphabet[words[i][0] - 'a'] && alphabet[words[i][words[i].length() - 1] - 'a'];
                count += cache[i];
            }
            answer.push_back(count);
        }
        return answer;
    }
};
