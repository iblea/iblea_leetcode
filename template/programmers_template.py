#!/usr/bin/python3
import unittest
from typing import List


"""
Solution Note

"""

def solution(num: int):
    return 0




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
        res = solution(1)
        self.assertEqual(res, 1)

    def test_case_normal_2(self):
        res = solution(2)
        self.assertEqual(res, 0)



if __name__ == "__main__":
    # 스크립트 실행 시, 해당 부분 동작
    unittest.main(verbosity=0)
    pass
