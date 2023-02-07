#!/usr/local/bin/pytest -s

#!/usr/bin/python3
import pytest
from typing import List


"""
Solution Note

"""

# Leet Code Solution
class Solution:
    def problem(self, arg1, arg2) -> int:
        return arg1 + arg2







@pytest.mark.parametrize(
    'expect, args',
    [
        [ 3, [ 1, 2 ] ],
        # [ 4, [ 1, 2 ] ],
    ])
def test_case_normal(expect, args):
    solution = Solution();
    assert expect == solution.problem(args[0], args[1])

# pytest fullcode.py
