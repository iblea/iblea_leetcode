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

https://leetcode.com/problems/delete-node-in-a-bst/
"""

# Leet Code Solution
class Solution:
    def deleteNode(self, root: Optional[TreeNode], key: int) -> Optional[TreeNode]:
        if root is None:
            return None

        node = root
        parent = None
        while node is not None:
            if node.val == key:
                break
            parent = node
            if node.val > key:
                node = node.left
            else:
                node = node.right

        # node 를 못찾았다면
        if node is None:
            return root

        # 찾은 노드가 root 노드라면
        if parent is None:
            if node.right is None:
                return root.left
            if node.right is None:
                return root.right

        # 바꿔치기할 노드가 없다면
        if node.right is None:
            node.val = None
            self.setParents(parent, node.left)
            return root

        def change_node(keynode, node, parent=None):
            if node.left is None:
                # 바꿔치기
                keynode.val = node.val
                # 부모노드에서 자식 노드 포인터 재조정
                # parents가 없다면 keynode의 right 노드를 재조정한다.
                # (keynode의 바로 하위노드이기 때문)
                if parent is None:
                    keynode.right = node.right
                    return
                # node.val 이 None로 변경하고,
                # 부모노드에서 자식노드의 val이 None인 값을 찾아 변경한다.
                node.val = None
                self.setParents(parent, node.right)
                return

            change_node(keynode, node.left, node)
            return

        # node.right 에서 가장 작은 노드 (node.left) 를 찾아,
        # keynode 와 바꿔치기하고 부모노드를 재조정한다.
        change_node(node, node.right)
        return root

    def setParents(self, parent, node = None):
        if parent.left is not None and parent.left.val is None:
            parent.left = node
        elif parent.right is not None and parent.right.val is None:
            parent.right = node








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
        rootlist = [5,3,6,2,4,null,7]
        root = make_node(rootlist)
        answer = [5,4,6,2,null,null,7]
        result = self.solution.deleteNode(root, 3)
        resultlist = make_list(result)
        self.assertEqual(resultlist, answer)

    def test_case_2(self):
        rootlist = [0]
        root = make_node(rootlist)
        answer = []
        result = self.solution.deleteNode(root, 0)
        resultlist = make_list(result)
        self.assertEqual(resultlist, answer)

    def test_case_3(self):
        rootlist = [50,30,70,null,40,60,80]
        root = make_node(rootlist)
        answer = [60,30,70,null,40,null,80]
        result = self.solution.deleteNode(root, 50)
        resultlist = make_list(result)
        self.assertEqual(resultlist, answer)

    def test_case_4(self):
        rootlist = [5,3,6,2,4,null,7]
        root = make_node(rootlist)
        answer = [5,4,6,2,null,null,7]
        result = self.solution.deleteNode(root, 3)
        resultlist = make_list(result)
        self.assertEqual(resultlist, answer)

    def test_case_5(self):
        rootlist = [5,3,6,2,4,null,7]
        root = make_node(rootlist)
        answer = [6,3,7,2,4]
        result = self.solution.deleteNode(root, 5)
        resultlist = make_list(result)
        self.assertEqual(resultlist, answer)

    def test_case_6(self):
        rootlist = [5,3,6,2,4,null,7]
        root = make_node(rootlist)
        answer = [5,3,6,2,4]
        result = self.solution.deleteNode(root, 7)
        resultlist = make_list(result)
        self.assertEqual(resultlist, answer)



"""
        5
    3       6
 2    4       7

        5
    3       6
 2    4       7

"""





if __name__ == "__main__":
    # 스크립트 실행 시, 해당 부분 동작
    unittest.main(verbosity=0)
