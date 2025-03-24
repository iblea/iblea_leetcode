class Solution {
public:
    int countDays(int days, vector<vector<int>>& meetings) {
        sort(meetings.begin(), meetings.end(), [](vector<int>& a, vector<int>& b) {
            if (a[0] == b[0]) {
                return a[1] < b[1];
            }
            return a[0] < b[0];
        });

        vector<vector<int>> merged_meetings;
        for (int i = 0; i < meetings.size(); i++) {
            if (merged_meetings.empty() || merged_meetings.back()[1] < meetings[i][0]) {
                merged_meetings.push_back(meetings[i]);
            } else {
                merged_meetings.back()[1] = max(merged_meetings.back()[1], meetings[i][1]);
            }
        }

        int count = 0;
        for (int i = 0; i < merged_meetings.size(); i++) {
            count += merged_meetings[i][1] - merged_meetings[i][0] + 1;
        }
        if (count >= days) {
            return 0;
        }
        return days - count;
    }
};