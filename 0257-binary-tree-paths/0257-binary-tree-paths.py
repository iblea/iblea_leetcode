# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def binaryTreePaths(self, root: Optional[TreeNode]) -> List[str]:

        answer = []
        def traversal(node, lst):
            if node is None:
                return

            lst.append(node.val)
            if node.left is None and node.right is None:
                pathString = ""
                for node in lst:
                    pathString += "->{}".format(node)
                answer.append(pathString[2:])
                return

            tmp = [ lst[i] for i in range(len(lst))]
            traversal(node.left, lst)
            traversal(node.right, tmp)

        traversal(root, [])
        return answer

