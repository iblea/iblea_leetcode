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

merge sort

    [1 2 3 4 5 6 7 8]
[1 2 3 4]       [5 6 7 8]
[1 2]  [3 4]    [5 6]  [7 8]
"""

# Leet Code Solution

# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def mergeKLists(self, lists: List[Optional[ListNode]]) -> Optional[ListNode]:
        if not lists:
            return None
        if len(lists) == 1:
            return lists[0]

        mid: int = len(lists) // 2
        left: ListNode = self.mergeKLists(lists[:mid])
        right: ListNode = self.mergeKLists(lists[mid:])

        return self.mergeSortList(left, right)

    def mergeSortList(self, list1: Optional[ListNode], list2: Optional[ListNode]) -> Optional[ListNode]:
        mergelist: ListNode = ListNode()
        traversal: ListNode = mergelist

        while list1 and list2:
            if list1.val < list2.val:
                traversal.next = ListNode(list1.val)
                list1 = list1.next
            else:
                traversal.next = list2
                list2 = list2.next
            traversal = traversal.next

        if list1:
            self.list_add(traversal, list1)
        else:
            self.list_add(traversal, list2)
        return mergelist.next


    def list_add(self, dstlist: Optional[ListNode], srclist: Optional[ListNode]) -> None:
        while srclist:
            dstlist.next = ListNode(srclist.val)
            srclist = srclist.next
            dstlist = dstlist.next


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
