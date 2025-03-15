class Solution {
    int n;
    vector<int> *nums;

private:
    bool check(int mid, int k) {
        int count = 0;
        for (int i = 0; i < this->n; i++) {
            if ((*this->nums)[i] <= mid) {
                count++;
                i++;
            }
        }
        return count >= k;
    }

public:
    int minCapability(vector<int>& nums, int k) {
        this->n = nums.size();
        this->nums = &nums;

        int left = *min_element(nums.begin(), nums.end());
        int right = *max_element(nums.begin(), nums.end());

        while (left < right) {
            int mid = (left + right) / 2;
            if (this->check(mid, k)) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        return left;
    }
};