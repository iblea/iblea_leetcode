class Solution:
    def search(self, nums: List[int], target: int) -> int:

        left: int  = 0
        right: int = len(nums) - 1

        while left <= right:
            mid: int = (left + right) // 2 # 3.2 -> 3
            if nums[mid] == target:
                return mid

            # 타겟이 중간값보다 더 크면 오른쪽을 검색
            # target = 8
            # 4 5 7 8 9 10 1 2 3
            #     *   ^
            #     ^ * |
            # target = 10
            # 4 5 7 8 9 10 1 2 3
            #         ^    *
            #         |  * ^
            # [2, 1] 1 -> left = 0, mid = (0+1)//2 = 0
            if nums[left] <= nums[mid]:
                if nums[left] <= target < nums[mid]:
                    right = mid - 1
                else:
                    left = mid + 1
            # 타겟이 중간값보다 더 작으면 왼쪽 검색
            else:
                if nums[mid] < target <= nums[right]:
                    left = mid + 1
                else:
                    right = mid - 1
        return -1

