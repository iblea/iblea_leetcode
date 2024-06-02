# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def recoverFromPreorder(self, traversal: str) -> Optional[TreeNode]:
        stack: list = []
        while len(traversal) > 0:
            hyphen, number, i = self.get_level_and_number(traversal)
            traversal = traversal[i:]
            while len(stack) > hyphen:
                stack.pop()

            node = TreeNode(number)
            if stack and stack[-1].left is None:
                stack[-1].left = node
            elif stack:
                stack[-1].right = node
            stack.append(node)

        if len(stack) == 0:
            return None
        return stack[0]

    def get_level_and_number(self, traversal):
        hyphen = 0
        i = 0
        while i < len(traversal):
            if traversal[i] != '-':
                break
            hyphen += 1
            i += 1

        number = ""
        while i < len(traversal):
            if traversal[i] == '-':
                break
            number += traversal[i]
            i += 1

        number = int(number)
        return hyphen, number, i

