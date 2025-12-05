class Solution {
public:
    int countCollisions_for(string directions) {
        int totalR = 0;
        int totalL = 0;

        for (int i = 0; i < directions.size(); ++i) {
            if (directions[i] == 'R') {
                totalR++;
            } else if (directions[i] == 'L') {
                totalL++;
            }
        }
        for (int i = 0; i < directions.size(); ++i) {
            if (directions[i] != 'L') {
                break;
            }
            totalL--;
        }
        for (int i = directions.size() - 1; i >= 0; --i) {
            if (directions[i] != 'R') {
                break;
            }
            totalR--;
        }
        return (totalR + totalL);
    }
    // use two pointers
    int countCollisions(string& directions) {
        int n = directions.size();
        int left = 0;
        int right = n - 1;

        while (left <= right && directions[left] == 'L') left++;
        while (left <= right && directions[right] == 'R') right--;

        int count = 0;
        for (int i = left; i <= right; i++) {
            if (directions[i] != 'S') count++;
        }
        return count;
    }
};
