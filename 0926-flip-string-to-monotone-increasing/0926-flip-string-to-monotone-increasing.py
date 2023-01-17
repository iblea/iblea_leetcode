# Leet Code Solution
class Solution:
    def minFlipsMonoIncr(self, s: str) -> int:
        one_cnt = 0
        change_cnt = 0
        for num in s:
            if num == '1':
                one_cnt += 1
                continue
            if one_cnt > 0:
                one_cnt -= 1
                change_cnt += 1

        return change_cnt