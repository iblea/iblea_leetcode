class Solution:
    def removeOuterParentheses(self, s: str) -> str:
        stack = []
        result_string = ""
        for chr in s:
            if chr == ")":
                stack.pop()
                if not stack:
                    continue
                result_string += ")"
                continue

            if stack:
                result_string += "("
            stack.append(chr)
            continue

        return result_string

