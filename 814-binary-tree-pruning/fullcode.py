#!/usr/bin/python3
import unittest
from typing import *


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

"""
Solution Note

The number of nodes in the tree is in the range [1, 200].
Node.val is either 0 or 1.
"""

# Leet Code Solution
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

class Solution:
    def pruneTree(self, root: Optional[TreeNode]) -> Optional[TreeNode]:

        if root is None:
            return None

        if root.left is None and root.right is None and root.val == 0:
            return None

        result = TreeNode(root.val)

        def dfs(node: Optional[TreeNode], res: Optional[TreeNode]) -> None:
            if node.left is not None:
                res.left = TreeNode(node.left.val)
                dfs(node.left, res.left)

            if node.right is not None:
                res.right = TreeNode(node.right.val)
                dfs(node.right, res.right)
            
            if res.left is not None and res.left.val is None:
                res.left = None
            if res.right is not None and res.right.val is None:
                res.right = None
            
            if res.left is None and res.right is None and res.val == 0:
                res.val = None

        dfs(root, result)

        if result.val is None:
            return None

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
        ipt = [1,null,0,0,1]
        root = make_node(ipt)
        res = self.solution.pruneTree(root)
        output  = make_list(res)
        self.assertEqual(output, [1,null,0,null,1])

    def test_case_normal_2(self):
        ipt = [1,0,1,0,0,0,1]
        root = make_node(ipt)
        res = self.solution.pruneTree(root)
        output  = make_list(res)
        self.assertEqual(output, [1,null,1,null,1])

    def test_case_normal_3(self):
        ipt =  [1,1,0,1,1,0,1,0] 
        root = make_node(ipt)
        res = self.solution.pruneTree(root)
        output = make_list(res)
        self.assertEqual(output, [1,1,0,1,1,null,1])

    def test_case_normal_4(self):
        ipt =  [0,null,0,0,0]
        root = make_node(ipt)
        res = self.solution.pruneTree(root)
        output = make_list(res)
        self.assertEqual(output, [])



if __name__ == "__main__":
    # 스크립트 실행 시, 해당 부분 동작
    unittest.main(verbosity=0)
    pass
