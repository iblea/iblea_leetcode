#!/usr/bin/python3
import unittest
from typing import List


"""
Solution Note

1 <= s.length <= 3 * 10**5
s consist of printable ASCII characters.
"""

# Leet Code Solution
class Solution:
    def reverseVowels(self, s: str) -> str:
        vowels = ['A', 'E', 'I', 'O', 'U', 'a', 'e', 'i', 'o', 'u']
        liststr = list(s)
        first = 0
        last = len(liststr) - 1
        while first < last:
            if liststr[first] not in vowels:
                first += 1
                continue
            if liststr[last] not in vowels:
                last -= 1
                continue
            tmp = liststr[first]
            liststr[first] = liststr[last]
            liststr[last] = tmp
            first += 1
            last -= 1
        return "".join(liststr)







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
        res = self.solution.reverseVowels(s = "hello")
        self.assertEqual(res, "holle")

    def test_case_normal_2(self):
        res = self.solution.reverseVowels(s = "leetcode")
        self.assertEqual(res, "leotcede")



if __name__ == "__main__":
    # 스크립트 실행 시, 해당 부분 동작
    unittest.main(verbosity=0)
    pass
