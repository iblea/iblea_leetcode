"""
Solution Note

0 <= start < end <= 10^9
At most 1000 calls will be made to book.


"""

# Leet Code Solution
class MyCalendar:

    def __init__(self):
        #[ [start, end], [start, end], [start, end] ... ]
        self.calendar: List[List[int, int]] = []

    def book(self, start: int, end: int) -> bool:
        if len(self.calendar) == 0:
            self.calendar.append([start, end])
            return True

        index = self.bisect_right(start)
        if index == -1:
            if self.calendar[0][0] >= end:
                self.calendar.insert(0, [start, end])
                return True
            else:
                return False

        # start > cal[i][end]
        if start < self.calendar[index][1]:
            return False

        # end < cal[i+1][start]
        if (index + 1) < len(self.calendar) and end > self.calendar[index + 1][0]:
            return False

        self.calendar.insert(index + 1, [start, end])
        return True

    # find_value 와 같거나 find_value 보다 작으면서 가장 가까운 수를 찾는다.

    def bisect_right(self, find_value: int) -> int:
        low = 0
        high = len(self.calendar)

        if high == 0:
            if find_value < self.calendar[0][0]:
                return -1
            else:
                return 0

        while low < high:
            mid = low + (high - low) // 2
            if find_value < self.calendar[mid][0]: 
                high = mid
            else:
                low = mid + 1
        return low - 1

# Your MyCalendar object will be instantiated and called as such:
# obj = MyCalendar()
# param_1 = obj.book(start,end)

