from math import gcd
class Solution:
    def gcdOfStrings(self, str1: str, str2: str) -> str:
        if str1 + str2 != str2 + str1:
            return ''
        else:
            _gcd = gcd(len(str1),len(str2))
            max_str= max(str1, str2)
            return max_str[:_gcd]