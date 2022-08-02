# Leet Code Solution
class Solution:
    def kthSmallest(self, matrix: List[List[int]], k: int) -> int:
        lst_1dimension = []
        matrix_len_1d = len(matrix)
        for i in range(matrix_len_1d):
            for j in range(matrix_len_1d):
                lst_1dimension.append(matrix[i][j])
        
        lst_1dimension.sort()
        return lst_1dimension[k-1]

