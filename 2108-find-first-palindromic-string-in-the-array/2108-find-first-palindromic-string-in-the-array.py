class Solution:
    def firstPalindrome(self, words: List[str]) -> str:
        for word in words:
            left = 0
            right = len(word) - 1
            limit = len(word) // 2
            while left < limit:
                if word[left] != word[right]:
                    break
                left += 1
                right -= 1
            if left == limit:
                return word
        return ""