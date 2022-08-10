class Solution:
    def sortedArrayToBST(self, n: list[int]) -> TreeNode:
        if not n: return None                                           # <-- base case: leaf
        # 정렬된 배열 내에서 이진 트리의 루트 노드는
        # 배열의 중안 원소이다.
        # 따라서 배열의 길이 / 2 가 트리의 루트 노드가 될 수 있다.
        m = len(n)//2
        # 따라서 0 ~ (배열의 길이 / 2) 를 트리의 왼쪽으로
        # (배열의 길이 / 2 + 1) ~ 배열의 길이 - 1 를 트리의 오른쪽으로 이동한다.
        return TreeNode(n[m],self.sortedArrayToBST(n[:m]),              # <-- left  subtree
                             self.sortedArrayToBST(n[m+1:]))            # <-- right subtree