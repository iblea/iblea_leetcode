#!/usr/bin/python3
import unittest
from typing import List
from typing import Optional


"""
Solution Note

https://leetcode.com/problems/find-the-power-of-k-size-subarrays-i/

You are given an array of integers nums of length n and a positive integer k.
The power of an array is defined as:

- Its maximum element if all of its elements are consecutive and sorted in ascending order.
- -1 otherwise.

You need to find the power of all subarrays of nums of size k.
Return an integer array results of size n - k + 1, where results[i] is the power of nums[i..(i + k - 1)].

다음은 주어진 배열 nums의 길이 n과 양의 정수 k에 대한 설명입니다. 배열의 power는 다음과 같이 정의됩니다:
- 배열의 모든 요소가 연속적이고 오름차순으로 정렬되어 있으면 배열의 최대 요소입니다.
- 그렇지 않으면 -1입니다.
nums의 크기가 k인 모든 부분 배열의 power를 찾아야 합니다.
결과는 크기가 n - k + 1인 정수 배열로 반환해야 하며, 결과[i]는 nums[i..(i + k - 1)]의 power입니다.

1 <= n == nums.length <= 500
1 <= nums[i] <= 10**5
1 <= k <= n
"""

# Leet Code Solution
class Solution:
    def resultsArray(self, nums: List[int], k: int) -> List[int]:
        if k == 1:
            return nums

        l = 0
        r = k - 1
        length = len(nums)
        answer = []

        while r < length:
            is_sorted = True
            for i in range(l, r):
                if nums[i] + 1 != nums[i + 1]:
                    is_sorted = False
                    break
            if is_sorted:
                answer.append(nums[r])
            else:
                answer.append(-1)
            l += 1
            r += 1
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
        res = self.solution.resultsArray(nums = [1,2,3,4,3,2,5], k = 3)
        self.assertEqual(res, [3,4,-1,-1,-1])

        """
        Explanation:
        There are 5 subarrays of nums of size 3:
        [1, 2, 3] with the maximum element 3.
        [2, 3, 4] with the maximum element 4.
        [3, 4, 3] whose elements are not consecutive.
        [4, 3, 2] whose elements are not sorted.
        [3, 2, 5] whose elements are not consecutive.
        """

    def test_case_2(self):
        res = self.solution.resultsArray(nums = [2,2,2,2,2], k = 4)
        self.assertEqual(res, [-1,-1])

    def test_case_3(self):
        res = self.solution.resultsArray(nums = [3,2,3,2,3,2], k = 2)
        self.assertEqual(res,  [-1,3,-1,3,-1])

    def test_case_4(self):
        res = self.solution.resultsArray(nums = [1,3,4], k = 2)
        self.assertEqual(res,  [-1,4])




if __name__ == "__main__":
    # 스크립트 실행 시, 해당 부분 동작
    unittest.main(verbosity=0)
