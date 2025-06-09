class Solution {
private:
    set<string> wordSet;


    bool is_not_in_set(string s) {
        return this->wordSet.find(s) == this->wordSet.end();
    }

    bool dp(string s) {
        if (s.length() == 0) {
            return true;
        }
        for (int i = 1; i <= s.length(); i++) {

            // "catsadsa" -> "c" , "ca", "cat" .. 해서 해당 단어가 set에 있는지부터 확인해야 함.
            string sub = s.substr(0, i);
            if (this->is_not_in_set(sub)) {
                continue;
            }

            string remain = s.substr(i);
            if (remain.length() == 0) {
                return true;
            }
            if (this->dp(remain)) {
                this->wordSet.insert(s);
                return true;
            }
        }
        return false;
    }

public:
    bool wordBreak(string s, vector<string>& wordDict) {

        for (auto& word : wordDict) {
            this->wordSet.insert(word);
        }

        int res = this->dp(s);
        return res;
    }
};