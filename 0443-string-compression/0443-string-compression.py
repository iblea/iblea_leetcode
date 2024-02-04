class Solution:
    def compress(self, chars: List[str]) -> int:
        compress_char: str = ""
        compress_count: int = 0
        compress_arr: list[str] = []
        for char in chars:
            if compress_char == char:
                compress_count += 1
                continue
            if compress_count > 1:
                compress_arr += list(str(compress_count))
            compress_count = 1
            compress_char = char
            compress_arr.append(compress_char)

        # deep copy
        # chars = compress_arr (X)
        chars[:] = compress_arr
        if compress_count > 1:
            chars += list(str(compress_count))
        return len(chars)