# Leet Code Solution
class Solution:
    vowel = ('a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U')
    def halvesAreAlike(self, s: str) -> bool:
        slen = len(s) // 2

        stra = s[:slen]
        strb = s[slen:]
        avol = 0
        bvol = 0
        for ch in stra:
            if ch in self.vowel:
                avol += 1
        for ch in strb:
            if ch in self.vowel:
                bvol += 1

        return avol == bvol

