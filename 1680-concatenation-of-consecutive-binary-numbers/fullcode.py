#!/usr/bin/python3
import unittest
from typing import List


"""
Solution Note

1 <= n <= 10**5

MODULO 연산 테스트

11011100 = 220 -> 0
1 -> 1
110 -> 6
11011 -> 27 -> 7
111 -> 7
111100 -> 60
11011100 -> 220

"""


# Leet Code Solution
class Solution:
    def concatenatedBinary(self, n: int) -> int:
        MODULO = 10**9 + 7
        bin_data = 0

        if n == 0:
            return 0
        if n == 1:
            return 1

        sum = 1
        for num in range(2, n + 1):
            # cnt, tmp = 0, num
            # while tmp > 0:
            #     tmp //= 2
            #     cnt += 1
            # sum = sum << cnt
            # 해당 반복문보다 아래 한 줄이 더 빠르다. (더 느릴 줄 알았는데..)
            sum = sum << len(bin(num)[2:])
            sum = (sum | num) % MODULO

        return sum

    def concatenatedBinary_first(self, n: int) -> int:
        MODULO = 10**9 + 7
        strbin = ""

        for i in range(1, n + 1):
            strbin += bin(i)[2:]

        multiple = 1
        sum = 0
        for i in range(len(strbin) - 1, -1, -1):
            if strbin[i] == "1":
                sum += multiple
            multiple *= 2
            multiple %= MODULO

        return sum % MODULO





# python unit test
class UnitTest(unittest.TestCase):

    # 클래스 생성 시 1회 실행
    @classmethod
    def setUpClass(self):
        self.solution = Solution();

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
        res = self.solution.concatenatedBinary(1)
        self.assertEqual(res, 1)

    def test_case_normal_2(self):
        res = self.solution.concatenatedBinary(3)
        """
        Output: 27
        Explanation: In binary, 1, 2, and 3 corresponds to "1", "10", and "11".
        After concatenating them, we have "11011", which corresponds to the decimal value 27.
        """
        self.assertEqual(res, 27)

    def test_case_normal_3(self):
        res = self.solution.concatenatedBinary(12)
        """
        Output: 505379714
        Explanation: The concatenation results in "1101110010111011110001001101010111100".
        The decimal value of that is 118505380540.
        After modulo 10**9 + 7, the result is 505379714.
        """
        self.assertEqual(res, 505379714)

    def test_case_normal_4(self):
        res = self.solution.concatenatedBinary(2)
        self.assertEqual(res, 6)

    def test_case_normal_5(self):
        res = self.solution.concatenatedBinary(4)
        self.assertEqual(res, 220)

    def test_case_normal_6(self):
        res = self.solution.concatenatedBinary(5)
        self.assertEqual(res, 1765)

    def test_case_normal_7(self):
        res = self.solution.concatenatedBinary(77105)
        self.assertEqual(res, 359340584)





if __name__ == "__main__":
    # 스크립트 실행 시, 해당 부분 동작
    unittest.main(verbosity=0)
    pass
