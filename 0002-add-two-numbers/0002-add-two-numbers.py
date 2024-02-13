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
        result = res
        while True:
            result.val = num % 10
            num //= 10
            if num == 0:
                break
            result.next = ListNode()
            result = result.next
        return res

