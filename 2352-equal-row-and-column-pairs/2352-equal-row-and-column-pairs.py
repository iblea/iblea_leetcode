class Solution:
    def equalPairs(self, grid: List[List[int]]) -> int:

        map = {}
        for line in grid:
            strline = str(line)
            if strline not in map:
                map[strline] = 1
            else:
                map[strline] += 1

        count = 0
        for i in range(len(grid)):
            line = []
            for j in range(len(grid)):
                line.append(grid[j][i])
            strline = str(line)
            if strline in map:
                count += map[strline]

        return count
