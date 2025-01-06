class Solution {
public:

    vector<int> minOperations(string boxes) {
        vector<int> answer;
        for (int i = 0; i < boxes.size(); i++) {
            int sum = 0;
            for (int j = 0; j < boxes.size(); j++) {
                if (boxes[j] == '0') {
                    continue;
                }
                sum += abs(j - i);
            }
            answer.push_back(sum);
        }
        return answer;
    }
};