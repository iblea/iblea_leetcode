#!/usr/bin/python3
import unittest
from typing import List
from typing import Optional


class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next


"""
Solution Note

"""

# Leet Code Solution

# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def removeNthFromEnd(self, head: Optional[ListNode], n: int) -> Optional[ListNode]:
        if head is None:
            return None
        if n == 1 and head.next is None:
            return None
        lst = []
        while head:
            lst.append(head)
            head = head.next

        change_index: int = len(lst) - n
        prev_node: ListNode = lst[change_index - 1]
        if n == 1:
            prev_node.next = None
        elif change_index == 0:
            return lst[1]
        else:
            next_node: ListNode = lst[change_index + 1]
            prev_node.next = next_node
        return lst[0]





# python unit test
class UnitTest(unittest.TestCase):

    # 클래스 생성 시 1회 실행
    @classmethod
    def setUpClass(self):
        self.solution = Solution()

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
