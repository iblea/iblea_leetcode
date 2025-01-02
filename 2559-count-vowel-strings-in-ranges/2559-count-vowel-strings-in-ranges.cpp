class Solution {
public:
    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {

        bool alphabet[26] = {false,};
        alphabet['a' - 'a'] = true;
        alphabet['e' - 'a'] = true;
        alphabet['i' - 'a'] = true;
        alphabet['o' - 'a'] = true;
        alphabet['u' - 'a'] = true;

        vector<int> prefix_sum(words.size() + 1, 0);
        prefix_sum[0] = alphabet[words[0][0] - 'a'] && alphabet[words[0][words[0].length() - 1] - 'a'];
        for (int i = 1; i < words.size(); i++) {
            prefix_sum[i] = prefix_sum[i - 1];
            prefix_sum[i] += (alphabet[words[i][0] - 'a'] && alphabet[words[i][words[i].length() - 1] - 'a']);
        }

        vector<int> answer(queries.size(), 0);

        for (int i = 0; i < queries.size(); i++) {
            int li = queries[i][0];
            int ri = queries[i][1];
            if (li == 0) {
                answer[i] = prefix_sum[ri];
            } else {
                answer[i] = prefix_sum[ri] - prefix_sum[li - 1];
            }
        }
        return answer;
    }

};

