class Solution {
public:
    long long distributeCandies(int n, int limit) {

        long long result = 0;
        int minval = min(n, limit);
        int other;
        for (int i = 0; i <= minval; i++) {
            other = n - i;
            if (other <= 2 * limit) {
                // 두 번째 아이가 받을 수 있는 캔디 개수의 범위
                // 최소 : max(0, other - limit) (세 번째 아이가 limit 개 받고 남은 것)
                // 최대 : min(other, limit) (두 번째 아이가 받을 수 있는 최대 개수)
                // 따라서 최대 - 최소 + 1
                result += min(other, limit) - max(0, other - limit) + 1;
            }
        }
        return result;
    }

};