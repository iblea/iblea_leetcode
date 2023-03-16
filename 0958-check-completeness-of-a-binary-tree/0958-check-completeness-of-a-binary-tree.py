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