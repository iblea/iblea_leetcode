#!/usr/bin/python3
import unittest
from typing import List
from typing import Optional


"""
Solution Note
https://leetcode.com/problems/super-ugly-number/

313. Super Ugly Number

A super ugly number is a positive integer whose prime factors are in the array primes.
Given an integer n and an array of integers primes, return the nth super ugly number.
The nth super ugly number is guaranteed to fit in a 32-bit signed integer.

슈퍼 어글리 숫자는 소인수가 배열 primes에 있는 양의 정수입니다.
정수 n과 정수 배열 primes가 주어졌을 때, n번째 슈퍼 어글리 숫자를 반환하세요.
n번째 슈퍼 어글리 숫자는 32비트 부호 있는 정수에 맞는 것이 보장됩니다.

Constraints:

1 <= n <= 10**5
1 <= primes.length <= 100
2 <= primes[i] <= 1000
- primes[i] is guaranteed to be a prime number.
- All the values of primes are unique and sorted in ascending order.
"""

# Leet Code Solution

import heapq
class Solution:
    def nthSuperUglyNumber_wrong_answer(self, n: int, primes: List[int]) -> int:
        dp = [ 1 ]
        multiples_arr = [primes[i] for i in range(len(primes))]

        while len(dp) < n:

            # get min idx and val
            min_idx, min_val = min(enumerate(multiples_arr), key=lambda x: x[1])
            dp.append(min_val)
            multiples_arr[min_idx] = min_val * primes[min_idx]

        return dp[-1]


    def nthSuperUglyNumber(self, n: int, primes: List[int]) -> int:
        # https://leetcode.com/problems/super-ugly-number/solutions/868948/python3-l-faster-than-99-35-using-heapq/?envType=problem-list-v2&envId=dynamic-programming
        nums = primes.copy() # do a deep copy
        heapq.heapify(nums) #create a heap
        p = 1
        for _ in range(n - 1):
            p = heapq.heappop(nums) #take the smallest element
            for prime in primes:
                heapq.heappush(nums, p * prime) #add all those multiples with the smallest number
                if p % prime == 0:
                    break
        return p

    def nthSuperUglyNumber1(self, n: int, primes: List[int]) -> int:
        # create a list to store the super ugly numbers, initialize with 1
        super_ugly = [1]
        # create a list to store the indices for each prime number
        idx = [0] * len(primes)
        # create a list to store the product of prime numbers with their corresponding indices
        # this will be used to find the next super ugly number
        prod = [p for p in primes]

        # loop until we find the nth super ugly number
        while len(super_ugly) < n:
            # find the minimum value in prod, which will be the next super ugly number
            next_ugly = min(prod)
            # append it to the list of super ugly numbers
            super_ugly.append(next_ugly)

            # update the index for each prime number whose product is equal to next_ugly
            for i in range(len(primes)):
                if next_ugly == prod[i]:
                    idx[i] += 1
                    prod[i] = primes[i] * super_ugly[idx[i]]

        # return the last element in the list of super ugly numbers, which is the nth super ugly number
        return super_ugly[-1]




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
        res = self.solution.nthSuperUglyNumber(n = 12, primes = [2,7,13,19])
        self.assertEqual(res, 32)
        """
        Explanation: [1,2,4,7,8,13,14,16,19,26,28,32] is the sequence of the first 12 super ugly numbers given primes = [2,7,13,19].
        """

    def test_case_2(self):
        res = self.solution.nthSuperUglyNumber(n = 1, primes = [2,3,5])
        self.assertEqual(res, 1)
        """
        Explanation: 1 has no prime factors, therefore all of its prime factors are in the array primes = [2,3,5].
        """



if __name__ == "__main__":
    # 스크립트 실행 시, 해당 부분 동작
    unittest.main(verbosity=0)
