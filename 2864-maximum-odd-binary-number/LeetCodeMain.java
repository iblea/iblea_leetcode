// import java.util.*;

class Solution {
    public String maximumOddBinaryNumber(String s) {
        int one_char_length = -1;
        for (char c : s.toCharArray()) {
            if (c == '1') {
                one_char_length++;
            }
        }

        int zero_length = s.length() - one_char_length - 1;
        String result = "";

        while (one_char_length > 0) {
            result += "1";
            one_char_length--;
        }
        while (zero_length > 0) {
            result += "0";
            zero_length--;
        }
        result += "1";
        return result;
    }
}





class LeetCodeMain {
    public static void main(String[] args) {
        testcase1();
        testcase2();
    }

    public static void checkAnswer(String result, String expected) {
        System.out.println("result: " + result);
        System.out.println("expected: " + expected);

        if (result.equals(expected)) {
            System.out.println("Testcase is Passed!");
        } else {
            System.err.println("@@@@@@@@@@ Testcase is Failed! @@@@@@@@@@");
        }
        System.out.println();

    }

    public static void testcase1() {
        String input = "010";
        final String result = new Solution().maximumOddBinaryNumber(input);
        final String expected = "001";

        checkAnswer(result, expected);
    }

    public static void testcase2() {
        String input = "0101";
        final String expected = "1001";
        final String result = new Solution().maximumOddBinaryNumber(input);

        checkAnswer(result, expected);
    }

}