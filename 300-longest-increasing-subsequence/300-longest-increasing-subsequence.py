"""
Solution Note

1 <= nums.length <= 2500
-10^4 <= nums[i] <= 10^4
"""

# Leet Code Solution
from bisect import bisect_left
class Solution:
    def lengthOfLIS(self, nums: List[int]) -> int:
        lis = [ nums[0] ]
        for i in range(1, len(nums)):
            if (nums[i] > lis[-1]):
                lis.append(nums[i])
                continue

            index = bisect_left(lis, nums[i])
            # index가 len(lis) 일 리는 없다 (num[i] > lis[-1]) 에서 처리했기 때문
            if lis[index] == nums[i]:
                continue
            lis[index] = nums[i]

        return len(lis)

