#!/usr/bin/python3
import unittest
from typing import List
from typing import Optional


"""
Solution Note

https://leetcode.com/problems/minimum-path-sum/?envType=problem-list-v2&envId=dynamic-programming
"""

# Leet Code Solution
class Solution:
    def minPathSum(self, grid: List[List[int]]) -> int:

        dp = [ [0] * len(grid[0]) for _ in range(len(grid)) ]

        dp[0][0] = grid[0][0]
        for i in range(1, len(grid[0])):
            dp[0][i] = sum(grid[0][:i+1])
        for i in range(1, len(grid)):
            dp[i][0] = sum([grid[x][0] for x in range(i+1)])

        for i in range(1, len(grid)):
            for j in range(1, len(grid[0])):
                dp[i][j] = min(dp[i-1][j], dp[i][j-1]) + grid[i][j]

        return dp[-1][-1]




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
        res = self.solution.minPathSum(grid = [[1,3,1],[1,5,1],[4,2,1]])
        self.assertEqual(res, 7)

    def test_case_2(self):
        res = self.solution.minPathSum(grid = [[1,2,3],[4,5,6]])
        self.assertEqual(res, 12)



if __name__ == "__main__":
    # 스크립트 실행 시, 해당 부분 동작
    unittest.main(verbosity=0)
