#!/usr/bin/python3
import unittest
from typing import List
from typing import Optional


"""
Solution Note

"""

# Leet Code Solution

class Solution:

    def maxUniqueSplit(self, s: str) -> int:

        def backtrack(start, seen):
            if start == len(s):
                return 0

            v = 0
            for i in range(start, len(s)):
                substring = s[start:i+1]
                if substring not in seen:
                    seen.add(substring)
                    v = max(v, 1 + backtrack(i+1, seen))
                    seen.remove(substring)

            return v


        return backtrack(0, set())

    def maxUniqueSplit1(self, s: str) -> int:

        def backtrack(start, seen):
            if start == len(s):
                return 0
            max_splits = 0
            for end in range(start + 1, len(s) + 1):
                substring = s[start:end]
                # seen에 없으면
                if substring not in seen:
                    seen.add(substring)
                    max_splits = max(max_splits, 1 + backtrack(end, seen))
                    seen.remove(substring)
            return max_splits
        return backtrack(0, set())






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
        # a b ab c cc
        res = self.solution.maxUniqueSplit("ababccc")
        self.assertEqual(res, 5)

    def test_case_2(self):
        # a ba
        res = self.solution.maxUniqueSplit("aba")
        self.assertEqual(res, 2)

    def test_case_3(self):
        # a a
        res = self.solution.maxUniqueSplit("aa")
        self.assertEqual(res, 1)

    def test_case_4(self):
        # w, ww, z, f, v, e, d, wf, vh, sww
        # www, z, f, v, e, d, w, fv, h ,s, ww
        res = self.solution.maxUniqueSplit("wwwzfvedwfvhsww")
        self.assertEqual(res, 11)

    def test_case_5(self):
        # www, z, f, v, e, d, w, p, g, h, s, ww
        res = self.solution.maxUniqueSplit("wwwzfvedwpghsww")
        self.assertEqual(res, 12)

    def test_case_6(self):
        # m, b, j, h, jc, gb
        # mb, j, h, jc, g, b
        # m bj h j c g b
        res = self.solution.maxUniqueSplit("mbjhjcgb")
        self.assertEqual(res, 7)


"mbjhjcgb"

if __name__ == "__main__":
    # 스크립트 실행 시, 해당 부분 동작
    unittest.main(verbosity=0)
