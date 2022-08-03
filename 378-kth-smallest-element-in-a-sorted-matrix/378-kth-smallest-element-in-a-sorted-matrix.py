from bisect import bisect_right

# Leet Code Solution
class Solution:
    # binary search solution
    def kthSmallest(self, matrix: List[List[int]], k: int) -> int:
        low, high = matrix[0][0], matrix[-1][-1]
        # print("k = {}\n".format(k))
        while (low < high):
            mid = low + ((high - low) // 2)
            # print("low = {}, high = {}, mid = {}".format(low, high, mid))
            smaller_than_cnt = 0
            for i in range(len(matrix)):
                res = bisect_right(matrix[i], mid)
                # print("[{}] - res : {}".format(i, res))
                smaller_than_cnt += res
                # smaller_than_cnt += bisect_right(matrix[i],mid)
            # print("")
            if smaller_than_cnt < k:
                low = mid + 1
            else:
                high = mid

        # print("")
        # print("")
        return low

    # sort solution
    def kthSmallest_sort(self, matrix: List[List[int]], k: int) -> int:
        lst_1dimension = []
        matrix_len_1d = len(matrix)
        for i in range(matrix_len_1d):
            for j in range(matrix_len_1d):
                lst_1dimension.append(matrix[i][j])
        
        lst_1dimension.sort()
        return lst_1dimension[k-1]