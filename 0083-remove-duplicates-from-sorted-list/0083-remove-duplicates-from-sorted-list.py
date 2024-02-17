# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def deleteDuplicates(self, head: Optional[ListNode]) -> Optional[ListNode]:
        if not head:
            return None

        result = ListNode(head.val)
        traversal = result

        while head:
            if head.val != traversal.val:
                traversal.next = ListNode(head.val)
                traversal = traversal.next
            head = head.next

        return result