# Leet Code Solution
class Solution:
    def sumOfLeftLeaves(self, root: Optional[TreeNode]) -> int:
        if root is None:
            return 0

        val = 0
        lnode = root.left
        if lnode is not None and lnode.left is None and lnode.right is None:
            val += root.left.val
        val += self.sumOfLeftLeaves(root.left)
        val += self.sumOfLeftLeaves(root.right)
        return val

