#!/usr/bin/python3
import unittest
from typing import List


"""
Solution Note

"""

# Leet Code Solution

MAXVAL=2**31
class MinStack:

    def __init__(self):
        self.stack: list[int] = []
        self.min: int = MAXVAL


    def push(self, val: int) -> None:
        self.stack.append(val)
        if val < self.min:
            self.min = val


    def pop(self) -> None:
        self.stack.pop()
        self.min = min(self.stack, default=MAXVAL)


    def top(self) -> int:
        return self.stack[-1]


    def getMin(self) -> int:
        return self.min



# Your MinStack object will be instantiated and called as such:
# obj = MinStack()
# obj.push(val)
# obj.pop()
# param_3 = obj.top()
# param_4 = obj.getMin()




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
        res = self.solution.problem(1)
        self.assertEqual(res, 1)



if __name__ == "__main__":
    # 스크립트 실행 시, 해당 부분 동작
    unittest.main(verbosity=0)
    pass
