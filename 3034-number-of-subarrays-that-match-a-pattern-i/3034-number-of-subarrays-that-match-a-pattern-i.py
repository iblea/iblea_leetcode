class Solution:
    def countMatchingSubarrays(self, nums: List[int], pattern: List[int]) -> int:

        answer = 0
        for i in range(len(nums)):
            pi = 0
            ok = True
            for pi in range(len(pattern)):
                idx = i + pi
                if idx + 1 >= len(nums):
                    ok = False
                    break

                if pattern[pi] == 1:
                    if nums[idx] >= nums[idx + 1]:
                        ok = False
                        break
                elif pattern[pi] == -1:
                    if nums[idx] <= nums[idx + 1]:
                        ok = False
                        break
                else:
                    if nums[idx] != nums[idx + 1]:
                        ok = False
                        break
            if ok:
                answer += 1
        return answer
