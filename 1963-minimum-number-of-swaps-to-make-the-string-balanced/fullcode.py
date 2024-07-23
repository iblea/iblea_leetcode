#!/usr/bin/python3
import unittest
from typing import List
from typing import Optional


"""
Solution Note

"""

# Leet Code Solution

class Solution:
    def minSwaps(self, s: str) -> int:

        # changed = 0
        # slist = list(s)
        # stack = []
        # for i in range(len(slist)):
        #     if len(stack) == 0 and slist[i] == ']':
        #         changed += 1
        #         continue

        #     if slist[i] == '[':
        #         stack.append(i)
        #         continue

        #     if slist[i] == ']':
        #         stack.pop()
        #         continue
        # return changed

        rotate = 0
        bracket = 0
        for c in s:
            if c == ']' and bracket == 0:
                rotate += 1

            if c == '[' or bracket == 0:
                bracket += 1
            else:
                bracket -= 1
        return rotate






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
        res = self.solution.minSwaps(s = "][][")
        self.assertEqual(res, 1)

    def test_case_2(self):
        res = self.solution.minSwaps(s = "]]][[[")
        self.assertEqual(res, 2)

    def test_case_3(self):
        res = self.solution.minSwaps(s = "[]")
        self.assertEqual(res, 0)


if __name__ == "__main__":
    # 스크립트 실행 시, 해당 부분 동작
    unittest.main(verbosity=0)
