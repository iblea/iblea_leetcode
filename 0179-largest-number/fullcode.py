#!/usr/bin/python3
import unittest
from typing import List
from typing import Optional


"""
Solution Note

"""

# Leet Code Solution

import functools

def compare(a, b):
    ab = str(a) + str(b)
    ba = str(b) + str(a)
    if (ab > ba):
        return -1
    return 1

class Solution:
    def largestNumber(self, nums: List[int]) -> str:

        for i in range(len(nums)):
            nums[i] = str(nums[i])
        nums.sort(key=functools.cmp_to_key(compare))
        if nums[0] == "0":
            return "0"

        answer = ""
        for num in nums:
            answer += str(num)
        return answer



    def largestNumber_my(self, nums: List[int]) -> str:

        result = [ str(nums[0]) ]

        result [ "34323", "3432" ]

        for i in range(1, len(nums)):
            num = "3432"
            num = str(nums[i])
            numlen = len(num)

            # [34323, 3432]
            # [343233432]
            # [343234323]
            # [343234323]
            inserted = False
            for r in result:
                r = "34323"
                if len(r) == numlen:
                    if r <= num:
                        result.insert(result.index(r), num)
                        inserted = True
                        break
                elif len(r) > numlen:
                    if r[:numlen] > num:
                        continue
                    if r[:numlen] < num:
                        result.insert(result.index(r), num)
                        inserted = True
                        break
                    # 34323
                    # 3432
                    # 3432
                    last_n = num[numlen-1]
                    for j in range(numlen, len(r)):
                        if last_n > r[j]:
                            result.insert(result.index(r), num)
                            inserted = True
                            break
                        if last_n < r[j]:
                            break
                    if inserted == True:
                        break
                else:
                    if r > num[:len(r)]:
                        continue
                    if r < num[:len(r)]:
                        result.insert(result.index(r), num)
                        inserted = True
                        break
                    last_r = r[len(r)-1]
                    for j in range(len(r), numlen):
                        if last_r < num[j]:
                            result.insert(result.index(r), num)
                            inserted = True
                            break
                        if last_r > num[j]:
                            break
                    if inserted == True:
                        break

            if inserted == False:
                result.append(str(num))

        return "".join(result)




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
        res = self.solution.largestNumber([10, 2])
        self.assertEqual(res, "210")
    def test_case_2(self):
        res = self.solution.largestNumber([3,30,34,5,9])
        self.assertEqual(res, "9534330")



if __name__ == "__main__":
    # 스크립트 실행 시, 해당 부분 동작
    unittest.main(verbosity=0)
