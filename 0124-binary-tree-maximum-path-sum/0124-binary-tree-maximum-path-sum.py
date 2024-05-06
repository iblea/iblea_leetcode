class Solution:
    def maxPathSum(self, root: Optional[TreeNode]) -> int:
        if not root:
            return 0

        self.maxsum = float('-inf')
        def DFS(root) -> int:
            if not root:
                return 0

            left_sum: int = DFS(root.left)
            right_sum: int = DFS(root.right)

            # 자식의 합계가 음수면, 자식을 안 더하는 것이 베스트임.
            # 따라서 자식의 합계가 음수면 0으로 치환하는 작업이 필요함.
            if left_sum < 0:
                left_sum = 0
            if right_sum < 0:
                right_sum = 0

            self.maxsum = max(self.maxsum, left_sum + right_sum + root.val)

            # 왼쪽 또는 오른쪽의 합계와 현재 root node의 값을 더해 다음 작업을 진행.
            return max(left_sum, right_sum) + root.val

        DFS(root)
        return self.maxsum

