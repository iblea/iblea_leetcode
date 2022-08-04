#!/usr/bin/python3
import unittest
from typing import List
from random import randint
from copy import deepcopy


"""
Solution Note

matrix[n][n]
n == matrix.length == matrix[i].length
1 <= n <= 300
-10^9 <= matrix[i][j] <= 10^9 ( 1billion )
1 <= k <= n * n

All the rows and columns of matrix are guaranteed to be sorted in non-decreasing order.
"""

from bisect import bisect_right

class Solution:
    # binary search solution
    def kthSmallest(self, matrix: List[List[int]], k: int) -> int:
        low, high = matrix[0][0], matrix[-1][-1]
        # print("k = {}\n".format(k))
        while (low < high):
            mid = low + ((high - low) // 2)
            # print("low = {}, high = {}, mid = {}".format(low, high, mid))
            smaller_than_cnt = 0
            for i in range(len(matrix)):
                res = bisect_right(matrix[i], mid)
                # print("[{}] - res : {}".format(i, res))
                smaller_than_cnt += res
                # smaller_than_cnt += bisect_right(matrix[i],mid)
            # print("")
            if smaller_than_cnt < k:
                low = mid + 1
            else:
                high = mid

        # print("")
        # print("")
        return low

    # sort solution
    def kthSmallest_sort(self, matrix: List[List[int]], k: int) -> int:
        lst_1dimension = []
        matrix_len_1d = len(matrix)
        for i in range(matrix_len_1d):
            for j in range(matrix_len_1d):
                lst_1dimension.append(matrix[i][j])
        
        lst_1dimension.sort()
        return lst_1dimension[k-1]

def pnt_array(arr2d):
    for arr in arr2d:
        print("[ ", end="")
        for i in arr:
            print("{:02d}".format(i), end=", ")
        print("\b\b ]")
    print("")

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
        matrix = [[1,5,9],[10,11,13],[12,13,15]]
        pnt_array(matrix)
        res = self.solution.kthSmallest(matrix = matrix, k = 8)
        self.assertEqual(res, 13)

    def test_case_normal_2(self):
        res = self.solution.kthSmallest(matrix = [[-5]], k = 1)
        self.assertEqual(res, -5)


if __name__ == "__main__":
    # 스크립트 실행 시, 해당 부분 동작
    unittest.main(verbosity=0)
    pass
