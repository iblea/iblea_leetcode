#!/usr/local/bin/pytest

#!/usr/bin/python3
import pytest
from typing import List


"""
Solution Note

1 <= word.length <= 100
word consists of lowercase and uppercase English letters.
"""

# Leet Code Solution
class Solution:
    def detectCapitalUse(self, word: str) -> bool:
        # word length가 1이면 무조건 True다
        if len(word) == 1:
            return True

        # 첫 번째 글자가 대문자이면
        if word[0] == word[0].upper():
            # 두 번쨰 글자가 대문자인지 체크하고 대문자의 경우 뒷 글자 모두 대문자여야 함
            if word[1] == word[1].upper():
                return self.check_uppercase(word[2:])

            # 두 번째 글자가 소문자인 경우 뒷 글자 모두 소문자여야 함
            return self.check_lowercase(word[2:])
        # 첫 번째 글자가 소문자이면 뒷 글자는 모두 소문자여야 함
        else:
            return self.check_lowercase(word[1:])

    def check_uppercase(self, word: str) -> bool:
        for w in word:
            if w != w.upper():
                return False
        return True
        # if word == word.upper():
        #     return True
        # return False

    def check_lowercase(self, word: str) -> bool:
        for w in word:
            if w != w.lower():
                return False
        return True
        # if word == word.lower():
        #     return True
        # return False








@pytest.mark.parametrize(
    'expect, args',
    [
        [ True, [ "USA" ] ],
        [ False, [ "FlaG" ] ],
        [ True, [ "G" ] ],
        [ True, [ "g" ] ],
    ])
def test_case_normal(expect, args):
    solution = Solution();
    assert expect == solution.detectCapitalUse(args[0])

# pytest fullcode.py
