// import java.util.*;

class Solution {
    public double findMedianSortedArrays(int[] nums1, int[] nums2) {
        int length = nums1.length + nums2.length;
        int midLength = 0;
        midLength = length / 2 + 1;

        int[] merged = new int[midLength];

        int index1 = 0;
        int index2 = 0;
        for (int i = 0; i < midLength; i++) {

            if (index1 >= nums1.length) {
                merged[i] = nums2[index2];
                index2++;
                continue;
            }
            if (index2 >= nums2.length) {
                merged[i] = nums1[index1];
                index1++;
                continue;
            }

            if (nums1[index1] < nums2[index2]) {
                merged[i] = nums1[index1];
                index1++;
            } else {
                merged[i] = nums2[index2];
                index2++;
            }
        }

        if (length % 2 == 0) {
            return (double)(merged[midLength - 1] + merged[midLength - 2]) / 2.0;
        }
        return merged[midLength - 1];
    }




    public static void main(String[] args) {
        testcase1();
        testcase2();
    }

    public static void checkAnswer(double result, double answer) {
        System.out.println("result: " + result);
        System.out.println("answer: " + answer);

        if (result == answer) {
            System.out.println("Testcase is Passed!");
        } else {
            System.out.println("@@@@@@@@@@ Testcase is Failed! @@@@@@@@@@");
        }
        System.out.println();

    }

    public static void testcase1() {
        int[] nums1 = {1, 3};
        int[] nums2 = {2};

        double result = new Solution().findMedianSortedArrays(nums1, nums2);
        final double expected = 2.0;

        checkAnswer(result, expected);
    }

    public static void testcase2() {
        int[] nums1 = {1, 2};
        int[] nums2 = {3, 4};

        double result = new Solution().findMedianSortedArrays(nums1, nums2);
        final double expected = 2.5;

        checkAnswer(result, expected);
    }

}