import math
class Solution:
    def minSteps(self, n: int) -> int:
        if n == 1:
            return 0

        max_log = int(math.sqrt(n)) + 1
        save_nums = []
        cal = n
        while cal > 1:
            is_divide = False
            for i in range(2, max_log):
                if cal % i == 0:
                    save_nums.append(i)
                    cal = cal // i
                    is_divide = True
                    break
            if not is_divide:
                save_nums.append(cal)
                break
            else:
                max_log = int(math.sqrt(cal)) + 1

        sum = 0
        for num in save_nums:
            sum += num
        return sum

