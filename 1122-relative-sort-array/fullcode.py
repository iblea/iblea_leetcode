#!/usr/bin/python3
import unittest
from typing import List
from typing import Optional


"""
Solution Note

"""

# Leet Code Solution

class Solution:
    def relativeSortArray(self, arr1: List[int], arr2: List[int]) -> List[int]:
        dic = {}
        for num in arr1:
            if num in dic:
                dic[num] += 1
            else:
                dic[num] = 1

        res = []
        for num in arr2:
            res += [num] * dic[num]
            dic.pop(num)

        keys = sorted(dic.keys())
        for key in keys:
            res += [key] * dic[key]
        return res




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
        res = self.solution.relativeSortArray(arr1 = [2,3,1,3,2,4,6,7,9,2,19], arr2 = [2,1,4,3,9,6])
        self.assertEqual(res, [2,2,2,1,4,3,3,9,6,7,19])

    def test_case_2(self):
        res = self.solution.relativeSortArray(arr1 = [28,6,22,8,44,17], arr2 = [22,28,8,6])
        self.assertEqual(res, [22,28,8,6,17,44])



if __name__ == "__main__":
    # 스크립트 실행 시, 해당 부분 동작
    unittest.main(verbosity=0)
