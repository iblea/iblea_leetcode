class NumArray {

    private final int[] nums;
    private int sum = 0;
    private int nums_sum_limit_length = 0;

    public NumArray(int[] nums) {
        this.nums = nums;
        for (int num : nums) {
            this.sum += num;
        }
        this.nums_sum_limit_length = nums.length / 2;
    }
    
    // index의 값을 val로
    public void update(int index, int val) {
        int change_ago_index = nums[index];
        this.sum -= change_ago_index;
        this.sum += val;
        this.nums[index] = val;
    }
    
    // left부터 right 인덱스 까지의 합을 리턴 
    public int sumRange(int left, int right) {
        int result = 0;

        if ((right - left) > this.nums_sum_limit_length) {
            result = sum;

            for (int i = 0; i < left; ++i) {
                result -= this.nums[i];
            }
            for (int i = right + 1; i < this.nums.length; ++i) {
                result -= this.nums[i];
            }

            return result;
        }

        for (int i = left; i <= right; ++i) {
            result += this.nums[i];
        }
        return result;
    }
}