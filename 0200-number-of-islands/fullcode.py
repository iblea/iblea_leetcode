#!/usr/bin/python3
import unittest
from typing import List
from typing import Optional


"""
Solution Note
https://leetcode.com/problems/number-of-islands/description/?envType=study-plan-v2&envId=top-interview-150

Given an m x n 2D binary grid grid which represents a map of '1's (land) and '0's (water), return the number of islands.

An island is surrounded by water and is formed by connecting adjacent lands horizontally or vertically. You may assume all four edges of the grid are all surrounded by water.

m == grid.length
n == grid[i].length
1 <= m, n <= 300
grid[i][j] is '0' or '1'.

'1'(토지)과 '0'(물)의 지도를 나타내는 m x n 2D 이진 그리드 그리드가 주어지면 섬의 수를 반환합니다.
섬은 물로 둘러싸여 있으며 인접한 땅을 수평 또는 수직으로 연결하여 형성됩니다. 그리드의 네 가장자리가 모두 물로 둘러싸여 있다고 가정할 수 있습니다.
"""

# Leet Code Solution
class Solution:
    def numIslands(self, grid: List[List[str]]) -> int:

        answer = 0
        island = []
        is_visited = [[False for _ in range(len(grid[0]))] for _ in range(len(grid))]


        lenx = len(grid[0])
        leny = len(grid)
        dx = [1, 0, -1, 0]
        dy = [0, 1, 0, -1]

        for y in range(leny):
            for x in range(lenx):
                if is_visited[y][x]:
                    continue

                is_visited[y][x] = True
                if grid[y][x] == '0':
                    continue

                answer += 1
                island.append((y, x))
                while island:
                    iy, ix = island.pop()
                    for i in range(4):
                        ny = iy + dy[i]
                        nx = ix + dx[i]
                        if ny < 0 or ny >= leny or nx < 0 or nx >= lenx:
                            continue
                        if is_visited[ny][nx]:
                            continue
                        is_visited[ny][nx] = True
                        if grid[ny][nx] == '0':
                            continue
                        island.append((ny, nx))

        return answer



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
        grid = [
            ["1","1","1","1","0"],
            ["1","1","0","1","0"],
            ["1","1","0","0","0"],
            ["0","0","0","0","0"]
        ]
        res = self.solution.numIslands(grid)
        self.assertEqual(res, 1)

    def test_case_2(self):
        grid = [
            ["1","1","0","0","0"],
            ["1","1","0","0","0"],
            ["0","0","1","0","0"],
            ["0","0","0","1","1"]
        ]
        res = self.solution.numIslands(grid)
        self.assertEqual(res, 3)




if __name__ == "__main__":
    # 스크립트 실행 시, 해당 부분 동작
    unittest.main(verbosity=0)
