class Solution:
    def isValid(self, s: str) -> bool:
        stack = []
        for chr in s:
            if chr in ["(", "{", "["]:
                stack.append(chr)
                continue

            if not stack:
                return False
            ret = stack.pop()
            if ret == "(" and chr != ")":
                return False
            if ret == "{" and chr != "}":
                return False
            if ret == "[" and chr != "]":
                return False
        if stack:
            return False
        return True