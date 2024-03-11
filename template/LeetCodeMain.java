// import java.util.*;

class Solution {
    public void print() {
        System.out.println("Hello World!");
    }
}





class LeetCodeMain {
    public static void main(String[] args) {
        testcase1();
    }

    public static void checkAnswer() {

        if (true) {
            System.out.println("Testcase is Passed!");
            System.out.println();
        } else {

            System.err.println("@@@@@@@@@@ Testcase is Failed! @@@@@@@@@@");
            System.err.println("failed testcase : " + Thread.currentThread().getStackTrace()[2].getMethodName());
            System.out.println();
        }

    }

    public static void testcase1() {

        checkAnswer();

    }
}