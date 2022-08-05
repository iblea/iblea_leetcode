#!/usr/bin/python3
import numbers
import unittest
from typing import List


"""
Solution Note
https://leetcode.com/problems/combination-sum-iv/

1 <= nums.length <= 200
1 <= nums[i] <= 1000
All the elements of nums are unique.
1 <= target <= 1000
"""

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



# python unit test
class UnitTest(unittest.TestCase):

    # 클래스 생성 시 1회 실행
    @classmethod
    def setUpClass(self):
        self.solution = Solution();

    # 클래스 소멸 시 1회 실행
    @classmethod
    def tearDownClass(self):
        pass

    # 테스트 케이스 전 실행
    def setUp(self):
        pass

    # 테스트 케이스 후 실행
    def tearDown(self):
        pass

    def test_case_normal_1(self):
        res = self.solution.combinationSum4([3, 2, 1], 4)
        self.assertEqual(res, 7)

    def test_case_normal_2(self):
        res = self.solution.combinationSum4([9], 3)
        self.assertEqual(res, 0)

    def test_case_normal_3(self):
        res = self.solution.combinationSum4([7, 4], 74)
        self.assertEqual(res, 3150)



if __name__ == "__main__":
    # 스크립트 실행 시, 해당 부분 동작
    unittest.main(verbosity=0)
    pass
