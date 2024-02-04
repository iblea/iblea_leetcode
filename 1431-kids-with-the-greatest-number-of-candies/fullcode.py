#!/usr/bin/python3
import unittest
from typing import List


"""
Solution Note

"""

# Leet Code Solution


class Solution:
    def kidsWithCandies(self, candies: List[int], extraCandies: int) -> List[bool]:
        max_candies: int = max(candies)
        answer: List[bool] = [ ]
        for candy in candies:
            if candy + extraCandies >= max_candies:
                answer.append(True)
            else:
                answer.append(False)

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
        res = self.solution.kidsWithCandies(candies = [2,3,5,1,3], extraCandies = 3)
        self.assertEqual(res, [True,True,True,False,True])

    def test_case_2(self):
        res = self.solution.kidsWithCandies(candies = [4,2,1,1,2], extraCandies = 1)
        self.assertEqual(res, [True,False,False,False,False])

    def test_case_3(self):
        res = self.solution.kidsWithCandies(candies = [12,1,12], extraCandies = 10)
        self.assertEqual(res, [True,False,True])


if __name__ == "__main__":
    # 스크립트 실행 시, 해당 부분 동작
    unittest.main(verbosity=0)
    pass
