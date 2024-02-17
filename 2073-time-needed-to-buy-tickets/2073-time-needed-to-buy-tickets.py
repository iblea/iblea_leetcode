class Solution:
    def timeRequiredToBuy(self, tickets: List[int], k: int) -> int:
        want_ticket: int = tickets[k]
        second: int = 0
        for i in range(len(tickets)):
            ticket: int = tickets[i]
            if ticket < want_ticket:
                second += ticket
                continue

            second += want_ticket
            if i > k:
                second -= 1
        return second