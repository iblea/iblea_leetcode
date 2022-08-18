"""
Solution Note

2 <= arr.length <= 10**5
arr.length is even.
1 <= arr[i] <= 10**5
"""

# Leet Code Solution
class Solution:
    def minSetSize(self, arr: List[int]) -> int:
        total_len = len(arr)
        limit_len = total_len // 2

        del_count = 0
        del_number = 0
        counter = Counter(arr).most_common()

        for count in counter:
            del_count += count[1]
            del_number += 1
            if del_count >= limit_len:
                return  del_number
        return 0

