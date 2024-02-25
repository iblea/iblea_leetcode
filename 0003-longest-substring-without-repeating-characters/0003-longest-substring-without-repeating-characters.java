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