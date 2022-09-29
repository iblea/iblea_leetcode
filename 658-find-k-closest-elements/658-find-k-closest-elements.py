# Leet Code Solution
class Solution:
    def findClosestElements(self, arr: List[int], k: int, x: int) -> List[int]:
        # l = low
        l = 0
        # h = high
        h = len(arr) - k
        # high = len(arr)(5) - k(3) = 2
        # [1,2,3,4,5] k=3, x=3
        while l < h:
            mid = l + (h - l) // 2

            # l=0, h=2, mid=1
            # x(3) - arr[2](3) > arr[1+3](5) - x(3)
            # 0 > 2 (False) h=1
            # l=0, h=1, mid=0
            # x(3) - arr[0](1) > arr[0+3](4) - x(3)
            # 2 > 1 (True) l=1
            # l=1, h=1, mid=0 (False)
            if x - arr[mid] > arr[mid + k] - x:
                l = mid + 1
            else:
                h = mid

        # arr[1:1+3] = arr[1:4] = [2,3,4]
        return arr[l:l+k]