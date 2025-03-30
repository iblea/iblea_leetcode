class Solution {
public:
    vector<int> partitionLabels(string s) {
        int n = s.length();
        vector<int> result;
        map<char, int> last_index;
        for (int i = 0; i < n; i++) {
            last_index[s[i]] = i;
        }

        int count = 0;
        int max_index = 0;
        for (int i = 0; i < n; i++) {
            max_index = max(max_index, last_index[s[i]]);
            count++;
            if (max_index == i) {
                result.push_back(count);
                count = 0;
            }
        }
        return result;
    }
};