#!/usr/local/bin/pytest

#!/usr/bin/python3
import pytest
from typing import List


"""
Solution Note

2 <= s.length <= 1000
s.length is even.
s consists of uppercase and lowercase letters.
"""

# Leet Code Solution
class Solution:
    vowel = ('a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U')
    def halvesAreAlike(self, s: str) -> bool:
        slen = len(s) // 2

        stra = s[:slen]
        strb = s[slen:]
        avol = 0
        bvol = 0
        for ch in stra:
            if ch in self.vowel:
                avol += 1
        for ch in strb:
            if ch in self.vowel:
                bvol += 1

        return avol == bvol

    lowercase_vowel = ('a', 'e', 'i', 'o', 'u')
    def halvesAreAlike_lowercase(self, s: str) -> bool:
        slen = len(s) // 2

        stra = s[:slen].lower()
        strb = s[slen:].lower()
        avol = 0
        bvol = 0
        for ch in stra:
            if ch in self.lowercase_vowel:
                avol += 1
        for ch in strb:
            if ch in self.lowercase_vowel:
                bvol += 1

        return avol == bvol

    def halvesAreAlike_counter(self, s: str) -> bool:
        slen = len(s) // 2
        stra = s[:slen].lower()
        strb = s[slen:].lower()

        from collections import Counter
        countera = Counter(stra)
        counterb = Counter(strb)
        avol = countera['a'] + countera['e'] + countera['i'] + countera['o'] + countera['u']
        bvol = counterb['a'] + counterb['e'] + counterb['i'] + counterb['o'] + counterb['u']

        """
        avol = 0
        bvol = 0
        for ch in self.lowercase_vowel:
            avol += countera[ch]
            bvol += counterb[ch]
        """

        return avol == bvol







@pytest.mark.parametrize(
    'expect, args',
    [
        [True, [ "book" ]],
        [False, [ "textbook" ]]
    ])
def test_case_normal1(expect, args):
    solution = Solution();
    print(args)
    assert expect == solution.halvesAreAlike(args[0])

@pytest.mark.parametrize(
    'expect, args',
    [
        [True, [ "book" ]],
        [False, [ "textbook" ]]
    ])
def test_case_lowercase(expect, args):
    solution = Solution();
    print(args)
    assert expect == solution.halvesAreAlike_lowercase(args[0])

@pytest.mark.parametrize(
    'expect, args',
    [
        [True, [ "book" ]],
        [False, [ "textbook" ]]
    ])
def test_case_counter(expect, args):
    solution = Solution();
    print(args)
    assert expect == solution.halvesAreAlike_lowercase(args[0])
