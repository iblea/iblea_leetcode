#!/usr/bin/python3
import unittest
from typing import List


"""
1 <= s.length <= 10^5
s contains only lowercase English letters.

"""

# Leet Code Solution

ASCII_SMALL_A = 97
ASCII_SMALL_Z = 122

class Solution:
    def minDeletions(self, s: str) -> int:
        alphabet_dict = {}
        self.init_dictionary(alphabet_dict)
        for i in range(len(s)):
            alphabet_dict[s[i]] += 1

        self.delete_zero_value_in_dict(alphabet_dict)
        alphabet_list: List[int] = self.dict_to_list(alphabet_dict)

        value = self.find_remove_count(alphabet_list)
        return value

    def init_dictionary(self, dic: dict):
        for i in range(ASCII_SMALL_A, ASCII_SMALL_Z + 1):
            ascii_chr = chr(i)
            dic[ascii_chr] = 0

    def delete_zero_value_in_dict(self, dic:dict):
        for i in range(ASCII_SMALL_A, ASCII_SMALL_Z + 1):
            ascii_chr = chr(i)
            if dic[ascii_chr] != 0:
                continue
            del(dic[ascii_chr])

    def dict_to_list(self, dic:dict) -> List[int]:
        alphabet_list = []
        for key in dic.keys():
            alphabet_list.append(dic[key])
        alphabet_list.sort(reverse=True)
        return alphabet_list

    def find_remove_count(self, data: List[int]) -> int:
        if len(data) == 1:
            return 0

        max_value = data[0]
        del_count = 0
        print(data)
        for i in range(1, len(data)):
            # max_value가 1일 경우에는 예외처리한다.
            # max_value가 0이면 안되므로 max_value가 0일 경우 문자열에 값이 없음을 뜻함.
            # 고로 해당 문자를 모두 제거해야 한다는 의미임
            # 따라서 data[i]의 값을 모두 카운트함
            if max_value == 1:
                del_count += data[i]
                continue

            if max_value <= data[i]:
                del_count += (data[i] - max_value + 1)
                data[i] = max_value - 1
            max_value = data[i]

        return del_count






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
        res = self.solution.minDeletions("aab")
        self.assertEqual(res, 0)

    def test_case_normal_2(self):
        res = self.solution.minDeletions("aaabbbcc")
        self.assertEqual(res, 2)

    def test_case_normal_3(self):
        res = self.solution.minDeletions("ceabaacb")
        self.assertEqual(res, 2)

    def test_case_normal_4(self):
        res = self.solution.minDeletions("bbcebab")
        self.assertEqual(res, 2)

    def test_case_normal_4(self):
        res = self.solution.minDeletions("abcabc")
        self.assertEqual(res, 3)





if __name__ == "__main__":
    # 스크립트 실행 시, 해당 부분 동작
    unittest.main(verbosity=0)
    pass
