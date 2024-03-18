#!/usr/bin/python3
import unittest
from typing import List
from typing import Optional


"""
Solution Note


4 5 6 7 8 1 2
      ^
4 5 6 7 0 1 2
      ^
5 6 7 0 1 2 4
      ^

6 7 0 1 2 4 5
      ^

"""

# Leet Code Solution

class Solution:
    def findMin(self, nums: List[int]) -> int:
        left: int  = 0
        right: int = len(nums) - 1

        while True:
            if nums[left] <= nums[right]:
                return nums[left]

            mid: int = (left + right) // 2 # 3.2 -> 3
            if nums[left] > nums[mid]:
                right = mid
            else:
                left = mid + 1




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
        res = self.solution.findMin(nums = [3,4,5,1,2])
        self.assertEqual(res, 1)

    def test_case_2(self):
        res = self.solution.findMin(nums = [4,5,6,7,0,1,2])
        self.assertEqual(res, 0)

    def test_case_3(self):
        res = self.solution.findMin(nums = [11,13,15,17])
        self.assertEqual(res, 11)

    def test_case_4(self):
        res = self.solution.findMin(nums = [1])
        self.assertEqual(res, 1)




if __name__ == "__main__":
    # 스크립트 실행 시, 해당 부분 동작
    unittest.main(verbosity=0)
