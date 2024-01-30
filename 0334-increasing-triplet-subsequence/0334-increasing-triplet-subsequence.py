class Solution:
    def increasingTriplet(self, nums: List[int]) -> bool:
        # 오직 3개의 숫자 중 1개만 찾으면 됨.
        # 4 8 10 or 1 2 10 or 1 2 5
        # 4 8 1 10
        max1 = max2 = (2 ** 31) - 1
        for num in nums:
            if num <= max1:
                max1 = num
                continue
            if num <= max2:
                max2 = num
                continue
            return True
        return False
