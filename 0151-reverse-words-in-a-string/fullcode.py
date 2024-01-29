#!/usr/bin/python3
import unittest
from typing import List


"""
Solution Note

151. Reverse Words in a String

1 <= s.length <= 104
s contains English letters (upper-case and lower-case), digits, and spaces ' '.
There is at least one word in s.

Follow-up: If the string data type is mutable in your language, can you solve it in-place with O(1) extra space?
"""

# Leet Code Solution

class Solution:
    def reverseWords(self, s: str) -> str:
        # arr: list[str] = s.strip().split()
        arr: list[str] = s.split()
        arr.reverse() # arr = arr[::-1]
        return ' '.join(arr)




# python unit test
class UnitTest(unittest.TestCase):

    # 클래스 생성 시 1회 실행
    @classmethod
    def setUpClass(self):
        self.solution = Solution()

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
        res = self.solution.reverseWords(s = "the sky is blue")
        self.assertEqual(res, "blue is sky the")

    def test_case_2(self):
        res = self.solution.reverseWords(s = "  hello world  ")
        self.assertEqual(res, "world hello")

    def test_case_3(self):
        res = self.solution.reverseWords(s = "a good   example")
        self.assertEqual(res, "example good a")




if __name__ == "__main__":
    # 스크립트 실행 시, 해당 부분 동작
    unittest.main(verbosity=0)
    pass
