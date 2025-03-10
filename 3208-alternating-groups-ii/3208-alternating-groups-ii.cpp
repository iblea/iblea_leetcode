class Solution {
public:
    int numberOfAlternatingGroups(vector<int>& colors, int k) {

        int n = colors.size();
        int count = 0;
        int tmp = n - 1;
        vector<int> diff(n);

        for (int i = 0; i < tmp; i++) {
            diff[i] = colors[i] != colors[i + 1] ? 1 : 0;
        }
        diff[tmp] = colors[tmp] != colors[0] ? 1 : 0;
        // k = 3 이면, diff 합계가 2가 되어야 함.
        int expected = k - 1;
        int diff_sum = 0;
        for (int i = 0; i < expected; i++) {
            diff_sum += diff[i];
        }

        for (int i = 0; i < tmp; i++) {
            diff_sum = diff_sum - diff[i] + diff[(i + k - 1) % n];
            if (diff_sum == expected) {
                count++;
            }
        }
        return count;
    }
};