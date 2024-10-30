class Solution:
    def combine(self, n: int, k: int) -> List[List[int]]:

        nums = [i for i in range(1, n+1)]

        if n == k:
            return [ nums ]

        answer = []
        def backtracking(tmp, index):
            if len(tmp) == k:
                answer.append(tmp)
                return

            for i in range(index, len(nums)):
                backtracking(tmp + [nums[i]], i+1)
            return

        backtracking([], 0)
        return answer

