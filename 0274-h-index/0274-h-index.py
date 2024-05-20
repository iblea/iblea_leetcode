class Solution:
    def hIndex(self, citations: List[int]) -> int:
        citations_len: int = len(citations)
        quotation_count: list = [ 0 for _ in range (citations_len + 1)]
        for citation in citations:
            if (citation >= citations_len):
                quotation_count[citations_len] += 1
            else:
                quotation_count[citation] += 1

        cnt: int = 0
        for i in range(citations_len, -1, -1):
            cnt += quotation_count[i]
            if cnt >= i:
                return i
        return 0