class Solution {
public:
    string robotWithString(string s) {
        int n = s.length();

        // 각 위치에서 그 위치부터 끝까지의 최소 문자 계산
        vector<char> minSuffix(n);
        minSuffix[n-1] = s[n-1];
        for (int i = n-2; i >= 0; i--) {
            minSuffix[i] = min(s[i], minSuffix[i+1]);
        }

        string result = "";
        string t = "";  // 스택 역할
        int i = 0;  // s의 현재 인덱스

        while (i < n || !t.empty()) {
            // 스택이 비어있지 않고, 스택의 top이 앞으로 올 최소값보다 작거나 같으면 pop
            if (!t.empty() && (i >= n || t.back() <= minSuffix[i])) {
                result += t.back();
                t.pop_back();
                continue;
            }
            // 그렇지 않으면 s에서 문자를 가져와서 스택에 push
            t += s[i];
            i++;
        }

        return result;
    }
};