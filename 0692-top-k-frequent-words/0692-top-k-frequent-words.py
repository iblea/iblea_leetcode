# Leet Code Solution
class Solution:
    def topKFrequent(self, words: List[str], k: int) -> List[str]:
        output = []
        db = {}
        counter = Counter(words).most_common()
        # most_common이기에 첫번째 값이 가장 높은 빈도수를 가진다.
        max_val = counter[0][1]
        for word, count in counter:
            if count in db:
                db[count].append(word)
            else:
                db[count] = [word]

        for i in range(max_val, 0, -1):
            if i in db:
                db[i].sort()
                for word in db[i]:
                    output.append(word)
                    if len(output) == k:
                        return output
        return output