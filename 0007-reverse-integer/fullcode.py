#!/usr/bin/python3
import unittest
from typing import List
from typing import Optional


"""
Solution Note
https://leetcode.com/problems/reverse-integer

"""

# Leet Code Solution

class Solution:
    def reverse(self, x: int) -> int:
        if x == 0:
            return 0

        minus = False
        if x < 0:
            minus = True

        answer = 0
        x = abs(x)
        while x > 0:
            answer = (answer * 10) + (x % 10)
            x = x // 10
            if answer > 214748364:
                if x > 0:
                    return 0
            elif answer == 214748364:
                if minus and x > 8:
                    return 0
                if minus == False and x > 7:
                    return 0


        if minus:
            return -answer
        return answer




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
        res = self.solution.reverse(123)
        self.assertEqual(res, 321)

    def test_case_2(self):
        res = self.solution.reverse(-123)
        self.assertEqual(res, -321)

    def test_case_3(self):
        res = self.solution.reverse(120)
        self.assertEqual(res, 21)

    def test_case_4(self):
        res = self.solution.reverse(1452675)
        self.assertEqual(res, 5762541)



if __name__ == "__main__":
    # 스크립트 실행 시, 해당 부분 동작
    unittest.main(verbosity=0)
