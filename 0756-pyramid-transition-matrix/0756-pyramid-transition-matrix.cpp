class Solution {
public:
    map<string, vector<char>> tops;  // "AB" → ['C', 'D']
    unordered_set<string> failed;    // 메모이제이션: 실패한 층 기록

    bool pyramidTransition(string bottom, vector<string>& allowed) {
        // allowed: list->map 형태로 변환해서 탐색 시간 단축
        for (const string& s : allowed) {
            string key = s.substr(0, 2);
            tops[key].push_back(s[2]);
        }

        return solve(bottom);
    }

    bool solve(string& cur) {
        if (cur.size() == 1) return true;

        // 이미 실패한 층이면 바로 false
        if (failed.count(cur)) return false;

        string next = "";
        if (buildNext(cur, next, 0)) return true;

        // 실패 기록
        failed.insert(cur);
        return false;
    }

    bool buildNext(string& cur, string& next, int pos) {
        // 한 층 완성 -> 그 층으로 다시 solve
        if (pos == cur.size() - 1) {
            return solve(next);
        }

        string key = cur.substr(pos, 2);
        if (tops.find(key) == tops.end()) return false;

        for (char c : tops[key]) {
            next.push_back(c);
            if (buildNext(cur, next, pos + 1)) return true;
            next.pop_back();  // backtrack
        }

        return false;
    }
};
