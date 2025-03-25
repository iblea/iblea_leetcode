class Solution {
private:
    bool check(vector<pair<int, int>>& ranges) {
        sort(ranges.begin(), ranges.end(), [](const pair<int, int>& a, const pair<int, int>& b) {
            if (a.first == b.first) return a.second < b.second;
            return a.first < b.first;
        });
        int section = 0;
        int max_end = ranges[0].second;
        for (auto& range : ranges) {
            if (max_end <= range.first) {
                section++;
                if (section >= 2) {
                    return true;
                }
            }
            max_end = max(max_end, range.second);
        }
        return false;
    }

public:
    bool checkValidCuts(int n, vector<vector<int>>& rectangles) {

        vector<pair<int, int>> x_ranges;
        vector<pair<int, int>> y_ranges;

        for (auto& rect : rectangles) {
            x_ranges.push_back({rect[0], rect[2]});
            y_ranges.push_back({rect[1], rect[3]});
        }

        return check(x_ranges) || check(y_ranges);
    }
};