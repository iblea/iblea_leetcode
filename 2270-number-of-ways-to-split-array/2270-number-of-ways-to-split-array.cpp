class Solution {
public:
    int waysToSplitArray(vector<int>& nums) {

        int answer = 0;

        int end_idx = nums.size() - 1;
        long long left_sum = 0;
        long long right_sum = 0;
        for_each(nums.begin(), nums.end(), [&](int num){
            right_sum += num;
        });

        for(int i = 0; i < end_idx; i++){
            left_sum += nums[i];
            right_sum -= nums[i];
            if(left_sum >= right_sum){
                answer++;
            }
        }

        return answer;
    }
};
