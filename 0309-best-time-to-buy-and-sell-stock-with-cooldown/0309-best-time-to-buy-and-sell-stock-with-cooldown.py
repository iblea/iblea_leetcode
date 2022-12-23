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