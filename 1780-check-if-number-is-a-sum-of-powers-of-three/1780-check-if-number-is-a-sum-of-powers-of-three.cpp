class Solution {
private:
    static const int MAX_POWER = 10000000;
    vector<int> powers;
    bool dp(int n, int idx) {
        if (n == 0) return true;
        if (n < 0) return false;
        if (idx >= this->powers.size()) return false;
        // int sum = 0;
        // for (int i = idx; i < this->powers.size(); i++) {
        //     sum += this->powers[i];
        // }
        // if (sum == n) return true;
        // if (sum > n) return false;

        if (dp(n - this->powers[idx], idx + 1)) return true;
        if (dp(n, idx + 1)) return true;
        return false;
    }
public:
    bool checkPowersOfThree(int n) {
        int power = 1;
        while (power <= this->MAX_POWER) {
            this->powers.insert(this->powers.begin(), power);
            power *= 3;
        }
        int i;
        for (i = 0; i < this->powers.size(); i++) {
            if (this->powers[i] == n) {
                return true;
            }
            if (this->powers[i] < n) {
                break;
            }
        }
        return dp(n, i);
    }
};