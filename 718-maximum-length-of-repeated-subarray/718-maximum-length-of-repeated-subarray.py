# Leet Code Solution
class Solution:
    def findLength(self, nums1: List[int], nums2: List[int]) -> int:
        n, m = len(nums1), len(nums2)
        dp = [[0] * (m + 1) for _ in range(n + 1)]

        # self.print_2arr(dp)
        for i in range(n):
            for j in range(m):
                if nums1[i] != nums2[j]:
                    continue
                dp[i + 1][j + 1] = dp[i][j] + 1
            # self.print_2arr(dp)

        # print("\n========================\n")
        return max(map(max, dp))

    def print_2arr(self, arr):
        for row in arr:
            print(row)
        print("")

