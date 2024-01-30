class Solution:
    def productExceptSelf(self, nums: List[int]) -> List[int]:
        multiple_num = 1
        num_zero_count = 0

        for num in nums:
            if num == 0:
                num_zero_count += 1
                continue
            multiple_num *= num

        if num_zero_count >= 2:
            return [0] * len(nums)
        if num_zero_count == 1:
            return [0 if num != 0 else multiple_num for num in nums]
        return [multiple_num // num for num in nums]
