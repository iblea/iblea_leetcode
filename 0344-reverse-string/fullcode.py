#!/usr/bin/python3
import unittest
from typing import List
from typing import Optional


"""
Solution Note

"""

# Leet Code Solution

class Solution:
    def reverseString(self, s: List[str]) -> None:
        """
        Do not return anything, modify s in-place instead.
        """

        if len(s) % 2 == 0:
            slen = len(s) // 2
        else:
            slen = (len(s) // 2) + 1
        i = 0
        j = len(s) - 1
        while i < slen:
            tmp = s[i]
            s[i] = s[j]
            s[j] = tmp
            j -= 1
            i += 1



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
        input_arr = ["A"," ","m","a","n",","," ","a"," ","p","l","a","n",","," ","a"," ","c","a","n","a","l",":"," ","P","a","n","a","m","a"]

        answer = ["a","m","a","n","a","P"," ",":","l","a","n","a","c"," ","a"," ",",","n","a","l","p"," ","a"," ",",","n","a","m"," ","A"]
        self.solution.reverseString(input_arr)
        self.assertEqual(input_arr, answer)

    def test_case_2(self):
        input_arr = ["1", "2", "3", "4"]

        answer = ["4", "3", "2", "1"]
        self.solution.reverseString(input_arr)
        self.assertEqual(input_arr, answer)



if __name__ == "__main__":
    # 스크립트 실행 시, 해당 부분 동작
    unittest.main(verbosity=0)
