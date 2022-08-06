class Solution:
    def poorPigs(self, buckets: int, minutesToDie: int, minutesToTest: int) -> int:
        one_place = log2(buckets)
        t = ceil(minutesToTest/minutesToDie)

        if t == 1: return ceil(one_place)
        return ceil(one_place / log2(t+1))