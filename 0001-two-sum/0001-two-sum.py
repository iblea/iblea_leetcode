# Leet Code Solution
class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        # hash table 생성
        data = {}
        for i in range(len(nums)):
            # nums[i]가 data에 존재할 경우, data[nums[i]]에 i를 추가 -> [0, 1]
            if nums[i] in data:
                data[nums[i]].append(i)
                continue
            data[nums[i]] = [i]
        # data의 key의 값들을 순회하면서 target - key의 값이 data에 존재하는지 확인
        for key in data.keys():
            remain_key = target - key
            if not (remain_key in data):
                continue
            if key == remain_key:
                if len(data[key]) >= 2:
                    return [ data[key][0], data[key][1] ]
                continue
            return [data[key][0], data[remain_key][0]]