import java.util.*;

class Solution {
    public int lengthOfLongestSubstring(String s) {
        HashSet<Character> set = new HashSet<>();
        int maxLength = 0;
        int l = 0;

        for (int r = 0; r < s.length(); r++) {
            if (set.contains(s.charAt(r)) == false) {
                set.add(s.charAt(r));
                maxLength = Math.max(maxLength, r - l + 1);
                continue;
            }

            while (s.charAt(l) != s.charAt(r)) {
                set.remove(s.charAt(l));
                l++;
            }

            set.remove(s.charAt(l));
            l++;
            set.add(s.charAt(r));
        }

        return maxLength;
    }
}


class LeetCodeMain {
    public static void main(String[] args) {
        testcase1();
        testcase2();
        testcase3();
    }

    public static void checkAnswer(int result, int answer) {
        System.out.println("result: " + result);
        System.out.println("answer: " + answer);

        if (result == answer) {
            System.out.println("Testcase is Passed!");
        } else {
            System.out.println("@@@@@@@@@@ Testcase is Failed! @@@@@@@@@@");
        }
        System.out.println();
    }

    public static void testcase1() {
        String s = "abcabcbb";
        int result = new Solution().lengthOfLongestSubstring(s);
        final int answer = 3;

        checkAnswer(result, answer);
    }

    public static void testcase2() {
        String s = "bbbbb";
        int result = new Solution().lengthOfLongestSubstring(s);
        final int answer = 1;

        checkAnswer(result, answer);
    }

    public static void testcase3() {
        String s = "pwwkew";
        int result = new Solution().lengthOfLongestSubstring(s);
        final int answer = 3;

        checkAnswer(result, answer);
    }
}
