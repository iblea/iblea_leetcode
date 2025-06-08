class Solution {
public:
    vector<int> lexicalOrder(int n) {
        vector<int> result(n);
        int current = 1;

        for (int i = 0; i < n; i++) {
            result[i] = current;
            // 1, 10, 100, 1000, 1001, 1002 ... 1009, 101, 1010, 1011 ...
            if (current * 10 <= n) {
                current *= 10;
                continue;
            }
            // n = 13, { 1, 10, 11, 12, 13, 14? , 2, 3 ... }
            while (current % 10 == 9 || current >= n) {
                current /= 10;
            }
            current++;
        }
        return result;
    }
};