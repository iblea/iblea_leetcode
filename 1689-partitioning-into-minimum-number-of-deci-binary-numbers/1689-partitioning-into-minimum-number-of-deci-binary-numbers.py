ASCII_0_CHR_VALUE = 48

class Solution:
    def minPartitions(self, n: str) -> int:
        max_value = 0
        for i in range(len(n)):
            # 48은 상수 0 ascii 코드 값
            chr_to_int = ord(n[i]) - ASCII_0_CHR_VALUE
            if max_value < chr_to_int:
                max_value = chr_to_int

        return max_value

