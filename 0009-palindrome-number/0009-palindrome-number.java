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

}