#!/usr/bin/python3
import unittest
from typing import List


"""
Solution Note

"""

# true false 가 아니라 모든 값을 찾아야 할 경우
# input - 4 8 1 2 10 5 11

# 4 8 10, 4 8 11, 4 10 11
# 8 10 11
# 1 2 10, 1 2 5, 1 2 11, 1 10 11, 1 5 11
# 2 10 11, 2 5 11

# input - 4 8 1 2 10 5 11
# arr 1 - 3 2 4 3 1  1 0 - 자신의 인덱스를 기준으로 오른쪽에 있는 값 중 자신보다 큰 값의 개수

# arr 2 - 3 1 5 2 0  0 0 - input과 arr1 배열을 가지고 3개로 묶을 수 있는 케이스의 개수를 구한다.
# (arr2[i-1] 값이 0 일 경우, arr1에서 2 이상인지 찾고 2 이상일 경우 -1, 아닐 경우 0 으로 채움)
# (arr2[i-1] 값이 1 이상일 경우, 자신의 인덱스를 기준으로 오른쪽에 있는 값들 중 input[i] 보다 큰 값의 arr1[i] 를 찾고 그 값을 더해 추가)
# 즉 4는 (2(8) + 1(10) + 0(11) = 3), 8은 (1(10) + 0(11) = 1), 1은 (3(2) + 1(10) + 1(5) + 0(11) = 5) ...

# arr3 - 11 8 7 2 0  0 0 - 3개로 묶을 수 있는 토탈 케이스의 개수

# 12 10 5 11
# 0  1  1 0
# 0  0  0 0
# 0  0  0 0

# 8 10 5 11
# 2 1  1 0
# 1 0  0 0

# 1 2 3 4
# 3 2 1 0
# 3 1 0 0
# 0 0 0 0



# Leet Code Solution
class Solution:
    def increasingTriplet(self, nums: List[int]) -> bool:
        # 오직 3개의 숫자 중 1개만 찾으면 됨.
        # 4 8 10 or 1 2 10 or 1 2 5
        # 4 8 1 10
        max1 = max2 = (2 ** 31) - 1
        for num in nums:
            if num <= max1:
                max1 = num
                continue
            if num <= max2:
                max2 = num
                continue
            return True
        return False





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
        res = self.solution.increasingTriplet(nums = [1,2,3,4,5])
        self.assertEqual(res, True)

    def test_case_2(self):
        res = self.solution.increasingTriplet(nums = [5,4,3,2,1])
        self.assertEqual(res, False)

    def test_case_3(self):
        res = self.solution.increasingTriplet(nums = [2,1,5,0,4,6])
        self.assertEqual(res, True)

    def test_case_4(self):
        res = self.solution.increasingTriplet(nums = [1,1,1,1,1,1])
        self.assertEqual(res, False)

    def test_case_5(self):
        res = self.solution.increasingTriplet(nums = [20,100,10,12,5,13])
        self.assertEqual(res, True)




if __name__ == "__main__":
    # 스크립트 실행 시, 해당 부분 동작
    unittest.main(verbosity=0)
    pass
