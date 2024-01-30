#!/usr/bin/python3
import unittest
from typing import List


"""
Solution Note

case 1: 0이 2개 이상인 경우 -> 모든 값이 0
case 2: 0이 1개인 경우 -> 0이 아닌 값은 모두 0
case 3: 0이 없는 경우 -> 모든 값의 곱을 구한 후, 각각의 값으로 나누기
"""

# Leet Code Solution

class Solution:
    def productExceptSelf(self, nums: List[int]) -> List[int]:
        multiple_num = 1
        num_zero_count = 0

        for num in nums:
            if num == 0:
                num_zero_count += 1
                continue
            multiple_num *= num

        if num_zero_count >= 2:
            return [0] * len(nums)
        if num_zero_count == 1:
            return [0 if num != 0 else multiple_num for num in nums]
        return [multiple_num // num for num in nums]




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

    def test_case_1(self):
        res = self.solution.productExceptSelf(nums = [1,2,3,4])
        self.assertEqual(res, [24,12,8,6])
    def test_case_2(self):
        res = self.solution.productExceptSelf(nums = [-1,1,0,-3,3])
        self.assertEqual(res, [0,0,9,0,0])

    def test_case_3(self):
        res = self.solution.productExceptSelf(nums = [0,0,3,3,0])
        self.assertEqual(res, [0,0,0,0,0])



if __name__ == "__main__":
    # 스크립트 실행 시, 해당 부분 동작
    unittest.main(verbosity=0)
    pass
