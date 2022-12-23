#!/usr/local/bin/pytest -s

#!/usr/bin/python3
import pytest
from typing import List


"""
Solution Note

"""

# Leet Code Solution
class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        n = len(prices)
        buy1 = 0
        sell1 = prices[n-1]
        buy2 = 0
        for i in range(n - 2, -1, -1):
            buyi = max(buy1, sell1 - prices[i])
            selli = max(sell1, buy2 + prices[i])
            buy2 = buy1
            buy1 = buyi
            sell1 = selli
        return buy1


    """_summary_
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int buy1 = 0, sell1 = prices[n-1], buy2 = 0;
        for (int i = n - 2; i >= 0; i--) {
            int buyi = max(buy1, sell1 - prices[i]);
            int selli = max(sell1, buy2 + prices[i]);
            buy2 = buy1; buy1 = buyi; sell1 = selli;
        }
        return buy1;
    }
    """





@pytest.mark.parametrize(
    'expect, args',
    [
        [ 3, [ [1,2,3,0,2] ] ],
        [ 0, [ [1] ] ]
        # [4, [ 1, 2 ]],
    ])
def test_case_normal(expect, args):
    solution = Solution();
    assert expect == solution.maxProfit(args[0])

