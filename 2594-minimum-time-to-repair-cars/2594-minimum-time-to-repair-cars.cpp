class Solution {
public:
    long long repairCars(vector<int>& ranks, int cars) {
        sort(ranks.begin(), ranks.end());

        long long left = 0;
        long long right = 1LL * ranks[ranks.size() - 1] * cars * cars;

        while (left < right) {
            long long mid = (left + right) / 2;

            long long count = 0;
            for (int rank : ranks) {
                count += sqrt(mid / rank);
            }

            if (count < cars) {
                left = mid + 1;
            } else {
                right = mid;
            }
        }

        return left;
    }

};