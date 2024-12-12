class Solution {
public:
    vector<int> grayCode(int n) {
        if (n == 1) {
            return { 0, 1 };
        }
        vector<int> answer = { 0, 1 };

        for (int i = 1; i < n; i++) {
            int pow = 1 << i;

            int arrlen = answer.size();
            for (int j = arrlen - 1; j >= 0; j--) {
                answer.push_back(answer[j] + pow);
            }
        }
        return answer;

    }
};
