#!/usr/bin/python3
import unittest
from typing import List
from typing import Optional


"""
Solution Note

"""

# Leet Code Solution

class Solution:
    def searchInsert(self, nums: List[int], target: int) -> int:
        # Search - 했는데 있으면 인덱스 리턴
        # 없을 경우 - 들어갈 인덱스 찾기
        left: int  = 0
        right: int = len(nums) - 1

        while left <= right:
            mid: int = (left + right) // 2 # 3.2 -> 3
            if nums[mid] == target:
                return mid

            # 타겟이 중간값보다 더 크면 오른쪽을 검색
            if nums[mid] < target:
                left = mid + 1
            # 타겟이 중간값보다 더 작으면 왼쪽 검색
            else:
                right = mid - 1
        return left




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
        res = self.solution.searchInsert(nums = [1,3,5,6], target = 5)
        self.assertEqual(res, 2)

    def test_case_2(self):
        res = self.solution.searchInsert(nums = [1,3,5,6], target = 2)
        self.assertEqual(res, 1)

    def test_case_3(self):
        res = self.solution.searchInsert(nums = [1,3,5,6], target = 7)
        self.assertEqual(res, 4)




if __name__ == "__main__":
    # 스크립트 실행 시, 해당 부분 동작
    unittest.main(verbosity=0)
