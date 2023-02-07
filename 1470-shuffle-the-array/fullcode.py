#!/usr/local/bin/pytest -s

#!/usr/bin/python3
import pytest
from typing import List


"""
Solution Note

1 <= n <= 500
nums.length == 2n
1 <= nums[i] <= 10^3
"""

# Leet Code Solution
class Solution:
    def shuffle(self, nums: List[int], n: int) -> List[int]:
        result = []
        for i in range(n):
            result.append(nums[i])
            result.append(nums[i+n])
        print(result)
        return result






@pytest.mark.parametrize(
    'expect, args',
    [
        [ [2,3,5,4,1,7], [ [2,5,1,3,4,7], 3 ] ],
        [ [1,4,2,3,3,2,4,1], [ [1,2,3,4,4,3,2,1], 4 ] ],
        [ [1,2,1,2], [ [1,1,2,2], 2 ] ]
    ])
def test_case_normal(expect, args):
    solution = Solution();
    assert expect == solution.shuffle(args[0], args[1])

# pytest fullcode.py
