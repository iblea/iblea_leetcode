"""
Solution Note
0 <= nums.length <= 105
-109 <= nums[i] <= 109

"""

# Leet Code Solution
class Solution:
    def longestConsecutive(self, nums: List[int]) -> int:
        if len(nums) == 0:
            return 0
        elif len(nums) == 1:
            return 1

        numdict = {}
        for num in nums:
            if num in numdict:
                continue
            numdict[num] = None

        if len(numdict.keys()) == 1:
            return 1

        longest_index = 1
        for num in nums:
            if not num + 1 in numdict:
                continue

            # num + 1 이 존재하면 longest index를 찾는다.
            finding = num
            while finding + 1 in numdict:
                finding += 1
                if numdict[finding] is None:
                    continue
                finding = numdict[finding]
            numdict[num] = finding
            longest_index = max(longest_index, finding - num + 1)

        return longest_index

