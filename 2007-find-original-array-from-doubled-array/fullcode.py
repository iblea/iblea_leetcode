#!/usr/bin/python3
import unittest
from typing import List

from collections import Counter

"""
Solution Note

1 <= changed.length <= 10**5
0 <= changed[i] <= 10**5
"""

# Leet Code Solution
class Solution:
    def findOriginalArray(self, changed: List[int]) -> List[int]:
        changed.sort()
        counter = Counter(changed)
        result = []
        # 0에 대한 예외처리 진행
        if 0 in counter:
            if counter[0] % 2 == 1:
                return []
            for i in range(counter[0] // 2):
                result.append(0)
            del counter[0]

        for count in counter:
            if counter[count] == 0:
                continue
            if count * 2 in counter:
                if counter[count] > counter[count * 2]:
                    return []
                for i in range(counter[count]):
                    result.append(count)
                counter[count * 2] -= counter[count]
                counter[count] -= counter[count]
            else:
                if counter[count] > 0:
                    return []
        return result




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
        res = self.solution.findOriginalArray([1,3,4,2,6,8])
        self.assertEqual(res, [1,3,4])

    def test_case_normal_2(self):
        res = self.solution.findOriginalArray([6,3,0,1])
        self.assertEqual(res, [])

    def test_case_normal_3(self):
        res = self.solution.findOriginalArray([1])
        self.assertEqual(res, [])

    def test_case_normal_4(self):
        res = self.solution.findOriginalArray([0])
        self.assertEqual(res, [])

    def test_case_normal_5(self):
        res = self.solution.findOriginalArray([0,0,0,0])
        self.assertEqual(res, [0,0])

    def test_case_normal_6(self):
        res = self.solution.findOriginalArray([1,2,1,2])
        self.assertEqual(res, [1,1])

    def test_case_normal_7(self):
        res = self.solution.findOriginalArray([2,1])
        self.assertEqual(res, [1])





if __name__ == "__main__":
    # 스크립트 실행 시, 해당 부분 동작
    unittest.main(verbosity=0)
    pass
