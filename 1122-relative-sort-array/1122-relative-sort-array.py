class Solution:
    def relativeSortArray(self, arr1: List[int], arr2: List[int]) -> List[int]:
        dic = {}
        for num in arr1:
            if num in dic:
                dic[num] += 1
            else:
                dic[num] = 1

        res = []
        for num in arr2:
            res += [num] * dic[num]
            dic.pop(num)

        keys = sorted(dic.keys())
        for key in keys:
            res += [key] * dic[key]
        return res