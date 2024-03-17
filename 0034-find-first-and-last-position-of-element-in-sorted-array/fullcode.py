#!/usr/bin/python3
import unittest
from typing import List
from typing import Optional


"""
Solution Note

"""

# Leet Code Solution

# The isBadVersion API is already defined for you.
# def isBadVersion(version: int) -> bool:

class Solution:
    def searchRange(self, nums: List[int], target: int) -> List[int]:

        left = 0
        right = len(nums) - 1

        while left <= right:
            mid = (left + right) // 2
            if nums[mid] == target:
                start = mid
                while nums[start] == target and start >= 0:
                    start -= 1

                end = mid
                while end < len(nums) and nums[end] == target:
                    end += 1
                return [start + 1, end - 1]
            elif nums[mid] < target:
                left = mid + 1
            else:
                right = mid - 1

        return [-1, -1]




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
        res = self.solution.searchRange(nums = [5,7,7,8,8,10], target = 8)
        self.assertEqual(res, [3, 4])

    def test_case_2(self):
        res = self.solution.searchRange(nums = [5,7,7,8,8,10], target = 6)
        self.assertEqual(res, [-1, 1])

    def test_case_3(self):
        res = self.solution.searchRange(nums = [], target = 0)
        self.assertEqual(res, [-1, -1])



if __name__ == "__main__":
    # 스크립트 실행 시, 해당 부분 동작
    unittest.main(verbosity=0)
