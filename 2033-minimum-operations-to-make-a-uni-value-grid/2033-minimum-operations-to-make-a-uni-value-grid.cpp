class Solution {
public:
    int minOperations(vector<vector<int>>& grid, int x) {
        int m = grid.size();
        int n = grid[0].size();
        vector<int> nums;
        // grid 배열을 1차원 배열로 변환한다.
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                nums.push_back(grid[i][j]);
            }
        }

        // 정렬한 뒤
        sort(nums.begin(), nums.end());
        // 1차원 배열의 요소 값의 차이가 x의 배수인지 확인한다.
        for (int i = 1; i < nums.size(); i++) {
            if ((nums[i] - nums[i-1]) % x != 0) {
                return -1;
            }
        }

        // 최소 연산 횟수를 계산한다.
        // 최소 연산 횟수를 구하기 위해서는, 중간 값을 기준으로 최소 연산 횟수를 계산한다.
        int target = nums[nums.size() / 2];
        int operations = 0;
        for (int num : nums) {
            operations += abs(num - target) / x;
        }
        return operations;

    }
};