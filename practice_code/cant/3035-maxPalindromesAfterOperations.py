#!/usr/bin/python3
from collections import Counter
import unittest
from typing import List
from typing import Optional


"""
Solution Note

"""

# Leet Code Solution

class Solution:
    def maxPalindromesAfterOperations(self, words: List[str]) -> int:
        count = Counter(''.join(words))
        odd,even = 0,0
        ans = 0

        for val in count.values():
            even+=val-val%2
            odd+=val%2

        words.sort(key=len)

        for word in words:
            length = len(word) # length 5
            evenLenReq = length-(length%2)  # 4
            oddLenReq = length%2    # 1

            if (even>=evenLenReq and odd>=oddLenReq):
                ans+=1
                even-=evenLenReq
                odd-=oddLenReq
            elif even>=length:
                ans+=1
                even-=length

        return ans

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
        res = self.solution.maxPalindromesAfterOperations(words = ["abbb","ba","aa"])
        self.assertEqual(res, 3)

    def test_case_2(self):
        res = self.solution.maxPalindromesAfterOperations(words = ["abc","ab"])
        self.assertEqual(res, 2)

    def test_case_3(self):
        res = self.solution.maxPalindromesAfterOperations(words = ["cd","ef","a"])
        self.assertEqual(res, 1)



if __name__ == "__main__":
    # 스크립트 실행 시, 해당 부분 동작
    unittest.main(verbosity=0)
