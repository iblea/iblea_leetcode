class Solution:
    def majorityElement(self, nums: List[int]) -> int:
        if len(nums) // 2 == 0:
            major = len(nums) // 2
        else:
            major = len(nums) // 2 + 1

        numdicts: dict = {}
        for num in nums:
            if num in numdicts:
                numdicts[num] += 1
            else:
                numdicts[num] = 1

            if numdicts[num] >= major:
                return num
        pass

