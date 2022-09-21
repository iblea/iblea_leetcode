#!/usr/bin/python3
import unittest
from typing import List


"""
Solution Note

1 <= nums.length <= 10**4
-10**4 <= nums[i] <= 10**4
1 <= queries.length <= 10**4
-10**4 <= vali <= 10**4
0 <= indexi < nums.length
"""

# Leet Code Solution
class Solution:
    def sumEvenAfterQueries(self, nums: List[int], queries: List[List[int]]) -> List[int]:
        sum = 0

        # 짝수만 더한다.
        for num in nums:
            if num % 2 != 0:
                continue
            sum += num

        result = []
        for query in queries:
            val = query[0]
            index = query[1]

            # if 기존에 짝수였다면
            if nums[index] % 2 == 0:
                # 기존 짝수를 빼고
                sum -= nums[index]

            # 새로 더한 수가 짝수이면 더하고 아니면 더하지 않는다.
            nums[index] = nums[index] + val
            if nums[index] % 2 == 0:
                sum += nums[index]
            result.append(sum)

        return result





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
        res = self.solution.sumEvenAfterQueries(nums = [1,2,3,4], queries = [[1,0],[-3,1],[-4,0],[2,3]])
        self.assertEqual(res, [8,6,2,4])

    def test_case_normal_2(self):
        res = self.solution.sumEvenAfterQueries(nums = [1], queries = [[4,0]])
        self.assertEqual(res, [0])



if __name__ == "__main__":
    # 스크립트 실행 시, 해당 부분 동작
    unittest.main(verbosity=0)
    pass
