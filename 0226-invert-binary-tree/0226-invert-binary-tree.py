# Leet Code Solution
class Solution:
    def invertTree(self, root: Optional[TreeNode]) -> Optional[TreeNode]:
        if root is None:
            return None

        def makeInvert(root, result=None):
            if root is None:
                return None

            result = TreeNode(root.val)
            result.right = makeInvert(root.left, result.right)
            result.left = makeInvert(root.right, result.left)
            return result

        result = makeInvert(root)
        return result
