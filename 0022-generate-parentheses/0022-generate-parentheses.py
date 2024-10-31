class Solution:
    def generateParenthesis(self, n: int) -> List[str]:
        answer: List[str] = []

        def func(s, l, r):
            if l == 0 and r == 0:
                answer.append(s)
                return

            if l > 0:
                func(s + "(", l - 1, r)
            if r > 0 and l < r:
                func(s + ")", l, r - 1)

        func("", n, n)
        return answer
