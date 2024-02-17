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

        mid = len(lists) // 2
        left = self.mergeKLists(lists[:mid])
        right = self.mergeKLists(lists[mid:])

        mergelist = ListNode()
        traversal = mergelist

        while left and right:
            if left.val < right.val:
                traversal.next = ListNode(left.val)
                left = left.next
            else:
                traversal.next = right
                right = right.next
            traversal = traversal.next

        if left:
            self.list_add(traversal, left)
        else:
            self.list_add(traversal, right)
        return mergelist.next

    def list_add(self, dstlist, srclist):
        while srclist:
            dstlist.next = ListNode(srclist.val)
            srclist = srclist.next
            dstlist = dstlist.next