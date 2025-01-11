class Solution {
public:
    bool canConstruct(string s, int k) {
        if (s.length() < k) return false;
        int alphabet[26] = {0,};

        for (char c : s) {
            alphabet[c - 'a']++;
        }
        int odd_count = 0;
        for (int i = 0; i < 26; i++) {
            if (alphabet[i] % 2 == 1) odd_count++;
        }
        // 1, 즉 홀수 개가 몇 개가 있는지가 중요하다.
        // 홀수 개가 k와 같거나 작을 경우 회문을 만들 수 있고,
        // 홀수 개가 k보다 많을 경우 회문을 만들 수 없다.
        return odd_count <= k;
    }
};