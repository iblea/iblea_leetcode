"""
Solution Note

m == grid.length
n == grid[i].length
1 <= m, n <= 300
grid[i][j] is '0' or '1'.
"""

# Leet Code Solution
class Solution:
    def numIslands(self, grid: List[List[str]]) -> int:
        m = len(grid)
        n = len(grid[0])

        def traversal_island(i, j):
            if i < 0 or i >= m or j < 0 or j >= n or grid[i][j] == "0":
                return
            grid[i][j] = "0"
            traversal_island(i - 1, j)
            traversal_island(i + 1, j)
            traversal_island(i, j - 1)
            traversal_island(i, j + 1)
            return

        count = 0
        for i in range(m):
            for j in range(n):
                if grid[i][j] == "1":
                    traversal_island(i, j)
                    count += 1
        return count

