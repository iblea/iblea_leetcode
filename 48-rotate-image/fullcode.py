#!/usr/bin/python3
import unittest
from typing import List


"""
Solution Note

n == matrix.length == matrix[i].length
1 <= n <= 20
-1000 <= matrix[i][j] <= 1000
"""

# Leet Code Solution
from copy import deepcopy
class Solution:
    def rotate(self, matrix: List[List[int]]) -> None:
        """
        Do not return anything, modify matrix in-place instead.
        """
        sqr_len = len(matrix)
        sqr_end = sqr_len - 1
        div = sqr_len - 2

        n = 0
        m = 0

        # 0 1 = 1 0
        # 1 2 = 2 1

        while True:
            print(n, m)
            tmp = matrix[n][m]
            # 0 1
            # 0 0
            matrix[n][m] = matrix[sqr_end-m][n]
            # 0 1 = 1 0
            # 0 0 = 2 0
            matrix[sqr_end-m][n] = matrix[sqr_end-n][sqr_end-m]
            # 1 0 = 2 1
            # 2 0 = 2 2
            matrix[sqr_end-n][sqr_end-m] = matrix[m][sqr_end-n]
            # 2 1 = 1 2
            # 2 2 = 0 2
            matrix[m][sqr_end-n] = tmp
            # 1 2 = 0 1
            # 0 2 = 0 0

            if m >= div:
                if n >= div:
                    # 5,5 사각형인데 2,2 이면 끝
                    break
                n += 1
                m = n
                div -= 1
            else:
                m += 1

    def rotate1(self, matrix: List[List[int]]) -> None:
        """
        Do not return anything, modify matrix in-place instead.
        """
        
        sqr_len = len(matrix)
        n = sqr_len - 1
        tmp = deepcopy(matrix)

        for i in range(sqr_len):
            for j in range(sqr_len):
                matrix[j][n-i] = tmp[i][j]

        # n,m
        # 0,0 -> 0,3
        # 0,1 -> 1,3
        # 0,2 -> 2,3
        # 0,3 -> 3,3

        # 1,0 -> 0,2
        # 1,1 -> 1,2
        # 1,2 -> 2,2
        # 1,3 -> 3,2

        # 2,0 -> 0,1
        # 2,1 -> 1,1
        # 2,2 -> 2,1
        # 2,3 -> 3,1

        # 3,0 -> 0,0
        # 3,1 -> 1,0
        # 3,2 -> 2,0
        # 3,3 -> 3,0

        return




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
        matrix = [[1,2,3],[4,5,6],[7,8,9]]
        self.solution.rotate(matrix)
        self.assertEqual(matrix, [[7,4,1],[8,5,2],[9,6,3]])

    def test_case_normal_2(self):
        matrix = [[5,1,9,11],[2,4,8,10],[13,3,6,7],[15,14,12,16]]
        self.solution.rotate(matrix)
        self.assertEqual(matrix, [[15,13,2,5],[14,3,4,1],[12,6,8,9],[16,7,10,11]])



if __name__ == "__main__":
    # 스크립트 실행 시, 해당 부분 동작
    unittest.main(verbosity=0)
    pass
