#!/usr/bin/python3
import unittest
from typing import List
from typing import Optional


"""
Solution Note

"""

# Leet Code Solution
class Solution:

    def function(self, l):

        # 변경할 인덱스
        i = 0
        changed_index = -1

        cnt = 0
        # 변경 여부 상태 플래그 (코딩테스트, 알고리즘 문제 풀 때 플래그변수 쓰는거 별로 좋은 선택이 아님.)
        # 야메긴 한데...
        # 플래그변수를 쓰지말라고 하는게
        # 경우의 수가 x2배로 늘어나요.
        changed = False

        while i < len(l):
            stri = l[i]
            for cnt in range(i+1, len(l)):

                if l[cnt] <= stri:
                    continue

                changed = True
                if changed_index < 0 or l[changed_index] <= l[cnt]:
                    changed_index = cnt

            # 변경할 인덱스를 찾았을 경우 반복문을 탈출한다.
            if changed:
                break

            i += 1

        if changed_index >= 0:
            l[i], l[changed_index] = l[changed_index], l[i]

        return l


    def maximumSwap(self, num: int) -> int:
        s = list(str(num))

        s = self.function(s)

        return int("".join(s))




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
        res = self.solution.maximumSwap(2736)
        self.assertEqual(res, 7236)

    def test_case_2(self):
        res = self.solution.maximumSwap(9973)
        self.assertEqual(res, 9973)

    def test_case_3(self):
        res = self.solution.maximumSwap(1991)
        self.assertEqual(res, 9911)

    def test_case_4(self):
        res = self.solution.maximumSwap(99718)
        self.assertEqual(res, 99817)

    def test_case_5(self):
        res = self.solution.maximumSwap(1993)
        self.assertEqual(res, 9913)

    def test_case_6(self):
        res = self.solution.maximumSwap(2736)
        self.assertEqual(res, 7236)





if __name__ == "__main__":
    # 스크립트 실행 시, 해당 부분 동작
    unittest.main(verbosity=0)
