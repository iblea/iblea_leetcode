class Solution {
private:
    int binarySearch(vector<int>& potions, long long target) {
        int left = 0;
        int right = potions.size() - 1;

        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (potions[mid] < target) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        return left;
    }
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        sort(potions.begin(), potions.end());
        vector<int> answer;
        long long target;

        for (int spell : spells) {
            if (success % spell == 0) {
                target = success / spell;
            } else {
                target = success / spell + 1;
            }
            int index = binarySearch(potions, target);
            answer.push_back(potions.size() - index);
        }

        return answer;
    }
};