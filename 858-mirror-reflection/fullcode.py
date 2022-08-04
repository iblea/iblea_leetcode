#!/usr/bin/python3
import unittest
from typing import List


"""
Solution Note

1 <= q <= p <= 1000
"""

# Leet Code Solution
class Solution:
    def mirrorReflection(self, p: int, q: int) -> int:
        # 최소공배수 구하기
        L = lcm(p,q)

        if (L // q) % 2 == 0:
            return 2

        return (L // p) % 2

def gcd(x,y):
    while(y):
        tmp = x
        x = y
        y = tmp % y
    return x

def lcm(x,y):
    return x * y // gcd(x,y)




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
        res = self.solution.mirrorReflection(2, 1)
        self.assertEqual(res, 2)

    def test_case_normal_2(self):
        res = self.solution.mirrorReflection(3, 1)
        self.assertEqual(res, 1)

    def test_case_normal_2(self):
        res = self.solution.mirrorReflection(3, 2)
        self.assertEqual(res, 0)

    def test_case_normal_2(self):
        res = self.solution.mirrorReflection(4, 3)
        self.assertEqual(res, 2)



if __name__ == "__main__":
    # 스크립트 실행 시, 해당 부분 동작
    unittest.main(verbosity=0)
    pass
