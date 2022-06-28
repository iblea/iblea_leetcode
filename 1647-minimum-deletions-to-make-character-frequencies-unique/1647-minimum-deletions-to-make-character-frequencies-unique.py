"""
1 <= s.length <= 10^5
s contains only lowercase English letters.

"""

# Leet Code Solution

ASCII_SMALL_A = 97
ASCII_SMALL_Z = 122

class Solution:
    def minDeletions(self, s: str) -> int:
        alphabet_dict = {}
        self.init_dictionary(alphabet_dict)
        for i in range(len(s)):
            alphabet_dict[s[i]] += 1

        alphabet_list: List[int] = self.delete_zero_value_in_dict(alphabet_dict)

        value = self.find_remove_count(alphabet_list)
        return value

    def init_dictionary(self, dic: dict):
        for i in range(ASCII_SMALL_A, ASCII_SMALL_Z + 1):
            ascii_chr = chr(i)
            dic[ascii_chr] = 0

    def delete_zero_value_in_dict(self, dic:dict) -> List[int]:
        alphabet_list = []
        for i in range(ASCII_SMALL_A, ASCII_SMALL_Z + 1):
            ascii_chr = chr(i)
            if dic[ascii_chr] == 0:
                continue
            alphabet_list.append(dic[ascii_chr])

        alphabet_list.sort(reverse=True)
        return alphabet_list

    def find_remove_count(self, data: List[int]) -> int:
        if len(data) == 1:
            return 0

        max_value = data[0]
        del_count = 0
        print(data)
        for i in range(1, len(data)):
            # max_value가 1일 경우에는 예외처리한다.
            # max_value가 0이면 안되므로 max_value가 0일 경우 문자열에 값이 없음을 뜻함.
            if max_value == 1:
                del_count += data[i]
                continue

            if max_value <= data[i]:
                del_count += (data[i] - max_value + 1)
                data[i] = max_value - 1
            max_value = data[i]

        return del_count

