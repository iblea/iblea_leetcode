"""
Solution Note

중위순회 - Inorder
left -> middle -> right
"""
class Solution:
    def inorderTraversal(self, root: Optional[TreeNode]) -> List[int]:

        answer = []

        def inorder(node):
            if node is None:
                return
            inorder(node.left)
            answer.append(node.val)
            inorder(node.right)

        inorder(root)
        return answer

