"""
Solution Note

1 <= n <= 10**9
"""

# Leet Code Solution
from collections import Counter

class Solution:
    def reorderedPowerOf2(self, n: int) -> bool:
        LIMIT = 10 ** 9

        ncounter = Counter(str(n))
        i = 0
        val = 1 << i
        while val <= LIMIT:
            if ncounter == Counter(str(val)):
                return True
            i += 1
            val = 1 << i
        return False

