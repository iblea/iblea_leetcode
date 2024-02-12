class Solution:
    def evalRPN(self, tokens: List[str]) -> int:
        stack = []
        for token in tokens:
            if token == "+":
                num1: int = stack.pop()
                num2: int = stack.pop()
                stack.append(num2 + num1)
                continue
            if token == "-":
                num1: int = stack.pop()
                num2: int = stack.pop()
                stack.append(num2 - num1)
                continue
            if token == "*":
                num1: int = stack.pop()
                num2: int = stack.pop()
                stack.append(num2 * num1)
                continue
            if token == "/":
                num1: int = stack.pop()
                num2: int = stack.pop()
                stack.append(int(num2 / num1))
                continue
            stack.append(int(token))
        return stack[0]
