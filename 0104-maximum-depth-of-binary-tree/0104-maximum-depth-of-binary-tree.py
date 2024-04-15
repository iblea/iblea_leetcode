class Solution:
    def maxDepth(self, root: Optional[TreeNode]) -> int:

        def goDepth(node, level):
            if node is None:
                return level
            level += 1
            llevel = goDepth(node.left, level)
            rlevel = goDepth(node.right, level)
            if llevel > rlevel:
                return llevel
            else:
                return rlevel

        return goDepth(root, 0)

