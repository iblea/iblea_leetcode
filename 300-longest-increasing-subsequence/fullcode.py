#!/usr/bin/python3
import unittest
from typing import List


"""
Solution Note

1 <= nums.length <= 2500
-10^4 <= nums[i] <= 10^4
"""

# Leet Code Solution
from bisect import bisect_left
class Solution:
    def lengthOfLIS(self, nums: List[int]) -> int:
        lis = [ nums[0] ]
        for i in range(1, len(nums)):
            if (nums[i] > lis[-1]):
                lis.append(nums[i])
                continue

            index = bisect_left(lis, nums[i])
            # index가 len(lis) 일 리는 없다 (num[i] > lis[-1]) 에서 처리했기 때문
            if lis[index] == nums[i]:
                continue
            lis[index] = nums[i]

        return len(lis)



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

    def test_case_normal_1(self):
        res = self.solution.lengthOfLIS([10,9,2,5,3,7,101,18])
        self.assertEqual(res, 4)

    def test_case_normal_2(self):
        res = self.solution.lengthOfLIS([0,1,0,3,2,3])
        self.assertEqual(res, 4)

    def test_case_normal_3(self):
        res = self.solution.lengthOfLIS([7,7,7,7,7,7,7])
        self.assertEqual(res, 1)

    def test_case_normal_4(self):
        res = self.solution.lengthOfLIS([4,10,4,3,8,9])
        self.assertEqual(res, 3)



if __name__ == "__main__":
    # 스크립트 실행 시, 해당 부분 동작
    unittest.main(verbosity=0)
    pass
