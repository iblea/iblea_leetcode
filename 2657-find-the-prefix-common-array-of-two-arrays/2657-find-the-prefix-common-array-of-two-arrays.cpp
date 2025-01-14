class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        size_t n = A.size();
        set<int> seta;
        vector<int> result(n, 0);

        seta.insert(A[0]);
        if (seta.find(B[0]) != seta.end()) {
            result[0]++;
        } else {
            seta.insert(B[0]);
        }

        for (int i = 1; i < n; i++) {
            result[i] = result[i-1];
            if (seta.find(B[i]) != seta.end()) {
                result[i]++;
            } else {
                seta.insert(B[i]);
            }
            if (seta.find(A[i]) != seta.end()) {
                result[i]++;
            } else {
                seta.insert(A[i]);
            }
        }
        return result;
    }
};