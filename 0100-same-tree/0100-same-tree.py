class Solution:
    def isSameTree(self, p: Optional[TreeNode], q: Optional[TreeNode]) -> bool:
        stack_p = [ p ]
        stack_q = [ q ]

        while stack_p and stack_q:
            stat = self.equals(stack_p, stack_q)
            if stat == False:
                return False
            stack_p = self.move_child(stack_p)
            stack_q = self.move_child(stack_q)


        return True

    def equals(self, list_p, list_q) -> bool:
        if len(list_p) != len(list_q):
            return False

        for i in range(len(list_p)):
            if self.node_equal(list_p[i], list_q[i]) == False:
                return False

        return True

    def node_equal(self, node_p, node_q):
        if node_p is None:
            if node_q is None:
                return True
            return False
        if node_q is None:
            return False
        if node_p.val != node_q.val:
            return False
        return True



    def move_child(self, lst):
        cnt = len(lst)

        for _ in range(cnt):
            node = lst.pop(0)
            if node is None:
                continue
            if node.left is None:
                lst.append(None)
            else:
                lst.append(node.left)
            if node.right is None:
                lst.append(None)
            else:
                lst.append(node.right)

        return lst

