class Solution:
    def kidsWithCandies(self, candies: List[int], extraCandies: int) -> List[bool]:
        max_candies: int = max(candies)
        answer: List[bool] = [ ]
        for candy in candies:
            if candy + extraCandies >= max_candies:
                answer.append(True)
            else:
                answer.append(False)

        return answer