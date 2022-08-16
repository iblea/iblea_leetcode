#!/usr/bin/python3
import unittest
from typing import List


"""
Solution Note

1 <= s.length <= 105
s consists of only lowercase English letters.
"""

# Leet Code Solution
class Solution:
    def firstUniqChar(self, s: str) -> int:
        dic = {}
        for char in s:
            if char in dic:
                dic[char] += 1
                continue
            dic[char] = 1
        
        for i in range(len(s)):
            if dic[s[i]] == 1:
                return i
        return -1



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
        res = self.solution.firstUniqChar("leetcode")
        self.assertEqual(res, 0)

    def test_case_normal_2(self):
        res = self.solution.firstUniqChar("loveleetcode")
        self.assertEqual(res, 2)

    def test_case_normal_3(self):
        res = self.solution.firstUniqChar("aabb")
        self.assertEqual(res, -1)




if __name__ == "__main__":
    # 스크립트 실행 시, 해당 부분 동작
    unittest.main(verbosity=0)
    pass
