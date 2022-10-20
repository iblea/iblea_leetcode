#!/usr/bin/python3
import unittest
from typing import List


"""
Solution Note

1 <= words.length <= 500
1 <= words[i].length <= 10
words[i] consists of lowercase English letters.
k is in the range [1, The number of unique words[i]]

trie를 이용하는게 좋아보이긴 한데... 시간이 없으므로 hashtable로 구현해보자
"""

from collections import Counter
# Leet Code Solution
class Solution:
    def topKFrequent(self, words: List[str], k: int) -> List[str]:
        output = []
        db = {}
        counter = Counter(words).most_common()
        # most_common이기에 첫번째 값이 가장 높은 빈도수를 가진다.
        max_val = counter[0][1]
        for word, count in counter:
            if count in db:
                db[count].append(word)
            else:
                db[count] = [word]

        for i in range(max_val, 0, -1):
            if i in db:
                db[i].sort()
                for word in db[i]:
                    output.append(word)
                    if len(output) == k:
                        return output
        return output





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
        res = self.solution.topKFrequent(["i","love","leetcode","i","love","coding"], k = 2)
        self.assertEqual(res, ["i","love"])

    def test_case_normal_2(self):
        res = self.solution.topKFrequent(["the","day","is","sunny","the","the","the","sunny","is","is"], k = 4)
        self.assertEqual(res, ["the","is","sunny","day"])




if __name__ == "__main__":
    # 스크립트 실행 시, 해당 부분 동작
    unittest.main(verbosity=0)
    pass
