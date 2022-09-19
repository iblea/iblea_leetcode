#!/usr/bin/python3
import unittest
from typing import List
from collections import defaultdict

"""
Solution Note

1 <= paths.length <= 2 * 10**4
1 <= paths[i].length <= 3000
1 <= sum(paths[i].length) <= 5 * 10**5
paths[i] consist of English letters, digits, '/', '.', '(', ')', and ' '.
You may assume no files or directories share the same name in the same directory.
You may assume each given directory info represents a unique directory. A single blank space separates the directory path and file info.
"""

# Leet Code Solution
class Solution:
    def findDuplicate(self, paths: List[str]) -> List[List[str]]:
        storage = defaultdict(list)
        for p in paths:
            # 1. split the string by ' '
            path = p.split()
            # split_to - path, filename(content)
            directoryPath, rest = path[0], path[1:]
            for f in rest:
                spt = f.split('(')
                fileName, fileContent = spt[0], spt[1][:-1]
                storage[fileContent].append("{}/{}".format(directoryPath, fileName))

        return [storage[i] for i in storage.keys() if len(storage[i]) > 1]



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
        res = self.solution.findDuplicate(["root/a 1.txt(abcd) 2.txt(efgh)","root/c 3.txt(abcd)","root/c/d 4.txt(efgh)","root 4.txt(efgh)"])
        self.assertEqual(res, [["root/a/1.txt","root/c/3.txt"],["root/a/2.txt","root/c/d/4.txt","root/4.txt"]])

    def test_case_normal_2(self):
        res = self.solution.findDuplicate(["root/a 1.txt(abcd) 2.txt(efgh)","root/c 3.txt(abcd)","root/c/d 4.txt(efgh)"])
        self.assertEqual(res, [["root/a/1.txt","root/c/3.txt"],["root/a/2.txt","root/c/d/4.txt"]])



if __name__ == "__main__":
    # 스크립트 실행 시, 해당 부분 동작
    unittest.main(verbosity=0)
    pass
