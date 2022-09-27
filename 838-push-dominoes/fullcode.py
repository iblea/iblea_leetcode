#!/usr/bin/python3
import unittest
from typing import *


"""
Solution Note

n == dominoes.length
1 <= n <= 10**5
dominoes[i] is either 'L', 'R', or '.'.
"""

# Leet Code Solution
class Solution:
    def pushDominoes(self, dominoes: str) -> str:
        left_domino = self.leftside(dominoes)
        right_domino = self.rightside(dominoes)
        
        answer = self.merge(left_domino, right_domino)
        # print(dominoes)
        # print(left_domino)
        # print(right_domino)
        # print(answer)
        # print("")
        return answer
    
    def merge(self, left: str, right: str):
        result: List[str] = [ "." for _ in range(len(left)) ]

        for j in range(len(left)):
            if left[j] != "L":
                break
            result[j] = "L"
        # merge starting point
        i = j
        for j in range(len(right) - 1, -1 ,-1):
            if right[j] != "R":
                break
            result[j] = "R"

        end = j
        while i <= end: 
            if left[i] == right[i]:
                result[i] = left[i]
                i += 1
                continue

            merge_start = i
            merge_start_char = result[i - 1]
            while left[i] != right[i]:
                i += 1
            merge_end = i - 1
            merge_end_char = left[i]
            merge_diff = merge_end - merge_start + 1

            # merge_start_char = R, merge_end_char = L
            # RLLLL
            # RRRRL
            # -> RR.LL
            if merge_start_char != merge_end_char:
                for j in range(merge_diff // 2):
                    result[merge_start + j] = "R"
                    result[merge_end - j] = "L"
            # merge_start_char = R, merge_end_char = R
            # R...R
            # RRRRR
            # -> RRRRR
            else:
                for j in range(merge_diff):
                    result[merge_start + j] = merge_start_char

        return "".join(result)

    def leftside(self, minostr: str):
        mino: List[str] = list(minostr)
        break_down = False
        for i in range(len(mino) - 1, -1, -1):
            if mino[i] == "L":
                break_down = True
                continue
            if mino[i] == "R":
                break_down = False
                continue
            # mino [i] == "."
            if break_down is True:
                mino[i] = 'L'
        return "".join(mino)
    
    def rightside(self, minostr: str):
        mino: List[str] = list(minostr)
        break_down = False
        for i in range(len(mino)):
            if mino[i] == "L":
                break_down = False
                continue
            if mino[i] == "R":
                break_down = True
                continue
            # mino [i] == "."
            if break_down is True:
                mino[i] = "R"
        return "".join(mino)






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
        res = self.solution.pushDominoes("RR.L")
        self.assertEqual(res, "RR.L")

    def test_case_normal_2(self):
        res = self.solution.pushDominoes(".L.R...LR..L..")
        self.assertEqual(res, "LL.RR.LLRRLL..")

    def test_case_normal_3(self):
        res = self.solution.pushDominoes("R.R.L")
        self.assertEqual(res, "RRR.L")




if __name__ == "__main__":
    # 스크립트 실행 시, 해당 부분 동작
    unittest.main(verbosity=0)
    pass
