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

