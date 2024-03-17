#!/usr/bin/python3
import unittest
from typing import List
from typing import Optional


"""
Solution Note

"""

# Leet Code Solution

class Solution:
    def nextGreatestLetter(self, letters: List[str], target: str) -> str:

        left: int  = 0
        right: int = len(letters) - 1

        # target이 문자열의 가장 큰 값보다 크면 가장 작은 값 반환 e.g letters = [xy], target = y 일때 x 바로 반환
        if letters[right] <= target:
            return letters[0]

        while left <= right:
            mid: int = (left + right) // 2 # 3.2 -> 3
            if letters[mid] == target:
                return self.duplication_index_jump(letters, target, mid)
            # 타겟이 중간값보다 더 크면 오른쪽을 검색
            if letters[mid] < target:
                left = mid + 1
            # 타겟이 중간값보다 더 작으면 왼쪽 검색
            else:
                right = mid - 1

        return letters[left]

    def duplication_index_jump(
        self, letters: List[str], target: int, index: int
    ) -> str:
        while letters[index] == target:
            index += 1
        return letters[index]




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
        res = self.solution.nextGreatestLetter(letters = ["c","f","j"], target = "a")
        self.assertEqual(res, "c")

    def test_case_2(self):
        res = self.solution.nextGreatestLetter(letters = ["c","f","j"], target = "c")
        self.assertEqual(res, "f")

    def test_case_3(self):
        res = self.solution.nextGreatestLetter(letters = ["x","x","y","y"], target = "z")
        self.assertEqual(res, "x")

    def test_case_4(self):
        res = self.solution.nextGreatestLetter(letters = ["a", "b", "c"], target = "d")
        self.assertEqual(res, "a")




if __name__ == "__main__":
    # 스크립트 실행 시, 해당 부분 동작
    unittest.main(verbosity=0)
