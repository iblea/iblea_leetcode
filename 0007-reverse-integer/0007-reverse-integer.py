class Solution:
    def reverse(self, x: int) -> int:
        if x == 0:
            return 0

        minus = False
        if x < 0:
            minus = True

        answer = 0
        x = abs(x)
        while x > 0:
            answer = (answer * 10) + (x % 10)
            x = x // 10
            if answer > 214748364:
                if x > 0:
                    return 0
            elif answer == 214748364:
                if minus and x > 8:
                    return 0
                if minus == False and x > 7:
                    return 0


        if minus:
            return -answer
        return answer

