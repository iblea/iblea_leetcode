#!/usr/bin/python3
import unittest
from typing import List
from typing import Optional


"""
Solution Note

https://leetcode.com/problems/shortest-subarray-to-be-removed-to-make-array-sorted

Given an integer array arr, remove a subarray (can be empty) from arr such that the remaining elements in arr are non-decreasing.

Return the length of the shortest subarray to remove.
A subarray is a contiguous subsequence of the array.

정수 배열 arr이 주어지면 arr의 나머지 요소가 감소하지 않도록 arr에서 하위 배열(빈 상태일 수 있음)을 제거합니다.
제거할 최단 하위 배열의 길이를 반환합니다.
서브배열은 배열의 연속적인 후속작입니다.

- 정수 배열 arr이 주어졌을 때, arr에서 부분 배열(subarray)을 제거하여 남은 요소들이 비감소(non-decreasing) 수열이 되도록 만들어야 합니다.

1 <= arr.length <= 10**5
0 <= arr[i] <= 10**9
"""

# Leet Code Solution


class Solution:
    def findLengthOfShortestSubarray(self, arr: List[int]) -> int:

        n = len(arr)

        l = 0

        # 0,1,2,3,0
        while l + 1 < n and arr[l] <= arr[l+1]:
            l += 1

        l += 1

        if l == n:
            return 0

        r = n - 1
        while r > 0 and arr[r-1] <= arr[r]:
            r -= 1

        res = min(n - l, r)
        i = 0
        j = r

        # 이 로직이 없으면 반례 케이스가 존재함.
        # 1,2,3,4,5,3,4,5,6,7,8
        while i < l and j < n:
            if arr[i] <= arr[j]:
                res = min(res, j - i - 1)
                i += 1
            else:
                j += 1

        return res



    def findLengthOfShortestSubarray_answer(self, arr: List[int]) -> int:
        n = len(arr)

        # Step 1: Find the longest non-decreasing prefix
        left = 0
        while left + 1 < n and arr[left] <= arr[left + 1]:
            left += 1

        # If the entire array is already sorted
        if left == n - 1:
            return 0

        # Step 2: Find the longest non-decreasing suffix
        right = n - 1
        while right > 0 and arr[right - 1] <= arr[right]:
            right -= 1

        # Step 3: Find the minimum length to remove by comparing prefix and suffix
        result = min(n - left - 1, right)

        # Step 4: Use two pointers to find the smallest middle part to remove
        i, j = 0, right
        while i <= left and j < n:
            if arr[i] <= arr[j]:
                result = min(result, j - i - 1)
                i += 1
            else:
                j += 1

        return result









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
        res = self.solution.findLengthOfShortestSubarray(arr = [1,2,3,10,4,2,3,5])
        self.assertEqual(res, 3)
        """
        Explanation: The shortest subarray we can remove is [10,4,2] of length 3. The remaining elements after that will be [1,2,3,3,5] which are sorted.
        Another correct solution is to remove the subarray [3,10,4].
        [10,4,2]를 제거하면 남은 배열 [1,2,3,3,5]가 비감소 수열이 됨
        """

    def test_case_2(self):
        res = self.solution.findLengthOfShortestSubarray(arr = [5,4,3,2,1])
        self.assertEqual(res, 4)
        """
        Explanation: Since the array is strictly decreasing, we can only keep a single element. Therefore we need to remove a subarray of length 4, either [5,4,3,2] or [4,3,2,1].
        """

    def test_case_3(self):
        res = self.solution.findLengthOfShortestSubarray(arr = [1,2,3])
        self.assertEqual(res, 0)
        """
        Explanation: The array is already non-decreasing. We do not need to remove any elements.
        """

    def test_case_6(self):
        res = self.solution.findLengthOfShortestSubarray(arr = [1,2,3,4,5,100,101,102,10,11,12,13,14])
        self.assertEqual(res, 3)

    def test_case_7(self):
        res = self.solution.findLengthOfShortestSubarray(arr = [1,2,3,4,5,3,4,5,6,7,8])
        self.assertEqual(res, 2)
        """
        Explanation: The array is already non-decreasing. We do not need to remove any elements.
        """


    # def test_case_4(self):
    #     res = self.solution.findLengthOfShortestSubarray(arr = [10,11,12,1,2,3,7,4,5])
    #     self.assertEqual(res, 4)

    # def test_case_5(self):
    #     res = self.solution.findLengthOfShortestSubarray(arr = [10,11,12,1,2,20,3,4,5])
    #     self.assertEqual(res, 4)





if __name__ == "__main__":
    # 스크립트 실행 시, 해당 부분 동작
    unittest.main(verbosity=0)
