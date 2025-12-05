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



/* https://leetcode.com/problems/count-collisions-on-a-road/
 * @lc app=leetcode id=2211 lang=cpp
 * [2211] Count Collisions on a Road

There are n cars on an infinitely long road. The cars are numbered from 0 to n - 1 from left to right and each car is present at a unique point.

You are given a 0-indexed string directions of length n. directions[i] can be either 'L', 'R', or 'S' denoting whether the `i`th car is moving towards the left, towards the right, or staying at its current point respectively. Each moving car has the same speed.

The number of collisions can be calculated as follows:
- When two cars moving in opposite directions collide with each other, the number of collisions increases by 2.
- When a moving car collides with a stationary car, the number of collisions increases by 1.

After a collision, the cars involved can no longer move and will stay at the point where they collided. Other than that, cars cannot change their state or direction of motion.
Return the total number of collisions that will happen on the road.

무한히 긴 도로에 n대의 자동차가 있다. 자동차는 왼쪽에서 오른쪽으로 0부터 n - 1까지 번호가 매겨져 있으며 각 자동차는 고유한 지점에 위치해 있다.

길이 n의 0-인덱스 문자열 directions가 주어진다. directions[i]는 'L', 'R', 또는 'S'일 수 있으며, 각각 i번째 자동차가 왼쪽으로 이동 중인지, 오른쪽으로 이동 중인지, 또는 현재 지점에 정지해 있는지를 나타낸다. 각 이동 중인 자동차는 동일한 속도를 가진다.

충돌 횟수는 다음과 같이 계산된다:
- 반대 방향으로 이동하는 두 자동차가 서로 충돌하면 충돌 횟수가 2씩 증가한다.
- 이동 중인 자동차가 정지한 자동차와 충돌하면 충돌 횟수가 1씩 증가한다.

충돌 후, 관련된 자동차들은 더 이상 이동할 수 없으며 충돌한 지점에 머물게 된다. 그 외에는 자동차들이 상태나 이동 방향을 변경할 수 없다.
도로에서 발생할 총 충돌 횟수를 반환하라.

Constraints:
1 <= directions.length <= (10**5)
directions[i] is either 'L', 'R', or 'S'.
*/

// @lc code=start
class Solution {
public:
    int countCollisions_for(string directions) {
        int totalR = 0;
        int totalL = 0;

        for (int i = 0; i < directions.size(); ++i) {
            if (directions[i] == 'R') {
                totalR++;
            } else if (directions[i] == 'L') {
                totalL++;
            }
        }
        for (int i = 0; i < directions.size(); ++i) {
            if (directions[i] != 'L') {
                break;
            }
            totalL--;
        }
        for (int i = directions.size() - 1; i >= 0; --i) {
            if (directions[i] != 'R') {
                break;
            }
            totalR--;
        }
        return (totalR + totalL);
    }
    // use two pointers
    int countCollisions(string& directions) {
        int n = directions.size();
        int left = 0;
        int right = n - 1;

        while (left <= right && directions[left] == 'L') left++;
        while (left <= right && directions[right] == 'R') right--;

        int count = 0;
        for (int i = left; i <= right; i++) {
            if (directions[i] != 'S') count++;
        }
        return count;
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
    // Input: directions = "RLRSLL"
    // Output: 5
    // Explanation:
    // The collisions that will happen on the road are:
    // - Cars 0 and 1 will collide with each other. Since they are moving in opposite directions, the number of collisions becomes 0 + 2 = 2.
    // - Cars 2 and 3 will collide with each other. Since car 3 is stationary, the number of collisions becomes 2 + 1 = 3.
    // - Cars 3 and 4 will collide with each other. Since car 3 is stationary, the number of collisions becomes 3 + 1 = 4.
    // - Cars 4 and 5 will collide with each other. After car 4 collides with car 3, it will stay at the point of collision and get hit by car 5. The number of collisions becomes 4 + 1 = 5.
    // Thus, the total number of collisions that will happen on the road is 5.

    EXPECT_EQ(this->s.countCollisions("RLRSLL"), 5);
}

TEST_F(CLASS_NAME, __LINE__)
{
    // Example 2:
    // Input: directions = "LLRR"
    // Output: 0
    // Explanation:
    // No cars will collide with each other. Thus, the total number of collisions that will happen on the road is 0.

    EXPECT_EQ(this->s.countCollisions("LLRR"), 0);
}


int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
