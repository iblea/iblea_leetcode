#!/usr/bin/python3
import unittest
from typing import List


"""
Solution Note

"""

# Leet Code Solution

class Solution:
    def dailyTemperatures(self, temperatures: List[int]) -> List[int]:
        monotonic_stack: list[int] = []
        answer: list[int] = [ 0 for _ in range(len(temperatures)) ]

        for i in range(len(temperatures)-1, -1, -1):
            if not monotonic_stack:
                monotonic_stack.append(i)
                continue

            while monotonic_stack and temperatures[i] >= temperatures[monotonic_stack[-1]]:
                monotonic_stack.pop()
            if not monotonic_stack:
                answer[i] = 0
            else:
                answer[i] = monotonic_stack[-1] - i
            monotonic_stack.append(i)

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

    def test_case_1(self):
        res = self.solution.dailyTemperatures(temperatures = [73,74,75,71,69,72,76,73])
        self.assertEqual(res, [1,1,4,2,1,1,0,0])

    def test_case_2(self):
        res = self.solution.dailyTemperatures(temperatures = [30,40,50,60])
        self.assertEqual(res, [1,1,1,0])

    def test_case_3(self):
        res = self.solution.dailyTemperatures(temperatures = [30,60,90])
        self.assertEqual(res, [1,1,0])

    def test_case_4(self):
        res = self.solution.dailyTemperatures(temperatures = [89,62,70,58,47,47,46,76,100,70])
        self.assertEqual(res, [8,1,5,4,3,2,1,1,0,0])




if __name__ == "__main__":
    # 스크립트 실행 시, 해당 부분 동작
    unittest.main(verbosity=0)
    pass
