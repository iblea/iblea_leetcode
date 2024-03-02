class Solution {
    public int[] sortedSquares(int[] nums) {

        // 배열 첫 번째가 0보다 크면 투포인터 알고리즘 사용할 필요 없다.
        if (check_all_bigger_0_or_smaller_0(nums)) {
            return nums;
        }

        int left = 0;
        int right = nums.length - 1;

        int[] result = new int[nums.length];
        int index = nums.length - 1;
        while (left <= right) {

            int leftValue = Math.abs(nums[left]);
            int rightValue = nums[right];

            if (leftValue <= rightValue) {
                result[index] = rightValue * rightValue;
                right--;
            } else {
                result[index] = leftValue * leftValue;
                left++;
            }
            index--;
        }

        return result;
    }

    private boolean check_all_bigger_0_or_smaller_0(int[] nums) {
        if (nums[0] >= 0) {
            for (int i = 0; i < nums.length; i++) {
                nums[i] = nums[i] * nums[i];
            }
            return true;
        } else if (nums[nums.length - 1] <= 0) {
            int[] copied = Arrays.copyOf(nums, nums.length);
            int i = 0, j = nums.length - 1;
            while (i < nums.length) {
                nums[i] = copied[j] * copied[j];
                i++;
                j--;
            }
            return true;
        }
        return false;
    }
}
