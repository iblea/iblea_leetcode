#!/usr/bin/python3
import unittest
from typing import List


"""
Solution Note

"""

# Leet Code Solution

class Solution:
    def isValid(self, s: str) -> bool:
        stack = []
        for chr in s:
            if chr in ["(", "{", "["]:
                stack.append(chr)
                continue

            if not stack:
                return False
            ret = stack.pop()
            if ret == "(" and chr != ")":
                return False
            if ret == "{" and chr != "}":
                return False
            if ret == "[" and chr != "]":
                return False
        if stack:
            return False
        return True



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
        res = self.solution.isValid("()")
        self.assertEqual(res, True)

    def test_case_2(self):
        res = self.solution.isValid("()[]{}")
        self.assertEqual(res, True)

    def test_case_3(self):
        res = self.solution.isValid("(]")
        self.assertEqual(res, False)

    def test_case_4(self):
        res = self.solution.isValid("(")
        self.assertEqual(res, False)




if __name__ == "__main__":
    # 스크립트 실행 시, 해당 부분 동작
    unittest.main(verbosity=0)
    pass
