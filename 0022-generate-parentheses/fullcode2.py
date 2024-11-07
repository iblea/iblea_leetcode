#!/usr/bin/python3
import unittest
from typing import List
from typing import Optional


"""
Solution Note

"""

# Leet Code Solution

class Solution:
    def generateParenthesis(self, n: int) -> List[str]:
        answer = []

        stack = [ (n, n, "") ]
        while len(stack) > 0:

            curr = stack.pop(0)
            open = curr[0]
            close = curr[1]
            brackets = curr[2]

            if open == 0 and close == 0:
                answer.append(brackets)
                continue

            if open > 0:
                stack.append((open - 1, close, brackets + "("))
            if open < close:
                stack.append((open, close - 1, brackets + ")"))

        return answer


    def generateParenthesis_recursive(self, n: int) -> List[str]:
        answer = []
        def generate(open, close, brackets):
            if open == 0 and close == 0:
                nonlocal answer
                answer.append(brackets)
                return

            if open > 0:
                generate(open - 1, close, brackets + "(")
            if open < close:
                generate(open, close - 1, brackets + ")")

        generate(n, n, "")
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

    def test_case_2(self):
        res = self.solution.generateParenthesis(1)
        self.assertEqual(res, ["()"])



if __name__ == "__main__":
    # 스크립트 실행 시, 해당 부분 동작
    unittest.main(verbosity=0)
