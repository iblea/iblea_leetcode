from queue import Queue

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def levelOrder(self, root: Optional[TreeNode]) -> List[List[int]]:
        if root is None:
            return []

        result = [[root.val]]

        que = Queue()

        # bfs
        cur_level_count = 0
        if root.left is not None:
            que.put(root.left)
            cur_level_count += 1
        if root.right is not None:
            que.put(root.right)
            cur_level_count += 1

        node_data = []
        cur_node_count = 0
        cur_child_count = 0

        while que.qsize() > 0:
            node : TreeNode = que.get()
            cur_node_count += 1
            node_data.append(node.val)

            if node.left is not None:
                cur_child_count += 1
                que.put(node.left)

            if node.right is not None:
                cur_child_count += 1
                que.put(node.right)

            if cur_node_count == cur_level_count:
                cur_level_count = cur_child_count
                cur_child_count = 0
                cur_node_count = 0
                if len(node_data) > 0:
                    result.append(node_data)
                    node_data = []

        return result

