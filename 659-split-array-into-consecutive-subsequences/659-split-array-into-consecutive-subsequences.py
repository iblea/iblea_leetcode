# Leet Code Solution
class Solution:
    # retry - 나중에 다시 풀어볼 것
    def isPossible(self, nums: List[int]) -> bool:
        # https://leetcode.com/problems/split-array-into-consecutive-subsequences/discuss/2447044/Python-and-C%2B%2BEasiest-approach-Explainedor-Dictionary-and-Map-or-Easy-understand-_

        # print(nums)

        seq = defaultdict(int)      # key: ending number, val: how many seqs
        left = Counter(nums)        # key: number, val: how many of key are left unchecked
        
        for num in nums:
            if (not left[num]): continue   # the number is already in seqs, we don't need to check again
            # print(seq)
            # print(left)
            
            if (seq[num-1] > 0):    # If there is sequence before the number, we add the number to the seq
                seq[num-1] -= 1 
                seq[num] += 1
                left[num] -= 1
                
            else:   # If not we create a new seq using the number
                if (not left[num+1] or not left[num+2]):  #  If there aren't two numbers behind to let us create new seq, return False
                    # print("")
                    # print("")
                    return False
                left[num] -= 1
                left[num+1] -= 1
                left[num+2] -= 1
                seq[num+2] += 1

        # print(seq)
        # print(left)

        # print("")
        # print("")
        return True


    def isPossible1(self, nums: List[int]) -> bool:
        start = 0
        end = -1
        for i in range(len(nums) - 1):
            if (nums[i] == nums[i + 1]) or ((nums[i] + 1) == nums[i + 1]):
                continue
            end = i + 1
            c_len = end - start
            # c_len < 3 -> False
            if c_len < 3:
                return False

            # function
            res = self.possible(nums[start:end + 1])
            if res == False:
                return False
            start = end

        end = len(nums) - 1;
        c_len = end - start + 1
        if c_len < 3:
            return False

        return self.possible(nums[start:end + 1])


    def possible(self, lst):
        counter = Counter(lst).most_common()
        count = -1
        num_count = 0
        for i in range(len(counter)):
            if num_count == 0:
                count = counter[i][1]
                num_count += 1
                continue

            if not count == counter[i][1]:
                if num_count >= 3:
                    num_count = 0
                    count = -1
                    continue
                return False

            num_count += 1

        return True

