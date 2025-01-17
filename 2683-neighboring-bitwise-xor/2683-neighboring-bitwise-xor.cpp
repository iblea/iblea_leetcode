class Solution {
public:
    bool doesValidArrayExist(vector<int>& derived) {

        int result = 0;

        for (int n : derived) {
            result ^= n;
        }
        return result == 0;
    }
};