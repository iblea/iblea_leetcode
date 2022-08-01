class Solution:
    def uniquePaths(self, m: int, n: int) -> int:
        """_summary_
            result(m,n) = result(m-1,n) + result(m, n-1)
        Args:
            m (int): columns
            n (int): row

        Returns:
            int: result of unique paths
        """

        grid = [[1] * n] * m

        # 재귀를 for문으로 바꾸면 이렇게 된다.
        # m - 1은 무조건 1 이므로 제외하고 시작한다.
        # 0, 0 인덱스의 내용이 결과가 되도록 역순으로 for문을 진행한다.
        for col in range(m-2, -1, -1):
            for row in range(n-2, -1, -1):
                grid[col][row] = grid[col+1][row] + grid[col][row+1]

        return grid[0][0]

