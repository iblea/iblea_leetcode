# Leet Code Solution
class NumArray:

    nums = []
    sum_value = 0
    nums_len  = 0
    
    def __init__(self, nums: List[int]):
        self.nums = nums
        self.sum_value = sum(nums)
        self.nums_len = len(nums)

    def update(self, index: int, val: int) -> None:
        self.sum_value -= self.nums[index]
        self.nums[index] = val
        self.sum_value += self.nums[index]

    def sumRange(self, left: int, right: int) -> int:
        if right - left > self.nums_len // 2:
            answer = sum(self.nums[:left]) + sum(self.nums[right + 1:])
            return self.sum_value - answer
        else:
            return sum(self.nums[left: right + 1])


# Your NumArray object will be instantiated and called as such:
# obj = NumArray(nums)
# obj.update(index,val)
# param_2 = obj.sumRange(left,right)


