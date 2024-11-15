#!/usr/bin/python3
import unittest
from typing import List
from typing import Optional


"""
Solution Note

[10,11,12,1,2,20,3,4,5]
이 배열에서 최소한의 갯수의 요소를 제거해서 배열의 값이 비감소하는 배열을 만드는 파이썬 solution 함수를 만들어라.

예시 1은 다음과 같다.
input = [10,11,12,1,2,3,20,4,5]
output = 3
explanation: 최종 결과물은 [1,2,3,4,5] 이다. 따라서 3개의 요소 (10,11,12)를 제거해야 하므로 답은 3이다.

예시 2
input = [5,4,3,2,1,3]
output = 4
explanation: 최종 결과물은 [1,3] 또는 [2,3], [3,3] 이다. 따라서 4개의 요소를 제거해야 하므로 답은 4이다.

예시 3
input = [1,2,3,4,4,5]
output = 0
explanation: 이미 비감소하는 배열이므로 0개의 요소를 제거해야 한다.
"""

# Leet Code Solution

class Solution:
    def problem(self, numbers: List[int]) -> int:

        length = 0
        dp = [[float('inf')]]
        for i in range(len(numbers)):
            number = numbers[i]

            # number이 지금 만들어가진 가장 큰 숫자의 조합보다 크면, 뒤에 숫자를 더 붙인다.
            if dp[-1][-1] <= number:
                dp.append(dp[-1] + [number])
                continue

            # 그게 아니라면 기존에 만들어 둔 조합에서 최적의 조합을 재구성하기 위해 기존 조합을 수정한다.
            # 만들어둔 기존 조합보다 더 작은 수로 조합을 만들 수 있으면 수정하는 로직
            for j in range(len(dp)-2, -1, -1):
                if dp[j][-1] > number:
                    dp[j+1] = dp[j] + [number]
                    break
            if dp[0][0] > number:
                dp[0][0] = number

        return len(numbers) - len(dp[-1])




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
        res = self.solution.problem([10,11,12,1,2,3,20,4,5])
        self.assertEqual(res, 3)

    def test_case_2(self):
        res = self.solution.problem([5,4,3,2,1,3])
        self.assertEqual(res, 4)

    def test_case_3(self):
        res = self.solution.problem([1,2,3,4,4,5])
        self.assertEqual(res, 0)

    def test_case_4(self):
        res = self.solution.problem([5,4,3,2,1])
        self.assertEqual(res, 4)


if __name__ == "__main__":
    # 스크립트 실행 시, 해당 부분 동작
    unittest.main(verbosity=0)
