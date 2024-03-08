import java.util.*;

class Solution {
    public boolean canConstruct(String ransomNote, String magazine) {

        int[] magazineCount = new int[26];
        Arrays.fill(magazineCount, 0);
        for (char c : magazine.toCharArray()) {
            magazineCount[c - 'a']++;
        }

        for (char c : ransomNote.toCharArray()) {
            if (magazineCount[c - 'a'] == 0) {
                return false;
            }
            magazineCount[c - 'a']--;
        }
        return true;
    }
}




class LeetCodeMain {
    public static void main(String[] args) {
        testcase1();
        testcase2();
        testcase3();
    }

    public static void checkAnswer(boolean result, boolean expected) {
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
        String ransomNote = "a";
        String magazine = "b";

        final boolean result = new Solution().canConstruct(ransomNote, magazine);
        final boolean expected = false;

        checkAnswer(result, expected);
    }

    public static void testcase2() {
        String ransomNote = "aa";
        String magazine = "bb";

        final boolean result = new Solution().canConstruct(ransomNote, magazine);
        final boolean expected = false;

        checkAnswer(result, expected);
    }

    public static void testcase3() {
        String ransomNote = "aa";
        String magazine = "aab";

        final boolean result = new Solution().canConstruct(ransomNote, magazine);
        final boolean expected = true;

        checkAnswer(result, expected);
    }

}