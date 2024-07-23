# Leet Code Solution

class Solution:
    def minSwaps(self, s: str) -> int:

        rotate = 0
        bracket = 0
        for c in s:
            if c == ']' and bracket == 0:
                rotate += 1

            if c == '[' or bracket == 0:
                bracket += 1
            else:
                bracket -= 1
        return rotate
