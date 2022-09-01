#!/usr/bin/python3
import unittest
from typing import *


"""
Solution Note

"""

# Definition for a binary tree node.
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

# Leet Code Solution
class Solution:
    cnt = 1
    def goodNodes(self, root: TreeNode) -> int:

        self.cnt = 1
        self.dfs(root, root.val)
        return self.cnt

    def dfs(self, node: TreeNode, max_val: int):
        if node.left is not None:
            if node.left.val >= max_val:
                self.cnt += 1
                self.dfs(node.left, node.left.val)
            else:
                self.dfs(node.left, max_val)

        if node.right is not None:
            if node.right.val >= max_val:
                self.cnt += 1
                self.dfs(node.right, node.right.val)
            else:
                self.dfs(node.right, max_val)


def make_node(lst: List) -> TreeNode:
    if len(lst) == 0:
        return None
    

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


null = None
# python unit test
class UnitTest(unittest.TestCase):

    # 클래스 생성 시 1회 실행
    @classmethod
    def setUpClass(self):
        self.solution = Solution();

    # 클래스 소멸 시 1회 실행
    @classmethod
    def tearDownClass(self):
        pass

    # 테스트 케이스 전 실행
    def setUp(self):
        pass

    # 테스트 케이스 후 실행
    def tearDown(self):
        pass

    def test_case_normal_1(self):
        tree = make_node([3,1,4,3,null,1,5])
        res = self.solution.goodNodes(tree)
        self.assertEqual(res, 4)

    def test_case_normal_2(self):
        tree = make_node([3,3,null,4,2])
        res = self.solution.goodNodes(tree)
        self.assertEqual(res, 3)

    def test_case_normal_3(self):
        tree = make_node([1])
        res = self.solution.goodNodes(tree)
        self.assertEqual(res, 1)

    def test_case_normal_4(self):
        tree = make_node([2,null,4,10,8,null,null,4])
        res = self.solution.goodNodes(tree)
        self.assertEqual(res, 4)





if __name__ == "__main__":
    # 스크립트 실행 시, 해당 부분 동작
    unittest.main(verbosity=0)
    pass
