class Solution {
private:
    // 인덱스 반환
    int lowerBound(const vector<int>& arr, int target) {
        int lo = 0;
        int hi = arr.size();
        while (lo <hi) {
            int mi = lo + (hi - lo) / 2;
            if (arr[mi] >= target) {
                hi = mi;
            } else {
                lo = mi + 1;
            }
        }
        return lo;
    }

public:
    int findTheDistanceValue(vector<int>& arr1, vector<int>& arr2, int d) {
        sort(arr2.begin(), arr2.end());

        // lowerbound: arr1[n] - d <= arr2[i] <= upperbound: arr1[n] + d

        int result = 0;
        for (int i = 0; i < arr1.size(); ++i) {
            int lower_idx = lowerBound(arr2, arr1[i] - d);
            if (lower_idx == arr2.size() || arr2[lower_idx] > arr1[i] + d) {
                result++;
            }
        }
        return result;
    }
};