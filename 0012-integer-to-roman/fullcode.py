#!/usr/bin/python3
import unittest
from typing import List


"""
Solution Note

Symbol  Value
I       1
V       5
X       10
L       50
C       100
D       500
M       1000

1 <= num <= 3999
"""

# Leet Code Solution
class Solution:
    def intToRoman(self, num: int) -> str:
        ROAM = {
            1: ("I", "V", "X"),
            10: ("X", "L", "C"),
            100: ("C", "D", "M"),
            1000: ("M", "", "")
        }

        answer = ""
        n = num
        div = 1000
        while n > 0:
            int_div = n // div
            if  int_div <= 0:
                div //= 10
                continue
            str_1 = ROAM[div][0]
            str_5 = ROAM[div][1]
            str_10 = ROAM[div][2]
            if int_div <= 3:
                answer += (str_1 * int_div)
            elif int_div == 4:
                answer += str_1 + str_5
            elif int_div <= 8:
                answer += str_5 + (str_1 * (int_div - 5))
            elif int_div <= 9:
                answer += str_1 + str_10

            n %= div
            div //= 10

        # print(answer)
        return answer





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
        res = self.solution.intToRoman(3)
        self.assertEqual(res, "III")

    def test_case_normal_2(self):
        res = self.solution.intToRoman(58)
        self.assertEqual(res, "LVIII")

    def test_case_normal_3(self):
        res = self.solution.intToRoman(1994)
        self.assertEqual(res, "MCMXCIV")




if __name__ == "__main__":
    # 스크립트 실행 시, 해당 부분 동작
    unittest.main(verbosity=0)
    pass
