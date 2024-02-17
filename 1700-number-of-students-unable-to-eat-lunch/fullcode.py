#!/usr/bin/python3
import unittest
from typing import List
from typing import Optional


"""
Solution Note

"""

# Leet Code Solution

class Solution:
    def countStudents(self, students: List[int], sandwiches: List[int]) -> int:
        student_queue = students
        limit_count = 0

        while True:
            if len(student_queue) == 0:
                return 0

            if limit_count >= len(student_queue):
                break

            if student_queue[0] == sandwiches[0]:
                student_queue.pop(0)
                sandwiches.pop(0)
                limit_count = 0
                continue

            student_queue.append(student_queue.pop(0))
            limit_count += 1

        return len(student_queue)




# python unit test
class UnitTest(unittest.TestCase):

    # 클래스 생성 시 1회 실행
    @classmethod
    def setUpClass(self):
        self.solution = Solution()

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
        res = self.solution.countStudents(students = [1,1,0,0], sandwiches = [0,1,0,1])
        self.assertEqual(res, 0)

    def test_case_2(self):
        res = self.solution.countStudents(students = [1,1,1,0,0,1], sandwiches = [1,0,0,0,1,1])
        self.assertEqual(res, 3)




if __name__ == "__main__":
    # 스크립트 실행 시, 해당 부분 동작
    unittest.main(verbosity=0)
    pass
