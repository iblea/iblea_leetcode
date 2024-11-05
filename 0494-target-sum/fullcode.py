#!/usr/bin/python3
import unittest
from typing import List
from typing import Optional


"""
Solution Note

"""

# Leet Code Solution

class Solution:
    def findTargetSumWays(self, nums: List[int], target: int) -> int:

        nlen = len(nums)
        mem = {}
        def backtrack(start, s):

            # 1 + 1 - 1
            # 1 - 1 + 1
            # - 1 + 1 + 1
            # 이 3가지 경우의 수를 모두 계산할 필요 없다.
            # 따라서, 메모이제이션을 통해 중복 계산을 방지한다.
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


    def answer(self, nums, S):
        index = len(nums) - 1
        curr_sum = 0
        self.memo = {}
        return self.dp(nums, S, index, curr_sum)

    def dp(self, nums, target, index, curr_sum):
        if (index, curr_sum) in self.memo:
            return self.memo[(index, curr_sum)]

        if index < 0 and curr_sum == target:
            return 1
        if index < 0:
            return 0

        positive = self.dp(nums, target, index-1, curr_sum + nums[index])
        negative = self.dp(nums, target, index-1, curr_sum + -nums[index])

        self.memo[(index, curr_sum)] = positive + negative
        return self.memo[(index, curr_sum)]


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
        res = self.solution.findTargetSumWays([1, 1, 1, 1, 1], 3)
        self.assertEqual(res, 5)

    def test_case_2(self):
        res = self.solution.findTargetSumWays([1], 1)
        self.assertEqual(res, 1)

    def test_case_3(self):
        nums = [35,42,34,22,35,39,35,44,33,48,46,18,4,39,1,50,28,43,15,37]
        res = self.solution.findTargetSumWays(nums, 36)
        self.assertEqual(res, 5115)

    def test_case_4(self):
        res = self.solution.findTargetSumWays([1, 1, 1], 1)
        self.assertEqual(res, 3)



if __name__ == "__main__":
    # 스크립트 실행 시, 해당 부분 동작
    unittest.main(verbosity=0)
