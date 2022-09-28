#!/usr/bin/python3
import unittest
from typing import List
from typing import Optional


"""
Solution Note

1 <= sz <= 30
0 <= Node.val <= 100
1 <= n <= sz
"""

# Definition for singly-linked list.
class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next

# Leet Code Solution
class Solution:
    def removeNthFromEnd(self, head: Optional[ListNode], n: int) -> Optional[ListNode]:
        if head is None:
            return None
        
        node = head
        pointer: List[any] = [ node ]
        while node.next is not None:
            pointer.append(node.next)
            node = node.next
        
        if len(pointer) == 1:
            return None

        removal = len(pointer) - n - 1
        # [0,1,2,3,4]
        # [0,1,2,4]
        if removal < 0:
            head = head.next
        else:
            pointer[removal].next = pointer[removal+1].next
        return head



def print_linkedlist(head: Optional[ListNode]):
    if head is None:
        print("linked list is None")
        return

    print("[ ", end="")
    print(head.val, end=", ")
    node: ListNode = head
    while node.next is not None:
        node = node.next
        print(head.val, end=", ")

    print("\b\b ]")



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
        res = self.solution.problem([1])
        self.assertEqual(res, 1)

    def test_case_normal_2(self):
        res = self.solution.problem([2])
        self.assertEqual(res, 1)



if __name__ == "__main__":
    # 스크립트 실행 시, 해당 부분 동작
    unittest.main(verbosity=0)
    pass
