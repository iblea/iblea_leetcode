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