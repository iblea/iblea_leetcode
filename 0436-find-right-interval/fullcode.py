#!/usr/bin/python3
import unittest
from typing import List
from typing import Optional


"""
Solution Note

"""

# Leet Code Solution

# The isBadVersion API is already defined for you.
# def isBadVersion(version: int) -> bool:

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



# python unit test
class UnitTest(unittest.TestCase):

    # 클래스 생성 시 1회 실행
    @classmethod
    def setUpClass(self):
        pass

    # 클래스 소멸 시 1회 실행
    @classmethod
    def tearDownClass(self):
        pass

    # 테스트 케이스 전 실행
    def setUp(self):
        self.solution = Solution()

    # 테스트 케이스 후 실행
    def tearDown(self):
        pass

    def test_case_1(self):
        res = self.solution.findRightInterval(intervals = [[1,2]])
        self.assertEqual(res, [-1])

    def test_case_2(self):
        res = self.solution.findRightInterval(intervals = [[3,4],[2,3],[1,2]])
        self.assertEqual(res, [-1, 0, 1])

    def test_case_3(self):
        res = self.solution.findRightInterval(intervals = [[1,4],[2,3],[3,4]])
        self.assertEqual(res, [-1, 2, -1])

    def test_case_4(self):
        res = self.solution.findRightInterval([[4,5],[2,3],[1,2]])
        self.assertEqual(res, [-1,0,1])




if __name__ == "__main__":
    # 스크립트 실행 시, 해당 부분 동작
    unittest.main(verbosity=0)
