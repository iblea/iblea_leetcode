#!/usr/bin/python3
import unittest
from typing import List
from typing import Optional


"""
Solution Note

"""

# Leet Code Solution

import math
class Solution:
    def minSteps(self, n: int) -> int:
        if n == 1:
            return 0

        max_log = int(math.sqrt(n)) + 1
        save_nums = []
        cal = n
        while cal > 1:
            is_divide = False
            for i in range(2, max_log):
                if cal % i == 0:
                    save_nums.append(i)
                    cal = cal // i
                    is_divide = True
                    break
            if not is_divide:
                save_nums.append(cal)
                break
            else:
                max_log = int(math.sqrt(cal)) + 1

        sum = 0
        for num in save_nums:
            sum += num
        return sum




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
        res = self.solution.minSteps(3)
        self.assertEqual(res, 3)

    def test_case_2(self):
        res = self.solution.minSteps(1)
        self.assertEqual(res, 0)

    def test_case_3(self):
        res = self.solution.minSteps(2)
        self.assertEqual(res, 2)

    def test_case_4(self):
        res = self.solution.minSteps(7)
        self.assertEqual(res, 7)

    def test_case_5(self):
        res = self.solution.minSteps(18)
        self.assertEqual(res, 8)




if __name__ == "__main__":
    # 스크립트 실행 시, 해당 부분 동작
    unittest.main(verbosity=0)
