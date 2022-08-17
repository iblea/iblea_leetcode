"""
Solution Note

1 <= words.length <= 100
1 <= words[i].length <= 12
words[i] consists of lowercase English letters.
"""

# Leet Code Solution
class Solution:
    MORSE = [".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."]
    LOWER_A = 97
    def uniqueMorseRepresentations(self, words: List[str]) -> int:

        morse_dict = {}
        for word in words:
            string = ""
            for c in word:
                string += self.get_morse_code(c)
            if string in morse_dict:
                morse_dict[string] += 1
            else:
                morse_dict[string] = 1
        return len(morse_dict)

    def get_morse_code(self, char: str) -> str:
        return self.MORSE[ord(char) - self.LOWER_A ];


