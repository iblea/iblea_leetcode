#!/usr/bin/python3
import unittest
from typing import List
from typing import Optional


"""
Solution Note

"""

# Leet Code Solution
class Solution:
    def countNegatives(self, grid: List[List[int]]) -> int:
        gridLen: int = len(grid[0])
        negatives: int = 0

        target = -1
        for i in range(len(grid)):
            if grid[i][0] < 0:
                negatives += (gridLen * (len(grid) - i))
                return negatives

            # 행렬에서 binary search
            left: int  = 0
            right: int = gridLen - 1
            while left <= right:
                mid: int = (left + right) // 2 # 3.2 -> 3

                # 음수인거를 체크를 해서,음수면 mid부터 나머지 개수를 추가
                if grid[i][mid] == target:
                    left = mid
                    break

                # 중간값이 타겟보다 더 크면 오른쪽을 검색
                if grid[i][mid] > target:
                    left = mid + 1
                # 중간값이 타겟보다 더 작으면 왼쪽 검색
                else:
                    right = mid - 1

            if left >= gridLen:
                continue

            # 찾은 음수 개수 더하기
            while grid[i][left] < 0:
                left -= 1
            negatives += (gridLen - left) - 1

        return negatives



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
        res = self.solution.countNegatives(grid = [[4,3,2,-1],[3,2,1,-1],[1,1,-1,-2],[-1,-1,-2,-3]])
        self.assertEqual(res, 8)

    def test_case_2(self):
        res = self.solution.countNegatives(grid = [[3,2],[1,0]])
        self.assertEqual(res, 0)

    def test_case_3(self):
        res = self.solution.countNegatives(grid = [[4,3,-2,-3],[3,2,1,-1],[1,1,-1,-2],[-1,-1,-2,-3]])
        self.assertEqual(res, 9)

    def test_case_4(self):
        res = self.solution.countNegatives(grid = [[4, 0, 0,-1, -1, -2, -2]])
        self.assertEqual(res, 4)

    def test_case_5(self):
        res = self.solution.countNegatives(grid = [[4, 0, 0, 0, 0, -2, -2]])
        self.assertEqual(res, 2)




if __name__ == "__main__":
    # 스크립트 실행 시, 해당 부분 동작
    unittest.main(verbosity=0)
