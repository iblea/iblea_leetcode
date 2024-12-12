class Solution {
public:
    long long pickGifts(vector<int>& gifts, int k) {

        priority_queue<int, vector<int>, less<void>> que;
        for (int i = 0; i < gifts.size(); i++) {
            que.push(gifts[i]);
        }

        for (int i = 0; i < k; i++) {
            int top = que.top();
            if (top == 1) {
                break;
            }
            // 제곱근 구해서 내림
            que.pop();
            double squareRoot = sqrt(top);
            int flooredSquareRoot = floor(squareRoot);
            que.push(flooredSquareRoot);
        }

        long long answer = 0;
        while (!que.empty()) {
            answer += que.top();
            que.pop();
        }
        return answer;
    }
};

