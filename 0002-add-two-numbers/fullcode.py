#!/usr/bin/python3
import unittest
from typing import List, Optional


"""
Solution Note

"""

# Leet Code Solution

class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next

# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def addTwoNumbers(self, l1: Optional[ListNode], l2: Optional[ListNode]) -> Optional[ListNode]:
        num1 = self.getnumber(l1)
        num2 = self.getnumber(l2)
        result = num1 + num2
        print(result)
        return self.setnumber(num1 + num2)

    def getnumber(self, l: Optional[ListNode]) -> int:
        num = 0
        increase = 1
        while l:
            num  = l.val * increase + num
            increase *= 10
            l = l.next
        return num

    def setnumber(self, num: int) -> Optional[ListNode]:
        if num == 0:
            return ListNode(0)

        res = ListNode()
        tail = res
        while True:
            tail.val = num % 10
            num //= 10
            if num == 0:
                break
            tail.next = ListNode()
            tail = tail.next
        return res



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

    # def test_case_1(self):
    #     res = self.solution.problem(1)
    #     self.assertEqual(res, 1)



if __name__ == "__main__":
    # 스크립트 실행 시, 해당 부분 동작
    unittest.main(verbosity=0)
    pass
