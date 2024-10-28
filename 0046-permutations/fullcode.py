#!/usr/bin/python3
import unittest
from typing import List
from typing import Optional


"""
Solution Note

https://leetcode.com/problems/permutations/?envType=problem-list-v2&envId=backtracking
"""

# Leet Code Solution

class Solution:
    def permute(self, nums: List[int]) -> List[List[int]]:

        answer = []

        def backtracking(arr, tmp):

            arrlen = len(arr)
            if arrlen == 1:
                answer.append(tmp + arr)
                return

            for i in range(len(arr)):
                num= arr[i]
                tmparr = arr.copy()
                tmparr.pop(i)
                backtracking(tmparr, tmp + [num])

        backtracking(nums, [])
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
        res = self.solution.permute(nums = [1,2,3])
        self.assertEqual(res, [[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2],[3,2,1]])

    def test_case_2(self):
        res = self.solution.permute(nums = [0,1])
        self.assertEqual(res, [[0,1],[1,0]])

    def test_case_3(self):
        res = self.solution.permute(nums = [1])
        self.assertEqual(res, [[1]])



if __name__ == "__main__":
    # 스크립트 실행 시, 해당 부분 동작
    unittest.main(verbosity=0)
