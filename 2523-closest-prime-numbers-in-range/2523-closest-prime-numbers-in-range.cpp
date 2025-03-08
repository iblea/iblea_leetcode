class Solution {
public:
    vector<int> closestPrimes(int left, int right) {
        // 에라토스테네스의 체?
        int diff = INT_MAX;
        vector<bool> isPrime(right + 1, true);
        // diff = min(diff, num2 - num1)
        // 소수를 찾아야 하는데 어떻게 찾음?
        isPrime[0] = isPrime[1] = false;
        int i;
        for (i = 2; i * i <= right; i++) {
            if (! isPrime[i]) continue;

            for (int j = i * i; j <= right; j += i) {
                isPrime[j] = false;
            }
        }

        vector<int> primes;
        int num1 = 0;
        int num2 = 0;
        vector<int> ans = {-1, -1};
        for (i = left; i <= right; i++) {
            if (! isPrime[i]) continue;

            num2 = i;
            i++;
            break;
        }

        int absval = 0;
        for (; i <= right; i++) {
            if (! isPrime[i]) continue;

            num1 = num2;
            num2 = i;
            absval = num2 - num1;
            if (absval < diff) {
                diff = absval;
                ans = {num1, num2};
            }
            i++;
        }
        return ans;
    }
};