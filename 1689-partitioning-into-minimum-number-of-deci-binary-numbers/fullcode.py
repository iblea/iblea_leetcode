#!/usr/bin/python3
import unittest
from typing import List


"""
자릿수중에 가장 수가 높은 수를 찾아 리턴하면 끝 아닌가?
32 = 3
351 = 5
65390 = 9
...

문자열의 길이를 체크해 문자열을 순회하며 문자를 아스키코드로 변환,
아스키코드를 숫자로 재변환하여 문자열을 숫자로 바꿔 크기를 비교한다.

input value는 최소 1부터, 숫자만 들어오므로 예외처리는 진행하지 않는다.

"""


ASCII_0_CHR_VALUE = 48

# Leet Code Solution
class Solution:
    def minPartitions(self, n: str) -> int:
        max_value = 0
        for i in range(len(n)):
            # 48은 상수 0 ascii 코드 값
            chr_to_int = ord(n[i]) - ASCII_0_CHR_VALUE
            if max_value < chr_to_int:
                max_value = chr_to_int

        return max_value




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
        res = self.solution.minPartitions(n="32")
        self.assertEqual(res, 3)

    def test_case_normal_2(self):
        res = self.solution.minPartitions(n="82734")
        self.assertEqual(res, 8)

    def test_case_normal_3(self):
        res = self.solution.minPartitions(n="27346209830709182346")
        self.assertEqual(res, 9)




if __name__ == "__main__":
    # 스크립트 실행 시, 해당 부분 동작
    unittest.main(verbosity=0)
    pass
