# Leet Code Solution
# Definition for a binary tree node.
class Solution:
    def rightSideView(self, root: Optional[TreeNode]) -> List[int]:
        result : List[int] = []

        def dfs(node: Optional[TreeNode], level: int = 1):
            if node is None:
                return

            if (len(result) < level): 
                result.append(node.val)
            # result.append(node.val)

            dfs(node.right, level + 1)
            dfs(node.left, level + 1)

        dfs(root)
        return result


