#!/usr/bin/python3
import unittest
from typing import List


"""
Solution Note

"""

# Leet Code Solution
class Solution:
    def reverseWords(self, s: str) -> str:
        words = s.split(' ')
        result = ""

        for word in words:
            for i in range(len(word) - 1, -1, -1):
                result += word[i]
            result += " "
        return result[:-1]




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

    def test_case_normal_1(self):
        res = self.solution.reverseWords("Let's take LeetCode contest")
        self.assertEqual(res, "s'teL ekat edoCteeL tsetnoc")

    def test_case_normal_2(self):
        res = self.solution.reverseWords("God Ding")
        self.assertEqual(res, "doG gniD")



if __name__ == "__main__":
    # 스크립트 실행 시, 해당 부분 동작
    unittest.main(verbosity=0)
    pass
