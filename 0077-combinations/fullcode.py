#!/usr/bin/python3
import unittest
from typing import List
from typing import Optional


"""
Solution Note

"""

# Leet Code Solution

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
        res = self.solution.combine(n = 4, k = 2)
        self.assertEqual(res, [[1,2],[1,3],[1,4],[2,3],[2,4],[3,4]])

    def test_case_2(self):
        res = self.solution.combine(n = 1, k = 1)
        self.assertEqual(res, [[1]])



if __name__ == "__main__":
    # 스크립트 실행 시, 해당 부분 동작
    unittest.main(verbosity=0)
