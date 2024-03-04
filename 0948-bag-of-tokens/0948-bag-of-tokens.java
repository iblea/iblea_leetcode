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
