#!/usr/bin/python3
import unittest
from typing import List
from typing import Optional


"""
Solution Note




0         - 0 = 0
1         - 1 = 1

10        - 1 + 0 = 1
11        - 1 + 1 = 2

100       - 1 + 0 = 1
101       - 1 + 1 = 2
110       - 1 + 1 = 2
111       - 1 + 2 = 3

1000      - 1 + 0 = 1
1001      - 1 + 1 = 1
1010      - 1 + 1 = 2
1011      - 1 + 2 = 3
1100      - 1 + 1 = 2
1101      - 1 + 2 = 3
1110      - 1 + 2 = 3
1111      - 1 + 3 = 4

10000     - 1 + 0 = 1


0 - 0
1 - 1

2 - 2

3 - 4

4 - 8

5 - 16


2 ** (n-1) (2^(n-1))


n == 0: [0]
n == 1: [0, 1]
n == 2: [0, 1, 1]
n == 3: [0, 1, 1, 2]




아하, 2의 n승일 때마다 배열의 인덱스를 초기화해가면서 1 + 배열인덱스 하면 됨!

즉

n == 0: [0]
n == 1: [0, 1]


n == 0:
    return [0]

n == 1:
    return [0, 1]
까지는 상수로 리턴하고,


n == 2: [0, 1, arr[0] + 1] -> [0, 1, 2]
n == 3: [0, 1, arr[0] + 1, arr[1] + 1] -> [0, 1, 1, 2]

n == 4면 다시 구한 배열을 바탕으로,
n == 4: [0, 1, 1, 2, arr[0] + 1] -> [0, 1, 1, 2, 1]
n == 5: [0, 1, 1, 2, arr[0] + 1, arr[1] + 1] -> [0, 1, 1, 2, 1, 2]
n == 6: [0, 1, 1, 2, arr[0] + 1, arr[1] + 1, arr[2] + 1] -> [0, 1, 1, 2, 1, 2, 2]
n == 7: [0, 1, 1, 2, arr[0] + 1, arr[1] + 1, arr[2] + 1, arr[3] + 2] -> [0, 1, 1, 2, 1, 2, 2, 3]

"""

# Leet Code Solution
class Solution:
    def countBits(self, n: int) -> List[int]:
        if n == 0:
            return [0]

        if n == 1:
            return [0, 1]

        arr = [0, 1]
        traversal = 2


        while True:
            for i in range(traversal):
                arr.append(arr[i] + 1)
                if len(arr) > n:
                    return arr

            traversal *= 2




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
        res = self.solution.countBits(2)
        self.assertEqual(res, [0, 1, 1])

    def test_case_2(self):
        res = self.solution.countBits(5)
        self.assertEqual(res, [0,1,1,2,1,2])




if __name__ == "__main__":
    # 스크립트 실행 시, 해당 부분 동작
    unittest.main(verbosity=0)
