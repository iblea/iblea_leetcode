#!/usr/bin/python3
import unittest
from typing import List
from typing import Optional


"""
Solution Note

"""

# Leet Code Solution

class Solution:

    # https://leetcode.com/problems/combination-sum/discuss/4847482/Beat-82.92-or-Full-explanation-with-pictures
    def combinationSum(self, candidates: List[int], target: int) -> List[List[int]]:
        answer = []
        candidates.sort()

        def backtrack(start, target, path):
            if target == 0:
                answer.append(path.copy())
                return

            if target < 0:
                return

            for i in range(start, len(candidates)):
                path.append(candidates[i])
                backtrack(i, target - candidates[i], path)
                path.pop()

        backtrack(0, target, [])
        return answer


    # 내가 풀지 못한 문제.
    def combinationSum1(self, candidates: List[int], target: int) -> List[List[int]]:

        candidates.sort()

        answer: list = []

        def func(c, lst):

            sumval = sum(lst)

            # 정답인 경우
            if sumval == target:
                answer.append(lst.copy())
                lst.pop()
                return

            # 리스트에 어떤 값이 추가되어도 target을 매칭할 수 없는 경우
            if sumval + c[0] > target:
                lst.pop()
                return

            for i in range(len(c)):
                num = c[i]
                if sumval + num > target:
                    if len(lst) > 0:
                        lst.pop()
                    continue
                lst.append(num)
                tmp = lst.copy()
                func(c, lst)
            return

        # for i in range(len(candidates)-1):
        #     func(candidates[i:], [])
        func(candidates, [])
        print(answer)
        return answer







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
        res = self.solution.combinationSum([2,3,6,7], 7)
        self.assertEqual(res,  [[2,2,3],[7]])

    def test_case_2(self):
        res = self.solution.combinationSum(candidates = [2,3,5], target = 8)
        self.assertEqual(res,  [[2,2,2,2],[2,3,3],[3,5]])

    def test_case_3(self):
        res = self.solution.combinationSum([2], 1)
        self.assertEqual(res,  [])





if __name__ == "__main__":
    # 스크립트 실행 시, 해당 부분 동작
    unittest.main(verbosity=0)
