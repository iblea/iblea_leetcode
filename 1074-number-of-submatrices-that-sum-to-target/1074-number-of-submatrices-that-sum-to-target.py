class Solution:
    def numSubmatrixSumTarget(self, matrix: List[List[int]], target: int) -> int:
        for row in matrix:
            for i in range(len(row)-1):
                row[i+1] += row[i]

        count = 0
        for t in range(len(matrix)):
            for b in range(t, -1, -1):
                if t == b:
                    cur = matrix[t][:]
                else:
                    cur = [cur[i]+matrix[b][i] for i in range(len(matrix[0]))]
                # 행렬 합 계산 및 save 시킨다.
                seen = {0: 1}
                for v in cur:
                    if v - target in seen:
                        print("seen[v - target] :", seen[v - target])
                        count += seen[v - target]
                    seen[v] = seen.get(v, 0) + 1
        return count

