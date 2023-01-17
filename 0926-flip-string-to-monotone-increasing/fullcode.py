#!/usr/local/bin/pytest

#!/usr/bin/python3
import pytest
from typing import List


"""
Solution Note

1 <= s.length <= 10**5
s[i] is either '0' or '1'.
"""

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

"""
# 00110
+-----+---------+-----+
| idx | one_cnt | res |
+-----+---------+-----+
| 0   | 0       | 0   |
| 1   | 0       | 0   |
| 2   | 1       | 0   |
| 3   | 2       | 0   |
| 4   | 1       | 1   |
+-----+---------+-----+

# 010110
+-----+---------+-----+
| idx | one_cnt | res |
+-----+---------+-----+
| 0   | 0       | 0   |
| 1   | 1       | 0   |
| 2   | 0       | 1   |
| 3   | 1       | 1   |
| 4   | 2       | 1   |
| 5   | 1       | 2   |
+-----+---------+-----+
"""





@pytest.mark.parametrize(
    'expect, args',
    [
        [ 1, [ "00110" ] ],
        [ 2, [ "010110" ] ],
        [ 2, [ "00011000" ] ],
    ])
def test_case_normal(expect, args):
    solution = Solution();
    assert expect == solution.minFlipsMonoIncr(args[0])

# pytest fullcode.py
