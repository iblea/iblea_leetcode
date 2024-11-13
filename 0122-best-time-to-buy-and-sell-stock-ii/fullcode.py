#!/usr/bin/python3
import unittest
from typing import List
from typing import Optional


"""
Solution Note

https://leetcode.com/problems/best-time-to-buy-and-sell-stock-ii

You are given an integer array prices where prices[i] is the price of a given stock on the ith day.
On each day, you may decide to buy and/or sell the stock. You can only hold at most one share of the stock at any time. However, you can buy it then immediately sell it on the same day.
Find and return the maximum profit you can achieve.

정수 배열 가격이 주어지는데, 여기서 가격[i]은 i번째 날에 주어진 주식의 가격입니다.
매일 주식을 매수하거나 매도하기로 결정할 수 있습니다. 주식은 언제든지 최대 한 주까지만 보유할 수 있습니다. 그러나 주식을 매수한 후 즉시 당일에 매도할 수 있습니다.
달성할 수 있는 최대 수익을 찾아서 반환하세요.

1 <= prices.length <= 3 * (10**4)
0 <= prices[i] <= (10**4)
"""

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




# python unit test
class UnitTest(unittest.TestCase):

    # 클래스 생성 시 1회 실행
    @classmethod
    def setUpClass(self):
        pass

    # 클래스 소멸 시 1회 실행
    @classmethod
    def tearDownClass(self):
        pass

    # 테스트 케이스 전 실행
    def setUp(self):
        self.solution = Solution()

    # 테스트 케이스 후 실행
    def tearDown(self):
        pass

    def test_case_1(self):
        res = self.solution.maxProfit(prices = [7,1,5,3,6,4])
        self.assertEqual(res, 7)
        """
        Buy on day 2 (price = 1) and sell on day 3 (price = 5), profit = 5-1 = 4.
        Then buy on day 4 (price = 3) and sell on day 5 (price = 6), profit = 6-3 = 3.
        Total profit is 4 + 3 = 7.
        """

    def test_case_2(self):
        res = self.solution.maxProfit(prices = [1,2,3,4,5])
        self.assertEqual(res, 4)
        """
        Buy on day 1 (price = 1) and sell on day 5 (price = 5), profit = 5-1 = 4.
        Total profit is 4.
        """

    def test_case_3(self):
        res = self.solution.maxProfit(prices = [7,6,4,3,1])
        self.assertEqual(res, 0)
        """
        There is no way to make a positive profit, so we never buy the stock to achieve the maximum profit of 0.
        """



if __name__ == "__main__":
    # 스크립트 실행 시, 해당 부분 동작
    unittest.main(verbosity=0)
