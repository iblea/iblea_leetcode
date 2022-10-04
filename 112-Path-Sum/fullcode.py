#!/usr/bin/python3
import unittest
from typing import List
from typing import Optional


null = None
# Definition for a binary tree node.
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

The number of nodes in the tree is in the range [0, 5000].
-1000 <= Node.val <= 1000
-1000 <= targetSum <= 1000
"""

# Leet Code Solution
class Solution:
    def hasPathSum(self, root: Optional[TreeNode], targetSum: int) -> bool:
        if not root:
            return False

        targetSum -= root.val

        if targetSum == 0 and not root.left and not root.right:
            return True

        return self.hasPathSum(root.left, targetSum) or self.hasPathSum(root.right, targetSum)




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
        lst = [5,4,8,11,null,13,4,7,2,null,null,null,1]
        root = make_node(lst)
        res = self.solution.hasPathSum(root = root, targetSum = 22)
        self.assertEqual(res, True)

    def test_case_normal_2(self):
        lst = [1,2,3]
        root = make_node(lst)
        res = self.solution.hasPathSum(root = root, targetSum = 5)
        self.assertEqual(res, False)

    def test_case_normal_3(self):
        lst = []
        root = make_node(lst)
        res = self.solution.hasPathSum(root = root, targetSum = 0)
        self.assertEqual(res, False)




if __name__ == "__main__":
    # 스크립트 실행 시, 해당 부분 동작
    unittest.main(verbosity=0)
    pass
