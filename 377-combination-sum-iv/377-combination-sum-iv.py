# Leet Code Solution
class Solution:
    def combinationSum4(self, nums: List[int], target: int) -> int:
        # 탑다운 재귀를 반복문으로 풀어서 해결해보자!

        stack = []
        for num in nums:
            num_before = target - num
            if num_before >= 0:
                stack.append(num_before)

        dp = [None for _ in range(target + 1)]
        dp[target] = [ num for num in stack ]

        while stack:
            num_before = stack.pop(-1)

            # 저장된 값에 대해서는 continue
            if dp[num_before] != None:
                continue

            tmplist = []
            for num in nums:
                if num_before - num >= 0:
                    stack.append(num_before - num)
                    tmplist.append(num_before - num)
            dp[num_before] = tmplist

        dp[0] = 1
        # print(dp)

        for i in range(1, target + 1):
            # None일 경우 해당 인덱스는 아예 타지 않는것으로 파악함.
            if dp[i] == None:
                continue

            if not dp[i]:
                dp[i] = 0
                continue

            dp[i] = sum(dp[dp[i][j]] for j in range(len(dp[i])))

        # print(dp)
        # print(dp[target])

        return dp[target]

