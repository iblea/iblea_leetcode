#!/usr/bin/python3
import unittest
from typing import List
from typing import Optional


"""
Solution Note

You are given a 0-indexed integer array nums of size n, and a 0-indexed integer array pattern of size m consisting of integers -1, 0, and 1.
A subarray nums[i..j] of size m + 1 is said to match the pattern if the following conditions hold for each element pattern[k]:

- nums[i + k + 1] > nums[i + k] if pattern[k] == 1.
- nums[i + k + 1] == nums[i + k] if pattern[k] == 0.
- nums[i + k + 1] < nums[i + k] if pattern[k] == -1.
Return the count of subarrays in nums that match the pattern.
"""

# Leet Code Solution

class Solution:
    def countMatchingSubarrays(self, nums: List[int], pattern: List[int]) -> int:

        answer = 0
        for i in range(len(nums)):
            pi = 0
            ok = True
            for pi in range(len(pattern)):
                idx = i + pi
                if idx + 1 >= len(nums):
                    ok = False
                    break

                if pattern[pi] == 1:
                    if nums[idx] >= nums[idx + 1]:
                        ok = False
                        break
                elif pattern[pi] == -1:
                    if nums[idx] <= nums[idx + 1]:
                        ok = False
                        break
                else:
                    if nums[idx] != nums[idx + 1]:
                        ok = False
                        break
            if ok:
                answer += 1
        return answer




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
        res = self.solution.countMatchingSubarrays(nums = [1,2,3,4,5,6], pattern = [1,1])
        self.assertEqual(res, 4)

    def test_case_2(self):
        res = self.solution.countMatchingSubarrays(nums = [1,4,4,1,3,5,5,3], pattern = [1,0,-1])
        self.assertEqual(res, 2)



if __name__ == "__main__":
    # 스크립트 실행 시, 해당 부분 동작
    unittest.main(verbosity=0)
