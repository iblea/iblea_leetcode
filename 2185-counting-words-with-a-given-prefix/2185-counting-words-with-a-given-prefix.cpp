class Solution {
public:
    int prefixCount(vector<string>& words, string pref) {
        size_t pref_len = pref.length();
        int count = 0;
        for (const auto& word : words) {
            string substr = word.substr(0, pref_len);
            if (substr == pref) {
                count++;
            }
        }
        return count;
    }
};