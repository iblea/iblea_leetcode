#!/usr/bin/python3
from queue import Queue
import unittest
from typing import *


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
The number of nodes in the tree is in the range [0, 2000].
-1000 <= Node.val <= 1000

"""

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def levelOrder(self, root: Optional[TreeNode]) -> List[List[int]]:
        if root is None:
            return []

        result = [[root.val]]

        que = Queue()

        # bfs
        cur_level_count = 0
        if root.left is not None:
            que.put(root.left)
            cur_level_count += 1
        if root.right is not None:
            que.put(root.right)
            cur_level_count += 1

        node_data = []
        cur_node_count = 0
        next_leve_count = 0

        while que.qsize() > 0:
            node : TreeNode = que.get()
            cur_node_count += 1
            node_data.append(node.val)

            # 오른쪽 왼쪽 노드가 있는지 확인하고
            # 있으면 큐에 넣는다.
            # 이후 다음 레벨 카운트를 증가시킨다.
            if node.left is not None:
                next_leve_count += 1
                que.put(node.left)

            if node.right is not None:
                next_leve_count += 1
                que.put(node.right)

            # 트리레벨을 구하여 결과에 추가
            # 다음 레벨 카운트를 현재 레벨 카운트로 만들고 초기화시킨다.
            if cur_node_count == cur_level_count:
                cur_level_count = next_leve_count
                next_leve_count = 0
                cur_node_count = 0
                if len(node_data) > 0:
                    result.append(node_data)
                    node_data = []

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
        node = create_tree([3,9,20,null,null,15,7])
        res = self.solution.levelOrder(root=node)
        self.assertEqual(res, [[3],[9,20],[None, None, 15, 7]])

    def test_case_normal_2(self):
        node = create_tree([1])
        res = self.solution.levelOrder(root=node)
        self.assertEqual(res, [[1]])

    def test_case_normal_3(self):
        node = create_tree([ ])
        res = self.solution.levelOrder(root=node)
        self.assertEqual(res, [ ])

    def test_case_normal_4(self):
        node = create_tree([1,2,3,4,null,null,5])
        res = self.solution.levelOrder(root=node)
        self.assertEqual(res, [[1],[2,3],[4, None, None, 5]])




if __name__ == "__main__":
    # 스크립트 실행 시, 해당 부분 동작
    unittest.main(verbosity=0)
    pass
