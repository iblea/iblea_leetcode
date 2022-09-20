#!/usr/bin/python3
import unittest
from typing import List


"""
Solution Note

1 <= nums1.length, nums2.length <= 1000
0 <= nums1[i], nums2[i] <= 100
"""


# Leet Code Solution
class Solution:
    def findLength(self, nums1: List[int], nums2: List[int]) -> int:
        n, m = len(nums1), len(nums2)
        dp = [[0] * (m + 1) for _ in range(n + 1)]

        # self.print_2arr(dp)
        for i in range(n):
            for j in range(m):
                if nums1[i] != nums2[j]:
                    continue
                dp[i + 1][j + 1] = dp[i][j] + 1
            # self.print_2arr(dp)

        # print("\n========================\n")
        return max(map(max, dp))

    def print_2arr(self, arr):
        for row in arr:
            print(row)
        print("")



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
        res = self.solution.findLength(nums1 = [1,2,3,2,1], nums2 = [3,2,1,4,7])
        self.assertEqual(res, 3)

    def test_case_normal_2(self):
        res = self.solution.findLength([0,0,0,0,0], nums2 = [0,0,0,0,0])
        self.assertEqual(res, 5)



if __name__ == "__main__":
    # 스크립트 실행 시, 해당 부분 동작
    unittest.main(verbosity=0)
    pass
