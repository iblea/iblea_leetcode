class Solution:
    def canArrange(self, arr: List[int], k: int) -> bool:

        if k == 1:
            return True

        match_num = {}
        matched = 0
        true_val = len(arr) // 2

        for num in arr:
            found = False
            realnum = num % k
            if realnum == 0:
                realnum = k

            match= k - realnum
            if match == 0:
                match = k

            if match in match_num and match_num[match] > 0:
                matched += 1
                match_num[match] -= 1
            else:
                if realnum in match_num:
                    match_num[realnum] += 1
                else:
                    match_num[realnum] = 1

        if matched == true_val:
            return True
        return False
