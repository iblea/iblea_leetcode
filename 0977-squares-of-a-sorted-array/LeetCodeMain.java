// import java.util.*;

import java.util.Arrays;

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





class LeetCodeMain {
    public static void main(String[] args) {
        testcase1();
        testcase2();
        testcase3();
        testcase4();
    }

    public static void checkAnswer(int[] nums, int[] expected) {
        System.out.println("Hello checkAnswer!");
        System.out.println("nums: " + Arrays.toString(nums));
        System.out.println("expected: " + Arrays.toString(expected));

        if (Arrays.equals(nums, expected)) {
            System.out.println("Testcase is Passed!");
        } else {
            System.err.println("@@@@@@@@@@ Testcase is Failed! @@@@@@@@@@");
        }
        System.out.println();

    }

    public static void testcase1() {
        int[] nums = new int[]{-4,-1,0,3,10};
        int[] expected = new int[]{0,1,9,16,100};
        int[] result = new Solution().sortedSquares(nums);

        checkAnswer(result, expected);
    }

    public static void testcase2() {
        int[] nums = new int[]{-7,-3,2,3,11};
        int[] expected = new int[]{4,9,9,49,121};
        int[] result = new Solution().sortedSquares(nums);

        checkAnswer(result, expected);
    }

    public static void testcase3() {
        int[] nums = new int[]{0, 1, 2, 3, 4};
        int[] expected = new int[]{0, 1, 4, 9 ,16};
        int[] result = new Solution().sortedSquares(nums);

        checkAnswer(result, expected);
    }

    public static void testcase4() {
        int[] nums = new int[]{-5,-3,-2,-1};
        int[] expected = new int[]{1, 4, 9, 25};
        int[] result = new Solution().sortedSquares(nums);

        checkAnswer(result, expected);
    }
}