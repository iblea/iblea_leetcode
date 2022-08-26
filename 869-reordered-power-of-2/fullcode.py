#!/usr/bin/python3
import unittest
from typing import List


"""
Solution Note

1 <= n <= 10**9
"""

# Leet Code Solution
from collections import Counter

class Solution:
    def reorderedPowerOf2(self, n: int) -> bool:
        LIMIT = 10 ** 9

        ncounter = Counter(str(n))
        i = 0
        val = 1 << i
        while val <= LIMIT:
            if ncounter == Counter(str(val)):
                return True
            i += 1
            val = 1 << i
        return False


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
        res = self.solution.reorderedPowerOf2(1)
        self.assertEqual(res, True)

    def test_case_normal_2(self):
        res = self.solution.reorderedPowerOf2(10)
        self.assertEqual(res, False)

    def test_case_normal_3(self):
        res = self.solution.reorderedPowerOf2(16)
        self.assertEqual(res, True)

    def test_case_normal_4(self):
        res = self.solution.reorderedPowerOf2(46)
        self.assertEqual(res, True)






if __name__ == "__main__":
    # 스크립트 실행 시, 해당 부분 동작
    unittest.main(verbosity=0)
    pass
