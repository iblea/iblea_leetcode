class Solution {
public:
    string digitSum(string s, int k) {
        string result = s;

        while (result.length() > k) {
            string newResult = "";
            for (int i = 0; i < result.length(); i += k) {
                int sum = 0;
                int end = min(i + k, (int)result.length());
                for (int j = i; j < end; ++j) {
                    sum += result[j] - '0';
                }
                newResult += to_string(sum);
            }
            result = newResult;
        }
        
        return result;
    }
};