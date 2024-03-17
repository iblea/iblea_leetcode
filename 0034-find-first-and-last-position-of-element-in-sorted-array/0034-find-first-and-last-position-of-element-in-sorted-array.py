class Solution:
    def searchRange(self, nums: List[int], target: int) -> List[int]:

        left = 0
        right = len(nums) - 1

        while left <= right:
            mid = (left + right) // 2
            if nums[mid] == target:
                start = mid
                while nums[start] == target and start >= 0:
                    start -= 1

                end = mid
                while end < len(nums) and nums[end] == target:
                    end += 1
                return [start + 1, end - 1]
            elif nums[mid] < target:
                left = mid + 1
            else:
                right = mid - 1

        return [-1, -1]

