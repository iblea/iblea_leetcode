#!/usr/bin/python3
import unittest
from typing import List


"""
Solution Note

"""

# Leet Code Solution

class Solution:
    def mergeAlternately(self, word1: str, word2: str) -> str:
        minlen: int = min(len(word1), len(word2))
        answer: str = ""
        for i in range(minlen):
            answer += word1[i] + word2[i]

        if len(word1) > len(word2):
            answer += word1[minlen:]
        else:
            answer += word2[minlen:]
        return answer



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
        res = self.solution.mergeAlternately(word1 = "abc", word2 = "pqr")
        self.assertEqual(res, "apbqcr")

    def test_case_2(self):
        res = self.solution.mergeAlternately(word1 = "ab", word2 = "pqrs")
        self.assertEqual(res, "apbqrs")

    def test_case_3(self):
        res = self.solution.mergeAlternately(word1 = "abcd", word2 = "pq")
        self.assertEqual(res, "apbqcd")



if __name__ == "__main__":
    # 스크립트 실행 시, 해당 부분 동작
    unittest.main(verbosity=0)
    pass
