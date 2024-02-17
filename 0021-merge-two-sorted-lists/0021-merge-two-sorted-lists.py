# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def mergeTwoLists(self, list1: Optional[ListNode], list2: Optional[ListNode]) -> Optional[ListNode]:
        head = ListNode()
        result = head
        while list1 and list2:
            if list1.val < list2.val:
                result.next = ListNode(list1.val)
                list1 = list1.next
            else:
                result.next = ListNode(list2.val)
                list2 = list2.next
            result = result.next

        if list1:
            self.listadd(result, list1)
        else:
            self.listadd(result, list2)
        return head.next

    def listadd(self, dstlist, srclist):
        while srclist:
            dstlist.next = ListNode(srclist.val)
            srclist = srclist.next
            dstlist = dstlist.next

