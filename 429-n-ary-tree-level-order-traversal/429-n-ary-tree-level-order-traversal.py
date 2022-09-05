"""
Solution Note

The height of the n-ary tree is less than or equal to 1000
The total number of nodes is between [0, 104]
"""

# Leet Code Solution
"""
# Definition for a Node.
class Node:
    def __init__(self, val=None, children=None):
        self.val = val
        self.children = children
"""

class Solution:
    def levelOrder(self, root: 'Node') -> List[List[int]]:
        result = []

        if root is None:
            return []
        
        def bfs(node: 'Node', max_depth: int):
            if node is None:
                return
            
            if max_depth >= len(result):
                result.append([node.val])
            else:
                result[max_depth].append(node.val)
            
            max_depth += 1
            for child in node.children:
                bfs(child, max_depth)

        bfs(root, 0);
        return result

