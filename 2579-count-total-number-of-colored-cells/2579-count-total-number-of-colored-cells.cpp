class Solution {
public:
    long long coloredCells(int n) {
        // 1, 5, 13, 25, 41
        // 1, 2, 3,  4,  5
        // 0, 4, 8, 12,  16

        long long sum = 1;
        long long diff = 4;
        for (int i = 1; i < n; i++) {
            sum += diff;
            diff += 4;
        }
        return sum;
    }
};