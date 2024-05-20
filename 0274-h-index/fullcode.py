#!/usr/bin/python3
import unittest
from typing import List
from typing import Optional


"""
Solution Note

[0,0,0,0,0] = 0
[1,1,1,1,1] = 1
[5,5,5,1,2] = 3
[5,5,5,0,3] = 3
[5,5,5,0,4] = 4
[5,5,5,2,3] = 3
[5,5,5,5,3] = 4
[5,5,5,5,4] = 4
[5,5,5,5,6] = 5
[5,5,5,5,5] = 5
[15,15,15,10,50] = 5

"""

# Leet Code Solution

class Solution:
    def hIndex(self, citations: List[int]) -> int:
        citations_len: int = len(citations)
        quotation_count: list = [ 0 for _ in range (citations_len + 1)]
        for citation in citations:
            if (citation >= citations_len):
                quotation_count[citations_len] += 1
            else:
                quotation_count[citation] += 1

        cnt: int = 0
        for i in range(citations_len, -1, -1):
            cnt += quotation_count[i]
            if cnt >= i:
                return i
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
        self.solution = Solution()

    # 테스트 케이스 후 실행
    def tearDown(self):
        pass

    def test_case_1(self):
        res = self.solution.problem(1)
        self.assertEqual(res, 1)



if __name__ == "__main__":
    # 스크립트 실행 시, 해당 부분 동작
    unittest.main(verbosity=0)
