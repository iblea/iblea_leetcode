#!/opt/homebrew/bin/python3
import unittest
from typing import List


"""
Solution Note

Given an unsorted integer array nums. Return the smallest positive integer that is not present in nums.
You must implement an algorithm that runs in O(n) time and uses O(1) auxiliary space.

정렬되지 않은 정수 배열 번호가 주어지면 숫자에 없는 가장 작은 양의 정수를 반환하라.
O(n) 시간에 실행되고 O(1) 보조공간을 사용하는 알고리즘을 구현해야 한다.

O(n) - 즉 정렬 불가.
O(1) - 즉 추가 메모리 사용 불가.
"""

# Leet Code Solution

class Solution:
    def firstMissingPositive(self, nums: List[int]) -> int:
        for i in range(len(nums)):

            # normal case or already sorted.
            if nums[i] == i + 1:
                continue

            # abnormal case
            if nums[i] <= 0 or nums[i] > len(nums):
                nums[i] = -1
                continue

            # nums[0] = 1
            # nums[1] = 2
            # nums[2] = 3
            # nums[i] = i + 1
            # nums[i - 1] = i
            # ...

            self.changeIndex(nums, i)
        for i in range(len(nums)):
            if nums[i] != i + 1:
                return i + 1
        return len(nums) + 1

    def changeIndex(self, nums: List[int], i: int) -> None:
        while True:
            # i = 1
            # [3, 4, -1, 1]
            # [-1, 4, 3, 1]
            # [1, 3, -1, 4]
            # [1, -1, 3, 4]

            agovalue: int = nums[i]
            tmpValue: int = nums[agovalue - 1]
            nums[agovalue - 1] = nums[i]
            if nums[i] == tmpValue:
                break
            if tmpValue <= 0 or tmpValue > len(nums):
                nums[i] = -1
                break
            # value는 또다른 인덱스이다.
            nums[i] = tmpValue



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
        res = self.solution.firstMissingPositive(nums = [1,2,0])
        self.assertEqual(res, 3)

    def test_case_2(self):
        res = self.solution.firstMissingPositive(nums = [3,4,-1,1])
        self.assertEqual(res, 2)

    def test_case_3(self):
        res = self.solution.firstMissingPositive(nums = [7,8,9,11,12])
        self.assertEqual(res, 1)



if __name__ == "__main__":
    # 스크립트 실행 시, 해당 부분 동작
    unittest.main(verbosity=0)
