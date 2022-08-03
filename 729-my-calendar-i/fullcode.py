#!/usr/bin/python3
import unittest
from typing import List


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



def rbisect_right(arr, value, begin, end):
    if begin >= end:
        return begin
    mid = begin + (end - begin) // 2
    # bisect_right일 때에는 high 세팅 먼저
    # 고로 비교문을 < 로 해줘야 한다.
    if value < arr[mid]:
        return rbisect_right(arr, value, begin, mid)
    else:
        return rbisect_right(arr, value, mid + 1, end)

def rbisect_left(arr, value, begin, end):
    if begin >= end:
        return begin
    mid = begin + (end - begin) // 2
    # bisect_left일 때에는 low 세팅 먼저
    # 고로 비교문을 > 로 해줘야 한다.
    # if arr[mid] < value:
    if value > arr[mid]:
        return bisect_left(arr, value, mid + 1, end)
    else:
        return bisect_left(arr, value, begin, mid)

def bisect_right(arr, value):
    low = 0
    high = len(arr)

    if high == 0:
        if value < arr[0]:
            return 0
        else:
            return 1

    while low < high:
        mid = low + (high - low) // 2
        if value < arr[mid]: 
            high = mid
        else:
            low = mid + 1
    return low

def bisect_left(arr, value):
    low = 0
    high = len(arr)

    if high == 0:
        if value > arr[0]:
            return 1
        else:
            return 0

    while low < high:
        mid = low + (high - low) // 2
        if value > arr[mid]: 
            low = mid + 1
        else:
            high = mid
    return low


true = True
false = False

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
        pass

    # 테스트 케이스 후 실행
    def tearDown(self):
        pass

    def test_case_normal_1(self):
        cal= MyCalendar();
        input_value = [[10, 20], [15, 25], [20, 30]]
        expected = [True, False, True]

        cal= MyCalendar();
        for i in range(len(expected)):
            res = cal.book(input_value[i][0], input_value[i][1])
            self.assertEqual(res, expected[i])

    def test_case_normal_2(self):
        input_value = [[47,50],[33,41],[39,45],[33,42],[25,32],[26,35],[19,25],[3,8],[8,13],[18,27]]
        expected = [True,True,False,False,True,False,True,True,True,False]

        cal= MyCalendar();
        for i in range(len(expected)):
            # print("i = {}, input_value = {}".format(i, input_value[i]))
            res = cal.book(input_value[i][0], input_value[i][1])
            self.assertEqual(res, expected[i])
            # print(cal.calendar)

    def test_case_normal_3(self):
        input_value = [[20,29],[13,22],[44,50],[1,7],[2,10],[14,20],[19,25],[36,42],[45,50],[47,50],[39,45],[44,50],[16,25],[45,50],[45,50],[12,20],[21,29],[11,20],[12,17],[34,40],[10,18],[38,44],[23,32],[38,44],[15,20],[27,33],[34,42],[44,50],[35,40],[24,31]]
        expected = [True,False,True,True,False,True,False,True,False,False,False,False,False,False,False,False,False,False,False,False,False,False,False,False,False,False,False,False,False,False]
        cal= MyCalendar();
        for i in range(len(expected)):
            # print("i = {}, input_value = {}".format(i, input_value[i]))
            res = cal.book(input_value[i][0], input_value[i][1])
            self.assertEqual(res, expected[i])
            # print(cal.calendar)

    def test_case_normal_4(self):
        input_value = [[20,32],[1,19],[34,47],[30,48],[26,44]]
        expected = [true,true,true,false,false]
        cal= MyCalendar();
        for i in range(len(expected)):
            print("i = {}, input_value = {}".format(i, input_value[i]))
            res = cal.book(input_value[i][0], input_value[i][1])
            self.assertEqual(res, expected[i])
            print(cal.calendar)




    def test_bsearch1(self):
        cal= MyCalendar();
        cal.calendar = [[10,0], [20,0], [30,0], [40,0], [50,0], [60,0], [70,0], [80,0], [90,0]]
        status = cal.bisect_right(9)
        self.assertEqual(status, -1)
        status = cal.bisect_right(10)
        self.assertEqual(status, 0)
        status = cal.bisect_right(13)
        self.assertEqual(status, 0)
        status = cal.bisect_right(15)
        self.assertEqual(status, 0)
        status = cal.bisect_right(18)
        self.assertEqual(status, 0)
        status = cal.bisect_right(20)
        self.assertEqual(status, 1)
        status = cal.bisect_right(22)
        self.assertEqual(status, 1)
        status = cal.bisect_right(25)
        self.assertEqual(status, 1)
        status = cal.bisect_right(28)
        self.assertEqual(status, 1)
        status = cal.bisect_right(50)
        self.assertEqual(status, 4)
        status = cal.bisect_right(55)
        self.assertEqual(status, 4)

    def test_bsearch2(self):
        cal= MyCalendar();
        cal.calendar = [[10,0]]

        status = cal.bisect_right(5)
        self.assertEqual(status, -1)

        status = cal.bisect_right(10)
        self.assertEqual(status, 0)

        status = cal.bisect_right(15)
        self.assertEqual(status, 0)

        status = cal.bisect_right(20)
        self.assertEqual(status, 0)


    def test_bsearch_1d(self):
        import bisect
        lst = [10]

        status = bisect_right(lst, 5)
        self.assertEqual(status, bisect.bisect_right(lst, 5))

        status = bisect.bisect_right(lst, 10)
        self.assertEqual(status, bisect.bisect_right(lst, 10))

        status = bisect_right(lst, 15)
        self.assertEqual(status, bisect.bisect_right(lst, 15))

        status = bisect_right(lst, 20)
        self.assertEqual(status, bisect.bisect_right(lst, 20))

    def test_bisect_1d_2(self):
        import bisect
        lst = [1, 20]

        status = bisect_right(lst, 34)
        self.assertEqual(status, bisect.bisect_right(lst, 34))









if __name__ == "__main__":
    # 스크립트 실행 시, 해당 부분 동작
    unittest.main(verbosity=0)
    pass
