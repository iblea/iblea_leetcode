class Solution {
public:
    int minDominoRotations(vector<int>& tops, vector<int>& bottoms) {
        int n = tops.size();

        int count[7] = {0};
        int top_count[7] = {0};
        int bottom_count[7] = {0};
        for (int i = 0; i < n; i++) {
            if (tops[i] == bottoms[i]) {
                count[tops[i]]++;

            } else {
                count[tops[i]]++;
                count[bottoms[i]]++;
            }
            top_count[tops[i]]++;
            bottom_count[bottoms[i]]++;
        }

        for (int i = 1; i <= 6; i++) {
            if (count[i] == n) {
                return n - max(top_count[i], bottom_count[i]);
            }
        }
        return -1;
    }
};