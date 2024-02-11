MAXVAL=2**31
class MinStack:

    def __init__(self):
        self.stack: list[int] = []
        self.min: int = MAXVAL


    def push(self, val: int) -> None:
        self.stack.append(val)
        if val < self.min:
            self.min = val


    def pop(self) -> None:
        self.stack.pop()
        self.min = min(self.stack, default=MAXVAL)


    def top(self) -> int:
        return self.stack[-1]


    def getMin(self) -> int:
        return self.min
