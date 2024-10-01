class Solution:
    def findContentChildren(self, g: List[int], s: List[int]) -> int:
        sortg = sorted(g)
        sorts = sorted(s)

        cookies = 0
        for cookie in s:
            cookies += cookie

        satisfied_children = 0

        leng = len(sortg)
        lens = len(sorts)
        gindex = 0
        sindex = 0
        while gindex < leng and sindex < lens:
            if sortg[gindex] <= sorts[sindex]:
                gindex += 1
                satisfied_children += 1
            # else:
            #     sortg[gindex] -= sorts[sindex]
            sindex += 1
        return satisfied_children
