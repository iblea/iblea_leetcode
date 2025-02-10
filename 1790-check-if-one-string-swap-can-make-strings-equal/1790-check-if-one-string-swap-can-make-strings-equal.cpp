class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
        int diff_count = 0;
        int diff_idxs[2] = {-1, -1};
        int slen = s1.length();

        for (int i = 0; i < slen; i++) {
            if (s1[i] != s2[i]) {
                if (diff_count >= 2) {
                    return false;
                }
                diff_idxs[diff_count] = i;
                diff_count++;
            }
        }

        switch (diff_count) {
            case 0:
                return true;
            case 1:
                return false;
            case 2:
                return s1[diff_idxs[0]] == s2[diff_idxs[1]] && s1[diff_idxs[1]] == s2[diff_idxs[0]];
        }
        return false;
    }
};