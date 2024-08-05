class Solution:
    def isIsomorphic(self, s: str, t: str) -> bool:
        if len(s) != len(t):
            return False

        s1 = [ ]
        dic = {}
        cnt = 0
        for c in s:
            if c not in dic:
                dic[c] = cnt
                cnt += 1
            s1.append(dic[c])
        dic = {}
        cnt = 0
        for i in range(len(t)):
            c = t[i]
            if c not in dic:
                dic[c] = cnt
                cnt += 1
            if dic[c] != s1[i]:
                return False
        return True

