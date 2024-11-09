class Solution:
    def partition(self, s: str) -> List[List[str]]:
        answer = []
        def func(ss, lst):

            if ss == "":
                if len(lst) > 0:
                    nonlocal answer
                    answer.append(lst)
                return

            for i in range(1, len(ss)+1):
                curs = ss[:i]
                if self.is_palindrome(curs) is False:
                    continue
                func(ss[i:], lst + [curs])

        func(s, [])
        return answer

    def is_palindrome(self, s: str) -> bool:
        divide2 = len(s) // 2

        for i in range(divide2):
            if s[i] != s[len(s)-i-1]:
                return False
        return True

