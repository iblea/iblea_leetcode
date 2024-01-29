class Solution:
    def reverseWords(self, s: str) -> str:
        # arr: list[str] = s.strip().split()
        arr: list[str] = s.split()
        arr.reverse() # arr = arr[::-1]
        return ' '.join(arr)