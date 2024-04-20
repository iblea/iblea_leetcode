"""
Solution Note

https://leetcode.com/problems/delete-node-in-a-bst/
"""

# Leet Code Solution
class Solution:
    def deleteNode(self, root: Optional[TreeNode], key: int) -> Optional[TreeNode]:
        if root is None:
            return None

        node = root
        parent = None
        while node is not None:
            if node.val == key:
                break
            parent = node
            if node.val > key:
                node = node.left
            else:
                node = node.right

        if node is None:
            return root

        if parent is None:
            if node.right is None:
                return root.left
            if node.right is None:
                return root.right

        if node.right is None:
            node.val = None
            self.setParents(parent, node.left)
            return root

        def change_node(keynode, node, parent=None):
            if node.left is None:
                keynode.val = node.val
                if parent is None:
                    keynode.right = node.right
                    return
                node.val = None
                self.setParents(parent, node.right)
                return
            change_node(keynode, node.left, node)
            return

        change_node(node, node.right)
        return root

    def setParents(self, parent, node = None):
        if parent.left is not None and parent.left.val is None:
            parent.left = node
        elif parent.right is not None and parent.right.val is None:
            parent.right = node

