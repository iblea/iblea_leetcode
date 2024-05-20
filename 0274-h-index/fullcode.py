#!/usr/bin/python3
import unittest
from typing import List
from typing import Optional


"""
Solution Note

H-Index는 과학자의 생산성과 영향력을 나타내는 지표입니다.
어느 과학자의 H-Index를 나타내는 값인 h를 구하려고 합니다.
위키백과1에 따르면, H-Index는 다음과 같이 구합니다.

어떤 과학자가 발표한 논문 n편 중,
h번 이상 인용된 논문이 h편 이상이고
나머지 논문이 h번 이하 인용되었다면
h의 최댓값이 이 과학자의 H-Index입니다.

어떤 과학자가 발표한 논문의 인용 횟수를 담은 배열 citations가 매개변수로 주어질 때,
이 과학자의 H-Index를 return 하도록 solution 함수를 작성해주세요.

[3, 0, 6, 1, 5] -> 3
설명 ) 이 과학자가 발표한 논문의 수는 5편이고, 그중 3편의 논문은 3회 이상 인용되었습니다.
그리고 나머지 2편의 논문은 3회 이하 인용되었기 때문에 이 과학자의 H-Index는 3입니다.


[0,0,0,0,0] = 0
[1,1,1,1,1] = 1
[5,5,5,1,2] = 3
[5,5,5,0,3] = 3
[5,5,5,0,4] = 4
[5,5,5,2,3] = 3
[5,5,5,5,3] = 4
[5,5,5,5,4] = 4
[5,5,5,5,5] = 5
[5,5,5,5,6] = 5
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
