#!/usr/bin/python3
import unittest
from typing import List
from typing import Optional


"""
Solution Note

"""

# Leet Code Solution

class Solution:
    def isIsomorphic(self, s: str, t: str) -> bool:
        s1 = [ ]
        s2 = [ ]
        dic = {}
        cnt = 0
        for c in s:
            if c not in dic:
                dic[c] = cnt
                cnt += 1
            s1.append(dic[c])
        dic = {}
        cnt = 0
        for c in t:
            if c not in dic:
                dic[c] = cnt
                cnt += 1
            s2.append(dic[c])
        return s1 == s2



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
        res = self.solution.isIsomorphic(s = "egg", t = "add")
        self.assertEqual(res, True)

    def test_case_2(self):
        res = self.solution.isIsomorphic(s = "foo", t = "bar")
        self.assertEqual(res, False)

    def test_case_3(self):
        res = self.solution.isIsomorphic(s = "paper", t = "title")
        self.assertEqual(res, True)




if __name__ == "__main__":
    # 스크립트 실행 시, 해당 부분 동작
    unittest.main(verbosity=0)
