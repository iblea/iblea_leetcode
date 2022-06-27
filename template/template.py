#!/usr/bin/python3
import unittest
from typing import List


"""
Solution Note

"""

# Leet Code Solution

class Solution:
    def problem(self, input_data: List[int]) -> any:
        return self.code(input_data)


    def code(self, input_data: List[int]) -> any:
        """ method description (python doxygen)

        Args:
            input_data (List[int]): input_data argument description

        Returns:
            any: If len(input_data) is 0 -> return None |
            Else -> return input_data[0]
        """
        if (len(input_data) <= 0):
            return None
        output_data = input_data[0]
        return output_data





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
        res = self.solution.problem(input_data=[1])
        self.assertEqual(res, 1)

    def test_case_normal_2(self):
        res = self.solution.problem(input_data=[2])
        self.assertEqual(res, 2)



if __name__ == "__main__":
    # 스크립트 실행 시, 해당 부분 동작
    unittest.main(verbosity=0)
    pass
