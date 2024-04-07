#!/usr/bin/python3
import unittest
from typing import Optional, List


null = None

# Leet Code Solution
# Definition for a binary tree node.
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right


"""
Solution Note

"""

# Leet Code Solution

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
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







def make_node(treelist: List[any]) -> Optional[TreeNode]:
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


def make_list(root: TreeNode) -> List[any]:
    if root is None:
        return []

    result: List[any] = [ root.val ]
    queue: List[TreeNode] = [ ]

    if root.left is None and root.right is None:
        return result

    queue.append(root.left)
    queue.append(root.right)

    while len(queue) > 0:
        node: TreeNode = queue.pop(0)
        if node is None:
            result.append(None)
            continue

        result.append(node.val)

        if node.left is None and node.right is None:
            continue

        queue.append(node.left)
        queue.append(node.right)

    return result


# python unit test
class UnitTest(unittest.TestCase):

    # 클래스 생성 시 1회 실행
    @classmethod
    def setUpClass(self):
        pass

    # 클래스 소멸 시 1회 실행
    @classmethod
    def tearDownClass(self):
        pass

    # 테스트 케이스 전 실행
    def setUp(self):
        self.solution = Solution()

    # 테스트 케이스 후 실행
    def tearDown(self):
        pass

    def test_make_list(self):
        lst = [1,None,1,None,1]
        # list to TreeNode
        root = make_node(lst)
        # TreeNode to list
        answer = make_list(root)

        # self.solution.problem(root)
        self.assertEqual(answer, lst)

    def test_case_1(self):
        lst = [3,9,20,null,null,15,7]
        root = make_node(lst)
        result = self.solution.zigzagLevelOrder(root)
        answer = [[3],[20,9],[15,7]]
        self.assertEqual(answer, result)

    def test_case_2(self):
        lst = [1]
        root = make_node(lst)
        result = self.solution.zigzagLevelOrder(root)
        answer = [[1]]
        self.assertEqual(answer, result)

    def test_case_3(self):
        lst = []
        root = make_node(lst)
        result = self.solution.zigzagLevelOrder(root)
        answer = []
        self.assertEqual(answer, result)

    def test_case_3(self):
        lst = [1,2,3,4,null,null,5]
        root = make_node(lst)
        result = self.solution.zigzagLevelOrder(root)
        answer = [[1],[3,2],[4,5]]
        self.assertEqual(answer, result)







if __name__ == "__main__":
    # 스크립트 실행 시, 해당 부분 동작
    unittest.main(verbosity=0)
