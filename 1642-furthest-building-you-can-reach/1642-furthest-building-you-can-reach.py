
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

