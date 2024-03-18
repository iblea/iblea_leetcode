class Solution:
    def search(self, nums: List[int], target: int) -> int:
        nums, rotate = self.sortArray(nums)

        left: int  = 0
        right: int = len(nums) - 1

        while left <= right:
            mid: int = (left + right) // 2 # 3.2 -> 3
            if nums[mid] == target:
                originIdx = (mid + rotate) % len(nums)
                return originIdx

            # 타겟이 중간값보다 더 크면 오른쪽을 검색
            if nums[mid] < target:
                left = mid + 1
            # 타겟이 중간값보다 더 작으면 왼쪽 검색
            else:
                right = mid - 1
        return -1

    def sortArray(self, nums: List[int]) -> any:
        rotate = 0
        while nums[0] > nums[-1]:
            num = nums.pop(0)
            nums.append(num)
            rotate += 1

        return nums, rotate
