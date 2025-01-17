#!/usr/bin/python3
import unittest
from typing import List
from typing import Optional


"""
Solution Note

"""

# Leet Code Solution

class Solution:
    def candy(self, ratings: List[int]) -> int:

        candys = [ 1 for _ in ratings ]

        for i in range(1, len(ratings)):
            if ratings[i] > ratings[i-1] and candys[i] <= candys[i-1]:
                candys[i] = candys[i-1] + 1

        for i in range(len(ratings)-1, 0, -1):
            if ratings[i-1] > ratings[i] and candys[i-1] <= candys[i]:
                candys[i-1] = candys[i] + 1

        return sum(candys)




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
        res = self.solution.problem(1)
        self.assertEqual(res, 1)



if __name__ == "__main__":
    # 스크립트 실행 시, 해당 부분 동작
    unittest.main(verbosity=0)
