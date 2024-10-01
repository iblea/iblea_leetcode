#!/usr/bin/python3
import unittest
from typing import List
from typing import Optional


"""
Solution Note

"""

# Leet Code Solution

class Solution:
    def canArrange(self, arr: List[int], k: int) -> bool:

        if k == 1:
            return True

        match_num = {}
        matched = 0
        true_val = len(arr) // 2

        for num in arr:
            realnum = num % k
            if realnum == 0:
                realnum = k

            match= k - realnum
            if match == 0:
                match = k

            if match in match_num and match_num[match] > 0:
                matched += 1
                match_num[match] -= 1
            else:
                if realnum in match_num:
                    match_num[realnum] += 1
                else:
                    match_num[realnum] = 1

        if matched == true_val:
            return True
        return False







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
        res = self.solution.canArrange(arr = [1,2,3,4,5,10,6,7,8,9], k = 5)
        self.assertEqual(res, True)

    def test_case_2(self):
        res = self.solution.canArrange(arr = [1,2,3,4,5,6], k = 7)
        self.assertEqual(res, True)

    def test_case_3(self):
        res = self.solution.canArrange(arr = [1,2,3,4,5,6], k = 10)
        self.assertEqual(res, False)


if __name__ == "__main__":
    # 스크립트 실행 시, 해당 부분 동작
    unittest.main(verbosity=0)
