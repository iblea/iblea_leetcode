class Solution {
private:
    multiset<int> windowL;
    multiset<int> windowR;
    long long sumL;
    long long sumR;

    void initialize() {
        this->windowL.clear();
        this->windowR.clear();
        this->sumL = 0;
        this->sumR = 0;
    }

    void windowBalance() {
        int val;
        while (this->windowL.size() > this->windowR.size() + 1) {
            auto it = prev(this->windowL.end());
            val = *it;
            this->windowR.insert(val);
            this->windowL.erase(it);
            sumL -= val;
            sumR += val;
        }
        while (this->windowL.size() < this->windowR.size()) {
            auto it = this->windowR.begin();
            val = *it;
            this->windowL.insert(val);
            this->windowR.erase(it);
            sumL += val;
            sumR -= val;
        }
    }

    void windowInsert(int n) {
        if (this->windowL.empty() || n <= *(this->windowL).rbegin()) {
            this->windowL.insert(n);
            this->sumL += n;
        } else {
            this->windowR.insert(n);
            this->sumR += n;
        }
        this->windowBalance();
    }
    void windowErase(int n) {
        if (this->windowL.find(n) != this->windowL.end()) {
            this->windowL.erase(this->windowL.find(n));
            this->sumL -= n;
        } else {
            this->windowR.erase(this->windowR.find(n));
            this->sumR -= n;
        }
        this->windowBalance();
    }

    long long windowCost() {
        long long med = *(this->windowL).rbegin();
        return (med * (long long)this->windowL.size() - this->sumL) + (this->sumR - med * (long long)this->windowR.size());
    }

public:
    long long minOperations(vector<int>& nums, int x, int k) {
        vector<long long> costs(nums.size() - x + 1, 0);
        this->initialize();

/*
각 index의 cost 계산 로직
[2,1,2,1,2,-3,2]
[2,1,2]
  [1,2,1]
    [2,1,2]
      [1,2,-3]
        [2,-3,2]
 */

        // 초기값 넣기
        for (int i = 0; i < x; i++) {
            this->windowInsert(nums[i]);
        }
        costs[0] = this->windowCost();

        int repeat_cnt = costs.size() - 1;;
        for (int i = 0; i < repeat_cnt; ++i) {
            this->windowErase(nums[i]);
            this->windowInsert(nums[i + x]);
            costs[i + 1] = this->windowCost();
        }

        // 앞에서 i개의 원소만 봤을 때 길이 x 구간을 j개 만드는 최소 비용
        vector<vector<long long>> dp(nums.size() + 1, vector<long long>(k + 1, -1));

        // AI 리뷰: INF 를 추가하고, 배열 초기값을 INF 로 설정하면, dp 계산할 때, min으로 더 깔끔하게 처리할 수 있다.
        // const long long INF = 1e18;
        // vector<vector<long long>> dp(nums.size() + 1, vector<long long>(k + 1, INF));

        for (int i = 0 ; i < dp.size(); ++i) {
            dp[i][0] = 0;
        }

        // if x = 3 , i = 8 , j = 2
        // [1,2,3,3,4,2,1 | 3]
        // -> [1,2,3,3,4,2,1] (3이 필요없거나) [1,2,3,3,4] [2,1,3] 마지막 x길이만큼의 원소값이 필요하거나
        // min(dp[7][2] , dp[5][1] + cost[5]) -> dp[8][2]
        // dp[i][j] = min(dp[i-1][j], dp[i-x][j-1] + cost[i-x]) -> dp[i][j]

        for (int i = x; i <= nums.size(); ++i) {
            for (int j = 1; j <= k; ++j) {
                long long a = dp[i - 1][j];
                long long b = dp[i - x][j - 1];
                if (b == -1) {
                    dp[i][j] = a;
                    continue;
                } else {
                    dp[i][j] = a == -1 ? b + costs[i - x] : min(a, b + costs[i - x]);
                }
                // dp[i][j] = min(dp[i - 1][j], dp[i - x][j - 1] + costs[i - x]);
            }
        }

        return dp[nums.size()][k];
    }
};