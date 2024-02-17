# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def reverseList(self, head: Optional[ListNode]) -> Optional[ListNode]:
        if head is None:
            return None

        temp = [ ]
        traverse = head
        while traverse is not None:
            temp.append(traverse.val)
            traverse = traverse.next

        result = ListNode(temp[-1])
        traversal = result
        for i in range(len(temp) - 2, -1, -1):
            traversal.next = ListNode(temp[i])
            traversal = traversal.next

        return result
