
# Leet Code Solution
class Solution:
    def reverseVowels(self, s: str) -> str:
        vowels = ['A', 'E', 'I', 'O', 'U', 'a', 'e', 'i', 'o', 'u']
        liststr = list(s)
        first = 0
        last = len(liststr) - 1
        while first < last:
            if liststr[first] not in vowels:
                first += 1
                continue
            if liststr[last] not in vowels:
                last -= 1
                continue
            tmp = liststr[first]
            liststr[first] = liststr[last]
            liststr[last] = tmp
            first += 1
            last -= 1
        return "".join(liststr)