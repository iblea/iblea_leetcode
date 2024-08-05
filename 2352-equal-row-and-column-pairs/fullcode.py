#!/usr/bin/python3
import unittest
from typing import List
from typing import Optional


"""
Solution Note

"""

# Leet Code Solution
class Solution:
    def equalPairs(self, grid: List[List[int]]) -> int:

        map = {}
        for line in grid:
            strline = str(line)
            if strline not in map:
                map[strline] = 1
            else:
                map[strline] += 1

        count = 0
        for i in range(len(grid)):
            line = []
            for j in range(len(grid)):
                line.append(grid[j][i])
            strline = str(line)
            if strline in map:
                count += map[strline]

        return count





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
        res = self.solution.problem(1)
        self.assertEqual(res, 1)



if __name__ == "__main__":
    # 스크립트 실행 시, 해당 부분 동작
    unittest.main(verbosity=0)
