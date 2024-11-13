NO_STOCK = -1
# Leet Code Solution
class Solution:
    def maxProfit(self, prices: List[int]) -> int:

        # 1. 현재 날짜보다 다음 날짜의 주식 가격이 더 높다면, 매도하지 않고 유지한다.
        # 2. 현재 날짜보다 다음 날짜의 주식 가격이 더 낮거나 같다면, 매도하고 다음 날의 주식을 확인한다.
        # 2.1 매도한 뒤 다음 날의 주식을 확인하고, 다음 날의 주식보다 다다음 날의 주식이 더 낮거나 같으면 매수하지 않는다. (이하 반복)

        profits = 0
        stock = NO_STOCK

        for i in range(len(prices)-1):
            curr_stock = prices[i]
            next_stock = prices[i+1]

            # 주식을 매수하지 않은 상태라면, 매수한다.
            if stock == NO_STOCK:
                stock = curr_stock

            if curr_stock >= next_stock:
                profits += curr_stock - stock
                stock = NO_STOCK

        if stock != -1:
            profits += prices[-1] - stock
        return profits
