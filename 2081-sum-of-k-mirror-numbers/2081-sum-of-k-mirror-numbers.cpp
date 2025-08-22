class Solution {

    // k 자릿수의 펠린드롬 수를 생성하는 함수
    list<long long> generate_palindromes(int k) {
        list<long long> palindromes;

        if (k == 1) {
            for (int i = 1; i <= 9; i++) {
                palindromes.push_back(i);
            }
            return palindromes;
        }

        // 짝수와 홀수는 펠린드롬 생성이 살짝 다름.
        bool isOdd = (k % 2 == 1);
        int halfLength = (k + 1) / 2;  // 앞쪽 절반 길이

        // 앞쪽 절반의 시작값과 끝값 계산
        long long start = pow(10, halfLength - 1);
        long long end = pow(10, halfLength) - 1;

        for (long long half = start; half <= end; half++) {
            // 앞쪽 절반 자릿수를 통해 펠린드롬 수를 생성함.
            // k = 3
            // makePalindrome(10, 3, true) -> 101
            // makePalindrome(11, 3, true) -> 111
            // makePalindrome(12, 3, true) -> 121
            // ...

            // k = 4
            // makePalindrome(10, 3, true) -> 1001
            // makePalindrome(11, 3, true) -> 1111
            // makePalindrome(12, 3, true) -> 1221
            // ...
            long long palindrome = makePalindrome(half, k, isOdd);
            palindromes.push_back(palindrome);
        }

        return palindromes;
    }
    // 앞쪽 절반으로 전체 팰린드롬 만들기 (이 함수도 추가해야 함)
    long long makePalindrome(long long half, int totalLength, bool isOdd) {
        long long result = half;
        long long temp = half;

        if (isOdd) {
            temp /= 10; // 가운데 자리 제거
        }

        // 뒤쪽 절반을 앞쪽 절반의 역순으로 만들기
        while (temp > 0) {
            result = result * 10 + (temp % 10);
            temp /= 10;
        }

        return result;
    }

    // 십진수 숫자 num을 k진수로 변환하고, 변환된 수가 펠린드롬 수인지 판별하는 함수
    bool check_k_palindrome(long long num, int k) {
        if (num == 0) return true;

        long long original = num;
        long long reversed = 0;

        // k진법으로 뒤집기
        while (num > 0) {
            reversed = reversed * k + (num % k);
            num /= k;
        }

        return original == reversed;
    }

public:
    long long kMirror(int k, int n) {

        int count = 0;
        int digits = 1;
        long long result = 0;
        while (true) {
            list<long long> palindromes = generate_palindromes(digits);
            palindromes.sort();
            for (auto palindrome : palindromes) {
                if (check_k_palindrome(palindrome, k)) {
                    result += palindrome;
                    count++;
                    if (count >= n) {
                        return result;
                    }
                }
            }

            digits++;
        }
        return result;
    }
};