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