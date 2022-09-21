"""
Solution Note

1 <= nums.length <= 10**4
-10**4 <= nums[i] <= 10**4
1 <= queries.length <= 10**4
-10**4 <= vali <= 10**4
0 <= indexi < nums.length
"""

# Leet Code Solution
class Solution:
    def sumEvenAfterQueries(self, nums: List[int], queries: List[List[int]]) -> List[int]:
        sum = 0

        # 짝수만 더한다.
        for num in nums:
            if num % 2 != 0:
                continue
            sum += num

        result = []
        for query in queries:
            val = query[0]
            index = query[1]

            # if 기존에 짝수였다면
            if nums[index] % 2 == 0:
                # 기존 짝수를 빼고
                sum -= nums[index]

            # 새로 더한 수가 짝수이면 더하고 아니면 더하지 않는다.
            nums[index] = nums[index] + val
            if nums[index] % 2 == 0:
                sum += nums[index]
            result.append(sum)

        return result

