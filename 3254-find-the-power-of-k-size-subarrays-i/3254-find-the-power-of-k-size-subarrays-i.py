class Solution:
    def resultsArray(self, nums: List[int], k: int) -> List[int]:
        if k == 1:
            return nums

        l = 0
        r = k - 1
        length = len(nums)
        answer = []

        while r < length:
            is_sorted = True
            for i in range(l, r):
                if nums[i] + 1 != nums[i + 1]:
                    is_sorted = False
                    break
            if is_sorted:
                answer.append(nums[r])
            else:
                answer.append(-1)
            l += 1
            r += 1
        return answer

