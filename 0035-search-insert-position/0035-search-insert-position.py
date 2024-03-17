class Solution:
    def searchInsert(self, nums: List[int], target: int) -> int:
        # Search - 했는데 있으면 인덱스 리턴
        # 없을 경우 - 들어갈 인덱스 찾기
        left: int  = 0
        right: int = len(nums) - 1

        while left <= right:
            mid: int = (left + right) // 2 # 3.2 -> 3
            if nums[mid] == target:
                return mid

            # 타겟이 중간값보다 더 크면 오른쪽을 검색
            if nums[mid] < target:
                left = mid + 1
            # 타겟이 중간값보다 더 작으면 왼쪽 검색
            else:
                right = mid - 1
        return left
