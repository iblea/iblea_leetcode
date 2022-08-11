#!/usr/bin/python3
import unittest
from typing import List
from typing import Optional



# Definition for a binary tree node.
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

"""
Solution Note

The number of nodes in the tree is in the range [1, 10^4].
-2^(31) <= Node.val <= 2^(31) - 1
"""

# Leet Code Solution
class Solution:
    def isValidBST(self, root: Optional[TreeNode]) -> bool:

        if root is None:
            return True

        def dp(root: Optional[TreeNode], lower: int, upper: int) -> bool:
            if root is None:
                return True

            if not (lower < root.val < upper): 
            # if root.val <= lower or root.val >= upper:
                return False

            return dp(root.left, lower, root.val) and dp(root.right, root.val, upper)


        inf = 2 ** 31
        result = dp(root, -inf - 1, inf)
        return result


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
        tree = make_node([2,1,3])
        res = self.solution.isValidBST(tree)
        self.assertEqual(res, True)

    def test_case_normal_2(self):
        tree = make_node([5,1,4,null,null,3,6])
        res = self.solution.isValidBST(tree)
        self.assertEqual(res, False)

    def test_case_normal_3(self):
        tree = make_node([2147483647])
        res = self.solution.isValidBST(tree)
        self.assertEqual(res, True)

    def test_case_normal_4(self):
        tree = make_node([-2147483648])
        res = self.solution.isValidBST(tree)
        self.assertEqual(res, True)



if __name__ == "__main__":
    # 스크립트 실행 시, 해당 부분 동작
    unittest.main(verbosity=0)
    pass
