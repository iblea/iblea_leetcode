#!/usr/bin/python3
import unittest
from typing import List
from typing import Optional


"""
Solution Note

https://leetcode.com/problems/shortest-subarray-with-sum-at-least-k

Given an integer array nums and an integer k, return the length of the shortest non-empty subarray of nums with a sum of at least k.
If there is no such subarray, return -1.
A subarray is a contiguous part of an array.

주어진 정수 배열 nums와 정수 k가 있을 때, 합이 최소 k인 가장 짧은 비어 있지 않은 부분 배열의 길이를 반환하세요.
만약 그러한 부분 배열이 없다면 -1을 반환하세요.
부분 배열은 배열의 연속된 부분입니다.
"""

# Leet Code Solution
from collections import deque
class Solution:
    def shortestSubarray(self, nums: List[int], k: int) -> int:
        res = float("inf")

        cur_sum = 0
        q = deque()  # (prefix_sum, end_idx)

        for r in range(len(nums)):
            cur_sum += nums[r]
            if cur_sum >= k:
                res = min(res, r + 1)

            # Find the minimum valid window ending at r
            while q and cur_sum - q[0][0] >= k:
                _, end_idx = q.popleft()
                res = min(res, r - end_idx)

            # Validate the monotonic deque
            while q and q[-1][0] > cur_sum:
                q.pop()
            q.append((cur_sum, r))

        return -1 if res == float("inf") else res

    def shortestSubarray_time_limit_exceed(self, nums: List[int], k: int) -> int:
        # print("")
        maxlength = -1

        dp = [0] * (len(nums) + 1)
        dp[0] = 0
        for i in range(1, len(nums)+1):
            dp[i] = dp[i-1] + nums[i-1]
            if dp[i] >= k:
                maxlength = min(maxlength, i) if maxlength != -1 else i
                # print(maxlength , i)

        for i in range(1, len(dp)-1):

            # dp[2]~dp[len(dp)-1] 까지 dp[1]을 뺀다.
            # dp[3]~dp[len(dp)-1] 까지 dp[2]를 뺀다.
            # dp[4]~dp[len(dp)-1] 까지 dp[3]을 뺀다.

            for j in range(i+1, len(dp)):
                if dp[j] - dp[i] >= k:
                    maxlength = min(maxlength, j-i) if maxlength != -1 else j-i
                    # print(maxlength , i, j)

        return maxlength





# python unit test
class UnitTest(unittest.TestCase):

    # 클래스 생성 시 1회 실행
    @classmethod
    def setUpClass(self):
        pass

    # 클래스 소멸 시 1회 실행
    @classmethod
    def tearDownClass(self):
        pass

    # 테스트 케이스 전 실행
    def setUp(self):
        self.solution = Solution()

    # 테스트 케이스 후 실행
    def tearDown(self):
        pass

    def test_case_1(self):
        res = self.solution.shortestSubarray(nums = [1], k = 1)
        self.assertEqual(res, 1)

    def test_case_2(self):
        res = self.solution.shortestSubarray(nums = [1,2], k = 4)
        self.assertEqual(res, -1)

    def test_case_3(self):
        res = self.solution.shortestSubarray(nums = [2,-1,2], k = 3)
        self.assertEqual(res, 3)

    def test_case_4(self):
        res = self.solution.shortestSubarray(nums = [5,2,-1,2], k = 3)
        self.assertEqual(res, 1)

    def test_case_5(self):
        res = self.solution.shortestSubarray([48,99,37,4,-31], 140)
        self.assertEqual(res, 2)




if __name__ == "__main__":
    # 스크립트 실행 시, 해당 부분 동작
    unittest.main(verbosity=0)
