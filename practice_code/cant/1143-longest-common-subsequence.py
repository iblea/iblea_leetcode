#!/usr/bin/python3
import unittest
from typing import List
from typing import Optional


"""
Solution Note

https://leetcode.com/problems/longest-common-subsequence
"""

# Leet Code Solution
class Solution:

    def longestCommonSubsequence1(self, text1: str, text2: str) -> int:

        dp = [[0] * (len(text2) + 1) for _ in range(len(text1) + 1)]

        for i in range(1, len(text1) + 1):
            for j in range(1, len(text2) + 1):
                pass


        return 0


    def longestCommonSubsequence(self, text1: str, text2: str) -> int:
        txt1 = list(text1)
        txt2 = list(text2)

        dp = [[0] * (len(txt2) + 1) for _ in range(len(txt1) + 1)]

        for i in range(1, len(txt1) + 1):
            for j in range(1, len(txt2) + 1):
                if txt1[i - 1] == txt2[j - 1]:
                    dp[i][j] = dp[i - 1][j - 1] + 1
                else:
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1])
                print(dp)

        return dp[-1][-1]




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
        res = self.solution.longestCommonSubsequence("abcde", "ace")
        self.assertEqual(res, 3)

    def test_case_2(self):
        res = self.solution.longestCommonSubsequence("aaa", "aa")
        self.assertEqual(res, 2)

    def test_case_3(self):
        res = self.solution.longestCommonSubsequence("aa", "aaa")
        self.assertEqual(res, 2)




if __name__ == "__main__":
    # 스크립트 실행 시, 해당 부분 동작
    unittest.main(verbosity=0)
