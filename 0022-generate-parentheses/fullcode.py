#!/usr/bin/python3
import unittest
from typing import List
from typing import Optional


"""
Solution Note

https://leetcode.com/problems/generate-parentheses/
"""

# Leet Code Solution

class Solution:
    def generateParenthesis(self, n: int) -> List[str]:
        answer: List[str] = []

        def func(s, l, r):
            if l == 0 and r == 0:
                answer.append(s)
                return

            if l > 0:
                func(s + "(", l - 1, r)
            if r > 0 and l < r:
                func(s + ")", l, r - 1)


        func("", n, n)
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
        res = self.solution.generateParenthesis(3)
        self.assertEqual(res, ["((()))","(()())","(())()","()(())","()()()"])

    def test_case_1(self):
        res = self.solution.generateParenthesis(1)
        self.assertEqual(res, ["()"])




if __name__ == "__main__":
    # 스크립트 실행 시, 해당 부분 동작
    unittest.main(verbosity=0)
