class Solution:
    def firstMissingPositive(self, nums: List[int]) -> int:
        for i in range(len(nums)):

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

            j: int = i
            while True:
                tmpValue: int = nums[nums[j] - 1]
                nums[nums[j] - 1] = nums[j]
                if nums[j] == tmpValue:
                    break
                if tmpValue <= 0 or tmpValue > len(nums):
                    break
                # value는 또다른 인덱스이다.
                nums[j] = tmpValue

        for i in range(len(nums)):
            if nums[i] != i + 1:
                return i + 1
        return len(nums) + 1

