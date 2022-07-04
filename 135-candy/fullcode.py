#!/usr/bin/python3
import unittest
from typing import List


"""
Solution Note
https://leetcode.com/problems/candy/

n == ratings.length
1 <= n <= 2 * 104
0 <= ratings[i] <= 2 * 104

"""

# Leet Code Solution

class Solution:
    def candy(self, ratings: List[int]) -> int:

        candy_list = [1] * len(ratings)

        # 오름차순 candy list 획득
        for i in range(1, len(ratings)):
            if ratings[i] > ratings[i-1] and candy_list[i] <= candy_list[i-1]:
                candy_list[i] = candy_list[i-1] + 1

        # 내림차순 candy list 획득
        for i in range(len(ratings) - 1, 0, -1):
            if ratings[i-1] > ratings[i] and candy_list[i-1] <= candy_list[i]:
                candy_list[i-1] = candy_list[i] + 1
        
        return sum(candy_list)



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
        res = self.solution.candy(ratings=[0, 1, 2])
        self.assertEqual(res, 6)

    def test_case_normal_2(self):
        res = self.solution.candy(ratings=[1, 0, 2])
        self.assertEqual(res, 5)

    def test_case_normal_3(self):
        res = self.solution.candy(ratings=[1, 2, 2])
        self.assertEqual(res, 4)

    def test_case_normal_4(self):
        res = self.solution.candy(ratings=[1,2,87,87,87,2,1])
        self.assertEqual(res, 13)

    def test_case_normal_5(self):
        res = self.solution.candy(ratings=[4,3,2,1,1,2,3,4])
        self.assertEqual(res, 20)

    def test_case_normal_5(self):
        res = self.solution.candy(ratings=[1,3,2,2,1])
        self.assertEqual(res, 7)

    def test_case_normal_6(self):
        res = self.solution.candy(ratings=[1,6,10,8,7,3,2])
        self.assertEqual(res, 18)

    def test_case_normal_7(self):
        res = self.solution.candy(ratings=[1,3,4,5,2])
        self.assertEqual(res, 11)




if __name__ == "__main__":
    # 스크립트 실행 시, 해당 부분 동작
    unittest.main(verbosity=0)
    pass
