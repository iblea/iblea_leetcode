#!/usr/bin/python3
import unittest
from typing import List
from typing import Optional


"""
Solution Note

"""

# Leet Code Solution

class Solution:
    def longestCommonPrefix(self, strs: List[str]) -> str:
        answer: str = ""
        sorted_str: list[str] = sorted(strs)
        first: str = sorted_str[0]
        last: str= sorted_str[-1]

        for i in range(min(len(first), len(last))):
            if (first[i] != last[i]):
                break
            answer += first[i]

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
        strs = ["dog","racecar","car"]
        res = self.solution.longestCommonPrefix(strs = ["flower","flow","flight"])
        self.assertEqual(res, "fl")

    def test_case_2(self):
        res = self.solution.longestCommonPrefix(strs = ["dog","racecar","car"])
        self.assertEqual(res, "")


if __name__ == "__main__":
    # 스크립트 실행 시, 해당 부분 동작
    unittest.main(verbosity=0)
