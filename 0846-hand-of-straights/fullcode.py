#!/usr/bin/python3
import unittest
from typing import List
from typing import Optional


"""
Solution Note

"""

# Leet Code Solution

class Solution:
    def isNStraightHand(self, hand: List[int], groupSize: int) -> bool:
        if len(hand) % groupSize != 0:
            return False

        hand.sort()
        while len(hand) > 0:
            start = hand[0]
            for i in range(groupSize):
                if start + i not in hand:
                    return False
                hand.remove(start + i)

        return True



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
        res = self.solution.isNStraightHand(hand = [1,2,3,6,2,3,4,7,8], groupSize = 3)
        self.assertTrue(res)

    def test_case_2(self):
        res = self.solution.isNStraightHand(hand = [1,2,3,4,5], groupSize = 4)
        self.assertFalse(res)




if __name__ == "__main__":
    # 스크립트 실행 시, 해당 부분 동작
    unittest.main(verbosity=0)
