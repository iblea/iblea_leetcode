"""
Solution Note

m == matrix.length
n == matrix[i].length
1 <= m, n <= 100
-100 <= matrix[i][j] <= 100
-10**5 <= k <= 10**5

다음에 다시 풀어보기 바람
"""

# Leet Code Solution
class Solution:
    def maxSumSubmatrix(self, matrix: List[List[int]], k: int) -> int:
        import numpy as np
        
        matrix = np.array(matrix, dtype=np.int32)
        # print(matrix)
        
        M,N = matrix.shape
        # print(M)
        # print(N)
        
        ret = float("-inf")
        
        CUM = np.zeros((M,N), dtype=np.int32)
        for shift_r in range(M):
            # print("shift_r : {}".format(shift_r))
            CUM[:M-shift_r] += matrix[shift_r:]
            # print(CUM)
            
            _CUM = np.zeros((M-shift_r,N), dtype=np.int32)
            # print(_CUM)
            # print("------------------")
            for shift_c in range(N):
                # print("shift_c : {}".format(shift_c))
                _CUM[:, :N-shift_c] += CUM[:M-shift_r,shift_c:]
                # print(_CUM)
                # print((_CUM<=k) & (_CUM>ret))
                tmp = _CUM[(_CUM<=k) & (_CUM>ret)]
                # print(tmp)
                if tmp.size:
                    ret = tmp.max()
                # print("ret : {}".format(ret))
                # print("==================")
            if ret == k:
                # print("")
                return ret
        
        # print("")
        return ret

