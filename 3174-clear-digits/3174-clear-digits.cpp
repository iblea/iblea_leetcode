class Solution {
public:
    string clearDigits(string s) {

        vector<int> strv;
        vector<int> numv;

        for (int i = 0; i < s.length(); i++) {
            if (isdigit(s[i])) {
                numv.push_back(i);
            } else {
                strv.push_back(i);
            }
        }

        for (int i = 0; i < numv.size(); i++) {
            int num = numv[i];
            s[num] = '?';
            // upper_bound는 같거나 큰 값을 찾는다. 따라서 찾은 값의 이전 값을 찾아 삭제한다.
            auto it = upper_bound(strv.begin(), strv.end(), num);
            if (it != strv.begin()) {
                --it;
                s[*(it)] = '?';
                strv.erase(it);
            }
        }
        s.erase(remove(s.begin(), s.end(), '?'), s.end());
        return s;
    }
};