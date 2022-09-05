#!/usr/bin/python3
import unittest
from typing import List


"""
Solution Note

The height of the n-ary tree is less than or equal to 1000
The total number of nodes is between [0, 104]
"""

# Leet Code Solution
"""
# Definition for a Node.
class Node:
    def __init__(self, val=None, children=None):
        self.val = val
        self.children = children
"""

class Solution:
    def levelOrder(self, root: 'Node') -> List[List[int]]:
        result = []

        if root is None:
            return []
        
        def bfs(node: 'Node', max_depth: int):
            if node is None:
                return
            
            if max_depth >= len(result):
                result.append([node.val])
            else:
                result[max_depth].append(node.val)
            
            max_depth += 1
            for child in node.children:
                bfs(child, max_depth)

        bfs(root, 0);
        return result


class Node:
    def __init__(self, val=None, children=None):
        self.val = val
        self.children = children


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
        res = self.solution.problem([1])
        self.assertEqual(res, 1)

    def test_case_normal_2(self):
        res = self.solution.problem([2])
        self.assertEqual(res, 1)



if __name__ == "__main__":
    # 스크립트 실행 시, 해당 부분 동작
    unittest.main(verbosity=0)
    pass
