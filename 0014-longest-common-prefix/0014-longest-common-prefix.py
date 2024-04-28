class Solution:
    def longestCommonPrefix(self, strs: List[str]) -> str:
        answer: str = ""
        sorted_str: list[str] = sorted(strs)
        first: str = sorted_str[0]
        last: str= sorted_str[-1]

        for i in range(min(len(first), len(last))):
            if (first[i] != last[i]):
                break
            answer += first[i]

        return answer

