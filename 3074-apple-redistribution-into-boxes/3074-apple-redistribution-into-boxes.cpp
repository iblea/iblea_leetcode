class Solution {
public:
    int minimumBoxes(vector<int>& apple, vector<int>& capacity) {
        int sum = 0;
        for (int a : apple) {
            sum += a;
        }

        sort(capacity.begin(), capacity.end(), greater<int>());

        for (int i = 0; i < capacity.size(); i++) {
            sum -= capacity[i];
            if (sum <= 0) {
                return i + 1;
            }
        }
        return capacity.size();
    }
};
