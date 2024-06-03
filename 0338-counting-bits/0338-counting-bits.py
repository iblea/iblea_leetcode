class Solution:
    def countBits(self, n: int) -> List[int]:
        if n == 0:
            return [0]

        if n == 1:
            return [0, 1]

        arr = [0, 1]
        traversal = 2


        while True:
            for i in range(traversal):
                arr.append(arr[i] + 1)
                if len(arr) > n:
                    return arr

            traversal *= 2

