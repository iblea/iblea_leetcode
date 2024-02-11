class Solution:
    def groupAnagrams(self, strs: List[str]) -> List[List[str]]:

        anagrams = {}
        for s in strs:
            anagrams_key = ''.join(sorted(s))
            if anagrams_key in anagrams:
                anagrams[anagrams_key].append(s)
            else:
                anagrams[anagrams_key] = [s]

        return list(anagrams.values())
