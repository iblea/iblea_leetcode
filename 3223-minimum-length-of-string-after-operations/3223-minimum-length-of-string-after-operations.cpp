class Solution {
public:
    int minimumLength(string s) {
        int slen = s.length();
        if (slen <= 2) return slen;

        int alphabets[26] = {0, };
        for (char c : s) {
            alphabets[c - 'a']++;
        }
        for (int i = 0; i < 26; i++) {
            if (alphabets[i] >= 3) {
                while (alphabets[i] >= 3) {
                    alphabets[i] -= 2;
                }
            }
        }
        int result = 0;
        for (int i = 0; i < 26; i++) {
            result += alphabets[i];
        }
        return result;
    }
};