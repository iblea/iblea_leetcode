class Solution {
public:

    long long continuousSubarrays(vector<int>& nums) {

        const size_t nlen = nums.size();
        long long cnt = 0;

        multiset<int> hasX;
        size_t l = 0;
        for (size_t r = 0; r < nlen; r++) {
            hasX.insert(nums[r]);
            // l < r
            // set의 제일 마지막은 제일 큰값,
            // set의 제일 처음은 제일 작은값
            // 이 값의 차이가 2보다 크면 안된다.
            while (l < r && *prev(hasX.end())-*hasX.begin() > 2) {
                hasX.erase(hasX.find(nums[l]));
                l++;
            }
            cnt += r - l + 1;
        }
        return cnt;
    }
}
;
