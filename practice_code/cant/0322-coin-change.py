#!/usr/bin/python3
import unittest
from typing import List
from typing import Optional


"""
Solution Note

"""

# Leet Code Solution
class Solution:
    def coinChange(self, coins: List[int], amount: int) -> int:

        dp = [float('inf') for _ in range(amount+1)]
        dp[0] = 0
        coins.sort()
        for i in range(1, amount+1):
            for coin in coins:
                # (cur_amount(i) - 코인값) 이 0보다 작으면 -> 이 코인값은 더이상 구할 필요가 없다.
                if i - coin < 0:
                    break
                if dp[i-coin] != float('inf'):
                    dp[i] = min(dp[i], dp[i-coin]+1)
            pass

        if dp[amount] == float('inf'):
            return -1
        return dp[amount]


    def coinChange_TimeLimitExceed(self, coins: List[int], amount: int) -> int:
        if amount == 0:
            return 0

        dp = [ None  for _ in range(amount+1)]
        coins.sort(reverse=True)
        for coin in coins:
            dp[coin] = 1

        def dpfunc(num):
            print(num)
            if dp[num] != None:
                return dp[num]

            for i in range(len(coins)):
                # 코인값이 num값보다 크다 -> 이 코인값은 구할 필요가 없다.
                # 남아있는돈이 400, 500원짜리 동전을 추가할 수 없으니 이런 조건을 체크
                if coins[i] > num:
                    continue
                # num - 코인 -> dpfunc 돌림
                res = dpfunc(num - coins[i])
                if res == None:
                    continue
                if dp[num] == None:
                    dp[num] = res + 1
                else:
                    dp[num] = min(dp[num], res + 1)
            # dp에 값이 없으면 -> -1 이겠죠?
            return dp[num]

        res = dpfunc(amount)
        if res == None:
            return -1
        return res


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
        res = self.solution.coinChange([1, 2, 5], 11)
        self.assertEqual(res, 3)

    # def test_case_2(self):
    #     res = self.solution.coinChange([2], 3)
    #     self.assertEqual(res, -1)

    # def test_case_3(self):
    #     res = self.solution.coinChange([1], 0)
    #     self.assertEqual(res, 0)

    # def test_case_4(self):
    #     res = self.solution.coinChange([1, 2, 5], 100)
    #     self.assertEqual(res, 20)

    # def test_case_5(self):
    #     res = self.solution.coinChange([186,419,83,408], 6249)
    #     print(res)
    #     # self.assertEqual(res, 6249)



if __name__ == "__main__":
    # 스크립트 실행 시, 해당 부분 동작
    unittest.main(verbosity=0)
