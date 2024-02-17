#!/usr/bin/python3
import unittest
from typing import List


"""
Solution Note

"""

# Leet Code Solution

class Solution:
    def timeRequiredToBuy(self, tickets: List[int], k: int) -> int:
        want_ticket: int = tickets[k]
        second: int = 0
        for i in range(len(tickets)):
            ticket: int = tickets[i]
            if ticket < want_ticket:
                second += ticket
                continue

            second += want_ticket
            if i > k:
                second -= 1
        return second





# python unit test
class UnitTest(unittest.TestCase):

    # 클래스 생성 시 1회 실행
    @classmethod
    def setUpClass(self):
        self.solution = Solution()

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
        res = self.solution.timeRequiredToBuy(tickets = [2,3,2], k = 2)
        self.assertEqual(res, 6)

    def test_case_2(self):
        res = self.solution.timeRequiredToBuy(tickets = [5,1,1,1], k = 0)
        self.assertEqual(res, 8)

    def test_case_3(self):
        res = self.solution.timeRequiredToBuy(tickets = [5,1,4,1], k = 2)
        self.assertEqual(res, 10)

    def test_case_4(self):
        res = self.solution.timeRequiredToBuy([84,49,5,24,70,77,87,8], 3)
        self.assertEqual(res, 154)
        # 24+24+5+24+24+24+24+8=157



if __name__ == "__main__":
    # 스크립트 실행 시, 해당 부분 동작
    unittest.main(verbosity=0)
    pass
