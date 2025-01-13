class Solution {
public:
    bool isPrefixAndSuffix(const string& str1, const string& str2) {
        return str1.length() <= str2.length() && str1 == str2.substr(0, str1.length()) && str1 == str2.substr(str2.length() - str1.length());
    }
    int countPrefixSuffixPairs(vector<string>& words) {
        int count = 0;
        for (int i = 0; i < words.size(); i++) {
            for (int j = i + 1; j < words.size(); j++) {
                if (this->isPrefixAndSuffix(words[i], words[j])) {
                    count++;
                }
            }
        }

        return count;
    }
};