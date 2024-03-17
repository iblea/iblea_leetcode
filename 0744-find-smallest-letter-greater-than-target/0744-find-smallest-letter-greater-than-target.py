class Solution:
    def nextGreatestLetter(self, letters: List[str], target: str) -> str:

        left: int  = 0
        right: int = len(letters) - 1

        # target이 문자열의 가장 큰 값보다 크면 가장 작은 값 반환
        if letters[right] <= target:
            return letters[0]

        while left <= right:
            mid: int = (left + right) // 2 # 3.2 -> 3
            if letters[mid] == target:
                return self.duplication_index_jump(letters, target, mid)
            # 타겟이 중간값보다 더 크면 오른쪽을 검색
            if letters[mid] < target:
                left = mid + 1
            # 타겟이 중간값보다 더 작으면 왼쪽 검색
            else:
                right = mid - 1

        return letters[left]

    def duplication_index_jump(
        self, letters: List[str], target: int, index: int
    ) -> str:
        while letters[index] == target:
            index += 1
        return letters[index]

