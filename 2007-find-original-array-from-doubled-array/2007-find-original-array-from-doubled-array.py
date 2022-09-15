# Leet Code Solution
class Solution:
    def findOriginalArray(self, changed: List[int]) -> List[int]:
        changed.sort()
        counter = Counter(changed)
        result = []
        # 0에 대한 예외처리 진행
        if 0 in counter:
            if counter[0] % 2 == 1:
                return []
            for i in range(counter[0] // 2):
                result.append(0)
            del counter[0]

        for count in counter:
            if counter[count] == 0:
                continue
            if count * 2 in counter:
                if counter[count] > counter[count * 2]:
                    return []
                for i in range(counter[count]):
                    result.append(count)
                counter[count * 2] -= counter[count]
                counter[count] -= counter[count]
            else:
                if counter[count] > 0:
                    return []
        return result


