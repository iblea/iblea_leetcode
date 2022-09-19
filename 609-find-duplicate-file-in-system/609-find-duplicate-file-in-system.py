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

