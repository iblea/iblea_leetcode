# Leet Code Solution
class Solution:
    def intToRoman(self, num: int) -> str:
        ROAM = {
            1: ("I", "V", "X"),
            10: ("X", "L", "C"),
            100: ("C", "D", "M"),
            1000: ("M", "", "")
        }

        answer = ""
        n = num
        div = 1000
        while n > 0:
            int_div = n // div
            if  int_div <= 0:
                div //= 10
                continue
            str_1 = ROAM[div][0]
            str_5 = ROAM[div][1]
            str_10 = ROAM[div][2]
            if int_div <= 3:
                answer += (str_1 * int_div)
            elif int_div == 4:
                answer += str_1 + str_5
            elif int_div <= 8:
                answer += str_5 + (str_1 * (int_div - 5))
            elif int_div <= 9:
                answer += str_1 + str_10

            n %= div
            div //= 10

        # print(answer)
        return answer