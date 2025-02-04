#define SAME 0
#define INCREASE 1
#define DECREASE 2
typedef unsigned char uchar;

class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int nlen = nums.size() - 1;
        if (nlen == 0) {
            return 1;
        }
        int result = 1;
        int cnt = 0;
        uchar stat = SAME;

        for (int i = 0; i < nlen; i++) {
            if (nums[i] < nums[i+1]) {
                if (stat == INCREASE) {
                    cnt++;
                    continue;
                }
                result = max(result, cnt);
                cnt = 2;
                stat = INCREASE;
            } else if (nums[i] > nums[i+1]) {
                if (stat == DECREASE) {
                    cnt++;
                    continue;
                }
                result = max(result, cnt);
                cnt = 2;
                stat = DECREASE;
            } else {
                result = max(result, cnt);
                stat = SAME;
                cnt = 1;
            }
        }
        result = max(result, cnt);
        return result;
    }
};