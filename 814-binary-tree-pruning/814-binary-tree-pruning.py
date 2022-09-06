"""
Solution Note

The number of nodes in the tree is in the range [1, 200].
Node.val is either 0 or 1.
"""

# Leet Code Solution
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

class Solution:
    def pruneTree(self, root: Optional[TreeNode]) -> Optional[TreeNode]:
        from copy import deepcopy


        if root is None:
            return None

        if root.left is None and root.right is None and root.val == 0:
            return None

        result = TreeNode(root.val)

        def dfs(node: Optional[TreeNode], res: Optional[TreeNode]) -> None:
            if node.left is not None:
                res.left = TreeNode(node.left.val)
                dfs(node.left, res.left)

            if node.right is not None:
                res.right = TreeNode(node.right.val)
                dfs(node.right, res.right)
            
            if res.left is not None and res.left.val is None:
                res.left = None
            if res.right is not None and res.right.val is None:
                res.right = None
            
            if res.left is None and res.right is None and res.val == 0:
                res.val = None

        dfs(root, result)

        if result.val is None:
            return None

        return result

