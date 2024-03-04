import java.util.*;

class Solution {
    public int bagOfTokensScore(int[] tokens, int power) {
        Arrays.sort(tokens);

        int left = 0;
        int right = tokens.length - 1;

        int max_score = 0;
        int current_score = 0;

        while (left <= right) {
            if (power >= tokens[left]) {
                power -= tokens[left];
                current_score++;
                left++;
                max_score = Math.max(max_score, current_score);
                continue;
            }
            if (current_score > 0) {
                power += tokens[right];
                current_score--;
                right--;
                continue;
            }

            break;
        }

        return max_score;
    }
}




class LeetCodeMain {
    public static void main(String[] args) {
        testcase1();
        testcase2();
        testcase3();
    }

    public static void checkAnswer(int result, int expected) {
        System.out.println("result: " + result);
        System.out.println("expected: " + expected);

        if (result == expected) {
            System.out.println("Testcase is Passed!");
        } else {
            System.err.println("@@@@@@@@@@ Testcase is Failed! @@@@@@@@@@");
        }
        System.out.println();

    }

    public static void testcase1() {
        int[] tokens = { 100 };
        int power = 50;

        final int result = new Solution().bagOfTokensScore(tokens, power);
        final int expected = 0;

        checkAnswer(result, expected);
    }

    public static void testcase2() {
        int[] tokens = { 100, 200 };
        int power = 150;

        final int result = new Solution().bagOfTokensScore(tokens, power);
        final int expected = 1;

        checkAnswer(result, expected);
    }

    public static void testcase3() {
        int[] tokens = { 100, 200, 300, 400 };
        int power = 200;

        final int result = new Solution().bagOfTokensScore(tokens, power);
        final int expected = 2;

        checkAnswer(result, expected);
    }
}