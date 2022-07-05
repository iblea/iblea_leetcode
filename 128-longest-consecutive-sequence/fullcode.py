#!/usr/bin/python3
import unittest
from typing import List


"""
Solution Note
0 <= nums.length <= 105
-109 <= nums[i] <= 109

"""

# Leet Code Solution
class Solution:
    def longestConsecutive(self, nums: List[int]) -> int:

        # 0 또는 1 먼저 예외처리 해줌
        if len(nums) == 0:
            return 0
        elif len(nums) == 1:
            return 1

        # 넘버에 대한 딕셔너리를 만듦
        # 이 딕셔너리는 넘버의 연속된 인덱스를 확인하기 위해 만듦
        numdict = {}
        for num in nums:
            if num in numdict:
                continue
            numdict[num] = None

        # 키가 1개면 당연히 1 리턴
        # 더 계산하지 않음
        if len(numdict.keys()) == 1:
            return 1

        # longest_index 1로 초기화
        longest_index = 1
        for num in nums:
            # num + 1의 값이 존재하지 않으면 continue 진행함
            # num + 1의 값이 존재하지 않는데 연속된 인덱스 값을 찾을 이유가 없음
            if not num + 1 in numdict:
                continue

            # num + 1 이 존재하면 longest index를 찾는다.
            finding = num
            # 반복문을 진행할때마다 + 1을 해줌으로써 연속된 index의 최대 value를 찾음
            while finding + 1 in numdict:
                finding += 1

                # 텔레포트 구간이 없으면 그냥 찾아야 함..
                if numdict[finding] is None:
                    continue

                # 설정된 텔레포트 구간을 이용해 찾는 시간을 단축시킴
                finding = numdict[finding]

            # 텔레포트 구간을 만듦.
            # 이렇게 진행함으로써 만약 4, 2, 3, 1이  진행되었을 때
            # 1이 4를 찾게 되는 경우
            # numdict[2] = 4 가 되기 때문에 최대 value인 4를 바로 찾을 수 있어
            # 찾는 시간을 절약시킴
            numdict[num] = finding
            longest_index = max(longest_index, finding - num + 1)
            print(longest_index)

        return longest_index





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
        res = self.solution.longestConsecutive([100,4,200,1,3,2])
        self.assertEqual(res, 4)

    def test_case_normal_2(self):
        res = self.solution.longestConsecutive([0,3,7,2,5,8,4,6,0,1])
        self.assertEqual(res, 9)

    def test_case_normal_3(self):
        res = self.solution.longestConsecutive([100,3,200,4,2,5])
        self.assertEqual(res, 4)

    def test_case_normal_4(self):
        res = self.solution.longestConsecutive([1,3,200,4,2,5])
        self.assertEqual(res, 5)

    def test_case_normal_5(self):
        res = self.solution.longestConsecutive([-6,-1,-1,9,-8,-6,-6,4,4,-3,-8,-1])
        self.assertEqual(res, 1)

    def test_case_normal_6(self):
        res = self.solution.longestConsecutive([1, 2, 3, 4, 5])
        self.assertEqual(res, 5)






if __name__ == "__main__":
    # 스크립트 실행 시, 해당 부분 동작
    unittest.main(verbosity=0)
    pass
