#!/usr/bin/python3
import unittest
from typing import List


"""
Solution Note

"""

# Leet Code Solution

class Solution:
    def majorityElement(self, nums: List[int]) -> int:
        if len(nums) // 2 == 0:
            major = len(nums) // 2
        else:
            major = len(nums) // 2 + 1

        numdicts: dict = {}
        for num in nums:
            if num in numdicts:
                numdicts[num] += 1
            else:
                numdicts[num] = 1

            if numdicts[num] >= major:
                return num
        pass





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
        res = self.solution.majorityElement(nums = [3,2,3])
        self.assertEqual(res, 3)

    def test_case_2(self):
        res = self.solution.majorityElement(nums = [2,2,1,1,1,2,2])
        self.assertEqual(res, 2)




if __name__ == "__main__":
    # 스크립트 실행 시, 해당 부분 동작
    unittest.main(verbosity=0)
    pass
