class Solution {
public:
    int maximumCandies(vector<int>& candies, long long k) {
        sort(candies.begin(), candies.end());
        int n = candies.size();

        int min_candies = 0;
        int max_candies = candies[n - 1];

        int result = 0;
        while (min_candies <= max_candies) {
            int mid_candies = (max_candies + min_candies) / 2;
            if (mid_candies == 0) {
                if (min_candies != 0) {
                    break;
                }
                min_candies = 1;
                continue;
            }
            long long count = 0;
            for (int i = 0; i < n; i++) {
                count += candies[i] / mid_candies;
                if (count >= k) {
                    break;
                }
            }
            if (count >= k) {
                result = mid_candies;
                min_candies = mid_candies + 1;
            } else {
                max_candies = mid_candies - 1;
            }
        }
        return result;
    }
};