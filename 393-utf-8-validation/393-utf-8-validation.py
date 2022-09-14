"""
Solution Note

1 <= data.length <= 2 * 10**4
0 <= data[i] <= 255
"""

# Leet Code Solution
class Solution:
    # if list validate utf-8
    digit = [
        0b10000000,
        0b01000000,
        0b00100000,
        0b00010000,
        0b00001000,
        0b00000100,
        0b00000010,
        0b00000001,
    ]
    def validUtf8(self, data: List[int]) -> bool:
        index = 0
        while index < len(data):
            digit_result = self.check_digit(data[index])
            if digit_result < 0:
                return False

            index += 1
            if digit_result == 0:
                continue

            if index + digit_result > len(data):
                return False
        
            for i in range(digit_result):
                if data[index] & self.digit[0] != self.digit[0]:
                    return False
                if data[index] & self.digit[1] != 0:
                    return False
                index += 1

        return True
    
    # return UTF-8 Octet Sequence
    def check_digit(self, octet: int) -> int:
        if octet & self.digit[0] != self.digit[0]:
            return 0
        for i in range(2,5):
            if octet & self.digit[i] == self.digit[i]:
                continue

            # i 가 1 일 경우는 존재하지 못함
            if i == 1:
                return -1
            return i - 1
        
        return -1


