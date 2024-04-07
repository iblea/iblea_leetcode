class Solution:
    def pathSum(self, root: Optional[TreeNode], targetSum: int) -> List[List[int]]:
        results = []
        def traversal(root, lst):
            if root is None:
                return None

            lst.append(root.val)
            print(lst)

            if sum(lst) == targetSum:
                if root.left is None and root.right is None:
                    results.append([lst[i] for i in range(len(lst))])
                    # results.append(lst)
                    # lst.pop()
                    return None

            left_list = [ lst[i] for i in range(len(lst)) ]
            # right_list = [ lst[i] for i in range(len(lst)) ]
            traversal(root.left, left_list)
            # traversal(root.right, right_list)

            # traversal(root.left, lst)
            traversal(root.right, lst)



        traversal(root, [])
        return results

