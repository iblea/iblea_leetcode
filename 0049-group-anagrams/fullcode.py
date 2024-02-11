#!/usr/bin/python3
import unittest
from typing import List


"""
Solution Note

Given an array of strings strs, group the anagrams together. You can return the answer in any order.

An Anagram is a word or phrase formed by rearranging the letters of a different word or phrase, typically using all the original letters exactly once.
"""

# Leet Code Solution

class Solution:
    def groupAnagrams(self, strs: List[str]) -> List[List[str]]:

        anagrams = {}
        for string in strs:
            anagrams_key = ''.join(sorted(string))
            if anagrams_key in anagrams:
                anagrams[anagrams_key].append(string)
            else:
                anagrams[anagrams_key] = [string]

        return list(anagrams.values())





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

    def test_case_1(self):
        res = self.solution.groupAnagrams(strs = ["eat","tea","tan","ate","nat","bat"])
        self.assertEqual(res, [["bat"],["nat","tan"],["ate","eat","tea"]])

    def test_case_2(self):
        res = self.solution.groupAnagrams(strs = [""])
        self.assertEqual(res, [[""]])

    def test_case_3(self):
        res = self.solution.groupAnagrams(strs = ["a"])
        self.assertEqual(res, [["a"]])




if __name__ == "__main__":
    # 스크립트 실행 시, 해당 부분 동작
    unittest.main(verbosity=0)
    pass
