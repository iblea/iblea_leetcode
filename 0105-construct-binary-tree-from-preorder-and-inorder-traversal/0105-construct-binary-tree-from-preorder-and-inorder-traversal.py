"""
Solution Note

https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/
https://waristo.tistory.com/15#:~:text=%EC%A0%84%EC%9C%84%2C%20%EC%A4%91%EC%9C%84%2C%20%ED%9B%84%EC%9C%84%EB%8A%94%20tree,right%EC%9D%98%20%EC%88%9C%EC%84%9C%EB%A5%BC%20%EA%B0%80%EC%A7%84%EB%8B%A4.&text=Inorder%EB%8A%94%20left%20%2D%3E%20root%20%2D,right%EC%9D%98%20%EC%88%9C%EC%84%9C%EB%A5%BC%20%EA%B0%80%EC%A7%84%EB%8B%A4.&text=Postorder%EB%8A%94%20left%20%2D%3E%20right%20%2D,root%EC%9D%98%20%EC%88%9C%EC%84%9C%EB%A5%BC%20%EA%B0%80%EC%A7%84%EB%8B%A4.
"""

# Leet Code Solution
class Solution:
    def buildTree(self, preorder: List[int], inorder: List[int]) -> Optional[TreeNode]:
        if not preorder or not inorder:
            return None
        inorder_map = { value: index for index, value in enumerate(inorder) }

        def build(pre_start, pre_end, in_start, in_end):
            if pre_start > pre_end:
                return None

            root_value = preorder[pre_start]
            node = TreeNode(root_value)

            in_index = inorder_map[root_value]

            left_size = in_index - in_start
            node.left = build(pre_start + 1, pre_start + left_size, in_start, in_index - 1)

            node.right = build(pre_start + left_size + 1, pre_end, in_index + 1, in_end)

            return node

        return build(0, len(preorder) - 1, 0, len(inorder) - 1)
