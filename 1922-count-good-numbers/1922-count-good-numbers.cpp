class Solution {
private:
    // 지수 모듈러 연산의 최적화 알고리즘
    // base^exp % mod
    // 예) 20^500 % 1007 -> modPow(20,500,1007)
    // 500 -> 111110100(2)
    // 2로 나눠가면서 짝짝홀(계산)짝홀(계산)홀(계산)홀(계산)홀(계산)홀(계산)
    // 과 같이 계산해 값을 구함
    long long modPow(long long base, long long exp, long long mod) {
        long long result = 1;
        while (exp > 0) {
            if (exp % 2 == 1) {
                result = (result * base) % mod;
            }
            base = (base * base) % mod;
            exp /= 2;
        }
        return result;
    };
public:
    int countGoodNumbers(long long n) {
        // 1,100,10000 -> 짝홀짝홀짝 (1,3,5...)
        // 10, 1000, 100000 -> 짝홀짝홀짝홀 (2,4,6...)
        long long mod = pow(10, 9) + 7;
        long long result = modPow(20, n / 2, mod);

        if (n % 2 != 0) {
            result *= 5;
            result %= mod;
        }

        return (int)result;
    }
};