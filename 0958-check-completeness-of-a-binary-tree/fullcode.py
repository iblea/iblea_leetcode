#!/usr/bin/python3
from typing import List
from typing import Optional


null = None

class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

def make_node(treelist: List[any]) -> TreeNode:
    if len(treelist) == 0:
        return None

    # 깊은복사
    lst = []
    for val in treelist:
        lst.append(val)

    tree = TreeNode(lst.pop(0))
    stack = [ tree ]

    while len(lst) > 0:
        node = stack.pop(0)

        # left node
        value = lst.pop(0)
        if value is None:
            node.left = None
        else:
            node.left = TreeNode(value)
            stack.append(node.left)

        if len(lst) == 0:
            break

        #right node
        value = lst.pop(0)
        if value is None:
            node.right = None
        else:
            node.right = TreeNode(value)
            stack.append(node.right)

    return tree


"""
Solution Note

The number of nodes in the tree is in the range [1, 100].
1 <= Node.val <= 1000

힌트 : 완전이진트리이므로 자식노드가 없을 경우 모든 트리에 더이상 자식노드가 없어야 한다.
"""

from collections import deque

def not_empty(deq) -> bool:
    if deq:
        return True
    # 큐가 비어있으면 False
    return False

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def isCompleteTree(self, root: Optional[TreeNode]) -> bool:

        queue = deque([root])

        # 빈 노드를 확인할때까지 자식노들르 검색하여 추가한다.
        while queue[0]:
            node = queue.popleft()
            queue.extend([node.left, node.right])

        while not_empty(queue):
            # 큐가 emtpy() 상태가 되기 전 자식노드가 빈 노드가 아니면 완전이진탐색트리가 아니다.
            if queue.popleft() is not None:
                return False

        return True





solution = Solution()

if solution.isCompleteTree(root = make_node([1,2,3,4,5,6])) is not True:
    print("Wrong 1")


if solution.isCompleteTree(root = make_node([1,2,3,4,5,null,7])) is not False:
    print("Wrong 2")


if solution.isCompleteTree(root = make_node([1,2,3,5,null,7,8])) is not False:
    print("Wrong 3")

