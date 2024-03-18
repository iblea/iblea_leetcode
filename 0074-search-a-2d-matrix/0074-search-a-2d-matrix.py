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
