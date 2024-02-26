class Solution {

    public String makeSpecialAddString(String s) {
        StringBuilder sb = new StringBuilder();
        for (char c : s.toCharArray()) {
            sb.append("@").append(c);
        }
        sb.append("@");
        return sb.toString();

    }
    public String longestPalindrome(String s) {
        if (s.length() <= 1) {
            return s;
        }

        String specialAddString = makeSpecialAddString(s);
        int maxLen = 1;
        String maxString = Character.toString(s.charAt(0));

        int sLen = specialAddString.length();
        int center = 0;
        int right = 0;
        // 최대 회문 문자열의 길이를 저장하는 배열
        int[] dp = new int[sLen];
        Arrays.fill(dp, 0);

        // 0번째 인덱스는 어차피 추가 회문 문자 없음
        for (int i = 1; i < sLen; i++) {
            /* 회문의 반복성을 활용한 dp 배열 채우기
             * 012345678
             * zadadadao
             * 001232100
             * 본 문자열은 adadadada 문자열이 ada부터 점진적으로 계속 회문됨.
             * 따라서 대칭적인 문자열이 지속적으로 존재.
             * i = 3, dp[3] = 2, center = 3, right = 5 (3 + 2)
             * i = 4, dp[4] = min(5 - 4, dp[2*3-4])
             * i = 4, dp[4] = min(1, dp[2] = 1)
             * i = 4, dp[4] = 3, center = 4, right = 7
             * i = 5, dp[5] = min(7 - 5, dp[2*4-5])
             * i = 5, dp[5] = min(2, dp[3] = 2)
             *
             * 012345678
             * zabcdcbao
             * 000030000
             * 본 문자열은 abcdcba 문자열이 될때까지 회문 문자열 없음.
             * 따라서 dp 배열이 모두 0으로 고정됨. (abcdcba 문자열이 나오기 전까지 대칭적인 문자열이 없음.)
             */
            if (i < right) {
                dp[i] = Math.min(right - i, dp[2 * center - i]);
            }

			while (i - dp[i] - 1 >= 0 && i + dp[i] + 1 < sLen &&
                specialAddString.charAt(i - dp[i] - 1) == specialAddString.charAt(i + dp[i] + 1)) {
                dp[i]++;
			}

            if (i + dp[i] > right) {
                center = i;
                right = i + dp[i];
            }

            if (dp[i] > maxLen) {
                maxLen = dp[i];
                maxString = specialAddString.substring(i - dp[i], i + dp[i] + 1).replace("@", "");
            }
        }

        return maxString;
    }
}
