class Solution {

private:
    int get_sum_of_digits(int num) {
        int sum = 0;
        while (num > 0) {
            sum += num % 10;
            num /= 10;
        }
        return sum;
    }

public:
    int maximumSum(vector<int>& nums) {
        // key: 자릿수, value: 해당 자릿수의 제일 큰 숫자
        unordered_map<int, int> sum_map;
        int answer = -1;

        for (int num : nums) {
            int sum = get_sum_of_digits(num);
            if (sum_map.find(sum) == sum_map.end()) {
                sum_map[sum] = num;
                continue;
            }
            answer = max(answer, sum_map[sum] + num);
            if (sum_map[sum] < num) {
                sum_map[sum] = num;
            }
        }

        return answer;
    }
};