class Solution:
    def generateTrees(self, n: int) -> List[Optional[TreeNode]]:
        if n == 0:
            return []
        return self.generate_tree(1, n)



    def generate_tree(self, start, end) -> Optional[List[TreeNode]]:
        if (start > end):
            return [ None ]

        answer = []
        for i in range(start, end+1):
            left = self.generate_tree(start, i - 1)
            right = self.generate_tree(i + 1, end)

            if (len(left) == 0):
                left.append(None)
            if (len(right) == 0):
                right.append(None)

            for left_node in left:
                for right_node in right:
                    answer.append(TreeNode(i, left_node, right_node))

        return answer

