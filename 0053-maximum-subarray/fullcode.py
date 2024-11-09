#!/usr/bin/python3
import unittest
from typing import List
from typing import Optional


"""
Solution Note

"""

# Leet Code Solution
class Solution:
    def maxSubArray(self, nums: List[int]) -> int:
        # 아니 이거 copilot이 풀어줬는데??
        dp = []
        dp.append(nums[0])
        for i in range(1, len(nums)):
            dp.append(max(nums[i], nums[i] + dp[i-1]))
        return max(dp)


    def maxSubArray_time_limit_exceed(self, nums: List[int]) -> int:
        def dp(idx):
            max_val = float('-inf')
            val = 0
            for i in range(idx, len(nums)):
                val += nums[i]
                max_val = max(max_val, val)
            return max_val

        answer = float('-inf')
        for start in range(len(nums)):
            res = dp(start)
            answer = max(answer, res)
        return answer




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
        res = self.solution.maxSubArray(nums = [-2,1,-3,4,-1,2,1,-5,4])
        self.assertEqual(res, 6)

    def test_case_2(self):
        res = self.solution.maxSubArray(nums = [1])
        self.assertEqual(res, 1)

    def test_case_3(self):
        res = self.solution.maxSubArray(nums = [5,4,-1,7,8])
        self.assertEqual(res, 23)



if __name__ == "__main__":
    # 스크립트 실행 시, 해당 부분 동작
    unittest.main(verbosity=0)
