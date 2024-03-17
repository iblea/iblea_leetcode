class Solution:
    startList: List[List[int]] = None
    def findRightInterval(self, intervals: List[List[int]]) -> List[int]:
        self.startList: List[int] = sorted(list([intervals[i][0], i] for i in range(len(intervals))), key=lambda x: x[0])

        answer = []
        for interval in intervals:
            answer.append(self.bisect(interval[1]))
        return answer

    def bisect(self, target: int) -> int:
        left: int  = 0
        right: int = len(self.startList) - 1

        while left <= right:
            mid: int = (left + right) // 2
            if self.startList[mid][0] == target:
                return self.startList[mid][1]

            if self.startList[mid][0] < target:
                left = mid + 1
            else:
                right = mid - 1

        if left >= len(self.startList):
            return -1
        return self.startList[left][1]

