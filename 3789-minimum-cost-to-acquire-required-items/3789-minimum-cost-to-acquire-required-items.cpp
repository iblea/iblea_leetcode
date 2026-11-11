class Solution {
public:
    long long minimumCost(int cost1, int cost2, int costBoth, int need1, int need2) {
        // costBoth >= cost1 + cost2  -> costBoth는 쓰레기값.
        // 경우의 수 1: costBoth 가 아예 필요없는 경우. (낱개로 사는게 더 이득인 경우)
        if (costBoth >= cost1 + cost2) {
            return (long long)cost1 * need1 + (long long)cost2 * need2;
        }

        // 경우의 수 2: costBoth가 필요하되, need1, need2 의 공통 부분만큼만 사는게 이득인 경우.
        // cost1= 1, cost2=100, costBoth=80, need1=2, need2=1
        long long ans;
        if (need1 > need2) {
            ans = (long long)costBoth * need2 + (long long)cost1 * (need1 - need2);
        } else {
            ans = (long long)costBoth * need1 + (long long)cost2 * (need2 - need1);
        }

        // 경우의 수 3: costBoth로 전부 구매하는게 이득인 경우. (cost1= 100, cost2= 99, costBoth=1)
        return min(ans, (long long)costBoth * max(need1, need2));
    }
};