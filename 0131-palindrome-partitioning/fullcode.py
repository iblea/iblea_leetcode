#!/usr/bin/python3
import unittest
from typing import List
from typing import Optional


"""
Solution Note
https://leetcode.com/problems/palindrome-partitioning/

Given a string `s`, partition `s` such that every substring of the partition is a palindrome. Return all possible palindrome partitioning of `s`.
"""

# Leet Code Solution

class Solution:
    def partition(self, s: str) -> List[List[str]]:
        answer = []
        def func(ss, lst):

            if ss == "":
                if len(lst) > 0:
                    nonlocal answer
                    answer.append(lst)
                return

            for i in range(1, len(ss)+1):
                curs = ss[:i]
                if self.is_palindrome(curs) is False:
                    continue
                func(ss[i:], lst + [curs])

        func(s, [])
        return answer

    def is_palindrome(self, s: str) -> bool:
        divide2 = len(s) // 2

        for i in range(divide2):
            if s[i] != s[len(s)-i-1]:
                return False
        return True



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
        res = self.solution.partition("aab")
        answer = [["a","a","b"],["aa","b"]]
        self.assertEqual(res, answer)

    def test_case_2(self):
        res = self.solution.partition("a")
        answer = [["a"]]
        self.assertEqual(res, answer)



if __name__ == "__main__":
    # 스크립트 실행 시, 해당 부분 동작
    unittest.main(verbosity=0)
