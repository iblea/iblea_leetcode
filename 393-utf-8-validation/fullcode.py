#!/usr/bin/python3
from unicodedata import digit
import unittest
from typing import List


"""
Solution Note

1 <= data.length <= 2 * 10**4
0 <= data[i] <= 255
"""

# Leet Code Solution
class Solution:
    # if list validate utf-8
    digit = [
        0b10000000,
        0b01000000,
        0b00100000,
        0b00010000,
        0b00001000,
        0b00000100,
        0b00000010,
        0b00000001,
    ]
    def validUtf8(self, data: List[int]) -> bool:
        index = 0
        while index < len(data):
            digit_result = self.check_digit(data[index])
            if digit_result < 0:
                return False

            index += 1
            if digit_result == 0:
                continue

            if index + digit_result > len(data):
                return False
        
            for i in range(digit_result):
                if data[index] & self.digit[0] != self.digit[0]:
                    return False
                if data[index] & self.digit[1] != 0:
                    return False
                index += 1

        return True
    
    # return UTF-8 Octet Sequence
    def check_digit(self, octet: int) -> int:
        if octet & self.digit[0] != self.digit[0]:
            return 0
        for i in range(2,5):
            if octet & self.digit[i] == self.digit[i]:
                continue

            # i 가 1 일 경우는 존재하지 못함
            if i == 1:
                return -1
            return i - 1
        
        return -1





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
        res = self.solution.validUtf8([197,130,1])
        self.assertEqual(res, True)

    def test_case_normal_2(self):
        res = self.solution.validUtf8([235,140,4])
        self.assertEqual(res, False)

    def test_case_normal_3(self):
        res = self.solution.validUtf8([230,136,145])
        self.assertEqual(res, True)

    def test_case_normal_4(self):
        res = self.solution.validUtf8([250,145,145,145,145])
        self.assertEqual(res, False)






if __name__ == "__main__":
    # 스크립트 실행 시, 해당 부분 동작
    unittest.main(verbosity=0)
    pass
