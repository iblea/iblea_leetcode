#include <gtest/gtest.h>
#include <iostream>
#include <iomanip>
#include <algorithm>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <queue>
#include <array>
#include <any>

using namespace std;


/* https://leetcode.com/problems/apple-redistribution-into-boxes
 * @lc app=leetcode id=3074 lang=cpp
 * [3074] Apple Redistribution into Boxes

You are given an array apple of size n and an array capacity of size m.
There are n packs where the ith pack contains apple[i] apples. There are m boxes as well, and the ith box has a capacity of capacity[i] apples.
Return the minimum number of boxes you need to select to redistribute these n packs of apples into boxes.
Note that, apples from the same pack can be distributed into different boxes.

크기가 n인 배열 apple과 크기가 m인 배열 capacity가 주어집니다.
n개의 팩이 있으며, i번째 팩에는 apple[i]개의 사과가 들어 있습니다. 또한 m개의 상자가 있으며, i번째 상자의 용량은 capacity[i]개의 사과입니다.
이 n개의 사과 팩을 상자에 재분배하기 위해 선택해야 하는 최소 상자 개수를 반환하세요.
참고로, 같은 팩의 사과는 서로 다른 상자에 분배될 수 있습니다.

Constraints:
1 <= n == apple.length <= 50
1 <= m == capacity.length <= 50
1 <= apple[i], capacity[i] <= 50
The input is generated such that it's possible to redistribute packs of apples into boxes.
 */
// @lc code=start
class Solution {
public:
    int minimumBoxes(vector<int>& apple, vector<int>& capacity) {
        int sum = 0;
        for (int a : apple) {
            sum += a;
        }

        sort(capacity.begin(), capacity.end(), greater<int>());

        for (int i = 0; i < capacity.size(); i++) {
            sum -= capacity[i];
            if (sum <= 0) {
                return i + 1;
            }
        }
        return capacity.size();
    }
};
// @lc code=end



#define CLASS_NAME gtest_template

class CLASS_NAME: public ::testing::Test {
private:
    clock_t t0;
    clock_t t1;
public:
    Solution s;
protected:
    CLASS_NAME() { this->s = Solution(); }
    ~CLASS_NAME() override { }

    void SetUp() override { set_start_time(); }
    void TearDown() override { set_end_time(); get_duration_time(); }

    void set_start_time() {
        this->t0 = clock(); // or gettimeofday or whatever
    }
    void set_end_time() {
        this->t1 = clock(); // or gettimeofday or whatever
    }

    // 시간 관련 체크
    void get_duration_time() {
        double elapsedSec = (double)(this->t1 - this->t0) / (double)1000000;
        double elapsedMS = (double)(this->t1 - this->t0) / (double)1000;

        cout << setprecision(3) << fixed << endl << "Duration of Times : ";
        cout << elapsedMS << "ms, " << elapsedSec << "sec" << endl << endl;
    }
};

TEST_F(CLASS_NAME, __LINE__)
{
    // Example 1:
    // Input: apple = [1,3,2], capacity = [4,3,1,5,2]
    // Output: 2
    // Explanation: We will use boxes with capacities 4 and 5.
    // It is possible to distribute the apples as the total capacity is greater than or equal to the total number of apples.
    // 설명: 용량이 4와 5인 상자를 사용할 것입니다.
    // 총 용량이 전체 사과 개수보다 크거나 같으므로 사과를 분배하는 것이 가능합니다.

    vector<int> apple = {1, 3, 2};
    vector<int> capacity = {4, 3, 1, 5, 2};
    EXPECT_EQ(this->s.minimumBoxes(apple, capacity), 2);
}

TEST_F(CLASS_NAME, __LINE__)
{
    // Example 2:
    // Input: apple = [5,5,5], capacity = [2,4,2,7]
    // Output: 4
    // Explanation: We will need to use all the boxes.
    // 설명: 우리는 모든 상자를 사용해야 할 것입니다.

    vector<int> apple = {5, 5, 5};
    vector<int> capacity = {2, 4, 2, 7};
    EXPECT_EQ(this->s.minimumBoxes(apple, capacity), 4);
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}