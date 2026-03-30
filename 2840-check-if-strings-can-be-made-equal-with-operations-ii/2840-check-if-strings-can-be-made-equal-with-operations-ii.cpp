class Solution {
public:
    bool checkStrings(string s1, string s2) {
        // odd
        vector<int> odd(26, 0);
        // even
        vector<int> even(26, 0);

        size_t arrlen = s1.length();
        for (size_t i = 0; i < arrlen; i+=2) {
            even[s1[i] - 'a']++;
            even[s2[i] - 'a']--;
        }
        for (size_t i = 1; i < arrlen; i+=2) {
            odd[s1[i] - 'a']++;
            odd[s2[i] - 'a']--;
        }

        for (size_t i = 0; i < 26; i++) {
            if (odd[i] != 0 || even[i] != 0) {
                return false;
            }
        }
        return true;
    }
};
