#!/usr/bin/python3
import unittest
from typing import Optional, List


null = None

class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next

# Leet Code Solution
# Definition for a binary tree node.
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right


"""
Solution Note

https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/
https://waristo.tistory.com/15#:~:text=%EC%A0%84%EC%9C%84%2C%20%EC%A4%91%EC%9C%84%2C%20%ED%9B%84%EC%9C%84%EB%8A%94%20tree,right%EC%9D%98%20%EC%88%9C%EC%84%9C%EB%A5%BC%20%EA%B0%80%EC%A7%84%EB%8B%A4.&text=Inorder%EB%8A%94%20left%20%2D%3E%20root%20%2D,right%EC%9D%98%20%EC%88%9C%EC%84%9C%EB%A5%BC%20%EA%B0%80%EC%A7%84%EB%8B%A4.&text=Postorder%EB%8A%94%20left%20%2D%3E%20right%20%2D,root%EC%9D%98%20%EC%88%9C%EC%84%9C%EB%A5%BC%20%EA%B0%80%EC%A7%84%EB%8B%A4.
"""

# Leet Code Solution
class Solution:
    def buildTree(self, preorder: List[int], inorder: List[int]) -> Optional[TreeNode]:
        if not preorder or not inorder:
            return None
        inorder_map = { value: index for index, value in enumerate(inorder) }

        def build(pre_start, pre_end, in_start, in_end):
            if pre_start > pre_end:
                return None

            root_value = preorder[pre_start]
            node = TreeNode(root_value)

            in_index = inorder_map[root_value]

            left_size = in_index - in_start
            node.left = build(pre_start + 1, pre_start + left_size, in_start, in_index - 1)

            node.right = build(pre_start + left_size + 1, pre_end, in_index + 1, in_end)

            return node

        return build(0, len(preorder) - 1, 0, len(inorder) - 1)






def make_linked_list(lst: List[any]) -> Optional[ListNode]:
    if lst is None or lst is []:
        return None

    linkedlist = ListNode(lst[0])
    traversal = linkedlist
    for i in range(1, len(lst)):
        traversal.next = ListNode(lst[i])
        traversal = traversal.next

    return linkedlist

def make_array_list(linked_list: Optional[ListNode]) -> List:
    if linked_list is None:
        return []

    lst = []
    traversal = linked_list
    while traversal is not None:
        lst.append(traversal.val)
        traversal = traversal.next
    return lst




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
            result.append(null)
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

    def test_make_linked_list(self):
        origin_lst = [1, 2, 3]
        origin_linked_list = ListNode(1)
        origin_linked_list.next = ListNode(2)
        origin_linked_list.next.next = ListNode(3)
        lnk_list = make_linked_list(origin_lst)
        arr_list = make_array_list(origin_linked_list)

        self.assertEqual(origin_lst, arr_list)
        answer_1 = []
        answer_2 = []
        traversal = origin_linked_list
        while traversal is not None:
            answer_1.append(traversal.val)
            traversal = traversal.next

        traversal = lnk_list
        while traversal is not None:
            answer_2.append(traversal.val)
            traversal = traversal.next
        self.assertEqual(answer_1, answer_2)

    def test_make_list(self):
        lst = [1,None,1,None,1]
        # list to TreeNode
        root = make_node(lst)
        # TreeNode to list
        answer = make_list(root)

        # print(lst)
        # print(answer)

        # self.solution.problem(root)
        self.assertEqual(answer, lst)

    def test_case_1(self):
        answer = [3,9,20,null,null,15,7]
        res = self.solution.buildTree(
            preorder = [3,9,20,15,7], inorder = [9,3,15,20,7]
        )
        result = make_list(res)
        self.assertEqual(result, answer)

    def test_case_2(self):
        answer = [-1]
        res = self.solution.buildTree(
            preorder = [-1], inorder = [-1]
        )
        result = make_list(res)
        self.assertEqual(result, answer)




if __name__ == "__main__":
    # 스크립트 실행 시, 해당 부분 동작
    unittest.main(verbosity=0)
