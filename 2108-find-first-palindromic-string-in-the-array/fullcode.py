#!/usr/bin/python3
import unittest
from typing import List


"""
Solution Note

"""

# Leet Code Solution

class Solution:
    def firstPalindrome(self, words: List[str]) -> str:
        for word in words:
            left = 0
            right = len(word) - 1
            limit = len(word) // 2
            while left < limit:
                if word[left] != word[right]:
                    break
                left += 1
                right -= 1
            if left == limit:
                return word
        return ""



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
        res = self.solution.firstPalindrome(words = ["abc","car","ada","racecar","cool"])
        self.assertEqual(res, "ada")

    def test_case_2(self):
        res = self.solution.firstPalindrome(words = ["notapalindrome","racecar"])
        self.assertEqual(res, "racecar")

    def test_case_3(self):
        res = self.solution.firstPalindrome(words = ["def","ghi"])
        self.assertEqual(res, "")




if __name__ == "__main__":
    # 스크립트 실행 시, 해당 부분 동작
    unittest.main(verbosity=0)
    pass
