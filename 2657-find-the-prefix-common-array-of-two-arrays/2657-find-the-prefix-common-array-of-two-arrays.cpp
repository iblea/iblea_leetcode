class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        int n = A.size();
        vector<int> count(n+1,-1);
        vector<int> C(n);

        int target;
        for (int i = 0 ; i < n; i++) {
            target = A[i];
            count[target] = i;
        }
        for (int i = 0; i < n; i++) {
            target = B[i];
            if (count[target] < i) {
                count[target] = i;
            }
        }

        int common = 0;
        for (int i = 0; i < n; i++) {
            if (count[A[i]] <= i) {
                common++;
            }
            if (A[i] != B[i] && count[B[i]] <= i) {
                common++;
            }
            C[i] = common;
        }

        return C;
        
    }

    vector<int> findThePrefixCommonArray2(vector<int>& A, vector<int>& B) {
        int n = A.size();
        vector<int> count(n + 1, 0);
        vector<int> C(n);
        int common = 0;

        for (int i = 0; i < n; i++) {
            if (++count[A[i]] == 2) common++;  // A[i] 등장 → 2면 공통
            if (++count[B[i]] == 2) common++;  // B[i] 등장 → 2면 공통
            C[i] = common;
        }
        return C;
    }

};
