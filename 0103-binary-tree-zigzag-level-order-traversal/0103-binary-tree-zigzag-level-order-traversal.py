class Solution:
    def zigzagLevelOrder(self, root: Optional[TreeNode]) -> List[List[int]]:

        if not root:
            return []

        result = []
        stack = [ root ]

        tmp_stack = []
        tmp_val = []

        node_count = 1
        next_count = 0
        add_type = 'l'

        while stack:
            for _ in range(node_count):
                node = stack.pop(0)
                tmp_val.append(node.val)
                tmp_stack, next_count = self.children_add(tmp_stack, node, next_count, add_type)

            result.append(tmp_val)
            tmp_val = []
            node_count = next_count
            next_count = 0

            while tmp_stack:
                stack.append(tmp_stack.pop())
            if add_type == 'r':
                add_type = 'l'
            else:
                add_type = 'r'

        return result

    def children_add(self, tmp_stack, node, next_count, add_type):
        if add_type == 'r':
            if node.right is not None:
                tmp_stack.append(node.right)
                next_count += 1
            if node.left is not None:
                tmp_stack.append(node.left)
                next_count += 1
        else:
            if node.left is not None:
                tmp_stack.append(node.left)
                next_count += 1
            if node.right is not None:
                tmp_stack.append(node.right)
                next_count += 1
        return tmp_stack, next_count


