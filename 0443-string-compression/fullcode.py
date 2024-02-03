#!/usr/bin/python3
import unittest
from typing import List


"""
Solution Note

"""

# Leet Code Solution

class Solution:
    def compress(self, chars: List[str]) -> int:
        compress_char: str = ""
        compress_count: int = 0
        compress_arr: list[str] = []
        for char in chars:
            if compress_char == char:
                compress_count += 1
                continue

            if compress_count > 1:
                compress_arr += list(str(compress_count))

            compress_count = 1
            compress_char = char
            compress_arr.append(compress_char)

        # deep copy
        # chars = compress_arr (X)
        chars[:] = compress_arr
        if compress_count > 1:
            chars += list(str(compress_count))
        return len(chars)




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

    def test_case_1(self):
        chars = ["a","a","b","b","c","c","c"]
        res = self.solution.compress(chars)
        print(res)
        print(chars)
        self.assertEqual(res, 6)
        self.assertEqual(chars, ["a","2","b","2","c","3"])

    def test_case_2(self):
        chars = ["a"]
        res = self.solution.compress(chars)
        self.assertEqual(res, 1)
        self.assertEqual(chars, ["a"])

    def test_case_3(self):
        chars = ["a","b","b","b","b","b","b","b","b","b","b","b","b"]
        res = self.solution.compress(chars)
        self.assertEqual(res, 4)
        self.assertEqual(chars, ["a","b","1","2"])





if __name__ == "__main__":
    # 스크립트 실행 시, 해당 부분 동작
    unittest.main(verbosity=0)
    pass
