#!/usr/bin/python3
from queue import PriorityQueue
from typing import List


def partition(arr,l,h):
    i = ( l - 1 )
    x = arr[h]
    for j in range(l , h):
        if   arr[j] <= x:
            # increment index of smaller element
            i = i+1
            arr[i],arr[j] = arr[j],arr[i]
    arr[i+1],arr[h] = arr[h],arr[i+1]
    return (i+1)

# Function to do Quick sort
# arr[] --> Array to be sorted,
# l  --> Starting index,
# h  --> Ending index
def quick_sort(arr,l,h):
    # Create an auxiliary stack
    size = h - l + 1
    stack = [0] * (size)
    # initialize top of stack
    top = -1
    # push initial values of l and h to stack
    top = top + 1
    stack[top] = l
    top = top + 1
    stack[top] = h
    # Keep popping from stack while is not empty
    while top >= 0:
        # Pop h and l
        h = stack[top]
        top = top - 1
        l = stack[top]
        top = top - 1
        # Set pivot element at its correct position in
        # sorted array
        p = partition( arr, l, h )
        # If there are elements on left side of pivot,
        # then push left side to stack
        if p-1 > l:
            top = top + 1
            stack[top] = l
            top = top + 1
            stack[top] = p - 1
        # If there are elements on right side of pivot,
        # then push right side to stack
        if p+1 < h:
            top = top + 1
            stack[top] = p + 1
            top = top + 1
            stack[top] = h


class Solution:
    def isPossible(self, target: List[int]) -> bool:

        # quick sort
        quick_sort(target, 0, len(target) - 1)
        print(target)

        # initialize setting
        que = PriorityQueue()
        self.queue_init(que, len(target))
        print(que.qsize())

        # data[0] = tmp_sum
        # data[1] = que_sum
        data = [len(target) -1, len(target)]

        self.loop(que, data)
        self.loop(que, data)
        self.loop(que, data)
        self.loop(que, data)
        self.loop(que, data)
        self.loop(que, data)
        self.loop(que, data)
        self.loop(que, data)
        self.loop(que, data)
        self.loop(que, data)

        return False

    def queue_init(self, queue: PriorityQueue, loop_count: int):
        for i in range(loop_count):
            queue.put(1)

    def loop(self, que, data):
        que.get()
        tmp_index = que.queue[0]
        que.put(data[1])
        data[1] += data[0]
        data[0] = data[1] - tmp_index
        print(que.queue)
        print("tmp : {0}, sum : {1}".format(data[0], data[1]))




solution = Solution()
solution.isPossible([9, 3, 5])




