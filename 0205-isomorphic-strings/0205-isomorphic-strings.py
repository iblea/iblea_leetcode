class Solution:
    def isIsomorphic(self, s: str, t: str) -> bool:
        s1 = [ ]
        s2 = [ ]
        dic = {}
        cnt = 0
        for c in s:
            if c not in dic:
                dic[c] = cnt
                cnt += 1
            s1.append(dic[c])
        dic = {}
        cnt = 0
        for c in t:
            if c not in dic:
                dic[c] = cnt
                cnt += 1
            s2.append(dic[c])
        return s1 == s2
