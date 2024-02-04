class Solution:
    def mergeAlternately(self, word1: str, word2: str) -> str:
        minlen: int = min(len(word1), len(word2))
        answer: str = ""
        for i in range(minlen):
            answer += word1[i] + word2[i]

        if len(word1) > len(word2):
            answer += word1[minlen:]
        else:
            answer += word2[minlen:]
        return answer