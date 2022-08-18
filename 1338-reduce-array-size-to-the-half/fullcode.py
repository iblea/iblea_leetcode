#!/usr/bin/python3
import unittest
from typing import List

from collections import Counter


"""
Solution Note

2 <= arr.length <= 10**5
arr.length is even.
1 <= arr[i] <= 10**5
"""

# Leet Code Solution
class Solution:
    def minSetSize(self, arr: List[int]) -> int:
        total_len = len(arr)
        limit_len = total_len // 2

        del_count = 0
        del_number = 0
        counter = Counter(arr).most_common()

        for count in counter:
            del_count += count[1]
            del_number += 1
            if del_count >= limit_len:
                return  del_number
        return 0



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
        res = self.solution.minSetSize([3,3,3,3,5,5,5,2,2,7])
        self.assertEqual(res, 2)

    def test_case_normal_2(self):
        res = self.solution.minSetSize([7,7,7,7,7,7])
        self.assertEqual(res, 1)



if __name__ == "__main__":
    # 스크립트 실행 시, 해당 부분 동작
    unittest.main(verbosity=0)
    pass
