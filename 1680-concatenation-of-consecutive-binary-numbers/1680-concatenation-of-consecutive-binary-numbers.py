# Leet Code Solution
class Solution:
    def concatenatedBinary(self, n: int) -> int:
        MODULO = 10**9 + 7
        bin_data = 0

        if n == 0:
            return 0
        if n == 1:
            return 1

        sum = 1
        for num in range(2, n + 1):
            # cnt, tmp = 0, num
            # while tmp > 0:
            #     tmp //= 2
            #     cnt += 1
            # sum = sum << cnt
            # 해당 반복문보다 아래 한 줄이 더 빠르다. (더 느릴 줄 알았는데..)
            sum = sum << len(bin(num)[2:])
            sum = (sum | num) % MODULO

        return sum