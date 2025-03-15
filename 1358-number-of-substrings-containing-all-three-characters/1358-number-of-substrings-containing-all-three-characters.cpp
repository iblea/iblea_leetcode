class Solution {
public:
    int numberOfSubstrings(string s) {
        int len = s.length();
        int count = 0;
        int a_count = 0;
        int b_count = 0;
        int c_count = 0;

        int left = 0;
        int right = 0;
        while (true) {
            while (right < len && !(a_count > 0 && b_count > 0 && c_count > 0)) {
                if (s[right] == 'a') a_count++;
                else if (s[right] == 'b') b_count++;
                else if (s[right] == 'c') c_count++;
                right++;
            }
            if (a_count > 0 && b_count > 0 && c_count > 0) {
                count += len - right + 1;
            }

            if (right >= len && left >= len) break;
            if (s[left] == 'a') a_count--;
            else if (s[left] == 'b') b_count--;
            else if (s[left] == 'c') c_count--;
            left++;
        }
        return count;
    }
};