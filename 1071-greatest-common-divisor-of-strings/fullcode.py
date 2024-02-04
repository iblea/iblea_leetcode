#!/usr/bin/python3
import unittest
from typing import List


"""
Solution Note

"""

# Leet Code Solution
from math import gcd
class Solution:
    def gcdOfStrings(self, str1: str, str2: str) -> str:
        if str1 + str2 != str2 + str1:
            return ''
        else:
            _gcd = gcd(len(str1),len(str2))
            max_str= max(str1, str2)
            return max_str[:_gcd]


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
        res = self.solution.gcdOfStrings(str1 = "ABCABC", str2 = "ABC")
        self.assertEqual(res, "ABC")

    def test_case_2(self):
        res = self.solution.gcdOfStrings(str1 = "ABABAB", str2 = "ABAB")
        self.assertEqual(res, "AB")

    def test_case_3(self):
        res = self.solution.gcdOfStrings(str1 = "LEET", str2 = "CODE")
        self.assertEqual(res, "")


if __name__ == "__main__":
    # 스크립트 실행 시, 해당 부분 동작
    unittest.main(verbosity=0)
    pass
