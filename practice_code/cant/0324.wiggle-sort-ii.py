#!/usr/bin/python3
import unittest
from typing import List
from typing import Optional


"""
Solution Note
https://leetcode.com/problems/wiggle-sort-ii

Given an integer array nums, reorder it such that nums[0] < nums[1] > nums[2] < nums[3]....
You may assume the input array always has a valid answer.

1 <= nums.length <= 5 * 10**4
0 <= nums[i] <= 5000
It is guaranteed that there will be an answer for the given input nums.
"""

# Leet Code Solution

class Solution:
    def wiggleSort(self, nums: List[int]) -> None:
        """
        Do not return anything, modify nums in-place instead.
        """
        nums.sort()
        k = (len(nums) - 1) // 2 + 1
        lower = nums[:k].copy()
        higher = nums[k:].copy()
        l = 0
        h = 0
        for i in range(len(nums)-1, -1, -1):
            if i % 2 == 1:
                nums[i] = higher[h]
                h += 1
            else:
                nums[i] = lower[l]
                l += 1


    def wiggleSort1(self, nums: List[int]) -> None:
        """
        Do not return anything, modify nums in-place instead.
        """
        nums1 = nums.copy()
        nums1.sort()

        n = len(nums)
        i = n - 1
        j = 0
        k = i // 2 + 1

        while i >= 0:
            if i % 2 == 1:
                nums[i] = nums1[k]
                k += 1
            else:
                nums[i] = nums1[j]
                j += 1

            i -= 1





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
        res = [1, 1, 2, 1, 2, 2, 1]
        self.solution.wiggleSort(res)
        self.assertEqual(res, [1,2,1,2,1,2,1])

    def test_case_2(self):
        res = [1, 1, 2, 2, 2, 1]
        self.solution.wiggleSort(res)
        self.assertEqual(res, [1,2,1,2,1,2])



if __name__ == "__main__":
    # 스크립트 실행 시, 해당 부분 동작
    unittest.main(verbosity=0)
