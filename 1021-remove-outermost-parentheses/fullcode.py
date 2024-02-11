#!/usr/bin/python3
import unittest
from typing import List


"""
Solution Note

"""

# Leet Code Solution

class Solution:
    def removeOuterParentheses(self, s: str) -> str:
        stack = []
        result_string = ""
        for chr in s:
            if chr == ")":
                stack.pop()
                if not stack:
                    continue
                result_string += ")"
                continue

            if stack:
                result_string += "("
            stack.append(chr)
            continue

        return result_string




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

    def test_case_1(self):
        res = self.solution.removeOuterParentheses("(()())(())")
        self.assertEqual(res, "()()()")

    def test_case_2(self):
        res = self.solution.removeOuterParentheses("(()())(())(()(()))")
        self.assertEqual(res, "()()()()(())")

    def test_case_3(self):
        res = self.solution.removeOuterParentheses("()()")
        self.assertEqual(res, "")







if __name__ == "__main__":
    # 스크립트 실행 시, 해당 부분 동작
    unittest.main(verbosity=0)
    pass
