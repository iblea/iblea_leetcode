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

}