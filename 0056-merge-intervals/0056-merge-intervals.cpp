class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), [](vector<int>& a, vector<int>& b) {
            if (a[0] == b[0]) {
                return a[1] < b[1];
            }
            return a[0] < b[0];
        });

        vector<vector<int>> result;
        vector<int> *last;
        int *last_end;
        result.push_back(intervals[0]);
        for (int i = 1; i < intervals.size(); i++) {
            last = &result.back();
            last_end = &last->back();
            if (*last_end >= intervals[i][0]) {
                *last_end = max(*last_end, intervals[i][1]);
            } else {
                result.push_back(intervals[i]);
            }
        }
        return result;
    }
};