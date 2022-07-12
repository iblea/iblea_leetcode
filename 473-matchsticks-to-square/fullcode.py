#!/usr/bin/python3
import math
from nis import match
import unittest
from typing import List
from functools import lru_cache as cache

"""
Solution Note
1 <= matchsticks.length <= 15
1 <= matchsticks[i] <= 108

"""

# Leet Code Solution
class Solution:
    def makesquare(self, matchsticks: List[int]) -> bool:
        if len(matchsticks) < 4:
            return False

        sum_of_matchsticks = 0

        matchsticks.sort(reverse=True)

        sum_of_matchsticks = sum(matchsticks)

        # 변결이가 맞지 않으면 바로 리턴 때림
        if sum_of_matchsticks % 4 != 0:
            return False

        edge_len = sum_of_matchsticks // 4
        # 한 변의 길이보다 큰 성냥이 있을 경우 바로 리턴 때림
        if edge_len < matchsticks[0]:
            return False

        @cache(maxsize=None)
        def is_edge_in_square(side1, side2, side3, side4, index):
            nonlocal edge_len

            if edge_len == side1 and edge_len == side2 and \
                edge_len == side3 and edge_len == side4:
                return True

            if index >= len(matchsticks):
                return False

            if edge_len < side1 or edge_len < side2 or \
                edge_len < side3 or edge_len < side4:
                return False

            # or 조건을 통해 모든 경우의 수를 순회하여 True 조건이 나올 경우 반환한다.
            # 만약 [4, 4, 3, 2, 2, 1] 리스트가 들어올 경우
            # 0 0 0 0
            # 4 0 0 0
            # 8 0 0 0 -> X
            # 4 4 0 0
            # 7 4 0 0 -> X
            # ...
            # 4 4 3 0
            # 4 4 5 0 -> X
            # 4 4 0 2
            # 4 4 3 2
            # 4 4 5 2 -> X
            # 4 4 3 4
            # 4 4 4 4 -> True
            # 처리됨

            # 숙제 - 재귀코드 반복문으로 만들기
            return is_edge_in_square(side1 + matchsticks[index], side2, side3, side4, index + 1) or \
                    is_edge_in_square(side1, side2 + matchsticks[index] , side3, side4, index + 1) or \
                    is_edge_in_square(side1, side2, side3 + matchsticks[index], side4, index + 1) or \
                    is_edge_in_square(side1, side2, side3, side4 + matchsticks[index] , index + 1)

        return is_edge_in_square(0, 0, 0, 0, 0)



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

    
    def cannot_make_square(self):
        res = self.solution.makesquare(matchsticks=[2, 2, 2])
        self.assertEqual(res, False)

    def test_case_normal_1(self):
        res = self.solution.makesquare(matchsticks=[1, 1, 2, 2, 2])
        self.assertEqual(res, True)

    def test_case_normal_2(self):
        res = self.solution.makesquare(matchsticks=[3, 3, 3, 3, 4])
        self.assertEqual(res, False)

    def test_case_normal_3(self):
        res = self.solution.makesquare(matchsticks=[1, 3, 1, 4, 3, 4])
        self.assertEqual(res, True)

    def test_case_normal_4(self):
        res = self.solution.makesquare(matchsticks=[1, 3, 1, 4, 3, 2, 6])
        self.assertEqual(res, False)




if __name__ == "__main__":
    # 스크립트 실행 시, 해당 부분 동작
    unittest.main(verbosity=0)
    pass
