"""
Solution Note

1 <= q <= p <= 1000
"""

# Leet Code Solution
class Solution:
    def mirrorReflection(self, p: int, q: int) -> int:
        # 최소공배수 구하기
        L = lcm(p,q)

        if (L // q) % 2 == 0:
            return 2

        return (L // p) % 2

def gcd(x,y):
    while(y):
        tmp = x
        x = y
        y = tmp % y
    return x

def lcm(x,y):
    return x * y // gcd(x,y)

