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
