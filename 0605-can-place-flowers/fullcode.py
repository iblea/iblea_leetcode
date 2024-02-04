#!/usr/bin/python3
import unittest
from typing import List


"""
Solution Note

"""

# Leet Code Solution

class Solution:
    def canPlaceFlowers(self, flowerbed: List[int], n: int) -> bool:

        last = len(flowerbed) - 1

        if n == 0:
            return True

        if len(flowerbed) == 1:
            if flowerbed[0] == 0:
                return True
            else:
                return False

        for i in range(len(flowerbed)):
            if flowerbed[i] == 1:
                i += 1
                continue
            if i == 0:
                if flowerbed[i+1] == 0:
                    flowerbed[i] = 1
                    n -= 1
                    i += 1
            elif i == last:
                if flowerbed[i-1] == 0:
                    flowerbed[i] = 1
                    n -= 1
            else:
                if flowerbed[i-1] == 0 and flowerbed[i+1] == 0:
                    flowerbed[i] = 1
                    n -= 1
                    i += 1
            if n == 0:
                return True
        return False



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
        res = self.solution.canPlaceFlowers(flowerbed = [1,0,0,0,1], n = 1)
        self.assertEqual(res, True)

    def test_case_2(self):
        res = self.solution.canPlaceFlowers(flowerbed = [1,0,0,0,1], n = 2)
        self.assertEqual(res, False)



if __name__ == "__main__":
    # 스크립트 실행 시, 해당 부분 동작
    unittest.main(verbosity=0)
    pass
