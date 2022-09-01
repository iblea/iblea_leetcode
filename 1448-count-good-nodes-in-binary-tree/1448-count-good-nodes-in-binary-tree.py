# Leet Code Solution
class Solution:
    cnt = 1
    def goodNodes(self, root: TreeNode) -> int:

        self.cnt = 1
        self.dfs(root, root.val)
        return self.cnt

    def dfs(self, node: TreeNode, max_val: int):
        if node.left is not None:
            if node.left.val >= max_val:
                self.cnt += 1
                self.dfs(node.left, node.left.val)
            else:
                self.dfs(node.left, max_val)

        if node.right is not None:
            if node.right.val >= max_val:
                self.cnt += 1
                self.dfs(node.right, node.right.val)
            else:
                self.dfs(node.right, max_val)