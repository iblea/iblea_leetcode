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



/* https://leetcode.com/problems/max-difference-you-can-get-from-changing-an-integer
 * @lc app=leetcode id=1432 lang=cpp
 * [1432] Max Difference You Can Get From Changing an Integer

You are given an integer num. You will apply the following steps to num two separate times:
- Pick a digit x (0 <= x <= 9).
- Pick another digit y (0 <= y <= 9). Note y can be equal to x.
- Replace all the occurrences of x in the decimal representation of num by y.
Let a and b be the two results from applying the operation to num independently.
Return the max difference between a and b.
Note that neither a nor b may have any leading zeros, and must not be 0.

정수 num이 주어집니다. num에 대해 다음 단계를 두 번 별도로 적용합니다:
- 숫자 x (0 <= x <= 9)를 선택합니다.
- 다른 숫자 y (0 <= y <= 9)를 선택합니다. y는 x와 같을 수 있습니다.
- num의 십진 표현에서 x가 나타나는 모든 위치를 y로 바꿉니다.
a와 b를 num에 독립적으로 연산을 적용한 두 결과라고 하겠습니다.
a와 b 사이의 최대 차이를 반환합니다.
a와 b 모두 앞에 0이 오면 안 되고, 0이 되어서도 안 됩니다.

Constraints:
1 <= num <= 10**8
 */

// @lc code=start
class Solution {
public:
    int maxDiff(int num) {
        string s = to_string(num);
        string y_str = "";
        string x_str = "";
        int x, y;
        int n = s.size();

        int idx = -1;
        for (int i = 0; i < n; i++) {
            if (s[i] == '9') {
                continue;
            }
            idx = i;
            break;
        }
        if (idx >= 0) {
            char changed_num = s[idx];
            for (char c : s) {
                if (c == changed_num) {
                    x_str += '9';
                } else {
                    x_str += c;
                }
            }
            x = stoi(x_str);
        } else {
            x = num;
        }
        idx = -1;

        if (s[0] == '1') {
            for (int i = 1; i < n; i++) {
                if (s[i] == '0' || s[i] == '1') {
                    continue;
                }
                idx = i;
                break;
            }
        } else {
            idx = 0;
        }
        if (idx == 0) {
            char changed_num = s[idx];
            y_str = "1";
            for (int i = 1; i < n; i++) {
                if (s[i] == changed_num) {
                    y_str += '1';
                } else {
                    y_str += s[i];
                }
            }
            y = stoi(y_str);
        } else if (idx >= 1) {
            char changed_num = s[idx];
            for (char c : s) {
                if (c == changed_num) {
                    y_str += '0';
                } else {
                    y_str += c;
                }
            }
            y = stoi(y_str);
        } else {
            y = num;
        }

        return x - y;
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
    // Input: num = 555
    // Output: 888
    // Explanation: The first time pick x = 5 and y = 9 and store the new integer in a.
    // The second time pick x = 5 and y = 1 and store the new integer in b.
    // We have now a = 999 and b = 111 and max difference = 888
    // 설명: 첫 번째로 x = 5, y = 9를 선택하여 새로운 정수를 a에 저장한다.
    // 두 번째로 x = 5, y = 1을 선택하여 새로운 정수를 b에 저장한다.
    // 이제 a = 999, b = 111이고 최대 차이는 888이다.

    EXPECT_EQ(this->s.maxDiff(555), 888);
}

TEST_F(CLASS_NAME, __LINE__)
{
    // Example 2:
    // Input: num = 9
    // Output: 8
    // Explanation: The first time pick x = 9 and y = 9 and store the new integer in a.
    // The second time pick x = 9 and y = 1 and store the new integer in b.
    // We have now a = 9 and b = 1 and max difference = 8
    // 설명: 첫 번째로 x = 9, y = 9를 선택하여 새로운 정수를 a에 저장한다.
    // 두 번째로 x = 9, y = 1을 선택하여 새로운 정수를 b에 저장한다.
    // 이제 a = 9, b = 1이고 최대 차이는 8이다.

    EXPECT_EQ(this->s.maxDiff(9), 8);
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
