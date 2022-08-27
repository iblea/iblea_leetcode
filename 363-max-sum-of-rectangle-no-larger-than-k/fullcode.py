#!/usr/bin/python3
import unittest
from typing import List


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



# python unit test
class UnitTest(unittest.TestCase):

    # 클래스 생성 시 1회 실행
    @classmethod
    def setUpClass(self):
        self.solution = Solution();

    # 클래스 소멸 시 1회 실행
    @classmethod
    def tearDownClass(self):
        pass

    # 테스트 케이스 전 실행
    def setUp(self):
        pass

    # 테스트 케이스 후 실행
    def tearDown(self):
        pass

    def test_case_normal_1(self):
        res = self.solution.maxSumSubmatrix(matrix = [[1,0,1],[0,-2,3]], k = 2)
        self.assertEqual(res, 2)

    def test_case_normal_2(self):
        res = self.solution.maxSumSubmatrix(matrix = [[2,2,-1]], k = 3)
        self.assertEqual(res, 3)



if __name__ == "__main__":
    # 스크립트 실행 시, 해당 부분 동작
    unittest.main(verbosity=0)
    pass
