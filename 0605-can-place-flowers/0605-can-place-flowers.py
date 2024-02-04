class Solution:
    def canPlaceFlowers(self, flowerbed: List[int], n: int) -> bool:

        last = len(flowerbed) - 1

        if n == 0:
            return True

        if len(flowerbed) == 1:
            if flowerbed[0] == 0:
                return True
            else:
                return False

        for i in range(len(flowerbed)):
            if i == 0:
                if flowerbed[i] == 0 and flowerbed[i+1] == 0:
                    flowerbed[i] = 1
                    n -= 1
            elif i == last:
                if flowerbed[i] == 0 and flowerbed[i-1] == 0:
                    flowerbed[i] = 1
                    n -= 1
            else:
                if flowerbed[i] == 0 and flowerbed[i-1] == 0 and flowerbed[i+1] == 0:
                    flowerbed[i] = 1
                    n -= 1
            if n == 0:
                return True
        return False

