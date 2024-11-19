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
