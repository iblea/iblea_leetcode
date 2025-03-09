class Solution {
public:
    int numberOfAlternatingGroups(vector<int>& colors, int k) {
        int count = 0;
        int color_size = colors.size();
        vector<int> diff(color_size);

        int tmp = color_size - 1;
        for (int i = 0; i < tmp; i++) {
            diff[i] = colors[i] != colors[i + 1] ? 1 : 0;
        }
        diff[tmp] = colors[tmp] != colors[0] ? 1 : 0;

        int diff_sum = 0;
        for (int i = 0; i < k - 1; i++) {
            diff_sum += diff[i];
        }

        // if (diff_sum == k - 1) {
        //     count = 1;
        // }

        for (int i = 0; i < color_size; i++) {
            diff_sum = diff_sum - diff[i] + diff[(i + k - 1) % color_size];
            if (diff_sum == k - 1) {
                count++;
            }
        }

        return count;
    }
};