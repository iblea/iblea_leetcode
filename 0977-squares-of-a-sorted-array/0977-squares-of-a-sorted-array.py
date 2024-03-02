import collections
class Solution:
    def sortedSquares(self, nums: List[int]) -> List[int]:
        li = nums
        l = 0
        r = len(li)-1
        result = collections.deque([])
        
        while l <= r:
            if li[l] ** 2 < li[r] ** 2:
                result.appendleft(li[r] ** 2)
                r-=1
            else:
                result.appendleft(li[l] ** 2)
                l+=1
        return list(result)
