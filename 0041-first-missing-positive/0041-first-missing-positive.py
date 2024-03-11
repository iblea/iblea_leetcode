class Solution:
    def firstMissingPositive(self, nums: List[int]) -> int:
        for i in range(len(nums)):

            # normal case or already sorted.
            if nums[i] == i + 1:
                continue

            # abnormal case
            if nums[i] <= 0 or nums[i] > len(nums):
                nums[i] = -1
                continue

            # nums[0] = 1
            # nums[1] = 2
            # nums[2] = 3
            # nums[i] = i + 1
            # nums[i - 1] = i
            # ...

            self.changeIndex(nums, i)
        for i in range(len(nums)):
            if nums[i] != i + 1:
                return i + 1
        return len(nums) + 1

    def changeIndex(self, nums: List[int], i: int) -> None:
        while True:
            # i = 1
            # [3, 4, -1, 1]
            # [-1, 4, 3, 1]
            # [1, 3, -1, 4]
            # [1, -1, 3, 4]

            agovalue: int = nums[i]
            tmpValue: int = nums[agovalue - 1]
            nums[agovalue - 1] = nums[i]
            if nums[i] == tmpValue:
                break
            if tmpValue <= 0 or tmpValue > len(nums):
                nums[i] = -1
                break
            # value는 또다른 인덱스이다.
            nums[i] = tmpValue

