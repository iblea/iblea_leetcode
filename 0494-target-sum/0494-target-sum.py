class Solution:
    def findTargetSumWays(self, nums: List[int], target: int) -> int:

        nlen = len(nums)
        mem = {}
        def backtrack(start, s):
            if (start, s) in mem:
                return mem[(start, s)]
            if start == nlen:
                if s == target:
                    return 1
                return 0

            cnt = 0
            cnt += backtrack(start + 1, s + nums[start])
            cnt += backtrack(start + 1, s - nums[start])
            mem[(start, s)] = cnt
            return cnt

        return backtrack(0, 0)
