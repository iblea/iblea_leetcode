#define RED_COLOR 0
#define WHITE_COLOR 1
#define BLUE_COLOR 2

class Solution {
public:
    void sortColors(vector<int>& nums) {
        vector<int> colorCount(3, 0);

        for (int i = 0; i < nums.size(); i++) {
            colorCount[nums[i]]++;
        }
        for (int i = 0; i < nums.size(); i++) {
            if (i < colorCount[RED_COLOR]) {
                nums[i] = RED_COLOR;
            } else if (i < colorCount[RED_COLOR] + colorCount[WHITE_COLOR]) {
                nums[i] = WHITE_COLOR;
            } else {
                nums[i] = BLUE_COLOR;
            }
        }
    }
};
