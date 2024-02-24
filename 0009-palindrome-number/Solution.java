// import java.util.*;

class Solution {

    public boolean isPalindrome(int x) {
        if (x < 0) {
            return false;
        }
        if (x < 10) {
            return true;
        }

        String numberString = Integer.toString(x);
        int midLength = numberString.length() / 2;

        int left = 0;
        int right = numberString.length() - 1;

        for (int i = 0; i < midLength; i++) {
            if (numberString.charAt(left) != numberString.charAt(right)) {
                return false;
            }
            left++;
            right--;
        }

        return true;
    }



    public static void main(String[] args) {
        testcase1();
    }

    public static void checkAnswer() {
        System.out.println("Hello checkAnswer!");

        if (true) {
            System.out.println("Testcase is Passed!");
        } else {
            System.out.println("@@@@@@@@@@ Testcase is Failed! @@@@@@@@@@");
        }
        System.out.println();

    }

    public static void testcase1() {

        System.out.println("Hello TestCase1!");
        checkAnswer();
    }
}