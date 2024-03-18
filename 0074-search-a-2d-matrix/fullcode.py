#!/usr/bin/python3
import unittest
from typing import List
from typing import Optional


"""
Solution Note

https://leetcode.com/problems/search-a-2d-matrix/

행렬에서 값이 존재하는지 대략 체크
대략 체크에서 걸렸으면 해당 행렬에서 이진 탐색
"""

# Leet Code Solution
class Solution:
    def searchMatrix(self, matrix: List[List[int]], target: int) -> bool:

        matrixIndex = self.getMatrix(matrix, target)
        if matrixIndex < 0:
            return False

        checkArr = matrix[matrixIndex]
        left = 0
        right = len(checkArr) - 1
        while left <= right:
            mid = (left + right) // 2
            if checkArr[mid] == target:
                return True
            if checkArr[mid] < target:
                left = mid + 1
            else:
                right = mid - 1
        return False


    def getMatrix(self, matrix: List[List[int]], target: int) -> bool:
        left = 0
        right = len(matrix) - 1

        while left <= right:
            mid = (left + right) // 2
            if matrix[mid][0] <= target:
                if matrix[mid][-1] >= target:
                    return mid
                left = mid + 1
            else:
                right = mid - 1

        return -1



# python unit test
class UnitTest(unittest.TestCase):

    # 클래스 생성 시 1회 실행
    @classmethod
    def setUpClass(self):
        pass

    # 클래스 소멸 시 1회 실행
    @classmethod
    def tearDownClass(self):
        pass

    # 테스트 케이스 전 실행
    def setUp(self):
        self.solution = Solution()

    # 테스트 케이스 후 실행
    def tearDown(self):
        pass

    def test_case_1(self):
        res = self.solution.searchMatrix(matrix = [[1,3,5,7],[10,11,16,20],[23,30,34,60]], target = 3)
        self.assertEqual(res, True)

    def test_case_2(self):
        res = self.solution.searchMatrix(matrix = [[1,3,5,7],[10,11,16,20],[23,30,34,60]], target = 13)
        self.assertEqual(res, False)




if __name__ == "__main__":
    # 스크립트 실행 시, 해당 부분 동작
    unittest.main(verbosity=0)
