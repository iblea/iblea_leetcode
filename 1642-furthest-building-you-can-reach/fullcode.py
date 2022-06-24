#!/usr/bin/python3
import unittest
from typing import List

"""
작은것은 벽돌로
큰것은 사다리로
"""
from queue import PriorityQueue

def set_queue_recursive(queue, data: int):
    queue.put(data * -1)

def get_queue_recursive(queue) -> any:
    if queue.empty():
        return None
    return (queue.get() * -1)

class Solution:
    def furthestBuilding(self, heights: List[int], bricks: int, ladders: int) -> int:
        len_heights = len(heights)

        # 배열 길이가 1이면..
        if len_heights is 1:
            return 0

        # 벽돌 카운트
        total_use_brick = 0
        cur = heights[0]

        # 우선순위 큐
        que = PriorityQueue()
        for i in range(1, len_heights):
            if heights[i] <= cur:
                cur = heights[i]
                continue

            diff = heights[i] - cur
            cur = heights[i]
            total_use_brick += diff

            # 내장 PriorityQueue는 오름차순으로 정렬하므로
            # 내림차순으로 정렬하기 위해 -1을 해 줌
            set_queue_recursive(que, diff)
            # 사다리를 이용
            if total_use_brick > bricks:
                # 사다리가 없으면 현재 index의 -1을 리턴
                if ladders <= 0:
                    return i - 1

                # 본 조건문에 걸릴 경우 que는 무조건 존재한다는 가정
                ladders -= 1
                total_use_brick -= get_queue_recursive(que)

        return len_heights - 1


class UnitTest(unittest.TestCase):

    # 클래스 생성 시 1회
    @classmethod
    def setUpClass(self):
        self.solution = Solution();

    # 클래스 소멸 시 1회
    @classmethod
    def tearDownClass(self):
        pass

    # 테스트 케이스 전 실행
    def setUp(self):
        pass

    # 테스트 케이스 후 실행
    def tearDown(self):
        pass


    def test_one_length(self):
        res = self.solution.furthestBuilding(heights = [4], bricks= 3, ladders= 1)
        self.assertEqual(res, 0)

    def test_case1(self):
        res = self.solution.furthestBuilding(heights = [4,2,7,6,9,14,12], bricks = 5, ladders = 1)
        self.assertEqual(res, 4)

    def test_no_further(self):
        res = self.solution.furthestBuilding([4, 9, 3, 5], 3, 0)
        self.assertEqual(res, 0)

    def test_case3(self):
        res = self.solution.furthestBuilding(heights = [14,3,19,3], bricks = 17, ladders = 0)
        self.assertEqual(res, 3)

    def test_case4(self):
        res = self.solution.furthestBuilding(heights = [4,12,2,7,3,18,20,3,19], bricks = 10, ladders = 2)
        self.assertEqual(res, 7)

    def ttest_case5(self):
        res = self.solution.furthestBuilding(heights = [4,12,2,7,3,18,20,23,3,19], bricks = 18, ladders= 1)
        self.assertEqual(res, 8)



if __name__ == "__main__":
    unittest.main()
