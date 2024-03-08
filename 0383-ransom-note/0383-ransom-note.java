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
