class Solution {
public:
    int xorAllNums(vector<int>& nums1, vector<int>& nums2) {
        int result1 = 0;
        int result2 = 0;

        int len1 = nums1.size();
        int len2 = nums2.size();
        if (len1 % 2 != 0) {
            for (int i = 0; i < nums2.size(); i++) {
                result2 ^= nums2[i];
            }
        }
        if (len2 % 2 != 0) {
            for (int i = 0; i < nums1.size(); i++) {
                result1 ^= nums1[i];
            }
        }
        return result1 ^ result2;
    }
};
