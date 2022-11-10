#!/usr/bin/python3
import unittest
from typing import List


"""
Solution Note

1 <= s.length <= 10**5
s consists of lowercase English letters.
"""

# Leet Code Solution
class Solution:
    def removeDuplicates(self, s: str) -> str:
        slist = list(s)
        i = 0

        while i < len(slist) - 1:
            if slist[i] == slist[i+1]:
                del slist[i]
                del slist[i]
                if i > 0:
                    i -= 1
                continue
            i += 1

        return "".join(slist)




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
        res = self.solution.removeDuplicates(s = "abbaca")
        self.assertEqual(res, "ca")

    def test_case_normal_2(self):
        res = self.solution.removeDuplicates("azxxzy")
        self.assertEqual(res, "ay")

    def test_case_normal_3_length_check(self):
        res = self.solution.removeDuplicates("a")
        self.assertEqual(res, "a")

    def test_case_normal_4_aaaaaaaa(self):
        res = self.solution.removeDuplicates("aaaaaaaa")
        self.assertEqual(res, "")




if __name__ == "__main__":
    # 스크립트 실행 시, 해당 부분 동작
    unittest.main(verbosity=0)
    pass
