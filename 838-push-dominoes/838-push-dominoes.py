# Leet Code Solution
class Solution:
    def pushDominoes(self, dominoes: str) -> str:
        left_domino = self.leftside(dominoes)
        right_domino = self.rightside(dominoes)
        
        answer = self.merge(left_domino, right_domino)
        # print(dominoes)
        # print(left_domino)
        # print(right_domino)
        # print(answer)
        # print("")
        return answer
    
    def merge(self, left, right):
        result = [ "." for _ in range(len(left)) ]

        for j in range(len(left)):
            if left[j] != "L":
                break
            result[j] = "L"
        # merge starting point
        i = j
        for j in range(len(right) - 1, -1 ,-1):
            if right[j] != "R":
                break
            result[j] = "R"

        end = j
        while i <= end: 
            if left[i] == right[i]:
                result[i] = left[i]
                i += 1
                continue

            merge_start = i
            merge_start_char = result[i - 1]
            while left[i] != right[i]:
                i += 1
            merge_end = i - 1
            merge_end_char = left[i]
            merge_diff = merge_end - merge_start + 1

            if merge_start_char != merge_end_char:
                for j in range(merge_diff // 2):
                    result[merge_start + j] = "R"
                    result[merge_end - j] = "L"
            else:
                for j in range(merge_diff):
                    result[merge_start + j] = merge_start_char

        return "".join(result)

    def leftside(self, minostr: str):
        mino = list(minostr)
        break_down = False
        for i in range(len(mino) - 1, -1, -1):
            if mino[i] == "L":
                break_down = True
                continue
            if mino[i] == "R":
                break_down = False
                continue
            # mino [i] == "."
            if break_down is True:
                mino[i] = 'L'
        return "".join(mino)
    
    def rightside(self, minostr: str):
        mino = list(minostr)
        break_down = False
        for i in range(len(mino)):
            if mino[i] == "L":
                break_down = False
                continue
            if mino[i] == "R":
                break_down = True
                continue
            # mino [i] == "."
            if break_down is True:
                mino[i] = "R"
        return "".join(mino)

