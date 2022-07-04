
class Solution:
    def candy(self, ratings: List[int]) -> int:

        candy_list = [1] * len(ratings)

        # 오름차순 candy list 획득
        for i in range(1, len(ratings)):
            if ratings[i] > ratings[i-1] and candy_list[i] <= candy_list[i-1]:
                candy_list[i] = candy_list[i-1] + 1

        # 내림차순 candy list 획득
        for i in range(len(ratings) - 1, 0, -1):
            if ratings[i-1] > ratings[i] and candy_list[i-1] <= candy_list[i]:
                candy_list[i-1] = candy_list[i] + 1
        
        return sum(candy_list)

