# Leet Code Solution
class Solution:
    def sortedListToBST(self, head: Optional[ListNode]) -> Optional[TreeNode]:
        if head is None:
            return None

        if head.next is None:
            return TreeNode(head.val)

        middle = self.get_middle_of_list(head)
        root = TreeNode(middle.val)

        root.left = self.sortedListToBST(head)
        root.right = self.sortedListToBST(middle.next)

        return root


    # 리스트의 middle을 리턴
    def get_middle_of_list(self, head):
        # 2칸씩 전진
        go_2 = head
        # 1칸씩 전진
        go_1 = head
        prev = None
        while go_2 and go_2.next:
            go_2 = go_2.next.next
            prev = go_1
            go_1 = go_1.next

        if prev:
            prev.next = None

        return go_1
