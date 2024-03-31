#!/usr/bin/python3
import unittest
from typing import *


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

중위순회 - Inorder
left -> middle -> right
"""
class Solution:
    def inorderTraversal(self, root: Optional[TreeNode]) -> List[int]:

        answer = []

        def inorder(node):
            if node is None:
                return
            inorder(node.left)
            answer.append(node.val)
            inorder(node.right)

        inorder(root)
        return answer



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
        pass

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
        root = make_node([1,null,2,3])
        res = self.solution.inorderTraversal(root)
        self.assertEqual(res, [1,3,2])

    def test_case_2(self):
        root = make_node([])
        res = self.solution.inorderTraversal(root)
        self.assertEqual(res, [])




if __name__ == "__main__":
    # 스크립트 실행 시, 해당 부분 동작
    unittest.main(verbosity=0)
    pass
