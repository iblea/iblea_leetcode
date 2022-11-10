# Leet Code Solution
class Solution:
    def removeDuplicates(self, s: str) -> str:
        slist = list(s)
        i = 0

        while i < len(slist) - 1:
            if slist[i] == slist[i+1]:
                del slist[i]
                del slist[i]
                if i > 0:
                    i -= 1
                continue
            i += 1

        return "".join(slist)