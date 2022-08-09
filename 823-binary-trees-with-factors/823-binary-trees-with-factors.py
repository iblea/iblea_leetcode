"""
Solution Note
https://leetcode.com/problems/binary-trees-with-factors/

1 <= arr.length <= 1000
2 <= arr[i] <= 10^9
All the values of arr are unique

return modulo (10^9 + 7 = 1000000007)
"""

# Leet Code Solution

# 제곱근 구하는 내장 함수
from math import sqrt
# 소수 내리는 내장 함수
from math import floor
class Solution:
    modulo: int = 1000000007
    def numFactoredBinaryTrees(self, arr: List[int]) -> int:
        arr.sort()
        # mdict = multiplication dictionary
        numdict = {}
        for num in arr:
            numdict[num] = True

        mdict = {}
        mdict[1] = 1
        mdict[arr[0]] = 1

        for i in range(1, len(arr)):
            cur = arr[i]
            mdict[cur] = 1
            sqrt_num = floor(sqrt(cur))
            if sqrt_num * sqrt_num == cur:
                if sqrt_num in mdict:
                    mdict[cur] += (mdict[sqrt_num] * mdict[sqrt_num])
                    sqrt_num -= 1

            sqrt_num += 1
            for j in range(i):
                num = arr[j]
                if num >= sqrt_num:
                    break
                # 숫자가 배열에 있는지부터 체크한다.
                if not (num in numdict):
                    continue
                if cur % num != 0:
                    continue

                if not (cur // num in numdict):
                    continue

                mdict[cur] += ( mdict[num] * mdict[cur // num] ) * 2

        answer: int = sum(mdict.values()) - 1
        return answer % self.modulo

