#!/usr/bin/python3
import unittest
from typing import *
from venv import create


null = None

class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

    def set_node(self, data: List[any], index: int = 0):
        if (len(data) == 0):
            self.val = None
            return

        if (len(data) <= index):
            return

        if (data[index] is null):
            self.val = None
            return

        if (self.left is None and self.right is None):
            self.val = data[index]


        index += 1
        if (len(data) > index * 2 - 1):
            self.left = TreeNode()
            self.left.set_node(data, index * 2 - 1)
        if (len(data) > index * 2):
            self.right = TreeNode()
            self.right.set_node(data, index * 2)

        return

def create_tree(data: List[any]) -> TreeNode:
    if (len(data) == 0):
        return None

    root = TreeNode()
    root.set_node(data)
    return root

"""
Solution Note
The number of nodes in the tree is in the range [0, 100].
-100 <= Node.val <= 100

"""

# Leet Code Solution
# Definition for a binary tree node.
class Solution:
    def rightSideView(self, root: Optional[TreeNode]) -> List[int]:
        result : List[int] = []

        def dfs(node: Optional[TreeNode], level: int = 1):
            if node is None:
                return

            if (len(result) < level): 
                result.append(node.val)
            # result.append(node.val)

            dfs(node.right, level + 1)
            dfs(node.left, level + 1)

        dfs(root)
        return result




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
        node = create_tree([1,2,3,null,5,null,4])
        res = self.solution.rightSideView(root=node)
        self.assertEqual(res, [1,3,4])

    def test_case_normal_2(self):
        node = create_tree([1,null,3])
        res = self.solution.rightSideView(root=node)
        self.assertEqual(res, [1, 3])

    def test_case_normal_3(self):
        node = create_tree([ ])
        res = self.solution.rightSideView(root=node)
        self.assertEqual(res, [ ])

    def test_case_normal_4(self):
        node = create_tree([1, 2, 3, 4, 5, 6, 7])
        res = self.solution.rightSideView(root=node)
        self.assertEqual(res, [1, 3, 7])

    def test_case_normal_5(self):
        node = create_tree([1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12 ,13, 14 ,15, 16 + \
            17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31])
        res = self.solution.rightSideView(root=node)
        self.assertEqual(res, [1, 3, 7])






if __name__ == "__main__":
    # 스크립트 실행 시, 해당 부분 동작
    unittest.main(verbosity=0)
    pass
