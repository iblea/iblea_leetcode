class Solution:
    def findMin(self, nums: List[int]) -> int:
        left: int  = 0
        right: int = len(nums) - 1

        while True:
            if nums[left] <= nums[right]:
                return nums[left]

            mid: int = (left + right) // 2 # 3.2 -> 3
            if nums[left] > nums[mid]:
                right = mid
            else:
                left = mid + 1

