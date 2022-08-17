#!/usr/bin/python3
import unittest
from typing import List


"""
Solution Note

1 <= words.length <= 100
1 <= words[i].length <= 12
words[i] consists of lowercase English letters.
"""

# Leet Code Solution
class Solution:

    MORSE = [".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."]
    LOWER_A = 97

    def uniqueMorseRepresentations(self, words: List[str]) -> int:
        morse_dict = {}
        for word in words:
            string = ""
            for c in word:
                string += self.get_morse_code(c)
            if string in morse_dict:
                morse_dict[string] += 1
            else:
                morse_dict[string] = 1
        return len(morse_dict)


    def get_morse_code(self, char: str) -> str:
        return self.MORSE[ord(char) - self.LOWER_A ];


    def uniqueMorseRepresentations_ver2(self, words: List[str]) -> int:
        s = set()

        for w in words:                         # Iterate through every word.
            m = ''
            for l in w:                         # Iterate through every letter in current word.
                m += self.MORSE[ord(l) - ord('a')]     # Change the letter into morse code.
            s.add(m)                            # Use set to avoid replicate answer.

        return len(s)




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
        res = self.solution.uniqueMorseRepresentations(["gin","zen","gig","msg"])
        self.assertEqual(res, 2)

    def test_case_normal_2(self):
        res = self.solution.uniqueMorseRepresentations(["a"])
        self.assertEqual(res, 1)



if __name__ == "__main__":
    # 스크립트 실행 시, 해당 부분 동작
    unittest.main(verbosity=0)
    pass
