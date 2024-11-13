#!/usr/bin/python3
import unittest
from typing import List
from typing import Optional


"""
Solution Note

https://leetcode.com/problems/random-point-in-non-overlapping-rectangles
"""

# Leet Code Solution

from random import randint
class Solution:

    def __init__(self, rects: List[List[int]]):
        self.rectangles = rects
        return

    def pick(self) -> List[int]:
        rect_random = self.rectangles[randint(0, len(self.rectangles) - 1)]
        x_random = randint(rect_random[0], rect_random[2])
        y_random = randint(rect_random[1], rect_random[3])
        return [x_random, y_random]


class Solution_Memory_Limit_Exceed:

    def __init__(self, rects: List[List[int]]):
        self.rectangles = []
        for rect in rects:
            left_bottom = (rect[0], rect[1])
            right_top = (rect[2], rect[3])
            # get raceangle area
            for x in range(left_bottom[0], right_top[0] + 1):
                for y in range(left_bottom[1], right_top[1] + 1):
                    self.rectangles.append((x, y))
        return

    def pick(self) -> List[int]:
        return self.rectangles[randint(0, len(self.rectangles) - 1)]





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
        pass

    # 테스트 케이스 후 실행
    def tearDown(self):
        pass

    def test_case_1(self):
        rectangles = [[-2, -2, 1, 1], [2, 2, 4, 6]]
        solution = Solution(rectangles)
        print(solution.pick())
        print(solution.pick())



if __name__ == "__main__":
    # 스크립트 실행 시, 해당 부분 동작
    unittest.main(verbosity=0)
