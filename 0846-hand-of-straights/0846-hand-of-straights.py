class Solution:
    def isNStraightHand(self, hand: List[int], groupSize: int) -> bool:
        if len(hand) % groupSize != 0:
            return False

        hand.sort()
        while len(hand) > 0:
            start = hand[0]
            for i in range(groupSize):
                if start + i not in hand:
                    return False
                hand.remove(start + i)

        return True
