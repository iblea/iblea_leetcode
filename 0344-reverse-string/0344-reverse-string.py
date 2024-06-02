class Solution:
    def reverseString(self, s: List[str]) -> None:
        """
        Do not return anything, modify s in-place instead.
        """

        if len(s) % 2 == 0:
            slen = len(s) // 2
        else:
            slen = (len(s) // 2) + 1
        i = 0
        j = len(s) - 1
        while i < slen:
            tmp = s[i]
            s[i] = s[j]
            s[j] = tmp
            j -= 1
            i += 1
