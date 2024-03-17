class Solution:
    def firstBadVersion(self, n: int) -> int:

        left: int = 0
        right: int = n

        while left <= right:
            mid: int = (left + right) // 2

            # 불량이면 왼쪽으로 이동해서 다시 찾는다.
            if isBadVersion(mid):
                right = mid - 1
            # 불량 아니면 오른쪽으로 이동해서 다시 찾는다.
            else:
                left = mid + 1
        return left
