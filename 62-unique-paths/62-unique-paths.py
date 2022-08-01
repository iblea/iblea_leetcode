"""
Solution Note

m = column
n = row

ex) m = 3, n = 4
o o o o
o o o o
o o o o

1 <= m, n <= 100
"""

# Leet Code Solution
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

        pos_list = [[0] * n for _ in range(m)]


        def get_unique_paths(m: int, n: int) -> int:
            # pos_dict에 이미 값이 있으면 더이상 계산하지 않고 해당 값을 리턴한다.
            if pos_list[m][n] != 0:
                return pos_list[m][n]

            # 만약 m 또는 n이 1이면 최단경로는 1이므로
            # m이 2이면 n을 리턴하고
            # n이 2이면 m을 리턴하면 된다.
            # 이러면 굳이 한번 더 재귀를 타지 않아도 된다.
            if m == 1:
                pos_list[m][n] = n + 1
                return n + 1
            if n == 1:
                pos_list[m][n] = m + 1
                return m + 1

            pos_list[m][n] = get_unique_paths(m-1, n) + get_unique_paths(m, n-1)
            return pos_list[m][n]

        # 배열로 처리해주기 위하여 m,n을 하나씩 뺌
        m -= 1
        n -= 1

        # get_unique_paths(m, n) 에서
        # m 또는 n이 1일 경우에는 처리할 수 없는 로직이기에
        # 함수를 타기 전 예외처리 진행한다.
        if m == 0 or n == 0:
            return 1

        result = get_unique_paths(m, n)
        return result


