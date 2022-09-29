#!/usr/bin/python3
import unittest
from typing import List


"""
Solution Note

1 <= k <= arr.length
1 <= arr.length <= 10**4
arr is sorted in ascending order.
-10**4 <= arr[i], x <= 10**4
"""

# Leet Code Solution
class Solution:
    def findClosestElements(self, arr: List[int], k: int, x: int) -> List[int]:
        # l = low
        l = 0
        # h = high
        h = len(arr) - k
        # high = len(arr)(5) - k(3) = 2
        # [1,2,3,4,5] k=3, x=3
        while l < h:
            mid = l + (h - l) // 2

            # l=0, h=2, mid=1
            # x(3) - arr[2](3) > arr[1+3](5) - x(3)
            # 0 > 2 (False) h=1
            # l=0, h=1, mid=0
            # x(3) - arr[0](1) > arr[0+3](4) - x(3)
            # 2 > 1 (True) l=1
            # l=1, h=1, mid=0 (False)
            if x - arr[mid] > arr[mid + k] - x:
                l = mid + 1
            else:
                h = mid

        # arr[1:1+3] = arr[1:4] = [2,3,4]
        return arr[l:l+k]

    def findClosestElements1(self, arr: List[int], k: int, x: int) -> List[int]:
        low = 0
        high = len(arr) - k

        while low < high:
            mid = low + (high - low) // 2
            if x - arr[mid] > arr[mid + k] - x:
                low = mid + 1
            else:
                high = mid

        return arr[low:low + k]





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
        res = self.solution.findClosestElements(arr = [1,2,3,4,5], k = 4, x = 3)
        self.assertEqual(res, [1,2,3,4])

    def test_case_normal_2(self):
        res = self.solution.findClosestElements(arr = [1,2,3,4,5], k = 4, x = -1)
        self.assertEqual(res, [1,2,3,4])



if __name__ == "__main__":
    # 스크립트 실행 시, 해당 부분 동작
    unittest.main(verbosity=0)
    pass
