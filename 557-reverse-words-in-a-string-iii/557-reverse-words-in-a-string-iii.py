class Solution:
    def reverseWords(self, s: str) -> str:
        words = s.split(' ')
        result = ""

        for word in words:
            for i in range(len(word) - 1, -1, -1):
                result += word[i]
            result += " "
        return result[:-1]

