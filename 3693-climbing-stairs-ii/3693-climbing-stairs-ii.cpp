class Solution {
public:
    int climbStairs(int n, vector<int>& costs) {
        long long steps[3] = {INT_MAX, INT_MAX, INT_MAX};
        steps[0] = costs[0] + 1;
        if (n >= 2) {
            steps[1] = min(steps[0] + costs[1] + 1, costs[1] + 4LL);
        } else {
            return (int)steps[0];
        }
        if (n >= 3) {
            steps[2] = min<long long>({steps[1] + costs[2] + 1, steps[0] + costs[2] + 4, costs[2] + 9});
        } else {
            return (int)steps[1];
        }
        long long curr;
        for (int i = 3; i < n; ++i) {
            // steps[0]: 3번째 전
            // steps[1]: 2번째 전
            // steps[2]: 1번째 전
            // curr: 현재 계단
            curr = costs[i] + min({ steps[0] + 9, steps[1] + 4, steps[2] + 1 });
            steps[0] = steps[1];
            steps[1] = steps[2];
            steps[2] = curr;
        }
        return (int)steps[2];
    }
};