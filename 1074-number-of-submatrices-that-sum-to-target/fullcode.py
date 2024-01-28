#!/usr/bin/python3
import unittest
from typing import List


"""
Solution Note

행렬계산

0 1 0
1 1 1
0 1 0

에서 3을 찾을 경우

아래 행렬 4개
0 1
1 1

아래 행렬 1개
1 1 1

아래 행렬 1개
1
1
1

총 6개

즉
0 0 0
0 1 3
3 5 6
"""

# Leet Code Solution (풀지 못함 해설 보고 풀이)
# https://leetcode.com/problems/number-of-submatrices-that-sum-to-target/solutions/4636811/beats-100-py-java-c-c-c-js-go-rust
class Solution:
    def numSubmatrixSumTarget(self, matrix: List[List[int]], target: int) -> int:
        for row in matrix:
            for i in range(len(row)-1):
                row[i+1] += row[i]

        count = 0
        for t in range(len(matrix)):
            for b in range(t, -1, -1):
                if t == b:
                    cur = matrix[t][:]
                else:
                    cur = [cur[i]+matrix[b][i] for i in range(len(matrix[0]))]
                # 행렬 합 계산 및 save 시킨다.
                seen = {0: 1}
                for v in cur:
                    if v - target in seen:
                        print("seen[v - target] :", seen[v - target])
                        count += seen[v - target]
                    seen[v] = seen.get(v, 0) + 1
        return count


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
        res = self.solution.numSubmatrixSumTarget(matrix = [[0,1,0],[1,1,1],[0,1,0]], target = 0)
        self.assertEqual(res, 4)

    def test_case_2(self):
        res = self.solution.numSubmatrixSumTarget(matrix = [[1,-1],[-1,1]], target = 0)
        self.assertEqual(res, 5)

    def test_case_3(self):
        res = self.solution.numSubmatrixSumTarget(matrix = [[904]], target = 0)
        self.assertEqual(res, 0)

    def test_case_4(self):
        res = self.solution.numSubmatrixSumTarget(matrix = [[0,1,0],[1,1,1],[0,1,0]], target = 3)
        self.assertEqual(res, 6)



if __name__ == "__main__":
    # 스크립트 실행 시, 해당 부분 동작
    unittest.main(verbosity=0)
    pass
