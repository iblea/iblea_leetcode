#!/usr/bin/python3
import unittest
from typing import List


"""
Solution Note

"""

# Leet Code Solution

class Solution:
    def evalRPN(self, tokens: List[str]) -> int:
        stack = []
        for token in tokens:
            if token == "+":
                num1: int = stack.pop()
                num2: int = stack.pop()
                stack.append(num2 + num1)
                continue
            if token == "-":
                num1: int = stack.pop()
                num2: int = stack.pop()
                stack.append(num2 - num1)
                continue
            if token == "*":
                num1: int = stack.pop()
                num2: int = stack.pop()
                stack.append(num2 * num1)
                continue
            if token == "/":
                num1: int = stack.pop()
                num2: int = stack.pop()
                stack.append(int(num2 / num1))
                continue
            stack.append(int(token))
        return stack[0]





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
        res = self.solution.evalRPN(tokens = ["2","1","+","3","*"])
        self.assertEqual(res, 9)

    def test_case_2(self):
        res = self.solution.evalRPN(tokens = ["4","13","5","/","+"])
        self.assertEqual(res, 6)

    def test_case_3(self):
        res = self.solution.evalRPN(tokens = ["10","6","9","3","+","-11","*","/","*","17","+","5","+"])
        self.assertEqual(res, 22)




if __name__ == "__main__":
    # 스크립트 실행 시, 해당 부분 동작
    unittest.main(verbosity=0)
    pass
