class Solution:
    def dailyTemperatures(self, temperatures: List[int]) -> List[int]:
        monotonic_stack: list[int] = []
        answer: list[int] = [ 0 for _ in range(len(temperatures)) ]

        for i in range(len(temperatures)-1, -1, -1):
            if not monotonic_stack:
                monotonic_stack.append(i)
                continue

            while monotonic_stack and temperatures[i] >= temperatures[monotonic_stack[-1]]:
                monotonic_stack.pop()
            if not monotonic_stack:
                answer[i] = 0
            else:
                answer[i] = monotonic_stack[-1] - i
            monotonic_stack.append(i)

        return answer

