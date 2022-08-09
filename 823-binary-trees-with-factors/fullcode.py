#!/usr/bin/python3
import unittest
from typing import List


"""
Solution Note
https://leetcode.com/problems/binary-trees-with-factors/

1 <= arr.length <= 1000
2 <= arr[i] <= 10^9
All the values of arr are unique

return modulo (10^9 + 7 = 1000000007)
"""

# Leet Code Solution

# 제곱근 구하는 내장 함수
from math import sqrt
# 소수 내리는 내장 함수
from math import floor
class Solution:
    modulo: int = 1000000007
    def numFactoredBinaryTrees(self, arr: List[int]) -> int:
        arr.sort()
        # mdict = multiplication dictionary
        numdict = {}
        for num in arr:
            numdict[num] = True

        mdict = {}
        mdict[1] = 1
        mdict[arr[0]] = 1

        for i in range(1, len(arr)):
            cur = arr[i]
            mdict[cur] = 1
            sqrt_num = floor(sqrt(cur))
            if sqrt_num * sqrt_num == cur:
                if sqrt_num in mdict:
                    mdict[cur] += (mdict[sqrt_num] * mdict[sqrt_num])
                    sqrt_num -= 1

            sqrt_num += 1
            for j in range(i):
                num = arr[j]
                if num >= sqrt_num:
                    break
                # 숫자가 배열에 있는지부터 체크한다.
                if not (num in numdict):
                    continue
                if cur % num != 0:
                    continue

                if not (cur // num in numdict):
                    continue

                mdict[cur] += ( mdict[num] * mdict[cur // num] ) * 2

        answer: int = sum(mdict.values()) - 1
        return answer % self.modulo




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
        res = self.solution.numFactoredBinaryTrees([2,4])
        self.assertEqual(res, 3)

    def test_case_normal_2(self):
        res = self.solution.numFactoredBinaryTrees([2,4,10,5])
        self.assertEqual(res, 7)

    def test_case_normal_3(self):
        res = self.solution.numFactoredBinaryTrees([18,3,6,2])
        self.assertEqual(res, 12)

    def test_case_normal_4(self):
        res = self.solution.numFactoredBinaryTrees([2,10,5])
        self.assertEqual(res, 5)

    def test_case_normal_5(self):
        res = self.solution.numFactoredBinaryTrees([17,22,8,25])
        self.assertEqual(res, 4)

    def test_case_normal_6(self):
        lst = [45,42,2,18,23,1170,12,41,40,9,47,24,33,28,10,32,29,17,46,11,
            759,37,6,26,21,49,31,14,19,8,13,7,27,22,3,36,34,38,39,30,43,15,
            4,16,35,25,20,44,5,48]
        res = self.solution.numFactoredBinaryTrees(lst)
        self.assertEqual(res, 777)



if __name__ == "__main__":
    # 스크립트 실행 시, 해당 부분 동작
    unittest.main(verbosity=0)
    pass
