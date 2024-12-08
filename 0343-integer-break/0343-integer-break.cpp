class Solution {
public:
    int integerBreak(int n) {

        // 2보다 작은 경우는 1을 반환
        if (n <= 2) return 1;

        // 3보다 작은 경우는 2를 반환
        if (n == 3) return 2;

        // 4보다 작은 경우는 4를 반환
        if (n == 4) return 4;


        // 5보다 큰 경우는 3으로 나누어서 곱을 계산
        // 3 으로 나누어서 곱을 계산한 값이 제일 큰 값

        // 3으로 나누어서 4가 나올 경우, 3 * 3 * 2 * 2 가 제일 큰 값

        if (n % 3 == 0) {
            return pow(3, n / 3);
        } else if (n % 3 == 1) {
            return 4 * pow(3, (n - 4) / 3);
        } else {
            return 2 * pow(3, (n - 2) / 3);
        }
    }
};

