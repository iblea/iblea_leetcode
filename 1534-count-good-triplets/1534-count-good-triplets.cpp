class Solution {
public:
    int countGoodTriplets(vector<int>& arr, int a, int b, int c) {
        int count = 0;
        int N = arr.size();
        int Na = N - 2;
        int Nb = N - 1;

        int Ai, Aj;
        for (int i = 0; i < Na; i++) {
            Ai = arr[i];
            for (int j = i + 1; j < Nb; j++) {
                Aj = arr[j];
                if (abs(Ai - Aj) > a) continue;
                for (int k = j + 1; k < N; k++) {
                    if (abs(Ai - arr[k]) > c) continue;
                    if (abs(Aj - arr[k]) > b) continue;
                    count++;
                }
            }
        }
        return count;
    }
};