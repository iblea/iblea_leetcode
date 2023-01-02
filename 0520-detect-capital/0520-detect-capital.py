# Leet Code Solution
class Solution:
    def detectCapitalUse(self, word: str) -> bool:
        # 첫 번째 글자가 대문자이면
        if word[0] == word[0].upper():
            if len(word) == 1:
                return True

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