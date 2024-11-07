class Solution:
    def generateParenthesis(self, n: int) -> List[str]:
        answer = []

        stack = [ (n, n, "") ]
        while len(stack) > 0:

            curr = stack.pop(0)
            open = curr[0]
            close = curr[1]
            brackets = curr[2]

            if open == 0 and close == 0:
                answer.append(brackets)
                continue

            if open > 0:
                stack.append((open - 1, close, brackets + "("))
            if open < close:
                stack.append((open, close - 1, brackets + ")"))

        return answer
